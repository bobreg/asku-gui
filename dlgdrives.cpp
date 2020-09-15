#include "globalvar.h"
#include "dlgdrives.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgDrives::DlgDrives(QWidget *parent) : AskuDialog("dialog_drives", parent)
{
	ui.setupUi(this);
	setActive(false);
}

// ------------------------------------------------------------------
DlgDrives::~DlgDrives()
{
}

// ------------------------------------------------------------------
void DlgDrives::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgDrives::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgDrives::on_pushClose_clicked()
{
	sendAction("stopMonitor");
	hide();
}

// ------------------------------------------------------------------
void DlgDrives::sendRefreshAction()
{
	sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgDrives::on_pushReset_clicked()
{
	sendAction("resetDrive");
}

// ------------------------------------------------------------------
void DlgDrives::on_checkManual_stateChanged(int state)
{
	if(state == Qt::Checked)
		sendAction("setManualDrive");
	else
		sendAction("setAvtoDrive");
}

// ------------------------------------------------------------------
void DlgDrives::on_pushOn_clicked()
{
	sendAction("setDriveOn");
}

// ------------------------------------------------------------------
void DlgDrives::on_pushOff_clicked()
{
	sendAction("setDriveOff");
}

// ------------------------------------------------------------------
void DlgDrives::on_pushSet1_clicked()
{
	sendAction("setDriveMain1");
}

// ------------------------------------------------------------------
void DlgDrives::on_pushSet2_clicked()
{
	sendAction("setDriveMain2");
}

// ------------------------------------------------------------------
void DlgDrives::on_pushSetSpeed_clicked()
{
	sendAction("setDriveSpeed", QStringList() << QString::number(ui.spinSpeed->value(),'f',3));
}

// ------------------------------------------------------------------
void DlgDrives::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "drive";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgDrives::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgDrives: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "DRIVE_INFO")
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
				QDoubleSpinBox *spn = findChild<QDoubleSpinBox*>(key);
				if(spn != NULL)
				{
					qint32 v = info.value(key).toDouble();
					spn->setEnabled(v < 0.0);
					if(v >= 0.0)
						spn->setValue(v);
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
void DlgDrives::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgDrives::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgDrives::setActive(bool on)
{
	QList<QPushButton*> buttons = findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		if(button != ui.pushClose)
			button->setEnabled(on);

	QList<QDoubleSpinBox*> spins = findChildren<QDoubleSpinBox*>();
	foreach(QDoubleSpinBox* spin, spins)
		spin->setEnabled(on);

	QList<QLineEdit*> edits = findChildren<QLineEdit*>();
	foreach(QLineEdit* edit, edits)
		edit->setEnabled(on);

	QList<QCheckBox*> checks = findChildren<QCheckBox*>();
	foreach(QCheckBox* check, checks)
		check->setEnabled(on);
}

// ------------------------------------------------------------------
