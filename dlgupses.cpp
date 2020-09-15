#include "globalvar.h"
#include "dlgupses.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgUpses::DlgUpses(QWidget *parent) : AskuDialog("dialog_upses", parent)
{
	ui.setupUi(this);
	setActive(false);
}

// ------------------------------------------------------------------
DlgUpses::~DlgUpses()
{
}

// ------------------------------------------------------------------
void DlgUpses::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgUpses::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgUpses::on_pushClose_clicked()
{
	sendAction("stopMonitor");
	hide();
}

// ------------------------------------------------------------------
void DlgUpses::sendRefreshAction()
{
	sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgUpses::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "ups";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgUpses::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgUpses: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "UPS_INFO")
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
			}
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgUpses::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("startMonitor");
}

// ------------------------------------------------------------------
void DlgUpses::disconnectedRls()
{
	setActive(false);
}

// ------------------------------------------------------------------
void DlgUpses::setActive(bool on)
{
	QList<QLineEdit*> edits = findChildren<QLineEdit*>();
	foreach(QLineEdit* edit, edits)
		edit->setEnabled(on);
}

// ------------------------------------------------------------------
