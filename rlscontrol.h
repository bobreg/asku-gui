#ifndef __RLSCONTROL_H__
#define __RLSCONTROL_H__

#include <QObject>
#include <QHostAddress>
#include "config.h"

//----------------------------------------------------------------------------------------------------------------

enum AskuRlsIds {
	idRlsIdUnknown = -1
};

//----------------------------------------------------------------------------------------------------------------

class AskuRls
{
	QString m_name;
	QString m_scheme;
	QString m_title;
	QString m_litera;
	quint32 m_index;
	QHostAddress m_ip_gpr1;
	QHostAddress m_ip_gpr2;
	quint16 m_port_gpr1;
	quint16 m_port_gpr2;

public:
	AskuRls();
	AskuRls(QString name, QString scheme, QString title = QString(), QString litera = QString(), quint32 index = 0);

	void setName(QString name);
	void setSchemeFile(QString scheme);
	void setTitle(QString title);
	void setLitera(QString litera);
	void setIndex(quint32 index);
	void setNetwork(QString ip1, quint16 port1, QString ip2, quint16 port2);
	void setNetworkGpr1(QString ip, quint16 port);
	void setNetworkGpr2(QString ip, quint16 port);

	QString name();
	QString scheme();
	QString title();
	QString litera();
	quint32 index();
	QHostAddress ipGpr1();
	QHostAddress ipGpr2();
	quint16 portGpr1();
	quint16 portGpr2();
};

//----------------------------------------------------------------------------------------------------------------

typedef QMap<quint32, AskuRls*> AskuRlsList;

//----------------------------------------------------------------------------------------------------------------

class AskuRlsControl : public QObject
{
	Q_OBJECT

	AskuRlsList m_rlsList;
	AskuConfig *m_config;

public:
	AskuRlsControl(QObject * parent = 0);

	AskuRls * appendRls(QString name, QString config, QString title = QString(), QString litera = QString(), quint32 index = 0);
	void appendRls(AskuRls * rls);

	void clear();

	void setConfig(AskuConfig * config);

	AskuRlsList getRlsList();

	qint32 getRlsIdByPeer(QHostAddress address, quint16 port);

public slots:
	void applyConfig();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __RLSCONTROL_H__
