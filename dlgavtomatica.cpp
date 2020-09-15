#include "globalvar.h"
#include "dlgavtomatica.h"
#include "../common/module.h"
#include "../common/logger.h"

// ------------------------------------------------------------------
DlgAvtomatica::DlgAvtomatica(QWidget *parent) : AskuDialog("dialog_avtomatica", parent)
{
	ui.setupUi(this);
	setActive(false);
}

// ------------------------------------------------------------------
DlgAvtomatica::~DlgAvtomatica()
{
}

// ------------------------------------------------------------------
void DlgAvtomatica::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgAvtomatica::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgAvtomatica::on_pushClose_clicked()
{
	sendAction("stopMonitor");
	hide();
}

// ------------------------------------------------------------------
void DlgAvtomatica::sendRefreshAction()
{
	sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgAvtomatica::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "avt";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgAvtomatica::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgAvtomatica: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "AVT_INFO")
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
void DlgAvtomatica::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgAvtomatica::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgAvtomatica::setActive(bool on)
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
