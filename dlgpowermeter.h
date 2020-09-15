#ifndef __DLGPOWERMETER_H__
#define __DLGPOWERMETER_H__

#include <QDateTime>
#include "ui_powermeter.h"
#include "../common/dialog.h"

//----------------------------------------------------------------------------------------------------------------

class DlgPowerMeter : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void setActive(bool on);

public:
	DlgPowerMeter(QWidget *parent = 0);
	~DlgPowerMeter();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgPowerMeter ui;

private slots:
	void on_pushClose_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
	void on_pushMeasure_clicked();
	void on_pushReset_clicked();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGPOWERMETER_H__
