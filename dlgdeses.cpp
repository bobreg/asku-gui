#include "globalvar.h"
#include "dlgdeses.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgDeses::DlgDeses(QWidget *parent) : AskuDialog("dialog_deses", parent)
{
	ui.setupUi(this);
	setActive(false);
}

// ------------------------------------------------------------------
DlgDeses::~DlgDeses()
{
}

// ------------------------------------------------------------------
void DlgDeses::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgDeses::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOffEngine1_clicked()
{
	sendAction("setEngine1Off");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOnEngine1_clicked()
{
	sendAction("setEngine1On");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOffEngine2_clicked()
{
	sendAction("setEngine2Off");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOnEngine2_clicked()
{
	sendAction("setEngine2On");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOffGB1_clicked()
{
	sendAction("setGB1Off");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOnGB1_clicked()
{
	sendAction("setGB1On");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOffGB2_clicked()
{
	sendAction("setGB2Off");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOnGB2_clicked()
{
	sendAction("setGB2On");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOffMB1_clicked()
{
	sendAction("setMB1Off");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushOnMB1_clicked()
{
	sendAction("setMB1On");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushResetMns1_clicked()
{
	sendAction("resetMains1");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushResetDgs1_clicked()
{
	sendAction("resetDg1");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushResetDgs2_clicked()
{
	sendAction("resetDg2");
}

// ------------------------------------------------------------------
void DlgDeses::on_checkRegime1_clicked()
{
	sendAction("setAutoMode");
}

// ------------------------------------------------------------------
void DlgDeses::on_checkRegime2_clicked()
{
	sendAction("setSemiAutoMode");
}

// ------------------------------------------------------------------
void DlgDeses::on_checkRegime3_clicked()
{
	sendAction("setTestMode");
}

// ------------------------------------------------------------------
void DlgDeses::on_checkRegime4_clicked()
{
	sendAction("setManualMode");
}

// ------------------------------------------------------------------
void DlgDeses::on_checkRegime5_clicked()
{
	sendAction("setBlockMode");
}

// ------------------------------------------------------------------
void DlgDeses::on_pushClose_clicked()
{
	sendAction("stopMonitor");
	hide();
}

// ------------------------------------------------------------------
void DlgDeses::sendRefreshAction()
{
	sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgDeses::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "des";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgDeses::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgDeses: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "DES_INFO")
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
				QCheckBox *chk = findChild<QCheckBox*>(key);
				if(chk != NULL)
				{
					chk->blockSignals(true);
					chk->setChecked(info.value(key).toBool());
					chk->blockSignals(false);
				}
				QPushButton *btn = findChild<QPushButton*>(key);
				if(btn != NULL)
				{
					qint32 v = info.value(key).toInt();
					btn->blockSignals(true);
					btn->setEnabled(v >= 0);
					btn->setChecked(v > 0);
					btn->blockSignals(false);
				}
			}
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgDeses::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgDeses::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgDeses::setActive(bool on)
{
	QList<QPushButton*> buttons = findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		if(button != ui.pushClose)
			button->setEnabled(on);

	QList<QLineEdit*> edits = findChildren<QLineEdit*>();
	foreach(QLineEdit* edit, edits)
		edit->setEnabled(on);

	QList<QCheckBox*> checks = findChildren<QCheckBox*>();
	foreach(QCheckBox* check, checks)
		check->setEnabled(on);
}

// ------------------------------------------------------------------
