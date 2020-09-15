#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include <QObject>
#include <QAction>
#include <QWidget>
#include <QSignalMapper>
#include "config.h"

//----------------------------------------------------------------------------------------------------------------

typedef QList<QAction*> AskuActionList;
typedef QMap<QString, QAction*> AskuActionMap;

//----------------------------------------------------------------------------------------------------------------

class AskuActions : public QObject, public AskuActionMap
{
	Q_OBJECT

	QSignalMapper m_mapper;
	QObject *m_parent;
	AskuConfig *m_config;

public:
	AskuActions(QObject *parent = 0);
	~AskuActions();

	void addActions(QWidget* parent, QWidget* child, QStringList nameActionList);
	AskuActionList makeActionList(QStringList nameActions);
	void clearActions();

	void setConfig(AskuConfig* config);

private slots:
	void slotInvokeAction(const QString & name);

public slots:
	void applyConfig();

	void setEnableAction(QString name, bool on);
	void setEnableAction(QStringList nams, bool on);

	void activateAction(QString name, QStringList parameters = QStringList());

signals:
	void invokeAction(QString name, QStringList parameters = QStringList());
	void updated();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __ACTIONS_H__
