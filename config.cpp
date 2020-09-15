#include <QObject>
#include "../common/logger.h"
#include "config.h"
#include "globalvar.h"
#include "xpmset.h"

//----------------------------------------------------------------------------------------------------------------
AskuRlsConfig::AskuRlsConfig() : QVariantList()
{
	m_index = -1;
	clear();
}

//----------------------------------------------------------------------------------------------------------------
AskuRlsConfig::AskuRlsConfig(const AskuRlsConfig & cfg) : QVariantList()
{
	setRlsConfig(cfg);
}

//----------------------------------------------------------------------------------------------------------------
void AskuRlsConfig::setCurrentIndex(qint32 index)
{
	if(isIndexValid(index))
		m_index = index;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuRlsConfig::isIndexValid(qint32 index) const
{
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["index"] == index)
			return true;
	}

	return false;
}

//----------------------------------------------------------------------------------------------------------------
void AskuRlsConfig::setRlsConfig(const AskuRlsConfig & cfg)
{
	clear();

	m_index = cfg.currentIndex();

	AskuRlsConfig::const_iterator it;

	for(it = cfg.constBegin(); it != cfg.constEnd(); ++it)
		append(*it);
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRlsConfig::name(qint32 index) const
{
	QString result;
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["index"] == index)
		{
			result = map["name"].toString();
			break;
		}
	}

	return result;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRlsConfig::text(qint32 index) const
{
	QString result;
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["index"] == index)
		{
			result = map["text"].toString();
			break;
		}
	}

	return result;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRlsConfig::level(qint32 index) const
{
	QString result;
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["index"] == index)
		{
			result = map["level"].toString();
		}
	}

	return result;
}

//----------------------------------------------------------------------------------------------------------------
qint32 AskuRlsConfig::index(const QString & name) const
{
	qint32 result = -1;
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["name"] == name)
		{
			bool ok = false;
			qint32 res = map["index"].toUInt(&ok);

			if(ok)
			{
				result = res;
				break;
			}
		}
	}

	return result;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRlsConfig::text(const QString & name) const
{
	QString result;
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["name"] == name)
		{
			result = map["text"].toString();
			break;
		}
	}

	return result;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuRlsConfig::level(const QString & name) const
{
	QString result;
	AskuRlsConfig::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		const QVariantMap & map = (*it).toMap();

		if(map["name"] == name)
		{
			result = map["level"].toString();
		}
	}

	return result;
}

//----------------------------------------------------------------------------------------------------------------
AskuConfigFile::AskuConfigFile(const QString & filename) : XmlFile(), m_default(false)
{
	loadFile(filename);

	if(!wasError())
		makeRlsConfig(true);
}

//----------------------------------------------------------------------------------------------------------------
bool AskuConfigFile::loadFile(const QString & filename)
{
	LogInfo("Loading asku config: %s", qPrintable(filename));

	bool result = load(filename);
	if(wasError())
		LogError("Error loading asku config: %s", qPrintable(lastErrorMessage()));

	return result;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuConfigFile::checkContent()
{
	if(doctype().name() != "ASKU_config")
	{
		LogError("ASKU_config: not an ASKU_config");
		return false;
	}

	if(documentElement().tagName() != "config")
	{
		LogError("ASKU_config: no config tag");
		return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------
AskuActionList AskuConfigFile::makeAction(QDomElement & tag_action, QObject * parent)
{
	AskuActionList actionList;

	QString a_global_name = tag_action.attribute("name","");
	QString a_name = a_global_name;
	QString a_global_group = tag_action.attribute("group","");
	QString a_group = a_global_group;
	QString a_checkable = tag_action.attribute("checkable","false");
	QString a_global = tag_action.attribute("global","false");
	QString a_addname = tag_action.attribute("addname", "false");
	QString a_name_pixmap = QString();
	QString a_text_lang = QString();
	QString a_text = QString();
	QString a_shortcut = QString();
	QString a_tooltip_lang = QString();
	QString a_tooltip = QString();

	QDomElement tag_pixmap = tag_action.firstChildElement("pixmap");
	if(!tag_pixmap.isNull())
	{
		a_name_pixmap = tag_pixmap.attribute("name","");
		if(a_name_pixmap.isEmpty() || !m_pixmaps.contains(a_name_pixmap))
		{
			LogError("ASKU_config: no pixmap (%s) found", qPrintable(a_name_pixmap));
		}
	}

	QDomElement tag_text = tag_action.firstChildElement("text");
	if(!tag_text.isNull())
	{
		a_text_lang = tag_text.attribute("lang", "ru");
		a_text = textFromElement(tag_text,"\n");
	}

	QDomElement tag_shortcut = tag_action.firstChildElement("shortcut");
	if(!tag_shortcut.isNull())
	{
		a_shortcut = textFromElement(tag_shortcut,"\n");
	}

	QDomElement tag_tooltip = tag_action.firstChildElement("tooltip");
	if(!tag_tooltip.isNull())
	{
		a_tooltip_lang = tag_tooltip.attribute("lang", "ru");
		a_tooltip = textFromElement(tag_tooltip,"\n");
	}

	bool global = (a_global == "true" || m_rlsConfig.isEmpty());
	quint32 count = global ? 1 : m_rlsConfig.count();

	for(quint32 i = 0; i < count; i++)
	{
		QAction* action = new QAction(parent);
		QVariantMap rls = m_rlsConfig[i].toMap();

		if(!global && !rls["name"].toString().isEmpty())
		{
			a_name = QString("%1_%2").arg(rls["name"].toString()).arg(a_global_name);
			if(!a_global_group.isEmpty())
				a_group = QString("%1_%2").arg(rls["name"].toString()).arg(a_global_group);
		}
		if(!a_name.isEmpty())
		{
			QAction *act = parent->findChild<QAction*>(a_name);
			if(act != NULL)
			{
				LogError("ASKU_config: duplicate action (%s) found", qPrintable(a_name));
				act->deleteLater();
			}

			action->setObjectName(a_name);
			LogInfo("ASKU_config: make action (%s)", qPrintable(a_name));
		}
		else
		{
			LogError("ASKU_config: empty action name found");
		}

		if(!a_group.isEmpty())
		{
			QActionGroup *group = parent->findChild<QActionGroup*>(a_group);
			if(group == NULL)
			{
				group = new QActionGroup(parent);
				group->setObjectName(a_group);
				LogInfo("ASKU_config: make action group (%s) append (%s)", qPrintable(a_group), qPrintable(a_name));
			}
			else
			{
				LogInfo("ASKU_config: action group (%s) append (%s)", qPrintable(a_group), qPrintable(a_name));
			}
			group->addAction(action);
		}

		if(!a_checkable.isEmpty())
			action->setCheckable(a_checkable == "true");

		if(!a_name_pixmap.isEmpty() && m_pixmaps.contains(a_name_pixmap))
			action->setIcon(m_pixmaps[a_name_pixmap]);

		if(!a_text.isEmpty())
		{
			if(a_addname == "true")
				action->setText(a_text + " " + rls["text"].toString());
			else
				action->setText(a_text);
		}

		if(!a_shortcut.isEmpty())
			action->setShortcut(a_shortcut);

		if(!a_tooltip.isEmpty())
			action->setToolTip(a_tooltip);

		actionList << action;
	}

	return actionList;
}

//----------------------------------------------------------------------------------------------------------------
AskuActionList AskuConfigFile::makeDefaultActions(QObject *parent)
{
	AskuActionList actionList;

	QAction *exitAct = new QAction("Выход", parent);
	exitAct->setObjectName("act_quit");
	exitAct->setShortcut(QObject::tr("Ctrl+Q"));

	QAction *reloadAct = new QAction("Перезагрузить конфигурацию", parent);
	reloadAct->setObjectName("act_reload_config");
	reloadAct->setShortcut(QObject::tr("Ctrl+T"));

	actionList << reloadAct << exitAct;

	return actionList;
}

//----------------------------------------------------------------------------------------------------------------
AskuActionList AskuConfigFile::makeActions(QObject *parent)
{
	AskuActionList actionList;

	if(wasError())
	{
		LogError("ASKU_config: set default action list");
		m_default = true;
		return makeDefaultActions(parent);
	}

	bool found = false;
	QDomElement tag_actions = documentElement().firstChildElement("actions");
	if(!tag_actions.isNull())
	{
		for(QDomElement tag_action = tag_actions.firstChildElement("action"); !tag_action.isNull(); tag_action = tag_action.nextSiblingElement("action"))
		{
			found = true;
			AskuActionList newActions = makeAction(tag_action, parent);
			actionList << newActions;
 		}
	}

	if(!found)
	{
		LogError("ASKU_config: no actions tag found");
	}

	return actionList;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuConfigFile::makeMainWindowActions(const QString & rlsName)
{
	QStringList nameList;

	if(wasError())
		return nameList;

	QDomElement main = documentElement().firstChildElement("main");
	if(!main.isNull())
	{
		QDomElement actions = main.firstChildElement("actions");
		if(!actions.isNull())
		{
			for(QDomElement action = actions.firstChildElement("action"); !action.isNull(); action = action.nextSiblingElement("action"))
			{
				QString a_lang = action.attribute("lang", "ru");
				QString a_name = action.attribute("name", "");
				QString a_global = action.attribute("global", "false");

				if(a_global == "true" || m_rlsConfig.isEmpty() || a_name.isEmpty() || rlsName.isEmpty())
					nameList << a_name;
				else
					nameList << QString("%1_%2").arg(rlsName).arg(a_name);
			}
 		}
	}

	return nameList;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuConfigFile::makeMainContextMenuActions(const QString & rlsName)
{
	QStringList nameList;

	if(wasError())
		return nameList;

	QDomElement main = documentElement().firstChildElement("main");
	if(!main.isNull())
	{
		QDomElement actions = main.firstChildElement("menu");
		if(!actions.isNull())
		{
			for(QDomElement action = actions.firstChildElement("action"); !action.isNull(); action = action.nextSiblingElement("action"))
			{
				QString a_lang = action.attribute("lang", "ru");
				QString a_name = action.attribute("name", "");
				QString a_global = action.attribute("global", "false");

				if(a_global == "true" || m_rlsConfig.isEmpty() || a_name.isEmpty() || rlsName.isEmpty())
					nameList << a_name;
				else
					nameList << QString("%1_%2").arg(rlsName).arg(a_name);
			}
 		}
	}

	return nameList;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuConfigFile::makeMainToolBarActions(const QString & rlsName)
{
	QStringList nameList;

	if(wasError())
		return nameList;

	QDomElement main = documentElement().firstChildElement("main");
	if(!main.isNull())
	{
		QDomElement actions = main.firstChildElement("toolbar");
		if(!actions.isNull())
		{
			for(QDomElement action = actions.firstChildElement("action"); !action.isNull(); action = action.nextSiblingElement("action"))
			{
				QString a_lang = action.attribute("lang", "ru");
				QString a_name = action.attribute("name", "");
				QString a_global = action.attribute("global", "false");

				if(a_global == "true" || m_rlsConfig.isEmpty() || a_name.isEmpty() || rlsName.isEmpty())
					nameList << a_name;
				else
					nameList << QString("%1_%2").arg(rlsName).arg(a_name);
			}
 		}
	}

	return nameList;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuConfigFile::makeSmallWindowActions()
{
	QStringList nameList;

	if(wasError())
		return nameList;

	QDomElement main = documentElement().firstChildElement("status");
	if(!main.isNull())
	{
		QDomElement actions = main.firstChildElement("actions");
		if(!actions.isNull())
		{
			for(QDomElement action = actions.firstChildElement("action"); !action.isNull(); action = action.nextSiblingElement("action"))
			{
				QString a_lang = action.attribute("lang", "ru");
				QString a_name = action.attribute("name", "");
				QString a_global = action.attribute("global", "false");

				if(a_global == "true" || m_rlsConfig.isEmpty())
					nameList << a_name;
				else
				{
					AskuRlsConfig::const_iterator it;
					for(it = m_rlsConfig.constBegin(); it != m_rlsConfig.constEnd(); ++it)
					{
						const QVariantMap & rls = (*it).toMap();
						if(!rls["name"].toString().isEmpty())
							nameList << QString("%1_%2").arg(rls["name"].toString()).arg(a_name);
						else
							nameList << a_name;
					}
				}
			}
 		}
	}

	return nameList;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuConfigFile::makeDefaultSmallContextMenuActions()
{
	return QStringList() << "act_reload_config" << NULL << "act_quit";
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuConfigFile::makeSmallContextMenuActions()
{
	QStringList nameList;

	if(wasError())
	{
		m_default = true;
		return makeDefaultSmallContextMenuActions();
	}

	QDomElement main = documentElement().firstChildElement("status");
	if(!main.isNull())
	{
		QDomElement actions = main.firstChildElement("menu");
		if(!actions.isNull())
		{
			for(QDomElement action = actions.firstChildElement("action"); !action.isNull(); action = action.nextSiblingElement("action"))
			{
				QString a_lang = action.attribute("lang", "ru");
				QString a_name = action.attribute("name", "");
				QString a_global = action.attribute("global", "false");

				if(a_global == "true" || m_rlsConfig.isEmpty() || a_name.isEmpty())
					nameList << a_name;
				else
				{
					AskuRlsConfig::const_iterator it;
					for(it = m_rlsConfig.constBegin(); it != m_rlsConfig.constEnd(); ++it)
					{
						const QVariantMap & rls = (*it).toMap();
						if(!rls["name"].toString().isEmpty())
							nameList << QString("%1_%2").arg(rls["name"].toString()).arg(a_name);
						else
							nameList << a_name;
					}
				}
			}
 		}
	}

	return nameList;
}

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindowConfig AskuConfigFile::makeDefaultSmallWindowConfig()
{
	AskuSmallWindowConfig config;

	QList<QVariant> rowList;
	QList<QVariant> colList;
	QMap<QString, QVariant> element;

	element["type"] = "user";
	element["name"] = "message";
	element["state"] = "disabled";
	element["text"] = "Ошибка конфигурации";

	colList << QVariant(element);
	rowList << QVariant(colList);
	config["rows"] = QVariant(rowList);

	return config;
}

//----------------------------------------------------------------------------------------------------------------
QVariantList AskuConfigFile::makeSmallWindowRow(QDomElement & tag_row, QVariantMap rls)
{
	QVariantList colList;

	for(QDomElement tag_element = tag_row.firstChildElement("element"); !tag_element.isNull(); tag_element = tag_element.nextSiblingElement("element"))
	{
		QVariantMap element;

		QString a_type = tag_element.attribute("type", "");
		QString a_name = tag_element.attribute("name", "");
		QString a_state = tag_element.attribute("state", "");

		element["type"] = a_type;
		if(rls.contains("name") && !rls["name"].toString().isEmpty())
			element["name"] = QString("%1_%2").arg(rls["name"].toString()).arg(a_name);
		else
			element["name"] = a_name;
		element["state"] = a_state;

		QDomElement tag_text = tag_element.firstChildElement("text");
		if(!tag_text.isNull())
		{
			QString a_lang = tag_text.attribute("lang", "ru");
			QString a_text = textFromElement(tag_text,"\n");
			if(a_name == "name" && rls.contains("name") && !rls["text"].toString().isEmpty())
				element["text"] = rls["text"].toString();
			else
				element["text"] = a_text;
		}

		colList << QVariant(element);
	}

	return colList;
}

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindowConfig AskuConfigFile::makeSmallWindowConfig()
{
	AskuSmallWindowConfig config;

	if(wasError())
	{
		LogError("AskuSmallWindowConfig: Error loading file (%s)", qPrintable(lastErrorMessage()));
		return makeDefaultSmallWindowConfig();
	}

	QDomElement tag_status = documentElement().firstChildElement("status");
	if(!tag_status.isNull())
	{
		QString a_name = tag_status.attribute("name", "");
		QString a_align = tag_status.attribute("align", "");
		QString a_width = tag_status.attribute("width", "");
		QString a_height = tag_status.attribute("height", "");
		QString a_x = tag_status.attribute("x", "");
		QString a_y = tag_status.attribute("y", "");

		config["name"] = a_name;
		config["align"] = a_align;
		config["width"] = a_width;
		config["height"] = a_height;
		config["x"] = a_x;
		config["y"] = a_y;

		QDomElement tag_header = tag_status.firstChildElement("header");
		if(!tag_header.isNull())
		{
			QString a_lang = tag_header.attribute("lang", "ru");
			QString a_text = textFromElement(tag_header,"\n");
			config["header"] = a_text;
 		}
 		else
 		{
			LogError("AskuSmallWindowConfig: no header");
		}

		QDomElement tag_pixmap = tag_status.firstChildElement("pixmap");
		if(!tag_pixmap.isNull())
		{
			QString a_pixmap = tag_pixmap.attribute("name", "");
			config["pixmap"] = a_pixmap;
 		}
 		else
 		{
			LogError("AskuSmallWindowConfig: no pixmap");
		}

		QDomElement tag_menu = tag_status.firstChildElement("menu");
		if(!tag_menu.isNull())
		{
			QString a_name = tag_menu.attribute("name", "");
			config["menu_name"] = a_name;
 		}
 		else
 		{
			LogError("AskuSmallWindowConfig: no menu");
		}

		QVariantList rowListGlobal;

		for(QDomElement tag_row = tag_status.firstChildElement("row"); !tag_row.isNull(); tag_row = tag_row.nextSiblingElement("row"))
		{
			QString a_global = tag_row.attribute("global", "false");

			if(a_global == "true")
			{
				QVariantList colList = makeSmallWindowRow(tag_row);
				rowListGlobal << QVariant(colList);
			}
		}

		QVariantList rowList;
		AskuRlsConfig::const_iterator it;

		for(it = m_rlsConfig.constBegin(); it != m_rlsConfig.constEnd(); ++it)
		{
			const QVariantMap & rls = (*it).toMap();

			for(QDomElement tag_row = tag_status.firstChildElement("row"); !tag_row.isNull(); tag_row = tag_row.nextSiblingElement("row"))
			{
				QString a_global = tag_row.attribute("global", "false");

				if(a_global == "false")
				{
					QVariantList colList = makeSmallWindowRow(tag_row, rls);
					rowList << QVariant(colList);
				}
			}
		}

		rowList << rowListGlobal;
		config["rows"] = QVariant(rowList);
	}

	return config;
}

//----------------------------------------------------------------------------------------------------------------
AskuMainWindowConfig AskuConfigFile::makeMainWindowConfig()
{
	AskuMainWindowConfig config;

	if(wasError())
	{
		LogError("AskuMainWindowConfig: Error loading file (%s)", qPrintable(lastErrorMessage()));
		return config;
	}

	QDomElement tag_status = documentElement().firstChildElement("main");
	if(!tag_status.isNull())
	{
		QString a_name = tag_status.attribute("name", "");
		config["name"] = a_name;

		QDomElement tag_header = tag_status.firstChildElement("header");
		if(!tag_header.isNull())
		{
			QString a_lang = tag_header.attribute("lang", "ru");
			QString a_text = textFromElement(tag_header,"\n");
			config["header"] = a_text;
 		}
 		else
 		{
			LogError("AskuMainWindowConfig: no header");
		}

		QDomElement tag_pixmap = tag_status.firstChildElement("pixmap");
		if(!tag_pixmap.isNull())
		{
			QString a_pixmap = tag_pixmap.attribute("name", "");
			config["pixmap"] = a_pixmap;
 		}
 		else
 		{
			LogError("AskuMainWindowConfig: no pixmap");
		}

		QDomElement tag_central = tag_status.firstChildElement("central");
		if(!tag_central.isNull())
		{
			QString a_name = tag_central.attribute("name", "");
			config["central_name"] = a_name;
 		}
 		else
 		{
			LogError("AskuMainWindowConfig: no central");
		}

		QDomElement tag_toolbar = tag_status.firstChildElement("toolbar");
		if(!tag_toolbar.isNull())
		{
			QString a_name = tag_toolbar.attribute("name", "");
			config["toolbar_name"] = a_name;
 		}
 		else
 		{
			LogError("AskuMainWindowConfig: no toolbar");
		}

		QDomElement tag_menu = tag_status.firstChildElement("menu");
		if(!tag_menu.isNull())
		{
			QString a_name = tag_menu.attribute("name", "");
			config["menu_name"] = a_name;
 		}
 		else
 		{
			LogError("AskuMainWindowConfig: no menu");
		}

		QDomElement tag_statusbar = tag_status.firstChildElement("statusbar");
		if(!tag_statusbar.isNull())
		{
			QString a_name = tag_statusbar.attribute("name", "");
			config["statusbar_name"] = a_name;
 		}
 		else
 		{
			LogError("AskuMainWindowConfig: no statusbar");
		}
	}

	return config;
}

//----------------------------------------------------------------------------------------------------------------
AskuRlsConfig AskuConfigFile::makeRlsConfig(bool force)
{
	if(!force && !m_rlsConfig.isEmpty())
		return m_rlsConfig;

	AskuRlsConfig config;

	if(wasError())
	{
		LogError("AskuRlsConfig: Error loading file (%s)", qPrintable(lastErrorMessage()));
		return config;
	}

	QVariantMap rls_config;

	for(QDomElement tag_rls = documentElement().firstChildElement("rls"); !tag_rls.isNull(); tag_rls = tag_rls.nextSiblingElement("rls"))
	{
		QString a_name = tag_rls.attribute("name", "");
		QString a_level = tag_rls.attribute("config", "");
		QString a_litera = tag_rls.attribute("litera", "");
		QString a_index = tag_rls.attribute("index", "");
		rls_config["name"] = a_name;
		rls_config["level"] = a_level;
		rls_config["litera"] = a_litera;
		rls_config["index"] = a_index;

		QDomElement tag_text = tag_rls.firstChildElement("text");
		if(!tag_text.isNull())
		{
			QString a_lang = tag_text.attribute("lang", "ru");
			QString a_text = textFromElement(tag_text,"\n");
			rls_config["text"] = a_text;
 		}
 		else
 		{
			LogError("AskuRlsControlConfig: no rls name");
		}

		bool found = false;
		for(QDomElement tag_gpr = tag_rls.firstChildElement("gpr"); !tag_gpr.isNull(); tag_gpr = tag_gpr.nextSiblingElement("gpr"))
		{
			QString a_id = tag_gpr.attribute("index", "0");
			QString a_ip = tag_gpr.attribute("ip", "0.0.0.0");
			QString a_port = tag_gpr.attribute("port", "0");

			if(a_id == "1")
			{
				rls_config["gpr1_ip"] = a_ip;
				rls_config["gpr1_port"] = a_port;
				found = true;
			}
			else if(a_id == "2")
			{
				rls_config["gpr2_ip"] = a_ip;
				rls_config["gpr2_port"] = a_port;
				found = true;
			}
			else
			{
				LogError("AskuRlsControlConfig: incorrect gpr index");
			}
		}
		if(!found)
		{
			LogError("AskuRlsControlConfig: no gpr found");
		}

		config << rls_config;
	}

	m_rlsConfig = config;
	return config;
}

//----------------------------------------------------------------------------------------------------------------
AskuConfig::AskuConfig(const QString & filename, QObject * parent) : QObject(parent), AskuConfigFile(filename)
{
	m_filename = filename;
}

//----------------------------------------------------------------------------------------------------------------
AskuConfig::~AskuConfig()
{
}

//----------------------------------------------------------------------------------------------------------------
void AskuConfig::reload()
{
	loadFile(m_filename);

	if(!wasError())
		makeRlsConfig(true);

	emit updated();
}

//----------------------------------------------------------------------------------------------------------------
