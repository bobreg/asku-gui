#include "globalvar.h"
#include "dlgpowermeter.h"
#include "../common/module.h"
#include "../common/logger.h"

// ------------------------------------------------------------------
DlgPowerMeter::DlgPowerMeter(QWidget *parent) : AskuDialog("dialog_powermeter", parent)
{
	ui.setupUi(this);
	setActive(false);
}

// ------------------------------------------------------------------
DlgPowerMeter::~DlgPowerMeter()
{
}

// ------------------------------------------------------------------
void DlgPowerMeter::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgPowerMeter::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgPowerMeter::on_pushClose_clicked()
{
	sendAction("stopMonitor");
	hide();
}

// ------------------------------------------------------------------
void DlgPowerMeter::sendRefreshAction()
{
	sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgPowerMeter::on_pushMeasure_clicked()
{
	sendAction("measure");
}

// ------------------------------------------------------------------
void DlgPowerMeter::on_pushReset_clicked()
{
	sendAction("resetPwm");
}

// ------------------------------------------------------------------
void DlgPowerMeter::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "pwm";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgPowerMeter::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgPowerMeter: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "PWM_INFO")
	{
		if(data.contains("Info"))
		{
			setActive(true);

			QVariantMap info = data["Info"].toMap();

			foreach(QString key, info.keys())
			{
//				LogInfo("Info: %s = %s", qPrintable(key), qPrintable(info.value(key).toString()));

				QLineEdit *lbl = findChild<QLineEdit*>(key);
				if(lbl != NULL)
				{
					lbl->setText(info.value(key).toString());
				}

				QPushButton *btn = findChild<QPushButton*>(key);
				if(btn != NULL)
				{
					qint32 v = info.value(key).toInt();
					btn->blockSignals(true);
					btn->setEnabled(v >= 0);
					btn->blockSignals(false);
				}
			}
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgPowerMeter::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgPowerMeter::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgPowerMeter::setActive(bool on)
{
	QList<QLineEdit*> edits = findChildren<QLineEdit*>();
	foreach(QLineEdit* edit, edits)
		edit->setEnabled(on);

	QList<QPushButton*> buttons = findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		if(button != ui.pushClose)
			button->setEnabled(on);
}

// ------------------------------------------------------------------
