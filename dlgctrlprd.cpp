#include <QMessageBox>
#include "globalvar.h"
#include "dlgctrlprd.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgCtrlPrd::DlgCtrlPrd(QWidget *parent) : AskuDialog("dialog_control_prd", parent)
{
	ui.setupUi(this);
	m_commands.clear();
	m_selectors.clear();

	bool active = false;

	m_buttons["pushPowerOff"]		= AskuPanelButtonState(QStringList() << "setPrdPowerOff", active, false, false, "pushPowerOn");
	m_buttons["pushPowerOn"]		= AskuPanelButtonState(QStringList() << "setPrdPowerOn", active, false, false, "pushPowerOff");
	m_buttons["pushPumi1"]			= AskuPanelButtonState(QStringList() << "setPrdPumi1" << "setPrdPumiOff", active, false, true, "pushPumi2");
	m_buttons["pushPumi2"]			= AskuPanelButtonState(QStringList() << "setPrdPumi2" << "setPrdPumiOff", active, false, true, "pushPumi1");
	m_buttons["pushHotResOff"]		= AskuPanelButtonState(QStringList() << "setPrdHotResOff", active, false, false, "pushHotResOn");
	m_buttons["pushHotResOn"]		= AskuPanelButtonState(QStringList() << "setPrdHotResOn", active, false, false, "pushHotResOff");
	m_buttons["pushModule380Off"]	= AskuPanelButtonState(QStringList() << "setPrdModule380vOff", active, false, false, "pushModule380On");
	m_buttons["pushModule380On"]	= AskuPanelButtonState(QStringList() << "setPrdModule380vOn", active, false, false, "pushModule380Off");
	m_buttons["pushModuleOff"]		= AskuPanelButtonState(QStringList() << "setPrdModulePowerOff", active, false, false, "pushModuleOn");
	m_buttons["pushModuleOn"]		= AskuPanelButtonState(QStringList() << "setPrdModulePowerOn", active, false, false, "pushModuleOff");
	m_buttons["pushSVChOff"]		= AskuPanelButtonState(QStringList() << "setPrdModuleSvchOff", active, false, false, "pushSVChOn");
	m_buttons["pushSVChOn"]			= AskuPanelButtonState(QStringList() << "setPrdModuleSvchOn", active, false, false, "pushSVChOff");
	m_buttons["pushReset"]			= AskuPanelButtonState(QStringList() << "setPrdModuleReset", active, false, false, "pushReset");

	verifyButtons();

}

// ------------------------------------------------------------------
DlgCtrlPrd::~DlgCtrlPrd()
{
}

// ------------------------------------------------------------------
void DlgCtrlPrd::showEvent(QShowEvent * event)
{
	if(m_selectors.isEmpty())
		sendAction("refreshCtrlPrd");
	else
		sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushClose_clicked()
{
	hide();
}

// ------------------------------------------------------------------
QStringList DlgCtrlPrd::actionParameters()
{
	QStringList params;
	params << ui.comboSelectPrd->itemData(ui.comboSelectPrd->currentIndex()).toString();
	params << ui.comboSelectModule->itemData(ui.comboSelectModule->currentIndex()).toString();
	return params;
}

// ------------------------------------------------------------------
void DlgCtrlPrd::sendRefreshAction()
{
	sendAction("refreshCtrlPrd", actionParameters());
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_comboSelectPrd_currentIndexChanged(int index)
{
	Q_UNUSED(index);
	sendRefreshAction();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_comboSelectModule_currentIndexChanged(int index)
{
	Q_UNUSED(index);
	sendRefreshAction();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushPowerOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushPowerOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushPumi1_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushPumi2_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushHotResOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushHotResOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushModule380On_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushModule380Off_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushModuleOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushModuleOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushSVChOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushSVChOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::on_pushReset_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPrd::processButtonAction(QPushButton * button)
{
	if(button == NULL) return;

	AskuPanelButtonState buttonState = m_buttons.value(button->objectName());

	if(!button->isCheckable())
	{
		LogInfo("DlgCtrlPrd: click %s", qPrintable(button->objectName()));
		if(buttonState.actions.count())
			sendAction(buttonState.actions.first(), actionParameters());
	}
	else if(!button->isChecked())
	{
		if(!buttonState.uncheck)
		{
			LogInfo("DlgCtrlPrd: try uncheck %s but uncheck!", qPrintable(button->objectName()));
			button->blockSignals(true);
			button->setChecked(true);
			button->blockSignals(false);
		}
		else
		{
			LogInfo("DlgCtrlPrd: try uncheck %s", qPrintable(button->objectName()));
			if(buttonState.actions.count() > 1)
				sendAction(buttonState.actions.last(), actionParameters());
		}
	}
	else
	{
		LogInfo("DlgCtrlPrd: try check %s", qPrintable(button->objectName()));
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
			sendAction(buttonState.actions.first(), actionParameters());
	}
}

// ------------------------------------------------------------------
void DlgCtrlPrd::sendAction(QString command, QStringList parameters)
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
qint32 DlgCtrlPrd::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgCtrlPrd: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "ASKU_CONTROL_PRD_SELECTORS")
	{
		if(data.contains("Selectors"))
		{
			QVariantMap values = data["Selectors"].toMap();
			m_selectors = values;
			refreshSelectors();
		}

		result = AskuModule::CommandSuccess;
	}
	if(infoType == "ASKU_CONTROL_PRD_BUTTONS")
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
void DlgCtrlPrd::refreshSelectors()
{
	QVariantList list;

	ui.comboSelectPrd->blockSignals(true);
	ui.comboSelectModule->blockSignals(true);

	ui.comboSelectPrd->clear();
	ui.comboSelectPrd->setEnabled(true);

	list = m_selectors["SelectPrd"].toList();
	foreach(QVariant values, list)
	{
		QStringList text = values.toStringList();
		if(!text.isEmpty())
			ui.comboSelectPrd->addItem(text.first(), text.last());
	}

	ui.comboSelectModule->clear();
	ui.comboSelectModule->setEnabled(true);

	list = m_selectors["SelectUmi"].toList();
	foreach(QVariant values, list)
	{
		QStringList text = values.toStringList();
		if(!text.isEmpty())
			ui.comboSelectModule->addItem(text.first(), text.last());
	}

	ui.comboSelectPrd->setCurrentIndex(0);
	ui.comboSelectModule->setCurrentIndex(0);

	ui.comboSelectPrd->blockSignals(false);
	ui.comboSelectModule->blockSignals(false);

	sendRefreshAction();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::verifyCommands()
{
	QString value;

	value = m_commands["p380v"].toString();
	if(value == "off")
	{
		m_buttons["pushPowerOff"].checked = true;
		m_buttons["pushPowerOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushPowerOff"].checked = false;
		m_buttons["pushPowerOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushPowerOff"].checked = false;
		m_buttons["pushPowerOn"].checked = false;
	}
	m_buttons["pushPowerOff"].enabled = true;
	m_buttons["pushPowerOn"].enabled = true;


	value = m_commands["pumi"].toString();
	if(value == "off")
	{
		m_buttons["pushPumi1"].checked = false;
		m_buttons["pushPumi2"].checked = false;
	}
	else if(value == "1")
	{
		m_buttons["pushPumi1"].checked = true;
		m_buttons["pushPumi2"].checked = false;
	}
	else if(value == "2")
	{
		m_buttons["pushPumi1"].checked = false;
		m_buttons["pushPumi2"].checked = true;
	}
	m_buttons["pushPumi1"].enabled = true;
	m_buttons["pushPumi2"].enabled = true;


	value = m_commands["hotres"].toString();
	if(value == "off")
	{
		m_buttons["pushHotResOff"].checked = true;
		m_buttons["pushHotResOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushHotResOff"].checked = false;
		m_buttons["pushHotResOn"].checked = true;
	}

	m_buttons["pushHotResOff"].enabled = true;
	m_buttons["pushHotResOn"].enabled = true;


	value = m_commands["m380v"].toString();
	if(value == "off")
	{
		m_buttons["pushModule380Off"].checked = true;
		m_buttons["pushModule380On"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushModule380Off"].checked = false;
		m_buttons["pushModule380On"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushModule380Off"].checked = false;
		m_buttons["pushModule380On"].checked = false;
	}
	m_buttons["pushModule380Off"].enabled = true;
	m_buttons["pushModule380On"].enabled = true;


	value = m_commands["power"].toString();
	if(value == "off")
	{
		m_buttons["pushModuleOff"].checked = true;
		m_buttons["pushModuleOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushModuleOff"].checked = false;
		m_buttons["pushModuleOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushModuleOff"].checked = false;
		m_buttons["pushModuleOn"].checked = false;
	}
	m_buttons["pushModuleOff"].enabled = true;
	m_buttons["pushModuleOn"].enabled = true;


	value = m_commands["svch"].toString();
	if(value == "off")
	{
		m_buttons["pushSVChOff"].checked = true;
		m_buttons["pushSVChOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["pushSVChOff"].checked = false;
		m_buttons["pushSVChOn"].checked = true;
	}
	else //if(value == "na")
	{
		m_buttons["pushSVChOff"].checked = false;
		m_buttons["pushSVChOn"].checked = false;
	}
	m_buttons["pushSVChOff"].enabled = true;
	m_buttons["pushSVChOn"].enabled = true;

	m_buttons["pushReset"].enabled = true;

	verifyButtons();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::verifyButtons()
{
	foreach(QString key, m_buttons.keys())
	{
		AskuPanelButtonState buttonState = m_buttons.value(key);

		QPushButton *button = findChild<QPushButton*>(key);

//		LogInfo("DlgCtrlPrd: Buttons[%s] enabled=%d checked=%d uncheck=%d", qPrintable(key), buttonState.enabled, buttonState.checked, buttonState.uncheck);

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
void DlgCtrlPrd::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("refreshCtrlPrd");
}

// ------------------------------------------------------------------
void DlgCtrlPrd::disconnectedRls()
{
	setActive(false);
	m_commands.clear();
	m_selectors.clear();
}

// ------------------------------------------------------------------
void DlgCtrlPrd::setActive(bool on)
{
	QList<QPushButton*> buttons = ui.groupControl->findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		button->setEnabled(on);

	QList<QComboBox*> combos = ui.groupSelect->findChildren<QComboBox*>();
	foreach(QComboBox* combo, combos)
		combo->setEnabled(on);
}

// ------------------------------------------------------------------
