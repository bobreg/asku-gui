#include "globalvar.h"
#include "guiapplication.h"
#include "settingsui.h"

//-----------------------------------------------------------------------------
AskuGuiApplication::AskuGuiApplication(int & argc, char** argv) 
	: AskuApplication(argc, argv)
{
	guiModule = NULL;
	m_gprOverride = -1;

	if(argc > 1)
	{
		QString sargv(argv[1]);
		if(sargv == "-ppv")
			m_gprOverride = IDPPV;
		if(sargv == "-rmo")
			m_gprOverride = IDRMO;
	}

	if(!m_appDoubleCopy && m_testDoubleCopy && m_gprOverride < 0)
		return;

	setApplicationVersion("0.8.0.16 (13.09.2019)");
	loadSettings();

	guiModule = new AskuGuiModule(this, MYID());

//----чел----запуск программы слежения за asku-svc
    control_run.startDetached("/opt/amcs-observer/check_asku_svc");
//----чел----

}

//-----------------------------------------------------------------------------
AskuGuiApplication::~AskuGuiApplication()
{
	if(guiModule != NULL)
	{
		delete guiModule;
		guiModule = NULL;
	}
}

//-----------------------------------------------------------------------------
bool AskuGuiApplication::readSettings(QSettings &m_settings)
{
	bool data_error = false;

	m_settings.beginGroup("/setup");
		m_setup.main.id = m_settings.value("/id", 255).toUInt();
		if(m_setup.main.id == 255)
		{
			qDebug("%s: error in settings data",qPrintable(m_appName));
			data_error = true;
			m_setup.main.id = 0;
		}
		m_setup.main.shema = m_settings.value("/shema", true).toBool();
		m_setup.main.terminate = 0;
	m_settings.endGroup();

	if(m_gprOverride != -1)
		m_setup.main.id = m_gprOverride;

	QString setStr;
	if(ISPPV())
		setStr = "PPV";
	else if(ISURM())
		setStr = "URM";
	else if(ISRMO())
		setStr = QString("RMO%1").arg(MYID() - IDPPV - 1);

	if(!setStr.isEmpty())
		LogInfo("Settings: %s", qPrintable(setStr));

	m_settings.beginGroup("/path");
#ifdef Q_OS_LINUX
		m_setup.path.config = m_settings.value("/config", "/home/observer/config").toString();
		m_setup.path.level  = m_settings.value("/level",  "/home/observer/levels").toString();
		m_setup.path.media  = m_settings.value("/media",  "/home/observer/media").toString();
		m_setup.path.scheme = m_settings.value("/scheme", "/home/observer/scheme").toString();
#endif
#ifdef Q_OS_WIN32
		m_setup.path.config = m_settings.value("/config", "C:\\GPR\\config").toString();
		m_setup.path.level  = m_settings.value("/level",  "C:\\GPR\\levels").toString();
		m_setup.path.media  = m_settings.value("/media",  "C:\\GPR\\media").toString();
		m_setup.path.scheme = m_settings.value("/scheme", "C:\\GPR\\scheme").toString();
#endif
	m_settings.endGroup();

	m_settings.beginGroup("/ui");
		m_setup.ui.file    = m_settings.value("/file",    DEFAULT_SCHEME_FILE).toString();
		m_setup.ui.scale_x = m_settings.value("/scale_x", DEFAULT_SCHEME_SCALE_X).toInt();
		m_setup.ui.scale_y = m_settings.value("/scale_y", DEFAULT_SCHEME_SCALE_Y).toInt();
	m_settings.endGroup();

	m_settings.beginGroup("/media");
		m_setup.media.fileAvar  = m_settings.value("/fileAvar",  "avar.wav").toString();
		m_setup.media.fileError = m_settings.value("/fileError", "error.wav").toString();
		m_setup.media.fileNot   = m_settings.value("/fileOtkl",  "otkl.wav").toString();
	m_settings.endGroup();

//	m_settings.sync();

	return (data_error || (m_settings.status() != QSettings::NoError));
}

//-----------------------------------------------------------------------------
bool AskuGuiApplication::writeSettings(QSettings &m_settings)
{
	m_settings.beginGroup("/setup");
		m_settings.setValue("/id",    m_setup.main.id);
		m_settings.setValue("/shema", m_setup.main.shema);
	m_settings.endGroup();

	m_settings.beginGroup("/path");
		m_settings.setValue("/config", m_setup.path.config);
		m_settings.setValue("/level",  m_setup.path.level);
		m_settings.setValue("/media",  m_setup.path.media);
		m_settings.setValue("/scheme", m_setup.path.scheme);
	m_settings.endGroup();

	m_settings.beginGroup("/ui");
		m_settings.setValue("/file",    m_setup.ui.file);
		m_settings.setValue("/scale_x", m_setup.ui.scale_x);
		m_settings.setValue("/scale_y", m_setup.ui.scale_y);
	m_settings.endGroup();

	m_settings.beginGroup("/media");
		m_settings.setValue("/fileAvar",   m_setup.media.fileAvar);
		m_settings.setValue("/fileError",  m_setup.media.fileError);
		m_settings.setValue("/fileOtkl",   m_setup.media.fileNot);
	m_settings.endGroup();

//	m_settings.sync();

	return (m_settings.status() != QSettings::NoError);
}

//-----------------------------------------------------------------------------
