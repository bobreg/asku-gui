#include <QApplication>
#include "../common/global.h"
#include "../common/logger.h"
#include "../common/module.h"
#include "dlgabout.h"
#include "xpmset.h"

//-------------------------------------------------------------------------------
DlgAbout::DlgAbout(QWidget *parent) : AskuDialog("dialog_about", parent)
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	QTextCodec::setCodecForLocale(QTextCodec::codecForName(APP_CODEC_STRING));
#else
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName(APP_CODEC_STRING));
#endif
	setWindowIcon(m_pixmaps["label.xpm"]);
	ui.setupUi(this);
	ui.pixLbl->setPixmap(m_pixmaps["label.xpm"]);
	ui.versionLbl->setText(qApp->applicationVersion());

	m_connected[0] = m_connected[1] = false;

	clean(0);
	clean(1);
}

//-------------------------------------------------------------------------------
DlgAbout::~DlgAbout()
{

}

//-------------------------------------------------------------------------------
void DlgAbout::sendAction(quint32 toGpr, QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "control";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	data["ToGprId"] = toGpr;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

//-------------------------------------------------------------------------------
void DlgAbout::clean(quint32 n)
{
	if(n == 0)
		ui.versionLbl1->setText("--- нет связи с ГПР 1 ---");
	if(n == 1)
		ui.versionLbl2->setText("--- нет связи с ГПР 2 ---");
}

//-------------------------------------------------------------------------------
void DlgAbout::showEvent(QShowEvent * event)
{
	clean(0);
	clean(1);

	if(m_connected[0])
	{
		ui.versionLbl1->setText("...");
		sendAction(0, "version");
	}
	if(m_connected[1])
	{
		ui.versionLbl2->setText("...");
		sendAction(1, "version");
	}

	event->accept();
}

//-------------------------------------------------------------------------------
qint32 DlgAbout::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgAbout: empty info data!");
		return result;
	}

	bool ok = false;
	quint32 numGpr = data["GprId"].toUInt(&ok);
	if(!ok || (numGpr != IDGPR1 && numGpr != IDGPR2))
	{
		result = AskuModule::CommandSuccess;
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "APPLICATION_VERSION")
	{
		QVariantMap info = data["Info"].toMap();

		if(info.isEmpty())
		{
			LogError("DlgAbout: empty info");
			return result;
		}

		setVersionGpr(numGpr, info);

		result = AskuModule::CommandSuccess;
	}

	return result;
}

//-------------------------------------------------------------------------------
void DlgAbout::setVersionGpr(qint32 numGpr, QVariantMap info)
{
	QString strVersion = info["version"].toString();

	if(numGpr == IDGPR1)
		ui.versionLbl1->setText(strVersion);

	if(numGpr == IDGPR2)
		ui.versionLbl2->setText(strVersion);
}

//-------------------------------------------------------------------------------
void DlgAbout::connected(quint32 numGpr)
{
	if(numGpr == IDGPR1)
	{
		m_connected[0] = true;
		clean(0);

		if(isVisible())
		{
			ui.versionLbl1->setText("...");
			sendAction(0, "version");
		}
	}
	if(numGpr == IDGPR2)
	{
		m_connected[1] = true;
		clean(1);

		if(isVisible())
		{
			ui.versionLbl2->setText("...");
			sendAction(1, "version");
		}
	}
}

//-------------------------------------------------------------------------------
void DlgAbout::disconnected(quint32 numGpr)
{
	if(numGpr == IDGPR1)
	{
		m_connected[0] = false;
		clean(0);
	}
	if(numGpr == IDGPR2)
	{
		m_connected[1] = false;
		clean(1);
	}
}

//-------------------------------------------------------------------------------
