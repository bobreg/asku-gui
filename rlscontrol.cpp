#include "../common/logger.h"
#include "rlscontrol.h"

//----------------------------------------------------------------------------------------------------------------
AskuRls::AskuRls()
{
	m_name = QString();
	m_scheme = QString();
	m_title = QString();
	m_litera = QString();
	m_index = 0;
	m_ip_gpr1 = QHostAddress();
	m_ip_gpr2 = QHostAddress();
	m_port_gpr1 = 0;
	m_port_gpr2 = 0;
}

//----------------------------------------------------------------------------------------------------------------
AskuRls::AskuRls(QString name, QString scheme, QString title, QString litera, quint32 index)
{
	m_name = name;
	m_scheme = scheme;
	m_title = title;
	m_litera = litera;
	m_index = index;
	m_ip_gpr1 = QHostAddress();
	m_ip_gpr2 = QHostAddress();
	m_port_gpr1 = 0;
	m_port_gpr2 = 0;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setName(QString name)
{
	m_name = name;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setSchemeFile(QString scheme)
{
	m_scheme = scheme;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setTitle(QString title)
{
	m_title = title;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setLitera(QString litera)
{
	m_litera = litera;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setIndex(quint32 index)
{
	m_index = index;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setNetwork(QString ip1, quint16 port1, QString ip2, quint16 port2)
{
	m_ip_gpr1 = QHostAddress(ip1);
	m_ip_gpr2 = QHostAddress(ip2);
	m_port_gpr1 = port1;
	m_port_gpr2 = port2;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setNetworkGpr1(QString ip, quint16 port)
{
	m_ip_gpr1 = QHostAddress(ip);
	m_port_gpr1 = port;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRls::setNetworkGpr2(QString ip, quint16 port)
{
	m_ip_gpr2 = QHostAddress(ip);
	m_port_gpr2 = port;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRls::name()
{
	return m_name;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRls::scheme()
{
	return m_scheme;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRls::title()
{
	return m_title;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRls::litera()
{
	return m_litera;
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuRls::index()
{
	return m_index;
}

//----------------------------------------------------------------------------------------------------------------
QHostAddress AskuRls::ipGpr1()
{
	return m_ip_gpr1;
}

//----------------------------------------------------------------------------------------------------------------
QHostAddress AskuRls::ipGpr2()
{
	return m_ip_gpr2;
}

//----------------------------------------------------------------------------------------------------------------
quint16 AskuRls::portGpr1()
{
	return m_port_gpr1;
}

//----------------------------------------------------------------------------------------------------------------
quint16 AskuRls::portGpr2()
{
	return m_port_gpr2;
}

//----------------------------------------------------------------------------------------------------------------
AskuRlsControl::AskuRlsControl(QObject * parent) : QObject(parent)
{
	clear();
}

//----------------------------------------------------------------------------------------------------------------
void AskuRlsControl::clear()
{
	m_rlsList.clear();
}

//----------------------------------------------------------------------------------------------------------------
void AskuRlsControl::setConfig(AskuConfig * config)
{
	if(!config)
		return;

	m_config = config;
	connect(config, SIGNAL(updated()), this, SLOT(applyConfig()));

	applyConfig();
}

//----------------------------------------------------------------------------------------------------------------
void AskuRlsControl::applyConfig()
{
	if(!m_config)
		return;

	clear();

	AskuRlsConfig cfg = m_config->makeRlsConfig();

	foreach(QVariant r, cfg)
	{
		QVariantMap rls = r.toMap();
		AskuRls * prls = appendRls(rls["name"].toString(), rls["level"].toString(), rls["text"].toString(), rls["litera"].toString(), rls["index"].toUInt());
		prls->setNetwork(rls["gpr1_ip"].toString(), rls["gpr1_port"].toUInt(), rls["gpr2_ip"].toString(), rls["gpr2_port"].toUInt());
	}
}

//----------------------------------------------------------------------------------------------------------------
AskuRls * AskuRlsControl::appendRls(QString name, QString config, QString title, QString litera, quint32 index)
{
	AskuRls * rls = new AskuRls(name, config, title, litera, index);
	m_rlsList[index] = rls;
	return rls;
}

//----------------------------------------------------------------------------------------------------------------
AskuRlsList AskuRlsControl::getRlsList()
{
	return m_rlsList;
}

//----------------------------------------------------------------------------------------------------------------
qint32 AskuRlsControl::getRlsIdByPeer(QHostAddress address, quint16 port)
{
	foreach(AskuRls *rls, m_rlsList)
		if(rls && ((rls->ipGpr1() == address && rls->portGpr1() == port) || (rls->ipGpr2() == address && rls->portGpr2() == port)))
			return rls->index();
	return idRlsIdUnknown;
}

//----------------------------------------------------------------------------------------------------------------
