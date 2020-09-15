#include "globalvar.h"
#include "dlgcoolers.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgCoolers::DlgCoolers(QWidget *parent) : AskuDialog("dialog_coolers", parent)
{
	ui.setupUi(this);
	setActive(false);
}

// ------------------------------------------------------------------
DlgCoolers::~DlgCoolers()
{
}

// ------------------------------------------------------------------
void DlgCoolers::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgCoolers::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushClose_clicked()
{
	sendAction("stopMonitor");
	hide();
}

// ------------------------------------------------------------------
void DlgCoolers::sendRefreshAction()
{
	sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushReset_clicked()
{
	sendAction("resetSvo");
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushSetFreq_clicked()
{
	sendAction("setFreqSvo", QStringList() << QString::number(ui.vesperSlider1->value()) << QString::number(ui.vesperSlider2->value()));
}

// ------------------------------------------------------------------
void DlgCoolers::on_manualCheckBox_stateChanged(int state)
{
	if(state == Qt::Checked)
		sendAction("setManualSvo");
	else
		sendAction("setAvtoSvo");
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushOn1_clicked()
{
	sendAction("setSvo1On");
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushOff1_clicked()
{
	sendAction("setSvo1Off");
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushOn2_clicked()
{
	sendAction("setSvo2On");
}

// ------------------------------------------------------------------
void DlgCoolers::on_pushOff2_clicked()
{
	sendAction("setSvo2Off");
}

// ------------------------------------------------------------------
void DlgCoolers::on_vesperSlider1_valueChanged(int value)
{
	ui.vesperFreq1->setText(QString::number(value));
}

// ------------------------------------------------------------------
void DlgCoolers::on_vesperSlider2_valueChanged(int value)
{
	ui.vesperFreq2->setText(QString::number(value));
}

// ------------------------------------------------------------------
void DlgCoolers::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "coolers";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgCoolers::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgCoolers: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "COOLERS_INFO")
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
				QSlider *sld = findChild<QSlider*>(key);
				if(sld != NULL)
				{
					qint32 v = info.value(key).toInt();
					sld->setEnabled(v < 0);
					if(v >= 0)
						sld->setValue(v);
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
void DlgCoolers::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgCoolers::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgCoolers::setActive(bool on)
{
	QList<QPushButton*> buttons = findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		if(button != ui.pushClose)
			button->setEnabled(on);

	QList<QSlider*> sliders = findChildren<QSlider*>();
	foreach(QSlider* slider, sliders)
		slider->setEnabled(on);

	QList<QLineEdit*> edits = findChildren<QLineEdit*>();
	foreach(QLineEdit* edit, edits)
		edit->setEnabled(on);

	QList<QCheckBox*> checks = findChildren<QCheckBox*>();
	foreach(QCheckBox* check, checks)
		check->setEnabled(on);
}

// ------------------------------------------------------------------
