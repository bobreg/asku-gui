#include <QFileDialog>
#include <QDate>
#include "globalvar.h"
#include "dlgviewer.h"
#include "../common/module.h"
#include "../common/logger.h"

//-------------------------------------------------------------------------------
DlgViewer::DlgViewer(QWidget *parent) : AskuDialog("dialog_viewer", parent/*, Qt::Window*/)
{
	ui.setupUi(this);

	m_connected[0] = m_connected[1] = false;

	m_currentLoaded[0] = m_currentLoaded[1] = false;

	m_loadedFileName[0].clear();
	m_loadedFileName[1].clear();

	prepare(0);
	prepare(1);
}

//-------------------------------------------------------------------------------
DlgViewer::~DlgViewer()
{
}

//-------------------------------------------------------------------------------
void DlgViewer::sendAction(quint32 toGpr, QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "viewer";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	data["ToGprId"] = toGpr;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

//-------------------------------------------------------------------------------
void DlgViewer::clean(quint32 n)
{
	if(n == 0)
	{
		if(ui.pushFiles1->isChecked())
		{
			setFilesChecked(ui.pushFiles1, false);
			ui.list1->hide();
		}
		ui.pushCurrent1->setEnabled(false);
		ui.pushFiles1->setEnabled(m_connected[0]);
		ui.pushSelect1->setEnabled(false);

		showDate(0);
		showInformation(0, "НЕТ СВЯЗИ С ГПР1");

		checkSelect(0);
		clearContent(0);
		clearList(0);
	}
	if(n == 1)
	{
		if(ui.pushFiles2->isChecked())
		{
			setFilesChecked(ui.pushFiles2, false);
			ui.list2->hide();
		}
		ui.pushCurrent2->setEnabled(false);
		ui.pushFiles2->setEnabled(m_connected[1]);
		ui.pushSelect2->setEnabled(false);

		showDate(1);
		showInformation(1, "НЕТ СВЯЗИ С ГПР2");

		checkSelect(1);
		clearContent(1);
		clearList(1);
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::prepare(quint32 n)
{
	QTableWidget *t = 0;
	QListWidget *l = 0;

	if(n == 0)
	{
		t = ui.table1;
		l = ui.list1;
	}
	if(n == 1)
	{
		t = ui.table2;
		l = ui.list2;
	}

	if(t)
	{
		t->horizontalHeader()->resizeSection(0, 70);
		t->horizontalHeader()->resizeSection(1, 160);
		t->horizontalHeader()->resizeSection(2, 330);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//		t->horizontalHeader()->setClickable(false);
#else
		t->horizontalHeader()->setClickable(false);
#endif
		t->verticalHeader()->resizeSection(0, 10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//		t->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
//		t->verticalHeader()->setClickable(false);
#else
		t->verticalHeader()->setResizeMode(QHeaderView::Fixed);
		t->verticalHeader()->setClickable(false);
#endif
		t->verticalHeader()->hide();
		t->setSelectionMode(QAbstractItemView::NoSelection);
		t->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}

	if(l)
	{
		l->hide();
	}

	clean(n);
}

//-------------------------------------------------------------------------------
void DlgViewer::showInformation(quint32 n, QString text)
{
	if(n == 0)
	{
		ui.labelWait1->setText(text);

		if(text.isEmpty())
			ui.labelWait1->hide();
		else
			ui.labelWait1->show();
	}
	if(n == 1)
	{
		ui.labelWait2->setText(text);

		if(text.isEmpty())
			ui.labelWait2->hide();
		else
			ui.labelWait2->show();
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::showDate(quint32 n, QString text)
{
	if(n == 0)
	{
		ui.labelDate1->setText(text);
/*
		if(text.isEmpty())
			ui.labelDate1->hide();
		else
			ui.labelDate1->show();*/
	}
	if(n == 1)
	{
		ui.labelDate2->setText(text);
/*
		if(text.isEmpty())
			ui.labelDate2->hide();
		else
			ui.labelDate2->show();*/
	}
}

//-------------------------------------------------------------------------------
QString DlgViewer::nameToDate(QString name)
{
	QString strDate;
	if(!name.isEmpty())
	{
		QDate date = QDate::fromString(QFileInfo(name).baseName(), "yy_MM_dd");
		if(!date.isNull() && date.isValid())
			strDate = date.addYears(100).toString("dd.MM.yyyy");
	}
	return strDate;
}

//-------------------------------------------------------------------------------
void DlgViewer::checkLastMessage(quint32 n)
{
	if(n == 0 && ui.checkLast1->isChecked())
		ui.table1->scrollToBottom();
	if(n == 1 && ui.checkLast2->isChecked())
		ui.table2->scrollToBottom();
}

//-------------------------------------------------------------------------------
void DlgViewer::checkCurrent(quint32 n)
{
	if(n == 0)
		ui.pushCurrent1->setEnabled(!m_currentLoaded[0] && m_connected[0]);
	if(n == 1)
		ui.pushCurrent2->setEnabled(!m_currentLoaded[1] && m_connected[1]);
}

//-------------------------------------------------------------------------------
void DlgViewer::checkSelect(quint32 n)
{
	if(n == 0)
		ui.pushSelect1->setEnabled(m_connected[0]);
	if(n == 1)
		ui.pushSelect2->setEnabled(m_connected[1]);
}

//-------------------------------------------------------------------------------
void DlgViewer::showEvent(QShowEvent * event)
{
	clean(0);
	clean(1);

	if(m_connected[0])
		loadFile(0);

	if(m_connected[1])
		loadFile(1);

	event->accept();
}

//-------------------------------------------------------------------------------
qint32 DlgViewer::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgViewer: empty info data!");
		return result;
	}

	bool ok = false;
	quint32 numGpr = data["GprId"].toUInt(&ok);
	if(!ok || (numGpr != IDGPR1 && numGpr != IDGPR2))
	{
		result = AskuModule::CommandSuccess;
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "VIEWER_FILE_CONTENT")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgViewer: empty info on file content");
			return result;
		}

		processContent(numGpr, info);

		result = AskuModule::CommandSuccess;
	}
	if(infoType == "VIEWER_FILE_LIST")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgViewer: empty info on file list");
			return result;
		}

		processList(numGpr, info);

		result = AskuModule::CommandSuccess;
	}
	if(infoType == "VIEWER_MESSAGE")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgViewer: empty info on file list");
			return result;
		}

		processMessage(numGpr, info);

		result = AskuModule::CommandSuccess;
	}
	if(infoType == "VIEWER_CHANGED_DATE")
	{
		processChangedDate(numGpr);
		result = AskuModule::CommandSuccess;
	}

	return result;
}

//-------------------------------------------------------------------------------
void DlgViewer::on_pushCurrent1_clicked()
{
	loadFile(0);
}

//-------------------------------------------------------------------------------
void DlgViewer::on_pushSelect1_clicked()
{
	QListWidgetItem *item = ui.list1->currentItem();
	if(item)
	{
		QString name = item->text();
		loadFile(0, name);
	}
	else
	{
		loadFile(0);
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::setFilesChecked(QPushButton *pushFiles, bool on)
{
	pushFiles->setChecked(on);
	if(on)
		pushFiles->setText("Список <<");
	else
		pushFiles->setText("Список >>");
}

//-------------------------------------------------------------------------------
void DlgViewer::on_pushFiles1_clicked()
{
	if(!ui.pushFiles1->isChecked())
	{
		setFilesChecked(ui.pushFiles1, false);
		ui.list1->hide();
	}
	else
	{
		setFilesChecked(ui.pushFiles1, true);
		ui.list1->show();

		showInformation(0, "Ожидание загрузки списка файлов...");
		sendAction(0, "getList");
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::on_checkLast1_stateChanged(int state)
{
	if(state == Qt::Checked)
		checkLastMessage(0);
}

//-------------------------------------------------------------------------------
void DlgViewer::on_pushCurrent2_clicked()
{
	loadFile(1);
}

//-------------------------------------------------------------------------------
void DlgViewer::on_pushSelect2_clicked()
{
	QListWidgetItem *item = ui.list2->currentItem();
	if(item)
	{
		QString name = item->text();
		loadFile(1, name);
	}
	else
	{
		loadFile(1);
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::on_pushFiles2_clicked()
{
	if(!ui.pushFiles2->isChecked())
	{
		ui.pushFiles2->setChecked(false);
		ui.pushFiles2->setText("Список <<");
		ui.list2->hide();
	}
	else
	{
		ui.pushFiles2->setChecked(true);
		ui.pushFiles2->setText("Список >>");
		ui.list2->show();

		showInformation(1, "Ожидание загрузки списка файлов...");
		sendAction(1, "getList");
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::on_checkLast2_stateChanged(int state)
{
	if(state == Qt::Checked)
		checkLastMessage(1);
}

//-------------------------------------------------------------------------------
void DlgViewer::on_list1_itemDoubleClicked(QListWidgetItem * item)
{
	if(item)
		loadFile(0, item->text());
}

//-------------------------------------------------------------------------------
void DlgViewer::on_list2_itemDoubleClicked(QListWidgetItem * item)
{
	if(item)
		loadFile(1, item->text());
}

//-------------------------------------------------------------------------------
void DlgViewer::on_list1_itemSelectionChanged()
{
}

//-------------------------------------------------------------------------------
void DlgViewer::on_list2_itemSelectionChanged()
{
}

//-------------------------------------------------------------------------------
void DlgViewer::loadFile(quint32 n, QString name)
{
	showDate(n);
	showInformation(n, QString("Ожидание загрузки файла... \"%1\"").arg(name));

	if(name.isEmpty())
		sendAction(n, "getCurrent");
	else
		sendAction(n, "getFile", QStringList(name));
}

//-------------------------------------------------------------------------------
void DlgViewer::connected(quint32 numGpr)
{
	if(numGpr == IDGPR1)
	{
		m_connected[0] = true;
		clean(0);
		checkSelect(0);

		if(isVisible())
			loadFile(0);
	}
	if(numGpr == IDGPR2)
	{
		m_connected[1] = true;
		clean(1);
		checkSelect(1);

		if(isVisible())
			loadFile(1);
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::disconnected(quint32 numGpr)
{
	if(numGpr == IDGPR1)
	{
		m_connected[0] = false;
		clean(0);
	}
	if(numGpr == IDGPR2)
	{
		m_connected[1] = false;
		clean(1);
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::processList(quint32 numGpr, QVariantMap & info)
{
	QStringList list = info["List"].toStringList();

	if(numGpr == IDGPR1)
		processList(0, list);

	if(numGpr == IDGPR2)
		processList(1, list);
}

//-------------------------------------------------------------------------------
void DlgViewer::processContent(quint32 numGpr, QVariantMap & info)
{
	QVariantList content = info["Content"].toList();
	QString name = info["FileName"].toString();
	bool current = info["IsCurrent"].toBool();
	qint32 error = info["ErrorCode"].toInt();
	QString string = info["ErrorString"].toString();

	if(numGpr == IDGPR1)
		processContent(0, content, name, current, error, string);

	if(numGpr == IDGPR2)
		processContent(1, content, name, current, error, string);
}

//-------------------------------------------------------------------------------
void DlgViewer::processMessage(quint32 numGpr, QVariantMap & info)
{
	QStringList list = info["Message"].toStringList();

	if(numGpr == IDGPR1 && m_currentLoaded[0])
		processMessage(0, list);

	if(numGpr == IDGPR2 && m_currentLoaded[1])
		processMessage(1, list);
}

//-------------------------------------------------------------------------------
void DlgViewer::processChangedDate(quint32 numGpr)
{
	if(isVisible())
	{
		if(numGpr == IDGPR1)
		{
			if(m_currentLoaded[0])
				loadFile(0);
			if(ui.pushFiles1->isChecked())
				sendAction(0, "getList");
		}
		if(numGpr == IDGPR2)
		{
			if(m_currentLoaded[1])
				loadFile(1);
			if(ui.pushFiles2->isChecked())
				sendAction(1, "getList");
		}
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::processContent(quint32 n, QVariantList & content, QString & name, bool & current, qint32 & error, QString & errorString)
{
	bool err = false;

	QTableWidget *table;

	if(n == 0)
		table = ui.table1;
	else if(n == 1)
		table = ui.table2;
	else
		return;

	clearContent(n);

	m_currentLoaded[n] = current;
	m_loadedFileName[n] = name;

	foreach(QVariant vline, content)
	{
		QStringList line = vline.toStringList();
		if(line.count() == 4)
		{
			addContentLine(table, line);
		}
		else
		{
			err = true;
			break;
		}
	}

	checkCurrent(n);

	if(err)
	{
		showDate(n, nameToDate(name));
		showInformation(n, QString("Неверное содержимое файла \"%1\"!").arg(name));
	}
	else if(error < 0)
	{
		showDate(n, nameToDate(name));
		showInformation(n, QString("Ошибка загрузки файла \"%1\"(%2: %3)!").arg(name).arg(error).arg(errorString));
	}
	else
	{
		checkLastMessage(n);
		showDate(n, nameToDate(name));
		showInformation(n, QString("Файл успешно загружен \"%1\"").arg(name));
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::processList(quint32 n, QStringList & items)
{
	bool error = false;

	QListWidget *list;

	if(n == 0)
		list = ui.list1;
	else if(n == 1)
		list = ui.list2;
	else
		return;

	clearList(n);

	if(items.isEmpty())
		error = true;

	foreach(QString line, items)
		addListItem(list, line);

	selectListCurrent(n, m_loadedFileName[n]);

	if(error)
		showInformation(n, "Список файлов пуст");
	else
		showInformation(n, "Список файлов загружен");
}

//-------------------------------------------------------------------------------
void DlgViewer::processMessage(quint32 n, QStringList & line)
{
	bool error = false;

	QTableWidget *table;

	if(n == 0)
		table = ui.table1;
	else if(n == 1)
		table = ui.table2;
	else
		return;

	if(line.count() == 4)
	{
		addContentLine(table, line);
		checkLastMessage(n);
	}
	else
	{
		LogError("DlgViewer: incorrect message content");
		error = true;
	}

	if(error)
		showInformation(n, "Ошибка в сообщении!");
	else
		showInformation(n);
}

//-------------------------------------------------------------------------------
void DlgViewer::addContentLine(QTableWidget *table, QStringList & line)
{
	QString s_time = line[0];
	QString s_type = line[1];
	QString s_source = line[2];
	QString s_message = line[3];

	QBrush background = QBrush(QColor(s_type));

	QTableWidgetItem *item1 = new QTableWidgetItem(QString(s_time));
	item1->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	item1->setForeground(background);

	QTableWidgetItem *item2 = new QTableWidgetItem(QString(s_source));
	item2->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	item2->setForeground(background);

	QTableWidgetItem *item3 = new QTableWidgetItem(QString(s_message));
	item3->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	item3->setForeground(background);

	int row = table->rowCount();

	table->setRowCount(row + 1);
	table->setRowHeight(row, 16);

	table->setItem(row, 0, item1);
	table->setItem(row, 1, item2);
	table->setItem(row, 2, item3);
}

//-------------------------------------------------------------------------------
void DlgViewer::clearContent(quint32 n)
{
	if(n == 0)
	{
		for(qint32 row = ui.table1->rowCount(); row >= 0; row--)
			ui.table1->removeRow(row);
		m_currentLoaded[0] = false;
		m_loadedFileName[0].clear();
		checkCurrent(0);
	}
	if(n == 1)
	{
		for(qint32 row = ui.table2->rowCount(); row >= 0; row--)
			ui.table2->removeRow(row);
		m_currentLoaded[1] = false;
		m_loadedFileName[1].clear();
		checkCurrent(1);
	}
}

//-------------------------------------------------------------------------------
void DlgViewer::addListItem(QListWidget *list, QString & line)
{
	QListWidgetItem *item = new QListWidgetItem(style()->standardIcon(QStyle::SP_FileIcon), line);
	list->addItem(item);
}

//-------------------------------------------------------------------------------
void DlgViewer::selectListCurrent(quint32 n, QString name)
{
	QListWidget *list;

	if(n == 0)
		list = ui.list1;
	else if(n == 1)
		list = ui.list2;
	else
		return;

	QList<QListWidgetItem *> items = list->findItems(name,Qt::MatchExactly);
	if(!items.isEmpty())
		list->setCurrentItem(items.first());
}

//-------------------------------------------------------------------------------
void DlgViewer::clearList(quint32 n)
{
	if(n == 0)
	{
		ui.list1->clear();
	}
	if(n == 1)
	{
		ui.list2->clear();
	}
}

//-------------------------------------------------------------------------------
