#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <QObject>
#include <QTimer>
#include <QVariantMap>
#include "../common/stateset.h"
#include "actions.h"

// ----------------------------------------------------------------------------

#define MAX_GPR 2

// ----------------------------------------------------------------------------

enum AskuWaitTimeouts {
	INIT_WAIT_TIMEOUT = 10,
	CONTROL_GPR_TIMEOUT = 10
};

// ----------------------------------------------------------------------------

class AskuDtControl : public QObject
{
Q_OBJECT

	quint32 m_mainGpr;
	QString m_regime;
	QTimer *m_timer;
	QTimer *m_syncTimer;
	quint32 m_stamp;
	bool m_mainUpdate;

	bool m_isWorkGpr[MAX_GPR];
	quint32 m_counterGpr[MAX_GPR];
	quint32 m_initCounter;

	AskuBinStateSet m_gpr;

	void verifyStatus();

private:
	AskuConfig *m_config;
	AskuActions *m_actions;
	AskuRlsConfig m_rlsConfig;
	QString m_rlsName;

protected slots:
	void syncTimeout();

public:
	AskuDtControl(QObject * parent = NULL);
	~AskuDtControl();

	inline QString rlsName() {
		return !m_rlsName.isEmpty() ? m_rlsName + "_" : m_rlsName;
	}
	inline void setRlsName(QString name) {
		m_rlsName = name;
	}

	void setConfig(AskuConfig* config);
	void setActions(AskuActions* actions);

	void makeMessage();
	void makeSyncMessage();

	void sendRequest(QString command, QStringList parameters = QStringList());
	qint32 processInfo(QVariantMap data);
	qint32 processSyncControl(quint32 id, QVariantMap data);

	void setMain(quint32 numMain, bool force = false);
	void setRegime(QString regime, bool force = false);
	void setResetAvar(QString name);

	void updateStatus();

public slots:
	void timeoutControl();
	void requestControl();

	void actionReloadLevels();

	void setRaf();
	void setRgdv();
	void setTest();

	void applyConfig();
	void applyActions();
	void invokeAction(QString name, QStringList parameters = QStringList());

signals:
	void connectedRls();
	void disconnectedRls();

	void connectedGpr(quint32 nGpr);
	void disconnectedGpr(quint32 nGpr);

	void changedRegime(QString nameRegime);
	void changedMain(QString nameMain);

	void setSmallWindowControlText(QString name, QString text);
	void setSmallWindowControlState(QString name, QString state);

	void sigReloadConfig();
	void sigReloadLevels(QString path);

	void setConnectionStatus(QString status);

	void setEnableAction(QString actionName, bool on);
	void setEnableAction(QStringList actionName, bool on);

	void sendControlCommand(QString rlsName, QVariantMap data);
	void sendSyncMessage(QString rlsName, QVariantMap data);
};

// ----------------------------------------------------------------------------

#endif //__CONTROL_H__