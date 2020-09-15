#include <QMessageBox>
#include "globalvar.h"
#include "dlgctrlpanel.h"
#include "settingsui.h"
#include "../common/module.h"
#include "../common/logger.h"
#include "../common/stateset.h"

// ------------------------------------------------------------------
DlgCtrlPanel::DlgCtrlPanel(QWidget *parent) : AskuDialog("dialog_control_panel", parent), AskuControlPanel()
{
	ui.setupUi(this);

	if(settingsUI)
		connect(settingsUI, SIGNAL(changed()), this, SLOT(applyGraphic()));

	applyGraphic();
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//	ui.tableRaf->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
#else
	ui.tableRaf->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
#endif
/*
	QHeaderView *view = ui.tableRaf->verticalHeader();
	view->setResizeMode(0, QHeaderView::Fixed);
	view->setResizeMode(1, QHeaderView::Fixed);
	view->setResizeMode(2, QHeaderView::Fixed);
*/
	setVisibleRaf(false);
}

// ------------------------------------------------------------------
DlgCtrlPanel::~DlgCtrlPanel()
{
}

// ------------------------------------------------------------------
void DlgCtrlPanel::showEvent(QShowEvent * event)
{
	sendAction("refreshControl");
	event->accept();
}

// ------------------------------------------------------------------
void DlgCtrlPanel::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgCtrlPanel::setVisibleRaf(bool on)
{
	m_visibleRaf = on;

	ui.groupRafList->setVisible(on);
	ui.tableRaf->resizeColumnsToContents();
	adjustSize();
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_closeButton_clicked()
{
	hide();

	if(m_rafStatus["status"].toInt() == 0 && m_visibleRaf)
		setVisibleRaf(false);
}

// ------------------------------------------------------------------
void DlgCtrlPanel::applyGraphic()
{
	updateLabelState(ui.rafReady, m_indicators["rafState"].state);
	updateLabelState(ui.rgdvReady, m_indicators["rgdvState"].state);
}

//--------------------------------------------------------------
void DlgCtrlPanel::updateLabelState(QLabel *label, QString state)
{
	QPalette palette;
	palette.setColor(label->backgroundRole(), settingsUI->getItemBodyColor(stringToState(state)));
	label->setPalette(palette);
}

//--------------------------------------------------------------
void DlgCtrlPanel::setStateRaf(QString state, QString text)
{
	if(!text.isEmpty())
		ui.rafReady->setText(text);

	m_indicators["rafState"].state = state;
	m_indicators["rafState"].state = text;
	updateLabelState(ui.rafReady, state);
}

//--------------------------------------------------------------
void DlgCtrlPanel::setStateRgdv(QString state, QString text)
{
	if(!text.isEmpty())
		ui.rgdvReady->setText(text);

	m_indicators["rgdvState"].state = state;
	m_indicators["rgdvState"].text = text;

	updateLabelState(ui.rgdvReady, state);
}

// ------------------------------------------------------------------
void DlgCtrlPanel::activateButtonAction(QString command, QStringList parameters)
{
	Q_UNUSED(parameters);

	if(command == "setRgdvOn")
		emit activateAction(rlsName() + "act_dialog_listrgdv_show");
	else if(command == "setRgdvOff")
		emit activateAction(rlsName() + "act_dialog_listrgdv_hide");
}

// ------------------------------------------------------------------
void DlgCtrlPanel::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "control";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);

	activateButtonAction(command, parameters);
}

// ------------------------------------------------------------------
qint32 DlgCtrlPanel::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgCtrlPanel: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "ASKU_CONTROL_PANEL")
	{
		if(data.contains("CommandSet"))
		{
			QVariantMap values = data["CommandSet"].toMap();
			m_commands = values;
			verifyCommands();
		}

		if(data.contains("RafStatusSet"))
		{
			QVariantMap values = data["RafStatusSet"].toMap();
			m_rafStatus = values;
			updateRafStatus();
		}

		if(data.contains("MessageSet"))
		{
			QVariantMap map = data["MessageSet"].toMap();
			QDateTime updated = map["updated"].toDateTime();
			if(!updated.isValid() || !m_rafMessagesUpdated.isValid() || m_rafMessagesUpdated != updated)
			{
				m_rafMessagesUpdated = updated;
				m_rafMessages = map["messages"].toList();
				updateRafMessages();
			}
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgCtrlPanel::updateRafStatus()
{
	quint32 percent = m_rafStatus["percent"].toUInt();
	ui.progressBarRaf->setValue(percent);

	qint32 status = m_rafStatus["status"].toInt();
//	qDebug("percent = %d status = %d", percent, status);
	if(status != 0 && !m_visibleRaf)
	{
		setVisibleRaf(true);
	}
}

// ------------------------------------------------------------------
void DlgCtrlPanel::updateRafMessages()
{
	for(qint32 row = ui.tableRaf->rowCount(); row > 0; row--)
		ui.tableRaf->removeRow(row);

	qint32 count = m_rafMessages.count();
	ui.tableRaf->setRowCount(count);

	for(qint32 row = 0; row < count; row++)
	{
		QStringList list = m_rafMessages[row].toStringList();
		QString message, type, time, state;

		if(list.count() > 0)
			message = list[0];
		if(list.count() > 1)
			type = list[1];
		if(list.count() > 2)
			time = list[2];

		QColor back, fore;

		if(type == "command")
		{
			fore = Qt::blue;
			back = Qt::white;
			state = "команда";
		}
		else if(type == "ticket")
		{
			fore = Qt::darkGreen;
			back = Qt::white;
			state = "квитанция";
		}
		else if(type == "error")
		{
			fore = Qt::black;
			back = Qt::red;
			state = "ошибка";
		}
		else if(type == "complete")
		{
			fore = Qt::black;
			back = Qt::green;
			state = "завершено";
		}
		else	//default
		{
			fore = Qt::black;
			back = Qt::white;
			state = " ";
		}

		QTableWidgetItem *item1 = ui.tableRaf->item(row, 0);
		if(item1 != NULL)
			item1->setText(message);
		else
		{
			item1 = new QTableWidgetItem(message);
			item1->setFlags(Qt::NoItemFlags);
			ui.tableRaf->setItem(row, 0, item1);
		}

		item1->setForeground(QBrush(fore));
		item1->setBackground(QBrush(back));

		QTableWidgetItem *item2 = ui.tableRaf->item(row, 1);
		if(item2 != NULL)
			item2->setText(state);
		else
		{
			item2 = new QTableWidgetItem(state);
			item2->setFlags(Qt::NoItemFlags);
			ui.tableRaf->setItem(row, 1, item2);
		}

		item2->setForeground(QBrush(fore));
		item2->setBackground(QBrush(back));

		QTableWidgetItem *item3 = ui.tableRaf->item(row, 2);
		if(item3 != NULL)
			item3->setText(time);
		else
		{
			item3 = new QTableWidgetItem(time);
			item3->setFlags(Qt::NoItemFlags);
			ui.tableRaf->setItem(row, 2, item3);
		}

		item3->setForeground(QBrush(fore));
		item3->setBackground(QBrush(back));
	}

	ui.tableRaf->resizeColumnsToContents();
}

// ------------------------------------------------------------------
void DlgCtrlPanel::verifyCommands()
{
	QString value = m_commands["raf"].toString();
	if(value == "disable")
	{
		m_buttons["rafButtonOff"].checked = true;
		m_buttons["rafButtonOn"].checked = false;
		m_buttons["rafButtonOff"].enabled = false;
		m_buttons["rafButtonOn"].enabled = false;
	}
	else if(value == "off")
	{
		m_buttons["rafButtonOff"].checked = true;
		m_buttons["rafButtonOn"].checked = false;
		m_buttons["rafButtonOff"].enabled = true;
		m_buttons["rafButtonOn"].enabled = true;
	}
	else if(value == "on")
	{
		m_buttons["rafButtonOff"].checked = false;
		m_buttons["rafButtonOn"].checked = true;
		m_buttons["rafButtonOff"].enabled = true;
		m_buttons["rafButtonOn"].enabled = true;
	}

	value = m_commands["rgdv"].toString();
	if(value == "disable")
	{
		m_buttons["rgdvButtonOff"].checked = true;
		m_buttons["rgdvButtonOn"].checked = false;
		m_buttons["rgdvButtonOff"].enabled = false;
		m_buttons["rgdvButtonOn"].enabled = false;
	}
	else if(value == "off")
	{
		m_buttons["rgdvButtonOff"].checked = true;
		m_buttons["rgdvButtonOn"].checked = false;
		m_buttons["rgdvButtonOff"].enabled = true;
		m_buttons["rgdvButtonOn"].enabled = true;
	}
	else if(value == "on")
	{
		m_buttons["rgdvButtonOff"].checked = false;
		m_buttons["rgdvButtonOn"].checked = true;
		m_buttons["rgdvButtonOff"].enabled = true;
		m_buttons["rgdvButtonOn"].enabled = true;
	}

	setStateRaf(m_commands["ind_raf"].toString(), m_commands["ind_raf_text"].toString());
	setStateRgdv(m_commands["ind_rgdv"].toString(), m_commands["ind_rgdv_text"].toString());

	value = m_commands["obr"].toString();
	if(value == "off")
	{
		m_buttons["prlObrButton1"].checked = false;
		m_buttons["prlObrButton2"].checked = false;
	}
	else if(value == "1")
	{
		m_buttons["prlObrButton1"].checked = true;
		m_buttons["prlObrButton2"].checked = false;
	}
	else if(value == "2")
	{
		m_buttons["prlObrButton1"].checked = false;
		m_buttons["prlObrButton2"].checked = true;
	}

	value = m_commands["resobr"].toString();
	if(value == "off")
	{
		m_buttons["prlAutoButtonOff"].checked = true;
		m_buttons["prlAutoButtonOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["prlAutoButtonOff"].checked = false;
		m_buttons["prlAutoButtonOn"].checked = true;
	}

	value = m_commands["vrl"].toString();
	if(value == "off")
	{
		m_buttons["mvrlObrButton1"].checked = false;
		m_buttons["mvrlObrButton2"].checked = false;
	}
	else if(value == "1")
	{
		m_buttons["mvrlObrButton1"].checked = true;
		m_buttons["mvrlObrButton2"].checked = false;
	}
	else if(value == "2")
	{
		m_buttons["mvrlObrButton1"].checked = false;
		m_buttons["mvrlObrButton2"].checked = true;
	}

	value = m_commands["resvrl"].toString();
	if(value == "off")
	{
		m_buttons["vrlAutoButtonOff"].checked = true;
		m_buttons["vrlAutoButtonOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["vrlAutoButtonOff"].checked = false;
		m_buttons["vrlAutoButtonOn"].checked = true;
	}

	value = m_commands["bep"].toString();
	if(value == "off")
	{
		m_buttons["prvButtonOff"].checked = true;
		m_buttons["prvButtonOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["prvButtonOff"].checked = false;
		m_buttons["prvButtonOn"].checked = true;
	}

	value = m_commands["azsens"].toString();
	if(value == "off")
	{
		m_buttons["azimuthButton1"].checked = false;
		m_buttons["azimuthButton2"].checked = false;
	}
	else if(value == "1")
	{
		m_buttons["azimuthButton1"].checked = true;
		m_buttons["azimuthButton2"].checked = false;
	}
	else if(value == "2")
	{
		m_buttons["azimuthButton1"].checked = false;
		m_buttons["azimuthButton2"].checked = true;
	}

	value = m_commands["overview"].toString();
	if(value == "off")
	{
		m_buttons["overviewButton1"].checked = false;
		m_buttons["overviewButton2"].checked = false;
	}
	else if(value == "1")
	{
		m_buttons["overviewButton1"].checked = true;
		m_buttons["overviewButton2"].checked = false;
	}
	else if(value == "2")
	{
		m_buttons["overviewButton1"].checked = false;
		m_buttons["overviewButton2"].checked = true;
	}

	value = m_commands["prd"].toString();
	if(value == "off")
	{
		m_buttons["prdButtonOff"].checked = true;
		m_buttons["prdButtonOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["prdButtonOff"].checked = false;
		m_buttons["prdButtonOn"].checked = true;
	}
/*
	value = m_commands["prd1"].toString();
	if(value == "off")
	{
		m_buttons["prd1ButtonOff"].checked = true;
		m_buttons["prd1ButtonOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["prd1ButtonOff"].checked = false;
		m_buttons["prd1ButtonOn"].checked = true;
	}

	value = m_commands["prd2"].toString();
	if(value == "off")
	{
		m_buttons["prd2ButtonOff"].checked = true;
		m_buttons["prd2ButtonOn"].checked = false;
	}
	else if(value == "on")
	{
		m_buttons["prd2ButtonOff"].checked = false;
		m_buttons["prd2ButtonOn"].checked = true;
	}
*/
	value = m_commands["pumi"].toString();
	if(value == "off")
	{
		m_buttons["pumiButton1"].checked = false;
		m_buttons["pumiButton2"].checked = false;
	}
	else if(value == "1")
	{
		m_buttons["pumiButton1"].checked = true;
		m_buttons["pumiButton2"].checked = false;
	}
	else if(value == "2")
	{
		m_buttons["pumiButton1"].checked = false;
		m_buttons["pumiButton2"].checked = true;
	}

	verifyButtons();
}

// ------------------------------------------------------------------
void DlgCtrlPanel::verifyButtons()
{
	foreach(QString key, m_buttons.keys())
	{
		AskuPanelButtonState buttonState = m_buttons.value(key);

		QPushButton *button = findChild<QPushButton*>(key);

//		LogInfo("DlgCtrlPanel: Buttons[%s] enabled=%d checked=%d uncheck=%d", qPrintable(key), buttonState.enabled, buttonState.checked, buttonState.uncheck);

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
void DlgCtrlPanel::processButtonAction(QPushButton * button)
{
	if(button == NULL) return;

	AskuPanelButtonState buttonState = m_buttons.value(button->objectName());

	if(!button->isCheckable())
	{
		LogInfo("DlgCtrlPanel: click %s", qPrintable(button->objectName()));
		if(buttonState.actions.count())
			sendAction(buttonState.actions.first());
	}
	else if(!button->isChecked())
	{
		if(!buttonState.uncheck)
		{
			LogInfo("DlgCtrlPanel: try uncheck %s but uncheck!", qPrintable(button->objectName()));
			button->blockSignals(true);
			button->setChecked(true);
			button->blockSignals(false);
		}
		else
		{
			LogInfo("DlgCtrlPanel: try uncheck %s", qPrintable(button->objectName()));
			if(buttonState.actions.count() > 1)
				sendAction(buttonState.actions.last());
		}
	}
	else
	{
		LogInfo("DlgCtrlPanel: try check %s", qPrintable(button->objectName()));
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
void DlgCtrlPanel::on_rgdvButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_rgdvButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_rafButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_rafButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_howlButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_howlButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_howlButtonReset_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prlObrButton1_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prlObrButton2_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prlAutoButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prlAutoButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_azimuthButton1_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_azimuthButton2_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_overviewButton1_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_overviewButton2_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prvButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prvButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prdButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prdButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}
/*
// ------------------------------------------------------------------
void DlgCtrlPanel::on_prd1ButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prd1ButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prd2ButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_prd2ButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}
*/
// ------------------------------------------------------------------
void DlgCtrlPanel::on_pumiButton1_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_pumiButton2_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_mvrlObrButton1_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_mvrlObrButton2_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_vrlAutoButtonOff_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::on_vrlAutoButtonOn_clicked()
{
	processButtonAction(dynamic_cast<QPushButton*>(sender()));
}

// ------------------------------------------------------------------
void DlgCtrlPanel::connectedRls()
{
	setActive(false);
	clean();
	if(isVisible())
		sendAction("refreshControl");
}

// ------------------------------------------------------------------
void DlgCtrlPanel::disconnectedRls()
{
	setActive(false);
	clean();
}

// ------------------------------------------------------------------
void DlgCtrlPanel::setActive(bool on)
{
	QList<QPushButton*> buttons = findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
		if(button != ui.closeButton)
			button->setEnabled(on);
}

// ------------------------------------------------------------------
void DlgCtrlPanel::clean()
{
	m_rafMessagesUpdated = QDateTime();
	m_rafMessages.clear();
	updateRafMessages();

	m_rafStatus.clear();
	updateRafStatus();

	setStateRaf("not");
	setStateRgdv("not");

	if(m_visibleRaf)
		setVisibleRaf(false);
}

// ------------------------------------------------------------------
