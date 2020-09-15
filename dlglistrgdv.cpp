#include "globalvar.h"
#include "dlglistrgdv.h"
#include "settingsui.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

//-------------------------------------------------------------------------------
DlgListRGDV::DlgListRGDV(QWidget *parent) : AskuDialog("dialog_listrgdv", parent)
{
	ui.setupUi(this);

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//	ui.tableRgdv->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
#else
//	ui.tableRgdv->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	ui.tableRgdv->verticalHeader()->setResizeMode(0, QHeaderView::Stretch);
	ui.tableRgdv->verticalHeader()->setResizeMode(1, QHeaderView::ResizeToContents);
	ui.tableRgdv->verticalHeader()->setResizeMode(2, QHeaderView::ResizeToContents);
#endif
//	ui.tableRgdv->verticalHeader()->setStretchLastSection(true);

	clean();

	if(settingsUI)
		connect(settingsUI, SIGNAL(changed()), this, SLOT(applyGraphic()));

	applyGraphic();
}

//-------------------------------------------------------------------------------
DlgListRGDV::~DlgListRGDV()
{

}

//-------------------------------------------------------------------------------
void DlgListRGDV::on_pushClose_clicked()
{
	hide();
}

//-------------------------------------------------------------------------------
void DlgListRGDV::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "algorithm";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

//-------------------------------------------------------------------------------
void DlgListRGDV::showEvent(QShowEvent * event)
{
	sendAction("refreshListRgdv");
	event->accept();
}

//-------------------------------------------------------------------------------
qint32 DlgListRGDV::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgListRGDV: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "ASKU_RGDV_LIST")
	{
		QVariantList info = data["Info"].toList();
		bool full = data["FullSet"].toBool();

		if(info.isEmpty())
		{
			LogError("DlgListRGDV: empty info");
			return result;
		}

		refreshListRgdv(info, full);

		result = AskuModule::CommandSuccess;
	}
	else if(infoType == "ALGORITHM_LIST_RGDV_INFO")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgListRGDV: empty info");
			return result;
		}

		

		result = AskuModule::CommandSuccess;
	}

	return result;
}

//-------------------------------------------------------------------------------
void DlgListRGDV::applyGraphic()
{
	updateLabelState(ui.labelState, m_stateRgdv);

	for(qint32 row = 0; row < ui.tableRgdv->rowCount(); row++)
	{
		QTableWidgetItem *item1 = ui.tableRgdv->item(row,0);
		QTableWidgetItem *item2 = ui.tableRgdv->item(row,1);
		QTableWidgetItem *item3 = ui.tableRgdv->item(row,2);

		if(item1)
		{
			QString state = item1->data(Qt::UserRole).toString();
			if(state != "title")
			{
				QBrush background = QBrush(settingsUI->getItemBodyColor(stringToState(state)));
				item1->setBackground(background);
				if(item2)
					item2->setBackground(background);
				if(item3)
					item3->setBackground(background);
			}
		}
	}

	ui.tableRgdv->setVisible(false);
	ui.tableRgdv->resizeColumnsToContents();
	ui.tableRgdv->setVisible(true);
	ui.tableRgdv->verticalHeader()->setStretchLastSection(true);
}

//-------------------------------------------------------------------------------
void DlgListRGDV::cleanTable()
{
	for(qint32 row = ui.tableRgdv->rowCount(); row >= 0; row--)
		ui.tableRgdv->removeRow(row);
}

//-------------------------------------------------------------------------------
void DlgListRGDV::refreshListRgdv(QVariantList & info, bool full)
{
	if(full)
	{
		cleanTable();
	}

	for(qint32 i = 0; i < info.count(); i++)
	{
		QString element, source, name, state, text;

		QVariantMap map = info[i].toMap();

		name = map["name"].toString();
		element = map["title"].toString();
		source = map["source"].toString();
		state = map["state"].toString();
		text = map["text"].toString();

		if(name == "rgdv")
			updateRgdvState(text, state);
		else if(full)
			addLine(name, element, source, text, state);
		else
			updateLine(name, element, source, text, state);
	}

	if(full)
	{
		ui.tableRgdv->setVisible(false);
		ui.tableRgdv->resizeColumnsToContents();
		ui.tableRgdv->setVisible(true);
		ui.tableRgdv->verticalHeader()->setStretchLastSection(true);
	}
}

//--------------------------------------------------------------
void DlgListRGDV::updateRgdvState(QString text, QString state)
{
	m_stateRgdv = state;
	updateLabelState(ui.labelState, state);
	ui.labelState->setText(text);
}

//--------------------------------------------------------------
void DlgListRGDV::updateLabelState(QLabel *label, QString state)
{
	QPalette palette;
	palette.setColor(label->backgroundRole(), settingsUI->getItemBodyColor(stringToState(state)));
	label->setPalette(palette);
}

//-------------------------------------------------------------------------------
void DlgListRGDV::updateLine(QString name, QString element, QString source, QString text, QString state)
{
	for(qint32 row = 0; row < ui.tableRgdv->rowCount(); row++)
	{
		QTableWidgetItem *item3 = ui.tableRgdv->item(row, 2);
		if(item3)
		{
			QString itemName = item3->data(Qt::UserRole).toString();

			if(!itemName.isEmpty() && itemName == name)
			{
				QBrush background = QBrush(settingsUI->getItemBodyColor(stringToState(state)));

				item3->setBackground(background);
				item3->setText(text);

				QTableWidgetItem *item1 = ui.tableRgdv->item(row, 0);
				if(item1)
				{
					item1->setData(Qt::UserRole, state);
					item1->setBackground(background);
					item1->setText(element);
				}

				QTableWidgetItem *item2 = ui.tableRgdv->item(row, 1);
				if(item2)
				{
					item2->setBackground(background);
					item2->setText(source);
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------
void DlgListRGDV::addLine(QString name, QString element, QString source, QString text, QString state)
{
	if(state == "title")
	{
		QBrush background = QBrush(QColor("lightblue"));

		QTableWidgetItem *item1 = new QTableWidgetItem(QString(element));
		item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		item1->setBackground(background);
		item1->setData(Qt::UserRole, state);

		int row = ui.tableRgdv->rowCount();

		ui.tableRgdv->setRowCount(row + 1);
		ui.tableRgdv->setSpan(row, 0, 1, 3);
		ui.tableRgdv->setItem(row, 0, item1);
	}
	else
	{
		QBrush background = QBrush(settingsUI->getItemBodyColor(stringToState(state)));

		QTableWidgetItem *item1 = new QTableWidgetItem(QString(element));
		item1->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
		item1->setBackground(background);
		item1->setData(Qt::UserRole, state);

		QTableWidgetItem *item2 = new QTableWidgetItem(QString(source));
		item2->setTextAlignment(Qt::AlignCenter);
		item2->setBackground(background);

		QTableWidgetItem *item3 = new QTableWidgetItem(QString(text));
		item3->setTextAlignment(Qt::AlignCenter);
		item3->setBackground(background);
		item3->setData(Qt::UserRole, name);
	
		int row = ui.tableRgdv->rowCount();

		ui.tableRgdv->setRowCount(row + 1);
		ui.tableRgdv->setItem(row, 0, item1);
		ui.tableRgdv->setItem(row, 1, item2);
		ui.tableRgdv->setItem(row, 2, item3);
	}
}

//-------------------------------------------------------------------------------
void DlgListRGDV::clean()
{
	cleanTable();
	updateRgdvState("НЕТ СВЯЗИ С ГПР!", "disable");
}

//-------------------------------------------------------------------------------
void DlgListRGDV::connectedRls()
{
	clean();

	if(isVisible())
		sendAction("refreshListRgdv");
}

//-------------------------------------------------------------------------------
void DlgListRGDV::disconnectedRls()
{
	clean();
}

//-------------------------------------------------------------------------------
