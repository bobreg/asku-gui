#ifndef __GUIMODULE_H__
#define __GUIMODULE_H__

#include "../common/module.h"
#include "levelcollection.h"

//----------------------------------------------------------------------------------------------------------------

class AskuGuiApplication;
class AskuSmallWindow;
class AskuMainWindow;
class AskuActions;
class AskuConfig;
class AskuRlsControl;
class AskuDialogs;
using AskuLevels::AskuLevelCollection;
class AskuDtControl;

//----------------------------------------------------------------------------------------------------------------

class AskuGuiModule : public AskuModule
{
Q_OBJECT

	QTimer m_timer;

	AskuSmallWindow *smallWindow;
	AskuActions *actions;
	AskuConfig *config;
	AskuRlsControl *rlsControl;
	QMap<quint32, AskuMainWindow*> mainWindowMap;
	QMap<quint32, AskuLevelCollection*> m_levelCollectionMap;
	QMap<quint32, AskuDialogs*> m_dialogsMap;
	QMap<quint32, AskuDtControl*> m_controlMap;

protected slots:
	void loadSettingsUI();
	void saveSettingsUI();

	void sendControlCommand(QString rlsName, QVariantMap data);
	void sendSyncMessage(QString rlsName, QVariantMap data);

public:
	AskuGuiModule(AskuGuiApplication * parent, quint32 idModule);
	~AskuGuiModule();

	virtual void processMessage(AskuMessage & message, qint32 idModule, qint32 idConnection);
};

//----------------------------------------------------------------------------------------------------------------

#endif // __GUIMODULE_H__
