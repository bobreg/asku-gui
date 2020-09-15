#include <QDir>
#include "globalvar.h"
#include "guimodule.h"
#include "guiapplication.h"
#include "xpmset.h"
#include "mainwindow.h"
#include "smallwindow.h"
#include "actions.h"
#include "config.h"
#include "rlscontrol.h"
#include "levelcollection.h"
#include "dialogcollection.h"
#include "control.h"
#include "dlgabout.h"
#include "dlgdasd.h"
#include "dlgtables.h"
#include "dlgctrlpanel.h"
#include "dlgviewer.h"
#include "dlgphase.h"
#include "dlgmeasure.h"
#include "dlgskrpilot.h"
#include "dlgsetprm.h"
#include "dlglistrgdv.h"
#include "dlgctrlprd.h"
#include "dlgctrlelk.h"
#include "dlgcoolers.h"
#include "dlgdrives.h"
#include "dlgupses.h"
#include "dlgdeses.h"
#include "dlgchannel.h"
#include "dlgadvanced.h"
#include "dlglogger.h"
#include "dlgpowermeter.h"
#include "dlgavtomatica.h"

//----------------------------------------------------------------------------------------------------------------
AskuGuiModule::AskuGuiModule(AskuGuiApplication * parent, quint32 idGpr) : AskuModule(parent, idGpr, "AskuModuleGui", idAskuModuleGui)
{
	m_pixmaps.init();

	connect(this, SIGNAL(flushSettings()), parent, SLOT(flushSettings()));

#if QT_VERSION >= 0x050000
	config = new AskuConfig(QDir::toNativeSeparators(m_setup.path.config + "/asku-config.xml"), parent);
#else
	config = new AskuConfig(QDir::convertSeparators(m_setup.path.config + "/asku-config.xml"), parent);
#endif

	rlsControl = new AskuRlsControl(parent);
	rlsControl->setConfig(config);

	actions = new AskuActions(parent);
	actions->setConfig(config);

	loadSettingsUI();
	connect(settingsUI, SIGNAL(changed()), this, SLOT(saveSettingsUI()));

	AskuDialogs* m_dialogs = new AskuDialogs(this, "CommonDialogSet");
	m_dialogs->insert(settingsUI);
	m_dialogs->setActions(actions);

//Малое окно
	smallWindow = new AskuSmallWindow();
	smallWindow->setConfig(config);
	smallWindow->setActions(actions);
	smallWindow->applyGraphic();
	connect(settingsUI, SIGNAL(changed()), smallWindow, SLOT(applyGraphic()));
	connect(smallWindow, SIGNAL(sigReloadConfig()), config, SLOT(reload()));
	connect(smallWindow, SIGNAL(sigQuit()), parent, SLOT(slotQuit()));

	AskuRlsList rlsList = rlsControl->getRlsList();

	foreach(AskuRls *rls, rlsList)
	{
		LogInfo("Loading RLS: %d-\"%s\" (lt=\'%s\')", rls->index(), qPrintable(rls->title()), qPrintable(rls->litera()));

		AskuDtControl* m_control = new AskuDtControl(this);
		m_controlMap.insert(rls->index(), m_control);
		m_control->setRlsName(rls->name());
		m_control->setConfig(config);
		m_control->setActions(actions);
		connect(m_control, SIGNAL(sendControlCommand(QString, QVariantMap)), this, SLOT(sendControlCommand(QString, QVariantMap)));
		connect(m_control, SIGNAL(sendSyncMessage(QString, QVariantMap)), this, SLOT(sendSyncMessage(QString, QVariantMap)));
		connect(m_control, SIGNAL(sigReloadConfig()), config, SLOT(reload()));
		connect(m_control, SIGNAL(setSmallWindowControlText(QString, QString)), smallWindow, SLOT(setText(QString, QString)));
		connect(m_control, SIGNAL(setSmallWindowControlState(QString, QString)), smallWindow, SLOT(setState(QString, QString)));

//Создание уровней
		AskuLevelCollection* m_levelCollection = new AskuLevelCollection(this);
		m_levelCollectionMap.insert(rls->index(), m_levelCollection);
		m_levelCollection->setRlsName(rls->name());
		m_levelCollection->setLitera(rls->litera());
		m_levelCollection->setConfig(config);
		m_levelCollection->setActions(actions);
		connect(m_levelCollection, SIGNAL(sendControlCommand(QString, QVariantMap)), this, SLOT(sendControlCommand(QString, QVariantMap)));
		connect(m_control, SIGNAL(sigReloadLevels(QString)), m_levelCollection, SLOT(actionReloadLevels(QString)));
		connect(config, SIGNAL(updated()), m_control, SLOT(actionReloadLevels()));
		connect(config, SIGNAL(updated()), m_control, SLOT(requestControl()));
		connect(settingsUI, SIGNAL(changed()), m_levelCollection, SLOT(applyGraphic()));
		connect(m_levelCollection, SIGNAL(setStatusWindowState(QString, QString)), smallWindow, SLOT(setState(QString, QString)));
		connect(m_control, SIGNAL(setConnectionStatus(QString)), m_levelCollection, SLOT(setConnectionStatus(QString)));

		m_control->actionReloadLevels();

//Главное окно
		AskuMainWindow* mainWindow = new AskuMainWindow();
		mainWindowMap.insert(rls->index(), mainWindow);
		mainWindow->setRlsName(rls->name());
		mainWindow->setConfig(config);
		mainWindow->setActions(actions);
		mainWindow->setLevelCollection(m_levelCollection);
		mainWindow->applyGraphic();
		connect(mainWindow,SIGNAL(sendControlCommand(QString, QVariantMap)),this,SLOT(sendControlCommand(QString, QVariantMap)));
		connect(settingsUI, SIGNAL(changed()), mainWindow, SLOT(applyGraphic()));
		connect(mainWindow,SIGNAL(sigQuit()),parent,SLOT(slotQuit()));
		connect(m_control, SIGNAL(changedRegime(QString)), mainWindow, SLOT(onChangedRegime(QString)));
		connect(mainWindow,SIGNAL(sigQuit()),smallWindow,SLOT(close()));

//Создание диалоговых окон
		AskuDialogs* m_dialogs = new AskuDialogs(this, QString("rlsDialogSet_%1").arg(rls->index()));
		m_dialogsMap.insert(rls->index(), m_dialogs);
		m_dialogs->setRlsName(rls->name());
		m_dialogs->setConfig(config);
		m_dialogs->insert(new DlgAbout(mainWindow));
		m_dialogs->insert(new DlgDASD(mainWindow));
		m_dialogs->insert(new DlgTables(mainWindow));
		m_dialogs->insert(new DlgCtrlPanel(mainWindow));
		m_dialogs->insert(new DlgViewer(mainWindow));
		m_dialogs->insert(new DlgPhase(mainWindow));
		m_dialogs->insert(new DlgMeasure(mainWindow));
		m_dialogs->insert(new DlgSkrPilot(mainWindow));
		m_dialogs->insert(new DlgSetPrm(mainWindow));
		m_dialogs->insert(new DlgListRGDV(mainWindow));
		m_dialogs->insert(new DlgCtrlPrd(mainWindow));
		m_dialogs->insert(new DlgCtrlElk(mainWindow));
		m_dialogs->insert(new DlgCoolers(mainWindow));
		m_dialogs->insert(new DlgDrives(mainWindow));
		m_dialogs->insert(new DlgUpses(mainWindow));
		m_dialogs->insert(new DlgDeses(mainWindow));
		m_dialogs->insert(new DlgChannel(mainWindow));
		m_dialogs->insert(new DlgAdvanced(mainWindow));
		m_dialogs->insert(new DlgLogger(mainWindow));
		m_dialogs->insert(new DlgPowerMeter(mainWindow));
		m_dialogs->insert(new DlgAvtomatica(mainWindow));
		m_dialogs->setActions(actions);
		m_dialogs->applyGraphic();

		connect(settingsUI, SIGNAL(changed()), m_dialogs, SLOT(applyGraphic()));
		connect(m_control, SIGNAL(connectedGpr(quint32)), m_dialogs, SLOT(connected(quint32)));
		connect(m_control, SIGNAL(disconnectedGpr(quint32)), m_dialogs, SLOT(disconnected(quint32)));
		connect(m_control, SIGNAL(connectedRls()), m_dialogs, SLOT(connectedRls()));
		connect(m_control, SIGNAL(disconnectedRls()), m_dialogs, SLOT(disconnectedRls()));

		init(rls->ipGpr1(), rls->portGpr1());
		init(rls->ipGpr2(), rls->portGpr2());
	}

	smallWindow->show();
}

//----------------------------------------------------------------------------------------------------------------
AskuGuiModule::~AskuGuiModule()
{
	m_dialogsMap.clear();
	mainWindowMap.clear();
	m_controlMap.clear();
	m_levelCollectionMap.clear();
//	delete m_dialogs;
//	delete mainWindow;
	delete smallWindow;
//	delete m_control;
//	delete m_levelCollection;

	destroy();
}

//----------------------------------------------------------------------------------------------------------------
//Установка настроек графики
void AskuGuiModule::loadSettingsUI()
{
	settingsUI = new SettingsUI();
	settingsUI->setCurrentDir (m_setup.path.scheme);
	settingsUI->setCurrentFile(m_setup.ui.file);
	settingsUI->loadScheme();
	settingsUI->setScaleX(m_setup.ui.scale_x);
	settingsUI->setScaleY(m_setup.ui.scale_y);
}

//----------------------------------------------------------------------------------------------------------------
//Сохранение настроек графики
void AskuGuiModule::saveSettingsUI()
{
	m_setup.path.scheme = settingsUI->getCurrentDir();
	m_setup.ui.file = settingsUI->getCurrentFile();
	m_setup.ui.scale_x = settingsUI->getScaleX();
	m_setup.ui.scale_y = settingsUI->getScaleY();

	emit flushSettings();
}

//----------------------------------------------------------------------------------------------------------------
void AskuGuiModule::processMessage(AskuMessage & message, qint32 idModule, qint32 idConnection)
{
	QString type = message.getType();
	quint32 idGpr = message.getId();
//	qint32 idModule = message.getIdModule();
	qint32 idRls = rlsControl->getRlsIdByPeer(peerAddress(idConnection), peerPort(idConnection));
	qint32 processed = CommandNotFound;
	QString module;
	QString command;

	if(idRls != idRlsIdUnknown && idModule == idAskuModuleSvc)
	{
		QString type = message.getType();
		if(type == "Hello")
		{
//			LogInfo("recv Hello");
			processed = CommandSuccess;
		}
		else if(type == "Startup")
		{
//			LogInfo("recv Startup");
			QTimer::singleShot(0, m_controlMap[idRls], SLOT(requestControl()));
			QTimer::singleShot(0, m_levelCollectionMap[idRls], SLOT(requestRefresh()));
			processed = CommandSuccess;
		}
		else if(type == "ByeBye")
		{
//			LogInfo("recv ByeBye");
			processed = CommandSuccess;
		}
		else if(type == "ControlAnswer")
		{
//			LogInfo("recv ControlAnswer");
			processed = CommandSuccess;
		}
		else if(type == "InfoMessage")
		{
//			LogInfo("recv InfoMessage");

			if(message.hasData())
			{
				processed = CommandNotModule;

				QVariantMap map = message.getDataMap().value("Data").toMap();
				module = map["ModuleTo"].toString();

				if(module.startsWith("control"))
				{
					command = map["InfoType"].toString();
					processed = m_controlMap[idRls]->processInfo(map);
				}
				else if(module.startsWith("level"))
				{
					command = map["InfoType"].toString();
					processed = m_levelCollectionMap[idRls]->processInfo(map);
				}
				else if(module.startsWith("dialog_"))
				{
					command = map["InfoType"].toString();

					if(m_dialogsMap[idRls]->contains(module))
						processed = m_dialogsMap[idRls]->processInfo(module, map);
				}
			}
			else
			{
				processed = CommandInvalid;
			}
		}
		else if(type == "SyncMessage")
		{
			if(message.hasData())
			{
				processed = CommandNotModule;

				QVariantMap map = message.getDataMap().value("Data").toMap();
				module = map["ModuleTo"].toString();

				if(module == "control")
				{
					if(m_controlMap[idRls] != NULL)
					{
						command = map["Sync"].toString();
						processed = m_controlMap[idRls]->processSyncControl(idGpr, map);
					}
				}
			}
			else
			{
				processed = CommandInvalid;
			}
		}
	}

	switch(processed)
	{
		case CommandSuccess:
//			LogInfo("Control: \"%s\" processed \"%s\"", qPrintable(module), qPrintable(command));
			break;
		case CommandNotModule:
			LogError("Control: unknown module \"%s\"", qPrintable(module));
			break;
		case CommandNotFound:
			LogError("Control: unknown \"%s\" command \"%s\"", qPrintable(module), qPrintable(command));
			break;
		case CommandInvalid:
			LogError("Control: invalid \"%s\" command \"%s\"", qPrintable(module), qPrintable(command));
			break;
		case CommandNotEnoughParameters:
			LogError("Control: not enough parametes \"%s\" command \"%s\"", qPrintable(module), qPrintable(command));
			break;
		case CommandInvalidParameter:
			LogError("Control: invalid parameter \"%s\" command \"%s\"", qPrintable(module), qPrintable(command));
			break;
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuGuiModule::sendControlCommand(QString rlsName, QVariantMap data)
{
	AskuRlsList rlsList = rlsControl->getRlsList();
	foreach(AskuRls *rls, rlsList)
	{
		if(rls->name() == rlsName)
		{
			qint32 idConnection1 = findIdConnection(rls->ipGpr1(), rls->portGpr1());
			if(idConnection1 != idConnectionAll)
				AskuModule::sendControlCommand(data, idAskuModuleAll, idConnection1);

			qint32 idConnection2 = findIdConnection(rls->ipGpr2(), rls->portGpr2());
			if(idConnection2 != idConnectionAll)
				AskuModule::sendControlCommand(data, idAskuModuleAll, idConnection2);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuGuiModule::sendSyncMessage(QString rlsName, QVariantMap data)
{
	AskuRlsList rlsList = rlsControl->getRlsList();
	foreach(AskuRls *rls, rlsList)
	{
		if(rls->name() == rlsName)
		{
			qint32 idConnection1 = findIdConnection(rls->ipGpr1(), rls->portGpr1());
			if(idConnection1 != idConnectionAll)
				AskuModule::sendSyncMessage(data, idAskuModuleAll, idConnection1);

			qint32 idConnection2 = findIdConnection(rls->ipGpr2(), rls->portGpr2());
			if(idConnection2 != idConnectionAll)
				AskuModule::sendSyncMessage(data, idAskuModuleAll, idConnection2);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
