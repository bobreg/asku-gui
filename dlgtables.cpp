#include <QMessageBox>
#include <QPalette>
#include "globalvar.h"
#include "dlgtables.h"
#include "../common/module.h"
#include "../common/logger.h"

//--------------------------------------------------------------
DlgTables::DlgTables(QWidget *parent) : AskuDialog("dialog_dasd_tables", parent, Qt::Window)
{
	ui.setupUi(this);

	clear();

	connect(ui.tableSwitch,	SIGNAL(itemSelectionChanged()),this,SLOT(updateButtonsSwitch()));
	connect(ui.tableMode,	SIGNAL(itemSelectionChanged()),this,SLOT(updateButtonsMode()));
	connect(ui.tableRipch,	SIGNAL(itemSelectionChanged()),this,SLOT(updateButtonsRipch()));
	connect(ui.tableDisable,SIGNAL(itemSelectionChanged()),this,SLOT(updateButtonsDisable()));
}

//--------------------------------------------------------------
DlgTables::~DlgTables()
{

}

//--------------------------------------------------------------
bool DlgTables::isLoaded()
{
	return m_loadedSwitch && m_loadedMode && m_loadedRipch && m_loadedDisable;
}

//--------------------------------------------------------------
void DlgTables::on_pushRefresh_clicked()
{
	clear();
	sendAction("refreshTables");
}

//--------------------------------------------------------------
void DlgTables::on_pushRefreshFiles_clicked()
{
	clear();
	sendAction("refreshTablesFromFile");
}

//--------------------------------------------------------------
void DlgTables::on_pushSaveModule_clicked()
{
	if(!isLoaded())
	{
		QMessageBox::warning(this, "АСКУ", "Ошибка. Таблицы не загружены.");
	}
	else if(!checkTables())
	{
		QMessageBox::warning(this, "АСКУ", "Ошибка. Некорректные данные в таблице.");
	}
	else
	{
		sendAction("saveTableRipch", m_tableRipch);
		sendAction("saveTableMode", m_tableMode);
		sendAction("saveTableSwitch", m_tableSwitch);
		sendAction("saveTableDisable", m_tableDisable);
	}
}

//--------------------------------------------------------------
void DlgTables::on_pushSaveFiles_clicked()
{
	if(!isLoaded())
	{
		QMessageBox::warning(this, "АСКУ", "Ошибка. Таблицы не загружены.");
	}
	else if(!checkTables())
	{
		QMessageBox::warning(this, "АСКУ", "Ошибка. Некорректные данные в таблице.");
	}
	else
	{
		sendAction("saveFileTableRipch", m_tableRipch);
		sendAction("saveFileTableMode", m_tableMode);
		sendAction("saveFileTableSwitch", m_tableSwitch);
		sendAction("saveFileTableDisable", m_tableDisable);
	}
}

//--------------------------------------------------------------
void DlgTables::on_pushClose_clicked()
{
	hide();
	clearTables();
}

// ------------------------------------------------------------------
qint32 DlgTables::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgTables: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "DASD_STATUS_MESSAGE")
	{
		QString message = data["Message"].toString();

		if(message.isEmpty())
		{
			LogError("DlgTables: empty message");
			return result;
		}
		//TODO

		result = AskuModule::CommandSuccess;
	}
	if(infoType == "DASD_RIPCH_TABLE")
	{
		quint32 maxRow = data["TableMaxRow"].toUInt();
		if(maxRow > 0)
			ripchMaxRow = maxRow;

		QVariantMap table = data["TableData"].toMap();

		if(table.isEmpty())
		{
			LogError("DlgTables: empty mode table");
			return result;
		}

		refreshRipch(table);
		result = AskuModule::CommandSuccess;
	}
	if(infoType == "DASD_MODE_TABLE")
	{
		quint32 maxRow = data["TableMaxRow"].toUInt();
		if(maxRow > 0)
			modeMaxRow = maxRow;

		QVariantMap table = data["TableData"].toMap();

		if(table.isEmpty())
		{
			LogError("DlgTables: empty mode table");
			return result;
		}

		refreshMode(table);
		result = AskuModule::CommandSuccess;
	}
	if(infoType == "DASD_SWITCH_TABLE")
	{
		quint32 maxRow = data["TableMaxRow"].toUInt();
		if(maxRow > 0)
			switchMaxRow = maxRow;

		QVariantMap table = data["TableData"].toMap();

		if(table.isEmpty())
		{
			LogError("DlgTables: empty switch table");
			return result;
		}

		refreshSwitch(table);
		result = AskuModule::CommandSuccess;
	}

	if(infoType == "DASD_DISABLE_TABLE")
	{
		quint32 maxRow = data["TableMaxRow"].toUInt();
		if(maxRow > 0)
			disableMaxRow = maxRow;

		QVariantMap table = data["TableData"].toMap();

		if(table.isEmpty())
		{
			LogError("DlgTables: empty disable table");
			return result;
		}

		refreshDisable(table);
		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgTables::sendAction(QString command, QVariantMap table)
{
	QVariantMap data;
	data["ModuleTo"] = "dasd";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!table.isEmpty())
		data["TableData"] = table;
	emit action(data);
}

// ------------------------------------------------------------------
void DlgTables::showEvent(QShowEvent * event)
{
	sendAction("refreshTables");
	ui.pushSaveFiles->setEnabled(false);
	ui.pushSaveModule->setEnabled(false);
	m_loadedSwitch = m_loadedMode = m_loadedRipch = m_loadedDisable = false;
	event->accept();
}

//--------------------------------------------------------------
void DlgTables::clearTables()
{
	clearTable(ui.tableSwitch);
	clearTable(ui.tableMode);
	clearTable(ui.tableRipch);
	clearTable(ui.tableDisable);
}

//--------------------------------------------------------------
void DlgTables::clearTable(QTableWidget *table)
{
	Q_UNUSED(table);
//	table->setRowCount(0);
/*
	for(qint32 i=0;i<table->rowCount();i++)
		for(qint32 j=0;j<table->columnCount();j++)
		{
			QTableWidgetItem *item = table->item(i,j);
			if(item)
			{
				item->setText("");
			}
			else
			{
				item = new QTableWidgetItem("");
				table->setItem(i,j,item);
			}
		}
*/
}

//--------------------------------------------------------------
void DlgTables::setUnselectable(QTableWidget* table, int col)
{
	for(qint32 i=0;i<table->rowCount();i++)
	{
		QTableWidgetItem *item = table->item(i,col);
		if(item)
			item->setFlags(item->flags() & (~Qt::ItemIsEditable));
	}
}

//--------------------------------------------------------------
void DlgTables::setHeaderLabels(QTableWidget *table, QVariantMap header)
{
	if(!table)
		return;

	for(qint32 col = 0; col < table->columnCount(); col++)
	{
		QVariantMap headerItem;

		foreach(QString hkey, header.keys())
		{
			headerItem = header[hkey].toMap();
			if(headerItem["index"].toInt() == col)
				break;
		}

		QString title = headerItem["title"].toString();
		QString units = headerItem["units"].toString();
		QString text = title.replace(" ","\n");

		if(!units.isEmpty())
			text += QString("\n") + units;

		QTableWidgetItem * item = table->horizontalHeaderItem(col);
		if(item)
		{
			item->setText(text);
			item->setData(Qt::UserRole, headerItem);
		}
		else
		{
			item = new QTableWidgetItem(text);
			item->setData(Qt::UserRole, headerItem);
			table->setHorizontalHeaderItem(col, item);
		}
	}
}

//--------------------------------------------------------------
void DlgTables::setTable(QTableWidget * table, QVariantList list)
{
	qint32 row, col;

	table->blockSignals(true);

	for(row = 0; row < table->rowCount(); row++)
	{
		if(row >= list.count())
		{
			qDebug("warning 1");
			continue; 
		}
		QVariantList itemlist = list[row].toList();

		for(col = 0; col < table->columnCount(); col++)
		{
			if(col >= itemlist.count())
			{
				qDebug("warning 2");
				continue; 
			}
			QString text = itemlist[col].toString();
			QTableWidgetItem *item = table->item(row, col);
			if(item)
				item->setText(text);
			else
			{
				item = new QTableWidgetItem(text);
				table->setItem(row, col, item);
			}
		}
	}

	table->blockSignals(false);
}

//--------------------------------------------------------------
void DlgTables::on_comboSwitch_activated(int index)
{
	QString survey = QString("survey_%1").arg(index);
	QVariantMap header = m_tableSwitch["header"].toMap();
	QVariantList surveylist = m_tableSwitch[survey].toList();

	ui.tableSwitch->setColumnCount(header.count());
	ui.tableSwitch->setRowCount(surveylist.count());

	setHeaderLabels(ui.tableSwitch, header);
	setTable(ui.tableSwitch, surveylist);
	ui.tableSwitch->resizeColumnsToContents();
	checkTable(ui.tableSwitch);
}

//--------------------------------------------------------------
void DlgTables::on_comboMode_activated(int index)
{
	QString mode = QString("mode_%1").arg(index);
	QVariantMap header = m_tableMode["header"].toMap();
	QVariantList modelist = m_tableMode[mode].toList();

	ui.tableMode->setColumnCount(header.count());
	ui.tableMode->setRowCount(modelist.count());

	setHeaderLabels(ui.tableMode, header);
	setTable(ui.tableMode, modelist);
	ui.tableMode->resizeColumnsToContents();
	checkTable(ui.tableMode);
}

//--------------------------------------------------------------
void DlgTables::on_comboRipch_activated(int index)
{
	QString impulse = QString("impulse_%1").arg(index);
	QVariantMap header = m_tableRipch["header"].toMap();
	QVariantList impulselist = m_tableRipch[impulse].toList();

	ui.tableRipch->setColumnCount(header.count());
	ui.tableRipch->setRowCount(impulselist.count());

	setHeaderLabels(ui.tableRipch, header);
	setTable(ui.tableRipch, impulselist);
	ui.tableRipch->resizeColumnsToContents();
	checkTable(ui.tableRipch);
}

//--------------------------------------------------------------
void DlgTables::onDisable_activated()
{
	QString segment = QString("segments");
	QVariantMap header = m_tableDisable["header"].toMap();
	QVariantList segmentlist = m_tableDisable[segment].toList();

	ui.tableDisable->setColumnCount(header.count());
	ui.tableDisable->setRowCount(segmentlist.count());

	setHeaderLabels(ui.tableDisable, header);
	setTable(ui.tableDisable, segmentlist);
	ui.tableDisable->resizeColumnsToContents();
	checkTable(ui.tableDisable);
}

//--------------------------------------------------------------
bool DlgTables::checkTableSwitch()
{
	QVariantMap header = m_tableSwitch["header"].toMap();
	QStringList names = m_tableSwitch.keys();

	for(qint32 i = 0; i < names.count(); i++)
	{
		QString survey = QString("survey_%1").arg(i);
		qint32 index = names.indexOf(survey);
		if(index >= 0)
		{
			QVariantList surveylist = m_tableSwitch[survey].toList();

			for(qint32 row = 0; row < surveylist.count(); row++)
			{
				if(row >= surveylist.count())
				{
					qDebug("warning 1");
					continue; 
				}

				QVariantList itemlist = surveylist[row].toList();

				for(qint32 col = 0; col < header.count(); col++)
				{
					if(col >= itemlist.count())
					{
						qDebug("warning 2");
						continue; 
					}

					QVariantMap headerItem;
					foreach(QString hkey, header.keys())
					{
						headerItem = header[hkey].toMap();
						if(headerItem["index"].toInt() == col)
							break;
					}

					QString value = itemlist[col].toString();
					bool result = checkInputValue(value, headerItem);
					if(!result)
					{
						errorIndex = i;
						errorTab = 0;
						errorRow = row;
						errorCol = col;
						return false;
					}
				}
			}
		}
	}

	return true;
}

//--------------------------------------------------------------
bool DlgTables::checkTableMode()
{
	QVariantMap header = m_tableMode["header"].toMap();
	QStringList names = m_tableMode.keys();

	for(qint32 i = 0; i < names.count(); i++)
	{
		QString mode = QString("mode_%1").arg(i);
		qint32 index = names.indexOf(mode);
		if(index >= 0)
		{
			QVariantList modelist = m_tableMode[mode].toList();

			for(qint32 row = 0; row < modelist.count(); row++)
			{
				if(row >= modelist.count())
				{
					qDebug("warning 1");
					continue; 
				}

				QVariantList itemlist = modelist[row].toList();

				for(qint32 col = 0; col < header.count(); col++)
				{
					if(col >= itemlist.count())
					{
						qDebug("warning 2");
						continue; 
					}

					QVariantMap headerItem;
					foreach(QString hkey, header.keys())
					{
						headerItem = header[hkey].toMap();
						if(headerItem["index"].toInt() == col)
							break;
					}

					QString value = itemlist[col].toString();
					bool result = checkInputValue(value, headerItem);
					if(!result)
					{
						errorIndex = i;
						errorTab = 1;
						errorRow = row;
						errorCol = col;
						return false;
					}
				}
			}
		}
	}

	return true;
}

//--------------------------------------------------------------
bool DlgTables::checkTableRipch()
{
	QVariantMap header = m_tableRipch["header"].toMap();
	QStringList names = m_tableRipch.keys();

	for(qint32 i = 0; i < names.count(); i++)
	{
		QString impulse = QString("impulse_%1").arg(i);
		qint32 index = names.indexOf(impulse);
		if(index >= 0)
		{
			QVariantList impulselist = m_tableRipch[impulse].toList();

			for(qint32 row = 0; row < impulselist.count(); row++)
			{
				if(row >= impulselist.count())
				{
					qDebug("warning 1");
					continue; 
				}

				QVariantList itemlist = impulselist[row].toList();

				for(qint32 col = 0; col < header.count(); col++)
				{
					if(col >= itemlist.count())
					{
						qDebug("warning 2");
						continue; 
					}

					QVariantMap headerItem;
					foreach(QString hkey, header.keys())
					{
						headerItem = header[hkey].toMap();
						if(headerItem["index"].toInt() == col)
							break;
					}

					QString value = itemlist[col].toString();
					bool result = checkInputValue(value, headerItem);
					if(!result)
					{
						errorIndex = i;
						errorTab = 2;
						errorRow = row;
						errorCol = col;
						return false;
					}
				}
			}
		}
	}

	return true;
}

//--------------------------------------------------------------
bool DlgTables::checkTableDisable()
{
	//TODO
	return true;
}

//--------------------------------------------------------------
bool DlgTables::checkTables()
{
	if(!isLoaded())
		return false;

	bool res = checkTableSwitch();
	if(!res)
	{
		qDebug("tab=%d index=%d row=%d col=%d",errorTab,errorIndex,errorRow,errorCol);
		ui.tabWidget->setCurrentIndex(errorTab);
		ui.comboSwitch->setCurrentIndex(errorIndex);
		on_comboSwitch_activated(errorIndex);
		ui.tableSwitch->clearSelection();
//		ui.tableSwitch->item(errorRow, errorCol)->setSelected(true);
		return false;
	}

	res = checkTableMode();
	if(!res)
	{
		qDebug("tab=%d index=%d row=%d col=%d",errorTab,errorIndex,errorRow,errorCol);
		ui.tabWidget->setCurrentIndex(errorTab);
		ui.comboMode->setCurrentIndex(errorIndex);
		on_comboMode_activated(errorIndex);
		ui.tableMode->clearSelection();
//		ui.tableMode->item(errorRow, errorCol)->setSelected(true);
		return false;
	}

	res = checkTableRipch();
	if(!res)
	{
		qDebug("tab=%d index=%d row=%d col=%d",errorTab,errorIndex,errorRow,errorCol);
		ui.tabWidget->setCurrentIndex(errorTab);
		ui.comboRipch->setCurrentIndex(errorIndex);
		on_comboRipch_activated(errorIndex);
		ui.tableRipch->clearSelection();
//		ui.tableRipch->item(errorRow, errorCol)->setSelected(true);
		return false;
	}

	res = checkTableDisable();
	if(!res)
	{
		qDebug("tab=%d index=%d row=%d col=%d",errorTab,errorIndex,errorRow,errorCol);
		ui.tabWidget->setCurrentIndex(errorTab);
		onDisable_activated();
		ui.tableRipch->clearSelection();
//		ui.tableRipch->item(errorRow, errorCol)->setSelected(true);
		return false;
	}

	return true;
}

//--------------------------------------------------------------
bool DlgTables::checkTable(QTableWidget * table)
{
	for(qint32 col = 0; col < table->columnCount(); col++)
	{
		QVariantMap header = table->horizontalHeaderItem(col)->data(Qt::UserRole).toMap();

		for(qint32 row = 0; row < table->rowCount(); row++)
		{
			QTableWidgetItem *item = table->item(row, col);
			QString text = item->text();
			bool result = checkInputValue(text, header);
			setBackground(item, !result);
		}
	}

	return true;
}

//--------------------------------------------------------------
void DlgTables::refreshRipch(QVariantMap table)
{
	qint32 lastIndex = ui.comboRipch->currentIndex();
	if(lastIndex < 0)
		lastIndex = 0;
 
	ui.comboRipch->clear();
	QStringList names = table.keys();
	for(qint32 i = 0; i < names.count(); i++)
	{
		qint32 index = names.indexOf(QString("impulse_%1").arg(i));
		if(index >= 0)
		{
			QString name = QString("Импульс %1").arg(i/*+1*/);
			ui.comboRipch->addItem(name, i);
		}
	}

	m_tableRipch = table;
	m_loadedRipch = true;
	ui.tableRipch->clearSelection();
	ui.comboRipch->setCurrentIndex(lastIndex);
	on_comboRipch_activated(lastIndex);
	updateButtonsRipch();
	ui.pushSaveFiles->setEnabled(isLoaded());
	ui.pushSaveModule->setEnabled(isLoaded());
}

//--------------------------------------------------------------
void DlgTables::refreshMode(QVariantMap table)
{
	qint32 lastIndex = ui.comboMode->currentIndex();
	if(lastIndex < 0)
		lastIndex = 0;
 
	ui.comboMode->clear();
	QStringList names = table.keys();
	for(qint32 i = 0; i < names.count(); i++)
	{
		qint32 index = names.indexOf(QString("mode_%1").arg(i));
		if(index >= 0)
		{
			QString name = QString("Режим Обзора %1").arg(i/*+1*/);
			ui.comboMode->addItem(name, i);
		}
	}

	m_tableMode = table;
	m_loadedMode = true;
	ui.tableMode->clearSelection();
	ui.comboMode->setCurrentIndex(lastIndex);
	on_comboMode_activated(lastIndex);
	updateButtonsMode();
	ui.pushSaveFiles->setEnabled(isLoaded());
	ui.pushSaveModule->setEnabled(isLoaded());
}

//--------------------------------------------------------------
void DlgTables::refreshSwitch(QVariantMap table)
{
	qint32 lastIndex = ui.comboSwitch->currentIndex();
	if(lastIndex < 0)
		lastIndex = 0;
 
	ui.comboSwitch->clear();
	QStringList names = table.keys();
	for(qint32 i = 0; i < names.count(); i++)
	{
		qint32 index = names.indexOf(QString("survey_%1").arg(i));
		if(index >= 0)
		{
			QString name = QString("Обзор %1").arg(i/*+1*/);
			ui.comboSwitch->addItem(name, i);
		}
	}

	m_tableSwitch = table;
	m_loadedSwitch = true;
	ui.tableSwitch->clearSelection();
	ui.comboSwitch->setCurrentIndex(lastIndex);
	on_comboSwitch_activated(lastIndex);
	updateButtonsSwitch();
	ui.pushSaveFiles->setEnabled(isLoaded());
	ui.pushSaveModule->setEnabled(isLoaded());
}

//--------------------------------------------------------------
void DlgTables::refreshDisable(QVariantMap table)
{
	m_tableDisable = table;
	m_loadedDisable = true;
	
	ui.tableDisable->clearSelection();
	onDisable_activated();
	updateButtonsDisable();
	ui.pushSaveFiles->setEnabled(isLoaded());
	ui.pushSaveModule->setEnabled(isLoaded());
}

//--------------------------------------------------------------
void DlgTables::results(QString message)
{
	QMessageBox::information(this, "АСКУ", message);
}

//--------------------------------------------------------------
/*void DlgTables::result(qint32 result)
{
    QString strError;
    switch(result)
    {
        case TABLES_NO_ERROR:
            strError = "Выполнено успешно";
            break;
        case TABLES_ERROR_READ_FILE:
            strError = "Ошибка чтения файла";
            break;
        case TABLES_ERROR_WRITE_FILE:
            strError = "Ошибка записи файла";
            break;
        case TABLES_ERROR_READ_MODULE:
            strError = "Ошибка чтения модуля";
            break;
        case TABLES_ERROR_WRITE_MODULE:
            strError = "Ошибка записи модуля";
            break;
        case TABLES_ERROR_DATA:
            strError = "Ошибка данных таблицы";
            break;
        default:
            strError = "Ошибка";
    }
    if(result!=TABLES_NO_ERROR)
        QMessageBox::warning(this,"АСКУ",strError);
    else
        QMessageBox::information(this,"АСКУ",strError);
}*/

//--------------------------------------------------------------
QVariantList DlgTables::makeEmptyRow(QVariantMap header)
{
	QVariantList list;

	for(qint32 col = 0; col < header.count(); col++)
	{
		QVariantMap headerItem;

		foreach(QString hkey, header.keys())
		{
			headerItem = header[hkey].toMap();
			if(headerItem["index"].toInt() == col)
				break;
		}

		QString min = headerItem["min"].toString();
		list << min;
	}

	return list;
}

//--------------------------------------------------------------
bool DlgTables::checkInputValue(QString value, QVariantMap headerItem)
{
	QString sMin = headerItem["min"].toString();
	QString sMax = headerItem["max"].toString();

	if(sMin.isEmpty() && sMax.isEmpty())
		return true;

	bool ok = false;
	double dValue = value.toDouble(&ok);
	if(!ok)
		return false;

	double dMin = sMin.toDouble(&ok);
	if(!ok)
		return false;

	double dMax = sMax.toDouble(&ok);
	if(!ok)
		return false;

	if(dMin > dValue || dMax < dValue)
		return false;

	return true;
}

//--------------------------------------------------------------
void DlgTables::setBackground(QTableWidgetItem* item, bool error)
{
	QTableWidget *table = item->tableWidget();
	QBrush brush;

	table->blockSignals(true);

	if(error)
		brush = QBrush(Qt::red);
	else if(table->alternatingRowColors())
	{
		if((item->row() % 2) == 0)
			brush = palette().brush(QPalette::Base);
		else
			brush = palette().brush(QPalette::AlternateBase);
	}
	else
	{
		brush = palette().brush(QPalette::Base);
	}

	item->setBackground(brush);

	table->blockSignals(false);
}

//--------------------------------------------------------------
void DlgTables::on_tableSwitch_cellChanged(int row, int col)
{
	QTableWidget *tableSwitch = (QTableWidget*)sender();
	QString text = tableSwitch->item(row, col)->text();
	QVariantMap header = tableSwitch->horizontalHeaderItem(col)->data(Qt::UserRole).toMap();

	bool result = checkInputValue(text, header);

	setBackground(tableSwitch->item(row,col), !result);

//	if(result)
	{
		qint32 index = ui.comboSwitch->currentIndex();
		QString survey = QString("survey_%1").arg(index);

		QVariantList list = m_tableSwitch[survey].toList();
		QVariantList listRow = list[row].toList();
		listRow[col] = text;
		list[row] = listRow;
		m_tableSwitch[survey] = list;
	}
}

//--------------------------------------------------------------
void DlgTables::on_tableMode_cellChanged(int row, int col)
{
	QTableWidget *tableMode = (QTableWidget*)sender();
	QString text = tableMode->item(row, col)->text();
	QVariantMap header = tableMode->horizontalHeaderItem(col)->data(Qt::UserRole).toMap();

	bool result = checkInputValue(text, header);

	setBackground(tableMode->item(row,col), !result);

//	if(result)
	{
		qint32 index = ui.comboMode->currentIndex();
		QString mode = QString("mode_%1").arg(index);

		QVariantList list = m_tableMode[mode].toList();
		QVariantList listRow = list[row].toList();
		listRow[col] = text;
		list[row] = listRow;
		m_tableMode[mode] = list;
	}
}

//--------------------------------------------------------------
void DlgTables::on_tableRipch_cellChanged(int row, int col)
{
	QTableWidget *tableRipch = (QTableWidget*)sender();
	QString text = tableRipch->item(row, col)->text();
	QVariantMap header = tableRipch->horizontalHeaderItem(col)->data(Qt::UserRole).toMap();

	bool result = checkInputValue(text, header);

	setBackground(tableRipch->item(row,col), !result);

//	if(result)
	{
		qint32 index = ui.comboRipch->currentIndex();
		QString impulse = QString("impulse_%1").arg(index);

		QVariantList list = m_tableRipch[impulse].toList();
		QVariantList listRow = list[row].toList();
		listRow[col] = text;
		list[row] = listRow;
		m_tableRipch[impulse] = list;
	}
}

//--------------------------------------------------------------
void DlgTables::on_tableDisable_cellChanged(int row, int col)
{
	QTableWidget *tableDisable = (QTableWidget*)sender();
	QString text = tableDisable->item(row, col)->text();
	QVariantMap header = tableDisable->horizontalHeaderItem(col)->data(Qt::UserRole).toMap();

	bool result = checkInputValue(text, header);

	setBackground(tableDisable->item(row,col), !result);

//	if(result)
	{
		QString segment = QString("segments");
		QVariantList list = m_tableDisable[segment].toList();
		QVariantList listRow = list[row].toList();
		listRow[col] = text;
		list[row] = listRow;
		m_tableDisable[segment] = list;
	}
}

//--------------------------------------------------------------
void DlgTables::updateButtonsSwitch()
{
	QTableWidget *table = ui.tableSwitch;
	QPushButton *button_ad = ui.pushSwitchAdd;
	QPushButton *button_de = ui.pushSwitchDelete;
	QPushButton *button_up = ui.pushSwitchUp;
	QPushButton *button_dn = ui.pushSwitchDown;

	qint32 maxRow = switchMaxRow;//255

	if(maxRow > 0)
	{
		QList<QTableWidgetItem*> selection = table->selectedItems();

		button_ad->setEnabled(table->rowCount() < maxRow);
		button_de->setEnabled(!selection.isEmpty());
		button_up->setEnabled(!selection.isEmpty() && selection.first()->row() > 0);
		button_dn->setEnabled(!selection.isEmpty() && selection.first()->row() < (table->rowCount() - 1));
	}
	else
	{
		button_ad->setEnabled(false);
		button_de->setEnabled(false);
		button_up->setEnabled(false);
		button_dn->setEnabled(false);
	}
}

//--------------------------------------------------------------
void DlgTables::updateButtonsMode()
{
	QTableWidget *table = ui.tableMode;
	QPushButton *button_ad = ui.pushModeAdd;
	QPushButton *button_de = ui.pushModeDelete;
	QPushButton *button_up = ui.pushModeUp;
	QPushButton *button_dn = ui.pushModeDown;

	qint32 maxRow = modeMaxRow;//32

	if(maxRow > 0)
	{
		QList<QTableWidgetItem*> selection = table->selectedItems();

		button_ad->setEnabled(table->rowCount() < maxRow);
		button_de->setEnabled(!selection.isEmpty());
		button_up->setEnabled(!selection.isEmpty() && selection.first()->row() > 0);
		button_dn->setEnabled(!selection.isEmpty() && selection.first()->row() < (table->rowCount() - 1));
	}
	else
	{
		button_ad->setEnabled(false);
		button_de->setEnabled(false);
		button_up->setEnabled(false);
		button_dn->setEnabled(false);
	}
}

//--------------------------------------------------------------
void DlgTables::updateButtonsRipch()
{
	QTableWidget *table = ui.tableRipch;
	QPushButton *button_ad = ui.pushRipchAdd;
	QPushButton *button_de = ui.pushRipchDelete;
	QPushButton *button_up = ui.pushRipchUp;
	QPushButton *button_dn = ui.pushRipchDown;

	qint32 maxRow = ripchMaxRow;//16

	if(maxRow > 0)
	{
		QList<QTableWidgetItem*> selection = table->selectedItems();

		button_ad->setEnabled(table->rowCount() < maxRow);
		button_de->setEnabled(!selection.isEmpty());
		button_up->setEnabled(!selection.isEmpty() && selection.first()->row() > 0);
		button_dn->setEnabled(!selection.isEmpty() && selection.first()->row() < (table->rowCount() - 1));
	}
	else
	{
		button_ad->setEnabled(false);
		button_de->setEnabled(false);
		button_up->setEnabled(false);
		button_dn->setEnabled(false);
	}
}

//--------------------------------------------------------------
void DlgTables::updateButtonsDisable()
{
	QTableWidget *table = ui.tableDisable;
	QPushButton *button_ad = ui.pushDisableAdd;
	QPushButton *button_de = ui.pushDisableDelete;
	QPushButton *button_up = ui.pushDisableUp;
	QPushButton *button_dn = ui.pushDisableDown;

	qint32 maxRow = disableMaxRow;//32

	if(maxRow > 0)
	{
		QList<QTableWidgetItem*> selection = table->selectedItems();

		button_ad->setEnabled(table->rowCount() < maxRow);
		button_de->setEnabled(!selection.isEmpty());
		button_up->setEnabled(!selection.isEmpty() && selection.first()->row() > 0);
		button_dn->setEnabled(!selection.isEmpty() && selection.first()->row() < (table->rowCount() - 1));
	}
	else
	{
		button_ad->setEnabled(false);
		button_de->setEnabled(false);
		button_up->setEnabled(false);
		button_dn->setEnabled(false);
	}
}

//--------------------------------------------------------------
void DlgTables::on_pushSwitchAdd_clicked()
{
	qint32 index = ui.comboSwitch->currentIndex();
	QString survey = QString("survey_%1").arg(index);
	QVariantMap header = m_tableSwitch["header"].toMap();

	QList<QTableWidgetItem*> selection = ui.tableSwitch->selectedItems();

	qint32 col = 0;
	qint32 row = ui.tableSwitch->rowCount();

	if(!selection.isEmpty())
	{
		col = selection.first()->column();
		selection.first()->setSelected(false);
	}

	QVariantList list = m_tableSwitch[survey].toList();
	list.append(QVariant(makeEmptyRow(header)));
	m_tableSwitch[survey] = list;

	on_comboSwitch_activated(index);
	ui.tableSwitch->item(row,col)->setSelected(true);
	updateButtonsSwitch();
}

//--------------------------------------------------------------
void DlgTables::on_pushSwitchDelete_clicked()
{
	qint32 index = ui.comboSwitch->currentIndex();
	QString survey = QString("survey_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableSwitch->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();

	QVariantList list = m_tableSwitch[survey].toList();
	list.removeAt(row);
	m_tableSwitch[survey] = list;

	on_comboSwitch_activated(index);
	updateButtonsSwitch();
}

//--------------------------------------------------------------
void DlgTables::on_pushSwitchUp_clicked()
{
	qint32 index = ui.comboSwitch->currentIndex();
	QString survey = QString("survey_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableSwitch->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableSwitch->item(row,col)->setSelected(false);

	QVariantList list = m_tableSwitch[survey].toList();
	list.swap(row, row-1);
	m_tableSwitch[survey] = list;

	on_comboSwitch_activated(index);
	ui.tableSwitch->item(row-1,col)->setSelected(true);
	updateButtonsSwitch();
}

//--------------------------------------------------------------
void DlgTables::on_pushSwitchDown_clicked()
{
	qint32 index = ui.comboSwitch->currentIndex();
	QString survey = QString("survey_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableSwitch->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableSwitch->item(row,col)->setSelected(false);

	QVariantList list = m_tableSwitch[survey].toList();
	list.swap(row, row+1);
	m_tableSwitch[survey] = list;

	on_comboSwitch_activated(index);
	ui.tableSwitch->item(row+1,col)->setSelected(true);
	updateButtonsSwitch();
}

//--------------------------------------------------------------
void DlgTables::on_pushModeAdd_clicked()
{
	qint32 index = ui.comboMode->currentIndex();
	QString mode = QString("mode_%1").arg(index);
	QVariantMap header = m_tableMode["header"].toMap();

	QList<QTableWidgetItem*> selection = ui.tableMode->selectedItems();

	qint32 col = 0;
	qint32 row = ui.tableMode->rowCount();

	if(!selection.isEmpty())
	{
		col = selection.first()->column();
		selection.first()->setSelected(false);
	}

	QVariantList list = m_tableMode[mode].toList();
	list.append(QVariant(makeEmptyRow(header)));
	m_tableMode[mode] = list;

	on_comboMode_activated(index);
	ui.tableMode->item(row,col)->setSelected(true);
	updateButtonsMode();
}

//--------------------------------------------------------------
void DlgTables::on_pushModeDelete_clicked()
{
	qint32 index = ui.comboMode->currentIndex();
	QString mode = QString("mode_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableMode->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();

	QVariantList list = m_tableMode[mode].toList();
	list.removeAt(row);
	m_tableMode[mode] = list;

	on_comboMode_activated(index);
	updateButtonsMode();
}

//--------------------------------------------------------------
void DlgTables::on_pushModeUp_clicked()
{
	qint32 index = ui.comboMode->currentIndex();
	QString mode = QString("mode_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableMode->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableMode->item(row,col)->setSelected(false);

	QVariantList list = m_tableMode[mode].toList();
	list.swap(row, row-1);
	m_tableMode[mode] = list;

	on_comboMode_activated(index);
	ui.tableMode->item(row-1,col)->setSelected(true);
	updateButtonsMode();
}

//--------------------------------------------------------------
void DlgTables::on_pushModeDown_clicked()
{
	qint32 index = ui.comboMode->currentIndex();
	QString mode = QString("mode_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableMode->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableMode->item(row,col)->setSelected(false);

	QVariantList list = m_tableMode[mode].toList();
	list.swap(row, row+1);
	m_tableMode[mode] = list;

	on_comboMode_activated(index);
	ui.tableMode->item(row+1,col)->setSelected(true);
	updateButtonsMode();
}

//--------------------------------------------------------------
void DlgTables::on_pushRipchAdd_clicked()
{
	qint32 index = ui.comboRipch->currentIndex();
	QString impulse = QString("impulse_%1").arg(index);
	QVariantMap header = m_tableRipch["header"].toMap();

	QList<QTableWidgetItem*> selection = ui.tableRipch->selectedItems();

	qint32 col = 0;
	qint32 row = ui.tableRipch->rowCount();

	if(!selection.isEmpty())
	{
		col = selection.first()->column();
		selection.first()->setSelected(false);
	}

	QVariantList list = m_tableRipch[impulse].toList();
	list.append(QVariant(makeEmptyRow(header)));
	m_tableRipch[impulse] = list;

	on_comboRipch_activated(index);
	ui.tableRipch->item(row,col)->setSelected(true);
	updateButtonsRipch();
}

//--------------------------------------------------------------
void DlgTables::on_pushRipchDelete_clicked()
{
	qint32 index = ui.comboRipch->currentIndex();
	QString impulse = QString("impulse_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableRipch->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();

	QVariantList list = m_tableRipch[impulse].toList();
	list.removeAt(row);
	m_tableRipch[impulse] = list;

	on_comboRipch_activated(index);
	updateButtonsRipch();
}

//--------------------------------------------------------------
void DlgTables::on_pushRipchUp_clicked()
{
	qint32 index = ui.comboRipch->currentIndex();
	QString impulse = QString("impulse_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableRipch->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableRipch->item(row,col)->setSelected(false);

	QVariantList list = m_tableRipch[impulse].toList();
	list.swap(row, row-1);
	m_tableRipch[impulse] = list;

	on_comboRipch_activated(index);
	ui.tableRipch->item(row-1,col)->setSelected(true);
	updateButtonsRipch();
}

//--------------------------------------------------------------
void DlgTables::on_pushRipchDown_clicked()
{
	qint32 index = ui.comboRipch->currentIndex();
	QString impulse = QString("impulse_%1").arg(index);
	QList<QTableWidgetItem*> selection = ui.tableRipch->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableRipch->item(row,col)->setSelected(false);

	QVariantList list = m_tableRipch[impulse].toList();
	list.swap(row, row+1);
	m_tableRipch[impulse] = list;

	on_comboRipch_activated(index);
	ui.tableRipch->item(row+1,col)->setSelected(true);
	updateButtonsRipch();
}

//--------------------------------------------------------------
void DlgTables::on_pushDisableAdd_clicked()
{
	QString segment = QString("segments");
	QVariantMap header = m_tableDisable["header"].toMap();

	QList<QTableWidgetItem*> selection = ui.tableDisable->selectedItems();

	qint32 col = 0;
	qint32 row = ui.tableDisable->rowCount();

	if(!selection.isEmpty())
	{
		col = selection.first()->column();
		selection.first()->setSelected(false);
	}

	QVariantList list = m_tableDisable[segment].toList();
	list.append(QVariant(makeEmptyRow(header)));
	m_tableDisable[segment] = list;

	onDisable_activated();
	ui.tableDisable->item(row,col)->setSelected(true);
	updateButtonsDisable();
}

//--------------------------------------------------------------
void DlgTables::on_pushDisableDelete_clicked()
{
	QString segment = QString("segments");
	QList<QTableWidgetItem*> selection = ui.tableDisable->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();

	QVariantList list = m_tableDisable[segment].toList();
	list.removeAt(row);
	m_tableDisable[segment] = list;

	onDisable_activated();
	updateButtonsDisable();
}

//--------------------------------------------------------------
void DlgTables::on_pushDisableUp_clicked()
{
	QString segment = QString("segments");
	QList<QTableWidgetItem*> selection = ui.tableDisable->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableDisable->item(row,col)->setSelected(false);

	QVariantList list = m_tableDisable[segment].toList();
	list.swap(row, row-1);
	m_tableDisable[segment] = list;

	onDisable_activated();
	ui.tableDisable->item(row-1,col)->setSelected(true);
	updateButtonsDisable();
}

//--------------------------------------------------------------
void DlgTables::on_pushDisableDown_clicked()
{
	QString segment = QString("segments");
	QList<QTableWidgetItem*> selection = ui.tableDisable->selectedItems();

	if(selection.isEmpty())
		return; 

	qint32 row = selection.first()->row();
	qint32 col = selection.first()->column();

	ui.tableDisable->item(row,col)->setSelected(false);

	QVariantList list = m_tableDisable[segment].toList();
	list.swap(row, row+1);
	m_tableDisable[segment] = list;

	onDisable_activated();
	ui.tableDisable->item(row+1,col)->setSelected(true);
	updateButtonsDisable();
}

//--------------------------------------------------------------
void DlgTables::clear()
{
	clearTables();

	ui.pushSaveFiles->setEnabled(false);
	ui.pushSaveModule->setEnabled(false);

	m_loadedSwitch = m_loadedMode = m_loadedRipch = m_loadedDisable = false;
	ripchMaxRow = modeMaxRow = switchMaxRow = disableMaxRow = 0;

	updateButtonsMode();
	updateButtonsRipch();
	updateButtonsSwitch();
	updateButtonsDisable();
	
}

//--------------------------------------------------------------
void DlgTables::connectedRls()
{
	clear();
	if(isVisible())
		sendAction("refreshTables");

	ui.pushRefresh->setEnabled(true);
	ui.pushRefreshFiles->setEnabled(true);
}

//--------------------------------------------------------------
void DlgTables::disconnectedRls()
{
	clear();

	ui.pushRefresh->setEnabled(false);
	ui.pushRefreshFiles->setEnabled(false);
}

//--------------------------------------------------------------
