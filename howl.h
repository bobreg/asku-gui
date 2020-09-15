#ifndef HOWL_H_INCLUDED
#define HOWL_H_INCLUDED

#include <QProcess>
#include <QThread>
#include <QString>
#include <QSound>

class AskuLowPriorityProcess : public QProcess
{
protected:
	void setupChildProcess();
};

class AskuHowl : public QThread
{
#ifdef Q_OS_WIN32
	QSound *sndError;
	QSound *sndAvar;
	QSound *sndNot;
#endif

	QString fileAvar;
	QString fileError;
	QString fileNot;

	bool isErrorPOS;
	bool isCancel;
	bool isCancelRLK;
	bool isRunning;
	bool isEnabled;
	bool isAvar;
	bool isError;
	bool isNot;

	bool aplay_exec(QString filename);

public:
	AskuHowl();
	~AskuHowl();

	virtual void run();

	void setAvarStatus();
	void clearAvarStatus();

	void setErrorStatus();
	void clearErrorStatus();

	void setNotStatus();
	void clearNotStatus();

	void setCancel();
	void clearCancel();

	void setCancelRLK();
	void clearCancelRLK();

	void setOn();
	void setOff();
	void setEnable(bool enable);
	bool getEnabled();
	
	bool checkErrorRLK();
};

#endif
