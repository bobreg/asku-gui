#include "globalvar.h"
#include "dlgsetprm.h"
#include "../common/module.h"
#include "../common/logger.h"

//-------------------------------------------------------------------------------
DlgSetPrm::DlgSetPrm(QWidget *parent) : AskuDialog("dialog_setprm", parent)
{
	ui.setupUi(this);
	setActive(false);
}

//-------------------------------------------------------------------------------
DlgSetPrm::~DlgSetPrm()
{
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setActive(bool on)
{
	ui.checkBlock->setChecked(!on);
	if(!on) ui.checkAllow->setChecked(false);
	ui.checkAllow->setEnabled(on);
	ui.checkGsh->setEnabled(on);
	ui.checkZu->setEnabled(on);
	ui.checkPilot->setEnabled(on);
	ui.spinCh1->setEnabled(on);
	ui.spinCh2->setEnabled(on);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_pushClose_clicked()
{
	setActive(false);
	setOn(false);
	hide();
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_checkAllow_stateChanged(int state)
{
	bool on = (state == Qt::Checked);
	setOn(on);
	if(on)
	{
		setSHARU1(ui.spinCh1->value());
		setSHARU2(ui.spinCh2->value());
	}
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_checkBlock_stateChanged(int state)
{
	bool set = (state == Qt::Checked);

	setActive(!set);

	if(set)
		setOn(false);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setOn(bool on)
{
	sendAction("setPrmOn", QStringList() << QString::number((int)on));
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setGSH(bool on)
{
	sendAction("setPrmGsh", QStringList() << QString::number((int)on));
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setZU(bool on)
{
	sendAction("setPrmZu", QStringList() << QString::number((int)on));
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setPILOT(bool on)
{
	sendAction("setPrmPilot", QStringList() << QString::number((int)on));
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setSHARU1(quint32 value)
{
	sendAction("setPrmSharu1Code", QStringList() << QString::number(value));
}

//-------------------------------------------------------------------------------
void DlgSetPrm::setSHARU2(quint32 value)
{
	sendAction("setPrmSharu2Code", QStringList() << QString::number(value));
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_checkGsh_stateChanged(int state)
{
	setGSH(state == Qt::Checked);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_checkZu_stateChanged(int state)
{
	setZU(state == Qt::Checked);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_checkPilot_stateChanged(int state)
{
	setPILOT(state == Qt::Checked);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_spinCh1_valueChanged(int nvalue)
{
	setSHARU1(nvalue);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::on_spinCh2_valueChanged(int nvalue)
{
	setSHARU2(nvalue);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "dasd";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

//-------------------------------------------------------------------------------
void DlgSetPrm::showEvent(QShowEvent * event)
{
	sendAction("refreshSetPrm");
	event->accept();
}

//-------------------------------------------------------------------------------
qint32 DlgSetPrm::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgSetPrm: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "DASD_SETPRM_INFO")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgSetPrm: empty info");
			return result;
		}

		blockSignals(true);

		bool isActive = info["active"].toBool();

		setActive(isActive);
		if(isActive) ui.checkAllow->setChecked(true);

		ui.checkGsh->setChecked(info["gsh"].toBool());
		ui.checkZu->setChecked(info["zu"].toBool());
		ui.checkPilot->setChecked(info["pilot"].toBool());
		ui.spinCh1->setValue(info["sharu1"].toUInt());
		ui.spinCh2->setValue(info["sharu2"].toUInt());

		blockSignals(false);

		result = AskuModule::CommandSuccess;
	}

	return result;
}

//-------------------------------------------------------------------------------
void DlgSetPrm::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("refreshSetPrm");
}

//-------------------------------------------------------------------------------
void DlgSetPrm::disconnectedRls()
{
	setActive(false);
}

//-------------------------------------------------------------------------------
