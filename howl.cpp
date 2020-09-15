#include <QDir>
#include "howl.h"
#include "globalvar.h"
#ifdef Q_OS_LINUX
	#include <unistd.h>
#endif

void AskuLowPriorityProcess::setupChildProcess()
{
#ifdef Q_OS_LINUX
	setgid(getgid());
	setuid(getuid());
#endif
}

AskuHowl::AskuHowl()
{
	isCancel = false;
	isCancelRLK = false;
	isRunning = true;
	isEnabled = true;
	isAvar = false;
	isError = false;
	isNot = false;

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	fileAvar  = QDir::toNativeSeparators(m_setup.path.media + QString("/") + m_setup.media.fileAvar);
	fileError = QDir::toNativeSeparators(m_setup.path.media + QString("/") + m_setup.media.fileError);
	fileNot   = QDir::toNativeSeparators(m_setup.path.media + QString("/") + m_setup.media.fileNot);
#else
	fileAvar  = QDir::convertSeparators(m_setup.path.media + QString("/") + m_setup.media.fileAvar);
	fileError = QDir::convertSeparators(m_setup.path.media + QString("/") + m_setup.media.fileError);
	fileNot   = QDir::convertSeparators(m_setup.path.media + QString("/") + m_setup.media.fileNot);
#endif

#ifdef Q_OS_WIN32
	sndAvar = new QSound(fileAvar);
	sndError = new QSound(fileError);
	sndNot = new QSound(fileNot);
#endif
}

AskuHowl::~AskuHowl()
{
	isRunning = false;
	wait();

#ifdef Q_OS_WIN32
	delete sndAvar;
	delete sndError;
	delete sndNot;
#endif
}

bool AskuHowl::aplay_exec(QString filename)
{
	AskuLowPriorityProcess *process = new AskuLowPriorityProcess();
//	qDebug("proc starting = %s",qPrintable(QString("aplay ") + filename));
//	result = process->execute(strParameters.join(QString(" ")));
	process->start(QString("aplay ") + filename);
	if(!process->waitForStarted(10000))
	{
//		qDebug("proc not started");
	}
	else
	{
//		qDebug("proc waiting finish");
		if(!process->waitForFinished(-1))
		{
//			qDebug("proc not stopping");
		}
		else if(process->exitStatus() == QProcess::NormalExit)
		{
//			int result = process->exitCode();
//			qDebug("success exit code = %d",result);
		}
	}
//	qDebug("proc finished");
	process->close();
//	qDebug("proc deleting");
	delete process;
//	qDebug("proc deleted");
	process = NULL;
	return true;
}

void AskuHowl::run()
{
	while(isRunning)
	{
		if(isEnabled && !isCancel)
		{
			if(isAvar)
			{
#ifdef Q_OS_LINUX
				aplay_exec(fileAvar);
#endif

#ifdef Q_OS_WIN32
				sndAvar->play();
				msleep(1070);
#endif
			}

			if(!isRunning) break;

			if(isError)
			{

#ifdef Q_OS_LINUX
				aplay_exec(fileError);
#endif

#ifdef Q_OS_WIN32
				sndError->play();
				msleep(680);
#endif
			}

			if(!isRunning) break;

			if(isNot)
			{
#ifdef Q_OS_LINUX
				aplay_exec(fileNot);
#endif

#ifdef Q_OS_WIN32
				sndNot->play();
				msleep(510);
#endif
			}
		}

		msleep(100);
	}
}

void AskuHowl::setCancel()
{
	isCancel = true;
}

void AskuHowl::clearCancel()
{
	isCancel = false;
}

void AskuHowl::setCancelRLK()
{
	isCancelRLK = true;
}

void AskuHowl::clearCancelRLK()
{
	isCancelRLK = false;
}

void AskuHowl::setOn()
{
	isEnabled = true;
}

void AskuHowl::setOff()
{
	isEnabled = false;
}

void AskuHowl::setEnable(bool enable)
{
	isEnabled = enable;
}

bool AskuHowl::getEnabled()
{
	return isEnabled;
}

void AskuHowl::setAvarStatus()
{
	isAvar = true;
}

void AskuHowl::clearAvarStatus()
{
	isAvar = false;
}

void AskuHowl::setErrorStatus()
{
	isError = true;
}

void AskuHowl::clearErrorStatus()
{
	isError = false;
}

void AskuHowl::setNotStatus()
{
	isNot = true;
}

void AskuHowl::clearNotStatus()
{
	isNot = false;
}

bool AskuHowl::checkErrorRLK()
{
	if(isEnabled && !isCancelRLK && isErrorPOS)
	{
		return true;
	}
	else
	{
		return false;
	}
}
