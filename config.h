#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <QObject>
#include <QVariant>
#include <QAction>
#include "../common/xmlfile.h"

//----------------------------------------------------------------------------------------------------------------

typedef QMap<QString, QVariant> AskuSmallWindowConfig, AskuMainWindowConfig;
typedef QList<QAction*> AskuActionList;
typedef QMap<QString, QVariant> AskuConfigMap;

//----------------------------------------------------------------------------------------------------------------

class AskuRlsConfig : public QVariantList
{
	qint32 m_index;

public:
	AskuRlsConfig();
	AskuRlsConfig(const AskuRlsConfig & cfg);

	qint32 currentIndex() const {
		return m_index;
	}

	void setCurrentIndex(qint32 index);
	bool isIndexValid(qint32 index) const;

	void setRlsConfig(const AskuRlsConfig & cfg);

	QString name(qint32 index = -1) const;
	QString text(qint32 index = -1) const;
	QString level(qint32 index = -1) const;

	qint32 index(const QString & name) const;
	QString text(const QString & name) const;
	QString level(const QString & name) const;
};

//----------------------------------------------------------------------------------------------------------------

class AskuConfigFile : public XmlFile
{
	AskuRlsConfig m_rlsConfig;
	bool m_default;

	AskuActionList makeAction(QDomElement & root, QObject * parent = 0);
	QVariantList makeSmallWindowRow(QDomElement & tag_row, QVariantMap rls = QVariantMap());

	virtual bool checkContent();

public:
	AskuConfigFile(const QString & filename);

	bool loadFile(const QString & filename);

	bool isDefault() const {
		return m_default;
	}

	AskuActionList makeActions(QObject *parent = 0);
	AskuActionList makeDefaultActions(QObject *parent = 0);

	QStringList makeMainWindowActions(const QString & rlsName);
	QStringList makeMainContextMenuActions(const QString & rlsName);
	QStringList makeMainToolBarActions(const QString & rlsName);
	QStringList makeSmallWindowActions();
	QStringList makeSmallContextMenuActions();
	QStringList makeDefaultSmallContextMenuActions();

	AskuSmallWindowConfig makeSmallWindowConfig();
	AskuSmallWindowConfig makeDefaultSmallWindowConfig();
	AskuMainWindowConfig makeMainWindowConfig();
	AskuRlsConfig makeRlsConfig(bool force = false);
};

//----------------------------------------------------------------------------------------------------------------

class AskuConfig : public QObject, public AskuConfigFile
{
	Q_OBJECT

	QString m_filename;

public:
	AskuConfig(const QString & filename, QObject *parent = 0);
	~AskuConfig();

public slots:
	void reload();

signals:
	void updated();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __CONFIG_H__
