#include <QMenu>
#include <QToolBar>
#include "../common/logger.h"
#include "actions.h"
#include "globalvar.h"
#include "xpmset.h"

//----------------------------------------------------------------------------------------------------------------
AskuActions::AskuActions(QObject * parent) : AskuActionMap(), m_mapper(this)
{
	m_parent = parent;
	m_config = NULL;
	clear();

	connect(&m_mapper, SIGNAL(mapped(const QString &)), this, SLOT(slotInvokeAction(const QString &)));
}

//----------------------------------------------------------------------------------------------------------------
AskuActions::~AskuActions()
{
	clearActions();
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::clearActions()
{
	if(!isEmpty())
	{
		qDeleteAll(*this);
		clear();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::applyConfig()
{
	if(!m_config)
		return;

	clearActions();

	AskuActionList actionList = m_config->makeActions(this);

	foreach(QAction* action, actionList)
	{
		insert(action->objectName(), action);
		m_mapper.setMapping(action, action->objectName());
		connect(action, SIGNAL(triggered()), &m_mapper, SLOT(map()));
	}

	emit updated();
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::setConfig(AskuConfig* config)
{
	if(!config)
		return;

	m_config = config;
	connect(config,SIGNAL(updated()),this,SLOT(applyConfig()));

	applyConfig();
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::addActions(QWidget *parent, QWidget *child, QStringList nameActions)
{
	if(child)
	{
		QMenu *menu = qobject_cast<QMenu*>(child);
		if(menu)
			menu->clear();

		QToolBar *toolbar = qobject_cast<QToolBar*>(child);
		if(toolbar)
			toolbar->clear();
	}

	AskuActionList actionList = makeActionList(nameActions);

	foreach(QAction* action, actionList)
	{
		if(action != NULL)
		{
			if(child)
			{
				QMenu *menu = qobject_cast<QMenu*>(child);
				if(menu)
					menu->addAction(action);

				QToolBar *toolbar = qobject_cast<QToolBar*>(child);
				if(toolbar)
					toolbar->addAction(action);
			}

			if(parent)
				parent->addAction(action);
		}
		else
		{
			if(child)
			{
				QMenu *menu = qobject_cast<QMenu*>(child);
				if(menu)
				{
					menu->addSeparator();
					continue;
				}
				QToolBar *toolbar = qobject_cast<QToolBar*>(child);
				if(toolbar)
				{
					toolbar->addSeparator();
					continue;
				}
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
AskuActionList AskuActions::makeActionList(QStringList nameActions)
{
	AskuActionList actionList;

	foreach(QString nameAction, nameActions)
	{
		if(!nameAction.isEmpty())
		{
			QAction * action = value(nameAction);
			if(!action)
			{
				LogError("AskuActions: no action for name (%s)", qPrintable(nameAction));
			}
			else
			{
				actionList << action;
			}
		}
		else
		{
			actionList << NULL;
		}
	}

	return actionList;
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::slotInvokeAction(const QString & name)
{
//	LogInfo("AskuActions::slotInvokeAction \"%s\"", qPrintable(name));
	emit invokeAction(QString(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::setEnableAction(QStringList actionNames, bool on)
{
	foreach(QString name, actionNames)
		setEnableAction(name, on);
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::setEnableAction(QString nameAction, bool on)
{
	QAction * action = value(nameAction);
	if(!action)
	{
		LogError("AskuActions: no action for name (%s)", qPrintable(nameAction));
	}
	else
	{
//		LogInfo("AskuActions: action (%s) enable %d", qPrintable(nameAction), on);
		action->setEnabled(on);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuActions::activateAction(QString name, QStringList parameters)
{
//	LogInfo("AskuActions::activateAction \"%s\"", qPrintable(name));
	emit invokeAction(name, parameters);
}

//----------------------------------------------------------------------------------------------------------------
