#ifndef __DLGLOGGER_H__
#define __DLGLOGGER_H__

#include <QDateTime>
#include "ui_logger.h"
#include "../common/dialog.h"
#include "../common/logger.h"

//----------------------------------------------------------------------------------------------------------------

class DlgLogger : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void verifyButtons(quint32 n_gpr, bool console, bool file, LogLevels level);
	void getButtons(quint32 n_gpr, bool & console, bool & file, LogLevels & level);
	void setActive(quint32 n_gpr, bool on);
	void setCheck(QString name, bool checked, bool on = true);
	bool getCheck(QString name);
	void makeSet(quint32 n_gpr, bool console, bool file, LogLevels level);

public:
	DlgLogger(QWidget *parent = 0);
	~DlgLogger();

	void sendAction(quint32 toGpr, QString command, QStringList parameters = QStringList());

private:
	Ui::DlgLogger ui;

private slots:
	void on_pushSet_clicked();
	void on_pushClose_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connected(quint32 numGpr);
	virtual void disconnected(quint32 numGpr);
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGLOGGER_H__
