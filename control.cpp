#include "../common/logger.h"
#include "../common/module.h"
#include "globalvar.h"
#include "control.h"

// ----------------------------------------------------------------------------
AskuDtControl::AskuDtControl(QObject * parent) : QObject(parent)
{
	m_mainUpdate = true;
	m_mainGpr = 0;
	m_regime = QString();
	m_initCounter = 1;
	m_stamp = 0;

	m_config = NULL;
	m_rlsName = QString();
	m_rlsConfig.clear();

	m_gpr["gpr1"] = ELEM_NOT;
	m_gpr["gpr2"] = ELEM_NOT;

	for(quint32 n = 0; n < MAX_GPR; n++)
	{
		m_isWorkGpr[n] = false;
		m_counterGpr[n] = 0;
	}

	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(timeoutControl()));
	m_timer->start(1000);

	m_syncTimer = new QTimer(this);
	connect(m_syncTimer, SIGNAL(timeout()), this, SLOT(syncTimeout()));
	m_syncTimer->start(2000);
}

// ----------------------------------------------------------------------------
AskuDtControl::~AskuDtControl()
{
	if(m_syncTimer)
	{
		m_syncTimer->stop();
		delete m_syncTimer;
		m_syncTimer = 0;
	}
	if(m_timer)
	{
		m_timer->stop();
		delete m_timer;
		m_timer = 0;
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDtControl::sendRequest(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "control";
	data["ModuleFrom"] = "control";
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;

	emit sendControlCommand(m_rlsName, data);
}

//----------------------------------------------------------------------------------------------------------------
void AskuDtControl::requestControl()
{
	m_mainUpdate = true;
	sendRequest("refreshControl");
}

//----------------------------------------------------------------------------------------------------------------
void AskuDtControl::verifyStatus()
{
//	qDebug("verifyStatus");
	bool changed = false;

	for(quint32 nGpr = 0; nGpr < MAX_GPR; nGpr++)
	{
		if(m_counterGpr[nGpr])
		{
			if(!m_isWorkGpr[nGpr])
			{
				if(!m_isWorkGpr[0] && !m_isWorkGpr[1])
					emit connectedRls();

				m_isWorkGpr[nGpr] = true;
				LogCtrlInfo("Control: connected gpr%d", nGpr+1);
				m_gpr[QString("gpr%1").arg(nGpr+1)] = ELEM_NORMA;
				changed = true;
				emit connectedGpr(nGpr);
				updateStatus();
				applyActions();
//				emit signalConnectedGpr();
//				mainWgt->pViewerASKU->AddNormaMes("АСКУ","Установлена связь со смежным комплектом");
			}

			m_counterGpr[nGpr]--;
		}
		else
		{
			if(m_isWorkGpr[nGpr])
			{
				m_isWorkGpr[nGpr] = false;
				LogCtrlInfo("Control: disconnected gpr%d", nGpr+1);
				m_gpr[QString("gpr%1").arg(nGpr+1)] = ELEM_AVAR;
				changed = true;
				emit disconnectedGpr(nGpr);
				updateStatus();
				applyActions();
//				emit changedState(m_gpr);
//				emit signalDisconnectedGpr();
//				mainWgt->pViewerASKU->AddNormaMes("АСКУ","Разрыв связи со смежным комплектом");
			}
		}
	}

	if(changed && !m_isWorkGpr[0] && !m_isWorkGpr[1])
	{
		setMain(0);
		setRegime(QString());
		applyActions();
		emit disconnectedRls();
	}

	if(m_initCounter)
	{
		m_initCounter++;
		if(m_initCounter > INIT_WAIT_TIMEOUT)
		{
			m_initCounter = 0;

			for(quint32 nGpr = 0; nGpr < MAX_GPR; nGpr++)
				if(!m_isWorkGpr[nGpr])
				{
					LogCtrlInfo("Control: no connection to gpr%d", nGpr+1);
					m_gpr[QString("gpr%1").arg(nGpr+1)] = ELEM_AVAR;
					emit disconnectedGpr(nGpr);
					updateStatus();
				}

			if(!m_isWorkGpr[0] && !m_isWorkGpr[1])
			{
				setMain(0, true);
				setRegime(QString(), true);
				applyActions();
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
qint32 AskuDtControl::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("Control: empty info data!");
		return result;
	}

	QVariantMap ctrl = data["RegimeSet"].toMap();

	QString nameRegime = ctrl["regimeName"].toString();
	setRegime(nameRegime);

	quint32 mainGpr = ctrl["main"].toUInt();
//	qDebug("mainGpr=%d", mainGpr);
	setMain(mainGpr, m_mainUpdate);

//	updateCommandSet(data["CommandSet"].toMap());

	result = AskuModule::CommandSuccess;

	return result;
}

// ----------------------------------------------------------------------------
qint32 AskuDtControl::processSyncControl(quint32 id, QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("processSyncControl: empty sync data!");
		return result;
	}

	QVariantMap sync = data["Sync"].toMap();

	if(id < MAX_GPR)
	{
		m_counterGpr[id] = CONTROL_GPR_TIMEOUT;
	}
/*
	if(FROM_OTHER_GPR(id))
	{
		result = processSyncControlGpr(id, sync);
	}
	else if(FROM_PPV(id) || FROM_RMO(id))
	{
		result = processSyncControlRmo(id, sync);
	}
	else
	{
		LogCtrlError("Control: error self sync message");
		result = AskuModule::CommandInvalid;
	}
*/
	result = AskuModule::CommandSuccess;
	return result;
}

// ----------------------------------------------------------------------------
void AskuDtControl::syncTimeout()
{
	makeSyncMessage();
}

// ----------------------------------------------------------------------------
void AskuDtControl::makeSyncMessage()
{
	QVariantMap data;

	data["InfoType"] = "ASKU_SYNC_INFO";
	data["ModuleTo"] = "control";
	data["ModuleFrom"] = "dtcontrol";

	QVariantMap info;
	info["idgpr"] = MYID();
	info["stamp"] = m_stamp++;
	data["Sync"] = info;

//	qDebug() << data;

	emit sendSyncMessage(m_rlsName, data);
}

// ----------------------------------------------------------------------------
void AskuDtControl::timeoutControl()
{
	verifyStatus();
}

// ----------------------------------------------------------------------------
void AskuDtControl::setMain(quint32 numMain, bool force)
{
	if(force || numMain != m_mainGpr)
	{
		m_mainGpr = numMain;
		m_mainUpdate = false;

		QString nameMain;

		if(m_mainGpr != 0)
		{
			if(ISGPR())
			{
				if((numMain == 1 && ISGPR1()) || (numMain == 2 && ISGPR2()))
					nameMain = QString("Осн");
				else
					nameMain = QString("Рез");
			}
			else
				nameMain = QString("Обр-%1").arg(numMain);
		}
		else
			nameMain = QString("---");

		emit changedMain(nameMain);
		emit setSmallWindowControlText(rlsName() + "control", nameMain);
		if(m_mainGpr != 0)
		{
			emit setSmallWindowControlState(rlsName() + "control", "norma");
		}
		else
		{
			emit setSmallWindowControlState(rlsName() + "control", "avar");
			emit setSmallWindowControlState(rlsName() + "common_urlk", "not");
			emit setSmallWindowControlState(rlsName() + "common_porl", "not");
			emit setSmallWindowControlState(rlsName() + "common_mvrl", "not");
			emit setSmallWindowControlState(rlsName() + "common_mpsn", "not");
			emit setSmallWindowControlState(rlsName() + "common_ksb", "not");
		}
	}
}

// ----------------------------------------------------------------------------
void AskuDtControl::setRegime(QString regime, bool force)
{
	if(force || m_regime != regime)
	{
		m_regime = regime;
		emit changedRegime(m_regime);
		emit setEnableAction(rlsName() + "act_dialog_listrgdv_show", m_regime == "РГДВ");
	}
}

// ----------------------------------------------------------------------------
void AskuDtControl::setRaf()
{
	sendRequest("setRaf");
}

// ----------------------------------------------------------------------------
void AskuDtControl::setRgdv()
{
	sendRequest("setRgdv");
}

// ----------------------------------------------------------------------------
void AskuDtControl::setTest()
{
	sendRequest("setTest");
}

// ----------------------------------------------------------------------------
void AskuDtControl::setResetAvar(QString name)
{
	if(name.startsWith(rlsName() + "act_reset_avar_prd1"))
		sendRequest("resetAvarPrd1");
	else if(name.startsWith(rlsName() + "act_reset_avar_prd2"))
		sendRequest("resetAvarPrd2");
	else if(name.startsWith(rlsName() + "act_reset_avar_prm"))
		sendRequest("resetAvarPrm");
	else if(name.startsWith(rlsName() + "act_reset_avar_bep"))
		sendRequest("resetAvarBep");
	else if(name.startsWith(rlsName() + "act_reset_avar_svo"))
		sendRequest("resetAvarSvo");
	else if(name.startsWith(rlsName() + "act_reset_avar_comm"))
		sendRequest("resetAvarComm");
}

//----------------------------------------------------------------------------------------------------------------
void AskuDtControl::setConfig(AskuConfig * config)
{
	if(!config)
		return;

	m_config = config;
	connect(config, SIGNAL(updated()), this, SLOT(applyConfig()));

	applyConfig();
}

//----------------------------------------------------------------------------------------------------------------
void AskuDtControl::applyConfig()
{
	if(!m_config)
		return;

	m_rlsConfig = m_config->makeRlsConfig();
}

//-------------------------------------------------------------------------------
void AskuDtControl::applyActions()
{
	bool workGpr = m_isWorkGpr[0] || m_isWorkGpr[1];

	emit setEnableAction(rlsName() + "act_dialog_listrgdv_show", m_regime == "РГДВ");

	emit setEnableAction(rlsName() + "act_dialog_control_panel_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_control_prd_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_control_elk_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_phase_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_setprm_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_skrpilot_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_dasd_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_dasd_tables_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_drives_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_coolers_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_upses_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_deses_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_powermeter_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_avtomatica_show", workGpr);
	emit setEnableAction(rlsName() + "act_dialog_viewer_show", workGpr);

	emit setEnableAction(rlsName() + "act_reset_avar_prd1", workGpr);
	emit setEnableAction(rlsName() + "act_reset_avar_prd2", workGpr);
	emit setEnableAction(rlsName() + "act_reset_avar_prm",  workGpr);
	emit setEnableAction(rlsName() + "act_reset_avar_bep",  workGpr);
	emit setEnableAction(rlsName() + "act_reset_avar_svo",  workGpr);
	emit setEnableAction(rlsName() + "act_reset_avar_comm", workGpr);

	emit setEnableAction(rlsName() + "act_regime_test", workGpr);
	emit setEnableAction(rlsName() + "act_regime_rgdv", workGpr);
	emit setEnableAction(rlsName() + "act_regime_raf", workGpr);
}

//-------------------------------------------------------------------------------
void AskuDtControl::setActions(AskuActions *actions)
{
	if(!actions)
		return;

	m_actions = actions;
	connect(actions, SIGNAL(updated()), this, SLOT(applyActions()));
	connect(actions, SIGNAL(invokeAction(QString, QStringList)), this, SLOT(invokeAction(QString, QStringList)));
	connect(this, SIGNAL(setEnableAction(QString, bool)), actions, SLOT(setEnableAction(QString, bool)));
	connect(this, SIGNAL(setEnableAction(QStringList, bool)), actions, SLOT(setEnableAction(QStringList, bool)));

	applyActions();
}

//-------------------------------------------------------------------------------
void AskuDtControl::invokeAction(QString name, QStringList parameters)
{
	Q_UNUSED(parameters);
//	LogInfo("AskuDtControl::invokeAction : \"%s\"", qPrintable(name));

	if(name.startsWith(rlsName() + "act_reload_scheme"))
		actionReloadLevels();
	else if(name.startsWith("act_reload_config"))
		emit sigReloadConfig();
	else if(name.startsWith(rlsName() + "act_regime_test"))
		setTest();
	else if(name.startsWith(rlsName() + "act_regime_rgdv"))
		setRgdv();
	else if(name.startsWith(rlsName() + "act_regime_raf"))
		setRaf();
	else if(name.startsWith(rlsName() + "act_reset_avar_"))
		setResetAvar(name);
}

// ----------------------------------------------------------------------------
void AskuDtControl::actionReloadLevels()
{
	QString level_path = m_rlsConfig.level(m_rlsName);
	if(level_path.isEmpty())
		level_path = m_setup.path.level;
	emit sigReloadLevels(level_path);
}

// ----------------------------------------------------------------------------
void AskuDtControl::updateStatus()
{
	QString status = "0";

	if(m_isWorkGpr[0] && m_isWorkGpr[1])
		status = "3";
	else if(m_isWorkGpr[0])
		status = "1";
	else if(m_isWorkGpr[1])
		status = "2";

	emit setConnectionStatus(status);

	if(status == "0")
		emit disconnectedRls();
}

// ----------------------------------------------------------------------------
