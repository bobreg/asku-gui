#include "globalvar.h"
#include "dlgdasd.h"
#include "../common/module.h"
#include "../common/logger.h"

// ------------------------------------------------------------------
DlgDASD::DlgDASD(QWidget *parent) : AskuDialog("dialog_dasd", parent)
{
	ui.setupUi(this);

	counter = '-';
	m_connected[0] = m_connected[1] = false;
	m_activeGpr = 0;

	on_pushButtonSettings_toggled(false);

	setEnablePage(0, false);
	setEnablePage(1, false);
}

// ------------------------------------------------------------------
DlgDASD::~DlgDASD()
{
}

// ------------------------------------------------------------------
void DlgDASD::setEnablePage(quint32 page, bool on)
{
	if(page >= MAX_ACTIVE_GPR)
		return;

	if(m_activeGpr == page && !on)
	{
		QList<QLabel*> widgets = ui.tabWidget->findChildren<QLabel*>();
		widgets << ui.groupState->findChildren<QLabel*>();
		widgets << ui.groupVersion->findChildren<QLabel*>();

		foreach(QLabel* lbl, widgets)
		{
			if(lbl->frameShape() == QFrame::StyledPanel)
				lbl->setText(" ");
		}
	}
}

// ------------------------------------------------------------------
void DlgDASD::on_comboGpr_currentIndexChanged(int index)
{
	if(isVisible())
		sendAction(m_activeGpr, "stopMonitor");

	m_activeGpr = index;

	if(isVisible())
		sendAction(m_activeGpr, "startMonitor");

	if(!m_connected[index])
		setEnablePage(index, false);
}

// ------------------------------------------------------------------
void DlgDASD::on_pushButtonSettings_toggled(bool on)
{
	if(on)
	{
		ui.pushModuleCtrl1->show();
		ui.pushModuleCtrl2->show();
		ui.pushModuleCtrl3->show();
		ui.pushFormerCtrl1->show();
		ui.pushFormerCtrl2->show();
		ui.pushFormerCtrl3->show();
		ui.pushFormerCtrl5->show();
		ui.spinFormerCtrl17->setEnabled(true);
		ui.pushAzimCtrl1->show();
		ui.pushAzimCtrl3->show();
		ui.pushAzimCtrl4->show();
		ui.pushAzimCtrl5->show();
		ui.pushAzimCtrl6->show();
		ui.pushTimerCtrl1->show();
		ui.pushTimerState2->show();
		ui.pushSharuCtrl3->show();
		ui.pushErrorZu1->show();
		ui.pushErrorZu2->show();
		ui.pushSKR3->show();
		ui.pushSKR4->show();
		ui.pushPS3->show();
		ui.pushPS4->show();
		ui.pushGSH3->show();
		ui.pushGSH4->show();
		ui.pushZU3->show();
		ui.pushZU4->show();
		ui.spinOffset1->setEnabled(true);
		ui.spinOffset2->setEnabled(true);
		ui.pushButtonResetTables->show();
		ui.pushButtonReset->show();
		ui.spinStepDopler1->setEnabled(true);
		ui.spinFreqDeviation1->setEnabled(true);
		ui.spinAmpDelayPilot1->setEnabled(true);
		ui.spinAmpDelayPilot2->setEnabled(true);
		ui.spinSyncr1->setEnabled(true);
	}
	else
	{
		ui.pushModuleCtrl1->hide();
		ui.pushModuleCtrl2->hide();
		ui.pushModuleCtrl3->hide();
		ui.pushFormerCtrl1->hide();
		ui.pushFormerCtrl2->hide();
		ui.pushFormerCtrl3->hide();
		ui.pushFormerCtrl5->hide();
		ui.spinFormerCtrl17->setEnabled(false);
		ui.pushAzimCtrl1->hide();
		ui.pushAzimCtrl3->hide();
		ui.pushAzimCtrl4->hide();
		ui.pushAzimCtrl5->hide();
		ui.pushAzimCtrl6->hide();
		ui.pushTimerCtrl1->hide();
		ui.pushTimerState2->hide();
		ui.pushSharuCtrl3->hide();
		ui.pushErrorZu1->hide();
		ui.pushErrorZu2->hide();
		ui.pushSKR3->hide();
		ui.pushSKR4->hide();
		ui.pushPS3->hide();
		ui.pushPS4->hide();
		ui.pushGSH3->hide();
		ui.pushGSH4->hide();
		ui.pushZU3->hide();
		ui.pushZU4->hide();
		ui.spinOffset1->setEnabled(false);
		ui.spinOffset2->setEnabled(false);
		ui.pushButtonResetTables->hide();
		ui.pushButtonReset->hide();
		ui.spinStepDopler1->setEnabled(false);
		ui.spinFreqDeviation1->setEnabled(false);
		ui.spinAmpDelayPilot1->setEnabled(false);
		ui.spinAmpDelayPilot2->setEnabled(false);
		ui.spinSyncr1->setEnabled(false);
	}
}

// ------------------------------------------------------------------
void DlgDASD::sendAction(quint32 toGpr, QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "dasd";
	data["ModuleFrom"] = objectName();
	data["ToGprId"] = toGpr;
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
void DlgDASD::showEvent(QShowEvent * event)
{
	sendAction(m_activeGpr, "startMonitor");
	event->accept();
}

// ------------------------------------------------------------------
void DlgDASD::hideEvent(QHideEvent * event)
{
	sendAction(m_activeGpr, "stopMonitor");
	event->accept();
}

// ------------------------------------------------------------------
void DlgDASD::on_pushButtonClose_clicked()
{
	hide();
}

// ------------------------------------------------------------------
void DlgDASD::on_pushButtonReset_clicked()
{
	sendAction(m_activeGpr, "resetModule");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushButtonResetTables_clicked()
{
	sendAction(m_activeGpr, "resetTables");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushModuleCtrl1_clicked()
{
	sendAction(m_activeGpr, "toggleMain");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushModuleCtrl2_clicked()
{
	sendAction(m_activeGpr, "toggleAzimuthMode");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushModuleCtrl3_clicked()
{
	sendAction(m_activeGpr, "toggleBlockAvto");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushFormerCtrl1_clicked()
{
	sendAction(m_activeGpr, "toggleRipch");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushFormerCtrl2_clicked()
{
	sendAction(m_activeGpr, "toggleBlockZu");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushFormerCtrl3_clicked()
{
	sendAction(m_activeGpr, "toggleBlockSwitch");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushFormerCtrl5_clicked()
{
	sendAction(m_activeGpr, "toggleVaruBan");
}

// ------------------------------------------------------------------
void DlgDASD::on_spinFormerCtrl17_valueChanged(int value)
{
	sendAction(m_activeGpr, "setImpulsePrd", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_pushAzimCtrl1_clicked()
{
	sendAction(m_activeGpr, "toggleAzimuthSource");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushAzimCtrl3_clicked()
{
	sendAction(m_activeGpr, "toggleAzimuthPeriod");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushAzimCtrl4_clicked()
{
	sendAction(m_activeGpr, "toggleAzimuthLir1Load");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushAzimCtrl5_clicked()
{
	sendAction(m_activeGpr, "toggleAzimuthLir2Load");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushAzimCtrl6_clicked()
{
	sendAction(m_activeGpr, "toggleAzimuthSerialLoad");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushTimerCtrl1_clicked()
{
	sendAction(m_activeGpr, "toggleTimerSource");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushSharuCtrl3_clicked()
{
	sendAction(m_activeGpr, "toggleSharuSource");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushErrorZu1_clicked()
{
	sendAction(m_activeGpr, "toggleErrorZu1");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushErrorZu2_clicked()
{
	sendAction(m_activeGpr, "toggleErrorZu2");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushSKR3_clicked()
{
	sendAction(m_activeGpr, "toggleSkrAlwaysOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushSKR4_clicked()
{
	sendAction(m_activeGpr, "toggleSkrOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushPS3_clicked()
{
	sendAction(m_activeGpr, "togglePilotAlwaysOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushPS4_clicked()
{
	sendAction(m_activeGpr, "togglePilotOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushGSH3_clicked()
{
	sendAction(m_activeGpr, "toggleGshAlwaysOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushGSH4_clicked()
{
	sendAction(m_activeGpr, "toggleGshOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushZU3_clicked()
{
	sendAction(m_activeGpr, "toggleZuAlwaysOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushZU4_clicked()
{
	sendAction(m_activeGpr, "toggleZuOn");
}

// ------------------------------------------------------------------
void DlgDASD::on_pushTimerState2_clicked()
{
	sendAction(m_activeGpr, "toggleTimerLoad");
}

// ------------------------------------------------------------------
void DlgDASD::on_spinOffset1_valueChanged(int value)
{
	sendAction(m_activeGpr, "setLir1Offset", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_spinOffset2_valueChanged(int value)
{
	sendAction(m_activeGpr, "setLir2Offset", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_spinStepDopler1_valueChanged(int value)
{
	sendAction(m_activeGpr, "setStepDopler", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_spinFreqDeviation1_valueChanged(int value)
{
	sendAction(m_activeGpr, "setFreqDeviation", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_spinAmpDelayPilot1_valueChanged(int value)
{
	sendAction(m_activeGpr, "setDelayPilot", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_spinAmpDelayPilot2_valueChanged(int value)
{
	sendAction(m_activeGpr, "setAmpPilot", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::on_spinSyncr1_valueChanged(int value)
{
	sendAction(m_activeGpr, "setSyncrOutput", QStringList(QString::number(value, 16)));
}

// ------------------------------------------------------------------
void DlgDASD::counterNext()
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	switch(counter.toLatin1())
#else
	switch(counter.toAscii())
#endif
	{
		case '-':
			counter = '\\';
			break;
		case '\\':
			counter = '|';
			break;
		case '|':
			counter = '/';
			break;
		case '/':
			counter = '-';
			break;
	}
	ui.labelStateCounter->setText(counter);
}

// ------------------------------------------------------------------
void DlgDASD::setLabelClear(QLabel *lbl)
{
    lbl->setText(" ");
}

// ------------------------------------------------------------------
void DlgDASD::setSpinValue(QSpinBox *spn, quint32 data)
{
	if(!spn->isEnabled())
		spn->setValue(data);
}

// ------------------------------------------------------------------
qint32 DlgDASD::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgDASD: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "DASD_STATUS_MESSAGE")
	{
		QString message = data["Message"].toString();

		if(message.isEmpty())
		{
			LogError("DlgDASD: empty message");
			return result;
		}

		bool ok = false;
		quint32 numGpr = data["GprId"].toUInt(&ok);
		if(!(ok && numGpr == m_activeGpr))
		{
			result = AskuModule::CommandSuccess;
			return result;
		}

		QLabel *lbl = findChild<QLabel*>("labelState");

		if(lbl != NULL)
			lbl->setText(message);

		result = AskuModule::CommandSuccess;
	}
	if(infoType == "DASD_DIALOG_REGISTERS")
	{
		QVariantMap values = data["Values"].toMap();

		if(values.isEmpty())
		{
			LogError("DlgDASD: empty values");
			return result;
		}

		bool ok = false;
		quint32 numGpr = data["GprId"].toUInt(&ok);
		if(!(ok && numGpr == m_activeGpr))
		{
//			LogError("DlgDASD: success but not active");
			result = AskuModule::CommandSuccess;
			return result;
		}

		counterNext();

		foreach(QString key, values.keys())
		{
//			LogInfo("Values: %s = %s", qPrintable(key), qPrintable(values.value(key).toString()));
			QLabel *lbl = findChild<QLabel*>(key);

			if(lbl != NULL)
			{
				lbl->setText(values.value(key).toString());
			}
			else
			{
				QSpinBox *spn = findChild<QSpinBox*>(key);

				if(spn != NULL)
					if(!spn->isEnabled())
						spn->setValue(values.value(key).toUInt());
			}
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgDASD::connected(quint32 numGpr)
{
	if(numGpr == IDGPR1)
	{
		QLabel *lbl = findChild<QLabel*>("labelConnect1");
		if(lbl)
			lbl->setText("ДА");
		m_connected[0] = true;
	}
	if(numGpr == IDGPR2)
	{
		QLabel *lbl = findChild<QLabel*>("labelConnect2");
		if(lbl)
			lbl->setText("ДА");
		m_connected[1] = true;
	}

	if(isVisible())
		sendAction(m_activeGpr, "startMonitor");
	setEnablePage(numGpr, true);
}

// ------------------------------------------------------------------
void DlgDASD::disconnected(quint32 numGpr)
{
	if(numGpr == IDGPR1)
	{
		QLabel *lbl = findChild<QLabel*>("labelConnect1");
		if(lbl)
			lbl->setText("НЕТ");
		m_connected[0] = false;
	}
	if(numGpr == IDGPR2)
	{
		QLabel *lbl = findChild<QLabel*>("labelConnect2");
		if(lbl)
			lbl->setText("НЕТ");
		m_connected[1] = false;
	}

	setEnablePage(numGpr, false);
}

// ------------------------------------------------------------------
