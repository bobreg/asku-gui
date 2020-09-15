#ifndef __DLGCOOLERS_H__
#define __DLGCOOLERS_H__

#include <QDateTime>
#include "ui_coolers.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;

//----------------------------------------------------------------------------------------------------------------

class DlgCoolers : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void setActive(bool on);

public:
	DlgCoolers(QWidget *parent = 0);
	~DlgCoolers();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgCoolers ui;

private slots:
	void on_pushReset_clicked();
	void on_pushClose_clicked();
	void on_pushSetFreq_clicked();
	void on_pushOn1_clicked();
	void on_pushOff1_clicked();
	void on_pushOn2_clicked();
	void on_pushOff2_clicked();
	void on_manualCheckBox_stateChanged(int state);
	void on_vesperSlider1_valueChanged(int value);
	void on_vesperSlider2_valueChanged(int value);

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGCOOLERS_H__
