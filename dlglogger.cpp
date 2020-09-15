#include "globalvar.h"
#include "dlglogger.h"
#include "../common/module.h"

// ------------------------------------------------------------------
DlgLogger::DlgLogger(QWidget *parent) : AskuDialog("dialog_logger", parent)
{
	ui.setupUi(this);

	setActive(IDGPR1, false);
	setActive(IDGPR2, false);

	if(globalLog)
		verifyButtons(IDPPV, globalLog->getLogOutConsole(), globalLog->getLogOutFile(), globalLog->getLogLevel());
}

// ------------------------------------------------------------------
DlgLogger::~DlgLogger()
{
}

// ------------------------------------------------------------------
void DlgLogger::showEvent(QShowEvent * event)
{
	sendRefreshAction();
	event->accept();
}

// ------------------------------------------------------------------
void DlgLogger::hideEvent(QHideEvent * event)
{
	event->accept();
}

// ------------------------------------------------------------------
void DlgLogger::on_pushClose_clicked()
{
	hide();
}

// ------------------------------------------------------------------
void DlgLogger::sendRefreshAction()
{
	sendAction(IDGPR1, "refreshLogger");
	sendAction(IDGPR2, "refreshLogger");
}

// ------------------------------------------------------------------
void DlgLogger::makeSet(quint32 n_gpr, bool console, bool file, LogLevels level)
{
	sendAction(n_gpr, "setLogger", QStringList() << QString::number(console) << QString::number(file) << QString::number((qulonglong)level,16));
}

// ------------------------------------------------------------------
void DlgLogger::on_pushSet_clicked()
{
	bool console = false, file = false;
	LogLevels levels = 0;

	getButtons(IDGPR1, console, file, levels);
	makeSet(IDGPR1, console, file, levels);

	getButtons(IDGPR2, console, file, levels);
	makeSet(IDGPR2, console, file, levels);

	getButtons(IDPPV, console, file, levels);

	if(globalLog)
	{
		globalLog->setLogOutConsole(console);
		globalLog->setLogOutFile(file);
		globalLog->setLogLevel(levels);

		m_globaldata.log.level = levels;
		m_globaldata.log.console = console;
		m_globaldata.log.file = file;
	}
}

// ------------------------------------------------------------------
void DlgLogger::sendAction(quint32 toGpr, QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "svc_module";
	data["ModuleFrom"] = objectName();
	data["ToGprId"] = toGpr;
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

// ------------------------------------------------------------------
qint32 DlgLogger::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgLogger: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "ASKU_MODULE_LOGGER")
	{
		if(data.contains("Logger"))
		{
			QVariantMap values = data["Logger"].toMap();
			if(values.isEmpty())
			{
				LogError("DlgLogger: empty values");
				return result;
			}

			bool console     = (bool)values["console"].toString().toUInt();
			bool file        = (bool)values["file"].toString().toUInt();
			LogLevels levels = (qulonglong)values["levels"].toString().toULongLong(0,16);

			bool ok = false;
			quint32 numGpr = data["GprId"].toUInt(&ok);
			if(ok && numGpr == IDGPR1)
				verifyButtons(IDGPR1, console, file, levels);
			if(ok && numGpr == IDGPR2)
				verifyButtons(IDGPR2, console, file, levels);
		}

		result = AskuModule::CommandSuccess;
	}

	return result;
}

// ------------------------------------------------------------------
void DlgLogger::setCheck(QString name, bool checked, bool on)
{
	QCheckBox *check = findChild<QCheckBox*>(name);
	if(check)
	{
		check->setEnabled(on);
		check->setChecked(checked);
	}
}

// ------------------------------------------------------------------
bool DlgLogger::getCheck(QString name)
{
	QCheckBox *check = findChild<QCheckBox*>(name);
	return check && check->isChecked();
}

// ------------------------------------------------------------------
void DlgLogger::verifyButtons(quint32 n_gpr, bool console, bool file, LogLevels level)
{
	QString name;
	if(n_gpr == IDGPR1)
		name = "check1_";
	else if(n_gpr == IDGPR2)
		name = "check2_";
	else
		name = "check3_";

	setCheck(name + "c", console);
	setCheck(name + "f", file);

//	qDebug() << qPrintable(QString("%1").arg(((qulonglong)level),0, 16).toUpper());

	qulonglong x = 0x000000000000000f;

	for(quint32 i = 0; i < 16; i++)
	{
		QString namex = name + QString::number(i + 1);

//qDebug() << qPrintable(QString("x=%1").arg(((qulonglong)x),0, 16).toUpper());

		setCheck(namex, (x & level), true);

		x <<= 4;
	}
}

// ------------------------------------------------------------------
void DlgLogger::getButtons(quint32 n_gpr, bool & console, bool & file, LogLevels & level)
{
	QString name;
	if(n_gpr == IDGPR1)
		name = "check1_";
	else if(n_gpr == IDGPR2)
		name = "check2_";
	else
		name = "check3_";

	console = getCheck(name + "c");
	file = getCheck(name + "f");
	level = 0;

	qulonglong x = 0x000000000000000f;

	for(quint32 i = 0; i < 16; i++)
	{
		QString namex = name + QString::number(i + 1);

		if(getCheck(namex))
			level |= x;

		x <<= 4;
	}

	qDebug() << qPrintable(QString("%1").arg(((qulonglong)level),0, 16).toUpper());
}
// ------------------------------------------------------------------
void DlgLogger::connected(quint32 numGpr)
{
	if(isVisible())
	{
		if(numGpr == IDGPR1)
		{
			setActive(IDGPR1, false);
			sendAction(numGpr, "refreshLogger");
		}
		if(numGpr == IDGPR2)
		{
			setActive(IDGPR2, false);
			sendAction(numGpr, "refreshLogger");
		}
	}
}

// ------------------------------------------------------------------
void DlgLogger::disconnected(quint32 numGpr)
{
	setActive(numGpr, false);
}

// ------------------------------------------------------------------
void DlgLogger::setActive(quint32 n_gpr, bool on)
{
	QList<QCheckBox*> checks = findChildren<QCheckBox*>();
	foreach(QCheckBox* check, checks)
	{
		if(n_gpr == 0 && check->objectName().startsWith("check1_"))
			check->setEnabled(on);
		if(n_gpr == 1 && check->objectName().startsWith("check2_"))
			check->setEnabled(on);
		if(n_gpr == 2 && check->objectName().startsWith("check3_"))
			check->setEnabled(on);
	}
}

// ------------------------------------------------------------------
