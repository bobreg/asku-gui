#ifndef __DLGDRIVES_H__
#define __DLGDRIVES_H__

#include <QDateTime>
#include "ui_drives.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;

//----------------------------------------------------------------------------------------------------------------

class DlgDrives : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void setActive(bool on);

public:
	DlgDrives(QWidget *parent = 0);
	~DlgDrives();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgDrives ui;

private slots:
	void on_pushReset_clicked();
	void on_pushClose_clicked();
	void on_checkManual_stateChanged(int state);
	void on_pushOn_clicked();
	void on_pushOff_clicked();
	void on_pushSet1_clicked();
	void on_pushSet2_clicked();
	void on_pushSetSpeed_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGDRIVES_H__
