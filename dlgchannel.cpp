#include "globalvar.h"
#include "dlgchannel.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgChannel::DlgChannel(QWidget *parent) : AskuDialog("dialog_channel", parent)
{
    ui.setupUi(this);
/*
    connect(ui.tableCommand->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(tableCommand_sectionClicked(int)));
    connect(ui.tableTest2->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(tableTest2_sectionClicked(int)));
    connect(ui.tableState->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(tableState_sectionClicked(int)));
    connect(ui.tableDC->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(tableDC_sectionClicked(int)));

    ui.tableCommand->setVerticalHeaderLabels(captions);
    ui.tableTest1->setVerticalHeaderLabels(captions);
    ui.tableTest2->setVerticalHeaderLabels(captions);
    ui.tableState->setVerticalHeaderLabels(captions);
    ui.tableDC->setVerticalHeaderLabels(QStringList(captions[1]));
*/
}

// ------------------------------------------------------------------
DlgChannel::~DlgChannel()
{
}

// ------------------------------------------------------------------
void DlgChannel::on_tableCommand_itemClicked(QTableWidgetItem *item)
{
	Q_UNUSED(item);
//	quint32 nOY = item->row();
}

// ------------------------------------------------------------------
void DlgChannel::tableCommand_sectionClicked(int index)
{
	Q_UNUSED(index);
//	quint32 nOY = index;
}

// ------------------------------------------------------------------
void DlgChannel::on_tableTest2_itemClicked(QTableWidgetItem *item)
{
	Q_UNUSED(item);
//	quint32 nOY = item->row();
}

// ------------------------------------------------------------------
void DlgChannel::tableTest2_sectionClicked(int index)
{
	Q_UNUSED(index);
//	quint32 nOY = index;
}

// ------------------------------------------------------------------
void DlgChannel::on_tableState_itemClicked(QTableWidgetItem *item)
{
	Q_UNUSED(item);
//	quint32 nOY = item->row();
}

// ------------------------------------------------------------------
void DlgChannel::tableState_sectionClicked(int index)
{
	Q_UNUSED(index);
//	quint32 nOY = index;
}

// ------------------------------------------------------------------
void DlgChannel::on_tableDC_itemClicked(QTableWidgetItem *item)
{
	Q_UNUSED(item);
//	quint32 nUMI = item->column();
}

// ------------------------------------------------------------------
void DlgChannel::tableDC_sectionClicked(int index)
{
	Q_UNUSED(index);
}

// ------------------------------------------------------------------
void DlgChannel::refresh(QVariantMap data)
{
	Q_UNUSED(data);
/*
    QString str;
    quint32 numOY;
    quint32 numUMI;

//State
    for(numOY = 0; numOY < CA_N_DEVICES; numOY++)
    {
        if(data->getStateError(numOY)==CA_NO_ERROR)
        {
            for(quint32 offset = 0; offset < CA_HEADER_STATE_N_BYTES; offset++)
            {
                str.sprintf("%02X",data->getState(numOY,offset));
                ui.tableState->item(numOY,offset)->setText(str);
            }
        }
        else
        {
            str = "-";
            for(quint32 offset = 0; offset < CA_HEADER_STATE_N_BYTES; offset++)
                ui.tableState->item(numOY,offset)->setText(str);
        }
    }

//Test1
    for(numOY = 0; numOY < CA_N_DEVICES; numOY++)
    {
        if(data->getTest1Error(numOY)==CA_NO_ERROR)
        {
            str.sprintf("%02X",data->getTest1(numOY));
            ui.tableTest1->item(numOY,0)->setText(str);
        }
        else
        {
            str = "-";
            ui.tableTest1->item(numOY,0)->setText(str);
        }
    }

//Test2
    for(numOY = 0; numOY < CA_N_DEVICES; numOY++)
    {
        if(data->getTest2Error(numOY)==CA_NO_ERROR)
        {
            for(quint32 offset = 0; offset < CA_HEADER_TEST2_N_BYTES; offset++)
            {
                str.sprintf("%02X",data->getTest2(numOY,offset));
                ui.tableTest2->item(numOY,offset)->setText(str);
            }
        }
        else
        {
            str = "-";
            for(quint32 offset = 0; offset < CA_HEADER_TEST2_N_BYTES; offset++)
                ui.tableTest2->item(numOY,offset)->setText(str);
        }
    }

//Command1
    for(numOY = 0; numOY < CA_N_DEVICES; numOY++)
    {
        if(data->getCommandError(numOY)==CA_NO_ERROR)
        {
            str.sprintf("%02X",data->getCommand(numOY));
            ui.tableCommand1->item(numOY,0)->setText(str);
        }
        else
        {
            str = "-";
            ui.tableCommand1->item(numOY,0)->setText(str);
        }
    }

    if(m_setup.main.type >= ASKU_TYPE_4)
    {
//ParamUMI
        for(numUMI = 0; numUMI < CA_N_MODULES; numUMI++)
        {
            if(data->getParamUmiError(numUMI)==CA_NO_ERROR)
            {
                str.sprintf("%02X",data->getParamUmi(numUMI,0));
                ui.tableDC->item(0,numUMI)->setText(str);
            }
            else
            {
                str = "-";
                ui.tableDC->item(0,numUMI)->setText(str);
            }
        }
    }
*/
}

// ------------------------------------------------------------------
void DlgChannel::refreshCommand(QVariantMap data)
{
	Q_UNUSED(data);

/*
    QString str;

    if(numOY>=CA_N_DEVICES)
        return;

//Command
    str.sprintf("%02X",c1);
    ui.tableCommand->item(numOY,0)->setText(str);

    str.sprintf("%02X",c2);
    ui.tableCommand->item(numOY,1)->setText(str);

    str.sprintf("%02X",c3);
    ui.tableCommand->item(numOY,2)->setText(str);

//	if(dlgAdv->isVisible())
        dlgAdv->refresh(numOY,c1,c2,c3);
*/
}


// ------------------------------------------------------------------
void DlgChannel::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgChannel::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgChannel::on_pushClose_clicked()
{
	hide();
}

// ------------------------------------------------------------------
void DlgChannel::sendRefreshAction()
{
	sendAction("refreshUpses");
}

// ------------------------------------------------------------------
void DlgChannel::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "upses";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgChannel::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgDrives: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
/*	if(infoType == "ASKU_CONTROL_ELK_BUTTONS")
	{
		if(data.contains("CommandSet"))
		{
			QVariantMap values = data["CommandSet"].toMap();
			m_commands = values;
			verifyCommands();
		}
*/
		result = AskuModule::CommandSuccess;
//	}

	return result;
}

// ------------------------------------------------------------------
void DlgChannel::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("refreshUpses");
}

// ------------------------------------------------------------------
void DlgChannel::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgChannel::setActive(bool on)
{
	Q_UNUSED(on);

/*	QList<QPushButton*> buttons = ui.groupControl->findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		button->setEnabled(on);*/
}

// ------------------------------------------------------------------
