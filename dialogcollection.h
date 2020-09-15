#ifndef __DIALOGCOLLECTION_H__
#define __DIALOGCOLLECTION_H__

#include "../common/dialog.h"
#include "config.h"

//----------------------------------------------------------------------------------------------------------------

typedef QMap<QString, AskuDialog*> AskuDialogMap;
class AskuActions;
class AskuConfig;

//----------------------------------------------------------------------------------------------------------------

class AskuDialogs : public QObject, public AskuDialogMap
{
	Q_OBJECT

	AskuConfig *m_config;
	AskuActions *m_actions;
	QString m_rlsName;
	AskuRlsConfig m_rlsConfig;

public:
	AskuDialogs(QObject * parent = 0, const QString & name = QString("AskuDialogs"));

	void insert(AskuDialog * dialog);

	void setConfig(AskuConfig* config);
	void setActions(AskuActions *actions);

	inline QString rlsName() const {
		return !m_rlsName.isEmpty() ? m_rlsName + "_" : m_rlsName;
	}
	inline void setRlsName(const QString & name) {
		m_rlsName = name;
	}

public slots:
	void exec(const QString & name);

	void show(const QString & name);
	void hide(const QString & name);
	void raise(const QString & name);
	void showOrHide(const QString & name);

	void setFont(const QFont & font);
	void setFont(const QString & name, const QFont & font);

	void applyGraphic();
	void applyConfig();
	void applyActions();
	void invokeAction(const QString & action, const QStringList & parameters);

	qint32 processInfo(const QString & name, const QVariantMap & info);

	void connected(quint32 numGpr);
	void disconnected(quint32 numGpr);

	void connectedRls();
	void disconnectedRls();

signals:
	void activateAction(QString name, QStringList parameters = QStringList());
};

//----------------------------------------------------------------------------------------------------------------

#endif //__DIALOGCOLLECTION_H__
