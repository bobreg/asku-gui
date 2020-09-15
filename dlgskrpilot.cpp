#include "globalvar.h"
#include "dlgskrpilot.h"
#include "../common/module.h"
#include "../common/logger.h"

//-------------------------------------------------------------------------------
AskuSpinBox::AskuSpinBox(QWidget *parent) : QSpinBox(parent)
{
}

//-------------------------------------------------------------------------------
QString AskuSpinBox::textFromValue(int value) const
{
	QString str;
	str.sprintf("%3.4f", value * (360.0f / 64));
	return str;
}

//-------------------------------------------------------------------------------
int AskuSpinBox::valueFromText(const QString & text) const
{
	return (int) (64 * text.toFloat() / 360.f);
}

//-------------------------------------------------------------------------------
DlgSkrPilot::DlgSkrPilot(QWidget *parent) : AskuDialog("dialog_skrpilot", parent)
{
	ui.setupUi(this);

	spinSKR = new AskuSpinBox(ui.groupBox);
	spinPS  = new AskuSpinBox(ui.groupBox);

	spinSKR->setRange(0, 63);
	spinPS->setRange(0, 63);

	spinSKR->setGeometry(ui.spinSKR->geometry());
	spinPS->setGeometry(ui.spinPS->geometry());
	
	spinSKR->setFocusPolicy(Qt::NoFocus);
	spinPS->setFocusPolicy(Qt::NoFocus);
	ui.spinPeriod->setFocusPolicy(Qt::NoFocus);

	ui.spinSKR->deleteLater();
	ui.spinPS->deleteLater();

	ui.gridLayout->addWidget(spinSKR, 0, 1);
	ui.gridLayout->addWidget(spinPS, 1, 1);
}

//-------------------------------------------------------------------------------
DlgSkrPilot::~DlgSkrPilot()
{
}

//-------------------------------------------------------------------------------
void DlgSkrPilot::on_pushApply_clicked()
{
	sendAction("setSkrPilot", QStringList() << QString::number(spinSKR->value()) << QString::number(spinPS->value()) << QString::number(ui.spinPeriod->value()));
}

//-------------------------------------------------------------------------------
void DlgSkrPilot::sendAction(QString command, QStringList parameters)
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
void DlgSkrPilot::clean()
{
	spinSKR->setEnabled(false);
	spinPS->setEnabled(false);
	ui.spinPeriod->setEnabled(false);
	ui.pushApply->setEnabled(false);
}

//-------------------------------------------------------------------------------
void DlgSkrPilot::showEvent(QShowEvent * event)
{
	clean();
	sendAction("refreshSkrPilot");
	event->accept();
}

//-------------------------------------------------------------------------------
qint32 DlgSkrPilot::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgSkrPilot: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "DASD_SKRPILOT_INFO")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgSkrPilot: empty info");
			return result;
		}

		bool ok;
		quint32 iAzSkr  = info["azSkr"].toUInt(&ok);
		if(ok)
		{
			spinSKR->setValue(iAzSkr);
			spinSKR->setEnabled(true);
			ui.pushApply->setEnabled(true);
		}
		quint32 iAzPs   = info["azPs"].toUInt(&ok);
		if(ok)
		{
			spinPS->setValue(iAzPs);
			spinPS->setEnabled(true);
			ui.pushApply->setEnabled(true);
		}
		quint32 iPeriod = info["Period"].toUInt(&ok);
		if(ok)
		{
			ui.spinPeriod->setValue(iPeriod);
			ui.spinPeriod->setEnabled(true);
			ui.pushApply->setEnabled(true);
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

//-------------------------------------------------------------------------------
void DlgSkrPilot::connectedRls()
{
	clean();
	if(isVisible())
		sendAction("refreshSkrPilot");
}

//-------------------------------------------------------------------------------
void DlgSkrPilot::disconnectedRls()
{
	clean();
}

//-------------------------------------------------------------------------------
