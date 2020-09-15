#ifndef __DLGDESES_H__
#define __DLGDESES_H__

#include <QDateTime>
#include "ui_deses.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;

//----------------------------------------------------------------------------------------------------------------

class DlgDeses : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void setActive(bool on);

public:
	DlgDeses(QWidget *parent = 0);
	~DlgDeses();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgDeses ui;

private slots:
	void on_pushClose_clicked();
	void on_pushOffEngine1_clicked();
	void on_pushOnEngine1_clicked();
	void on_pushOffEngine2_clicked();
	void on_pushOnEngine2_clicked();
	void on_pushOffGB1_clicked();
	void on_pushOnGB1_clicked();
	void on_pushOffGB2_clicked();
	void on_pushOnGB2_clicked();
	void on_pushOffMB1_clicked();
	void on_pushOnMB1_clicked();
	void on_pushResetMns1_clicked();
	void on_pushResetDgs1_clicked();
	void on_pushResetDgs2_clicked();
	void on_checkRegime1_clicked();
	void on_checkRegime2_clicked();
	void on_checkRegime3_clicked();
	void on_checkRegime4_clicked();
	void on_checkRegime5_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGDESES_H__
