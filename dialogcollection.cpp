#include "../common/logger.h"
#include "dialogcollection.h"
#include "actions.h"
#include "settingsui.h"

//----------------------------------------------------------------------------------------------------------------
AskuDialogs::AskuDialogs(QObject * parent, const QString & name) : QObject(parent)
{
	if(!name.isEmpty())
		setObjectName(name);

	m_actions = NULL;
	clear();

	m_config = NULL;
	m_rlsName = QString();
	m_rlsConfig.clear();
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::applyGraphic()
{
	setFont(settingsUI->getDialogFont());
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::applyConfig()
{
	if(m_config)
		m_rlsConfig = m_config->makeRlsConfig();
	else
		m_rlsConfig.clear();
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::setConfig(AskuConfig* config)
{
	m_config = config;

	if(m_config)
	{
		connect(config, SIGNAL(updated()), this, SLOT(applyConfig()));

		applyConfig();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::setActions(AskuActions *actions)
{
	m_actions = actions;

	if(actions)
	{
		connect(actions, SIGNAL(updated()), this, SLOT(applyActions()));
		connect(actions, SIGNAL(invokeAction(QString,QStringList)), this, SLOT(invokeAction(QString,QStringList)));
		connect(this, SIGNAL(activateAction(QString,QStringList)), actions, SLOT(activateAction(QString,QStringList)));

		applyActions();
	}
}

//-------------------------------------------------------------------------------
void AskuDialogs::applyActions()
{
	
}

//-------------------------------------------------------------------------------
void AskuDialogs::invokeAction(const QString & action, const QStringList & parameters)
{
	Q_UNUSED(parameters);
//	LogInfo("%s::invokeAction : \"%s\"", qPrintable(objectName()), qPrintable(action));

	if(action.startsWith(rlsName() + "act_dialog"))
	{
		QString dlgName = action;
		dlgName = dlgName.remove(rlsName() + "act_");

		if(action.endsWith("_exec"))
		{
			dlgName = dlgName.remove("_exec");
			LogInfo("%s: Invoke action dialog \"%s\" exec", qPrintable(objectName()), qPrintable(dlgName));
			exec(dlgName);
		}
		else if(action.endsWith("_show"))
		{
			dlgName = dlgName.remove("_show");
			LogInfo("%s::Invoke action dialog \"%s\" show", qPrintable(objectName()), qPrintable(dlgName));
			show(dlgName);
		}
		else if(action.endsWith("_hide"))
		{
			dlgName = dlgName.remove("_hide");
			LogInfo("%s::Invoke action dialog \"%s\" hide", qPrintable(objectName()), qPrintable(dlgName));
			hide(dlgName);
		}
		else
		{
			LogInfo("%s::Invoke action dialog \"%s\" show or hide", qPrintable(objectName()), qPrintable(dlgName));
			showOrHide(dlgName);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::insert(AskuDialog * dialog)
{
	if(dialog)
	{
		dialog->setRlsName(m_rlsName, m_rlsConfig.text(m_rlsName));
		QMap::insert(dialog->objectName(), dialog);
		connect(dialog, SIGNAL(activateAction(QString,QStringList)), this, SIGNAL(activateAction(QString,QStringList)));
	}
	else
		LogError("%s: NULL dialog insert", qPrintable(objectName()));
}

//----------------------------------------------------------------------------------------------------------------
qint32 AskuDialogs::processInfo(const QString & name, const QVariantMap & info)
{
	AskuDialog *dlg = value(name);

	if(dlg)
		return dlg->processInfo(info);
	else
		LogError("%s::processInfo : \"%s\" not found", qPrintable(objectName()), qPrintable(name));

	return -1;
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::connected(quint32 numGpr)
{
	AskuDialogs::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		AskuDialog* dlg = it.value();

		if(dlg)
			dlg->connected(numGpr);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::disconnected(quint32 numGpr)
{
	AskuDialogs::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		AskuDialog* dlg = it.value();

		if(dlg)
			dlg->disconnected(numGpr);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::connectedRls()
{
	AskuDialogs::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		AskuDialog* dlg = it.value();

		if(dlg)
			dlg->connectedRls();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::disconnectedRls()
{
	AskuDialogs::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		AskuDialog* dlg = it.value();

		if(dlg)
			dlg->disconnectedRls();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::exec(const QString & name)
{
	AskuDialog *dlg = value(name);

	if(dlg)
		dlg->exec();
	else
		LogError("%s::exec : \"%s\" not found", qPrintable(objectName()), qPrintable(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::show(const QString & name)
{
	AskuDialog *dlg = value(name);

	if(dlg)
	{
		dlg->show();
//		dlg->raise();	//closed due to unexpected raise
		dlg->activateWindow();
	}
	else
		LogError("%s::show : \"%s\" not found", qPrintable(objectName()), qPrintable(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::hide(const QString & name)
{
	AskuDialog *dlg = value(name);

	if(dlg)
		dlg->hide();
	else
		LogError("%s::hide : \"%s\" not found", qPrintable(objectName()), qPrintable(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::raise(const QString & name)
{
	AskuDialog *dlg = value(name);

	if(dlg)
		dlg->raise();
	else
		LogError("%s::raise : \"%s\" not found", qPrintable(objectName()), qPrintable(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::showOrHide(const QString & name)
{
	AskuDialog *dlg = value(name);

	if(dlg)
		dlg->showOrHide();
	else
		LogError("%s::showOrHide : \"%s\" not found", qPrintable(objectName()), qPrintable(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::setFont(const QString & name, const QFont & font)
{
	AskuDialog *dlg = value(name);

	if(dlg)
		dlg->setFont(font);
	else
		LogError("%s::setFont : \"%s\" not found", qPrintable(objectName()), qPrintable(name));
}

//----------------------------------------------------------------------------------------------------------------
void AskuDialogs::setFont(const QFont & font)
{
	AskuDialogs::const_iterator it;

	for(it = constBegin(); it != constEnd(); ++it)
	{
		AskuDialog* dlg = it.value();

		if(dlg)
			dlg->setFont(font);
	}
}

//----------------------------------------------------------------------------------------------------------------
