#include <QMessageBox>
#include "globalvar.h"
#include "dlgctrlelk.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgCtrlElk::DlgCtrlElk(QWidget *parent) : AskuDialog("dialog_control_elk", parent)
{
	ui.setupUi(this);
	m_commands.clear();

	bool active = false;

	m_buttons["pushOsvPerimOff"]	= AskuPanelButtonState(QStringList() << "setElkOsvPerimOff", active, false, true, "pushOsvPerimOn");
	m_buttons["pushOsvPerimOn"]		= AskuPanelButtonState(QStringList() << "setElkOsvPerimOn", active, false, true, "pushOsvPerimOff");
	m_buttons["pushTestHowl"]		= AskuPanelButtonState(QStringList() << "setElkTestHowl", active, false, false, "pushTestHowl");
	m_buttons["pushFireOff"]		= AskuPanelButtonState(QStringList() << "setElkFireOff", active, false, false, "pushFireOn");
	m_buttons["pushFireOn"]			= AskuPanelButtonState(QStringList() << "setElkFireOn", active, false, false, "pushFireOff");
	m_buttons["pushGuardOff"]		= AskuPanelButtonState(QStringList() << "setElkGuardOff", active, false, false, "pushGuardOn");
	m_buttons["pushGuardOn"]		= AskuPanelButtonState(QStringList() << "setElkGuardOn", active, false, false, "pushGuardOff");
	m_buttons["pushCondOff"]		= AskuPanelButtonState(QStringList() << "setElkCondOff", active, false, false, "pushCondOn");
	m_buttons["pushCondOn"]			= AskuPanelButtonState(QStringList() << "setElkCondOn", active, false, false, "pushCondOff");
	m_buttons["pushReset"]			= AskuPanelButtonState(QStringList() << "setElkReset", active, false, false, "pushReset");

	verifyButtons();
}

// ------------------------------------------------------------------
DlgCtrlElk::~DlgCtrlElk()
{
}

// ------------------------------------------------------------------
void DlgCtrlElk::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgCtrlElk::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushClose_clicked()
{
	hide();
}

// ------------------------------------------------------------------
void DlgCtrlElk::sendRefreshAction()
{
	sendAction("refreshCtrlElk");
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushOsvPerimOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushOsvPerimOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushTestHowl_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushFireOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushFireOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushGuardOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushGuardOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushCondOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushCondOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::on_pushReset_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlElk::processButtonAction(QPushButton * button)
{
	if(button == NULL) return;

	AskuPanelButtonState buttonState = m_buttons.value(button->objectName());

	if(!button->isCheckable())
	{
		LogInfo("DlgCtrlElk: click %s", qPrintable(button->objectName()));
		if(buttonState.actions.count())
			sendAction(buttonState.actions.first());
	}
	else if(!button->isChecked())
	{
		if(!buttonState.uncheck)
		{
			LogInfo("DlgCtrlElk: try uncheck %s but uncheck!", qPrintable(button->objectName()));
			button->blockSignals(true);
			button->setChecked(true);
			button->blockSignals(false);
		}
		else
		{
			LogInfo("DlgCtrlElk: try uncheck %s", qPrintable(button->objectName()));
			if(buttonState.actions.count() > 1)
				sendAction(buttonState.actions.last());
		}
	}
	else
	{
		LogInfo("DlgCtrlElk: try check %s", qPrintable(button->objectName()));
		if(!buttonState.question.isEmpty())
		{
			if(QMessageBox::question(this, "Подтвердите действие...", buttonState.question, QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel) != QMessageBox::Yes)
			{
				button->blockSignals(true);
				button->setChecked(false);
				button->blockSignals(false);
				return;
			}
		}

		if(!buttonState.opposite.isEmpty())
		{
			QPushButton *opbutton = findChild<QPushButton*>(buttonState.opposite);
			if(opbutton)
				opbutton->setChecked(false);
		}

		if(buttonState.actions.count())
			sendAction(buttonState.actions.first());
	}
}

// ------------------------------------------------------------------
void DlgCtrlElk::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "canalasku";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgCtrlElk::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgCtrlElk: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "ASKU_CONTROL_ELK_BUTTONS")
	{
		if(data.contains("CommandSet"))
		{
			QVariantMap values = data["CommandSet"].toMap();
			m_commands = values;
			verifyCommands();
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgCtrlElk::verifyCommands()
{
	QString value;

	value = m_commands["osv_perim"].toString();
	if(value == "off")
	{
		m_buttons["pushOsvPerimOff"].checked = true;
		m_buttons["pushOsvPerimOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushOsvPerimOff"].checked = false;
		m_buttons["pushOsvPerimOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushOsvPerimOff"].checked = false;
		m_buttons["pushOsvPerimOn"].checked = false;
	}
	if(value != "disable")
	{
		m_buttons["pushOsvPerimOff"].enabled = true;
		m_buttons["pushOsvPerimOn"].enabled = true;
	}
	else
	{
		m_buttons["pushOsvPerimOff"].enabled = false;
		m_buttons["pushOsvPerimOn"].enabled = false;
	}

	value = m_commands["fire"].toString();
	if(value == "off")
	{
		m_buttons["pushFireOff"].checked = true;
		m_buttons["pushFireOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushFireOff"].checked = false;
		m_buttons["pushFireOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushFireOff"].checked = false;
		m_buttons["pushFireOn"].checked = false;
	}
	if(value != "disable")
	{
		m_buttons["pushFireOff"].enabled = true;
		m_buttons["pushFireOn"].enabled = true;
	}
	else
	{
		m_buttons["pushFireOff"].enabled = false;
		m_buttons["pushFireOn"].enabled = false;
	}

	value = m_commands["guard"].toString();
	if(value == "off")
	{
		m_buttons["pushGuardOff"].checked = true;
		m_buttons["pushGuardOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushGuardOff"].checked = false;
		m_buttons["pushGuardOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushGuardOff"].checked = false;
		m_buttons["pushGuardOn"].checked = false;
	}
	if(value != "disable")
	{
		m_buttons["pushGuardOff"].enabled = true;
		m_buttons["pushGuardOn"].enabled = true;
	}
	else
	{
		m_buttons["pushGuardOff"].enabled = false;
		m_buttons["pushGuardOn"].enabled = false;
	}

	value = m_commands["cond"].toString();
	if(value == "off")
	{
		m_buttons["pushCondOff"].checked = true;
		m_buttons["pushCondOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushCondOff"].checked = false;
		m_buttons["pushCondOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushCondOff"].checked = false;
		m_buttons["pushCondOn"].checked = false;
	}
	if(value != "disable")
	{
		m_buttons["pushCondOff"].enabled = true;
		m_buttons["pushCondOn"].enabled = true;
	}
	else
	{
		m_buttons["pushCondOff"].enabled = false;
		m_buttons["pushCondOn"].enabled = false;
	}

	m_buttons["pushTestHowl"].enabled = true;
	m_buttons["pushReset"].enabled = true;

	verifyButtons();
}

// ------------------------------------------------------------------
void DlgCtrlElk::verifyButtons()
{
	foreach(QString key, m_buttons.keys())
	{
		AskuPanelButtonState buttonState = m_buttons.value(key);

		QPushButton *button = findChild<QPushButton*>(key);

//		LogInfo("DlgCtrlElk: Buttons[%s] enabled=%d checked=%d uncheck=%d", qPrintable(key), buttonState.enabled, buttonState.checked, buttonState.uncheck);

		if(button != NULL)
		{
			button->blockSignals(true);
			button->setEnabled(buttonState.enabled);
			button->setChecked(buttonState.checked);
			button->blockSignals(false);
		}
	}
}

// ------------------------------------------------------------------
void DlgCtrlElk::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("refreshCtrlElk");
}

// ------------------------------------------------------------------
void DlgCtrlElk::disconnectedRls()
{
	setActive(false);
	m_commands.clear();
}

// ------------------------------------------------------------------
void DlgCtrlElk::setActive(bool on)
{
	QList<QPushButton*> buttons = ui.groupControl->findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		button->setEnabled(on);
}

// ------------------------------------------------------------------
