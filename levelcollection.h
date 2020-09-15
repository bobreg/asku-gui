#ifndef __LEVELCOLLECTION_H__
#define __LEVELCOLLECTION_H__

#include <QObject>
#include <QList>
#include <QStack>
#include <QPainter>

#include "../common/xmlfile.h"
#include "globalvar.h"
#include "levelstructure.h"
#include "levelfiles.h"
#include "actions.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------

class AskuLevelPainter;

//----------------------------------------------------------------------------------------------------------------

class AskuLevelCollection : public QObject
{
	Q_OBJECT

	bool m_needUpdate;

	QString baseName;
	QString zalName;
	QString errorName;
	QString warningName;
	QString currentName;
	QString m_connectionStatus;

	QStack<QString> levelStack;
	QMap<QString,AskuLevel*> levels;

	FunctionItems functions;

	void makeSupportLevels();
	QStringList levelNameList();

	inline AskuLevelPrimitive* existsLevelPrimitive(QString levelName, QString primitiveName);
	inline AskuLevel* existsLevel(QString levelName);
	inline AskuLevel* currentLevel();
	inline AskuLevel* warningLevel();
	inline AskuLevel* errorLevel();

	enum TripDirection {
		TripTop		= 0,
		TripDown	= 1,
		TripUp		= 2
	};

	QString findTrip(QString levelName, QString elementName);
	QStringList findEnter(QString levelName);
	QStringList findLeave(QString levelName);
	QStringList findClick(QString levelName, QString element);

	bool doTrip(TripDirection direction, QString levelName = QString());

	AskuConfig *m_config;
	AskuActions *m_actions;
	QString m_rlsName;
	QString m_litera;
	AskuRlsConfig m_rlsConfig;

	void refreshConnectionStatus();

public:

	AskuLevelCollection(QObject* parent);
	~AskuLevelCollection();

	void appendLevel(AskuLevel* level);
	void removeLevel(AskuLevel* level);
	void removeLevel(QString name);
	void removeAll();
	void cleanAll();

	bool loadFromPath(QString path);
	void clear();

	void levelUp();
	void levelTop(int showZal);

	void draw(AskuLevelPainter* painter);
	bool invalidate();
	bool needUpdate();
	void restoreSaved();

	bool mousePress(QPoint point);
	bool mouseMove(QPoint point);

	void setConfig(AskuConfig* config);
	void setActions(AskuActions *actions);

	inline QString rlsName() {
		return !m_rlsName.isEmpty() ? m_rlsName + "_" : m_rlsName;
	}
	inline void setRlsName(QString name) {
		m_rlsName = name;
	}

	inline QString rlsLitera() {
		return m_litera;
	}
	inline void setLitera(QString litera) {
		m_litera = litera;
	}

	qint32 processInfo(QVariantMap info);

	void sendRequest(QString command, QStringList parameters = QStringList());
	void sendFunction(QString command, QStringList parameters = QStringList());
	void executeFunction(QStringList function);

protected slots:
	void levelChanged();

signals:
	void error(qint32 errorCode, QString errorString);
	void changed();
	void setStatusWindowState(QString name, QString state);
	void sendControlCommand(QString rlsName, QVariantMap data);

public slots:
	void applyGraphic();
	void applyConfig();
	void applyActions();
	void invokeAction(QString action, QStringList parameters);

	void actionReloadLevels(QString levelPath);

	void requestRefresh();
	void requestReload();

	void setConnectionStatus(QString status);
};

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------

#endif //__LEVELCOLLECTION_H__
