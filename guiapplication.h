#ifndef __GUIAPPLICATION_H__
#define __GUIAPPLICATION_H__

#include "../common/application.h"
#include "guimodule.h"

//----------------------------------------------------------------------------------------------------------------
class AskuGuiApplication : public AskuApplication
{
Q_OBJECT

	AskuGuiModule *guiModule;
	qint32 m_gprOverride;

private:
	virtual bool writeSettings(QSettings &m_settings);
	virtual bool readSettings (QSettings &m_settings);

public:
	AskuGuiApplication(int & argc, char** argv);
	virtual ~AskuGuiApplication();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __GUIAPPLICATION_H__
