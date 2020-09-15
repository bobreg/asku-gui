#ifndef __DLGSETPRM_H__
#define __DLGSETPRM_H__


#include "ui_setprm.h"
#include <../common/dialog.h>

//----------------------------------------------------------------------------------------------------------------

class DlgSetPrm : public AskuDialog
{
	Q_OBJECT

public:
	DlgSetPrm(QWidget *parent = 0);
	~DlgSetPrm();

private:
	Ui::DlgSetPrm ui;

protected:
	void sendAction(QString command, QStringList parameters = QStringList());
	void setOn(bool on);
	void setGSH(bool on);
	void setZU(bool on);
	void setPILOT(bool on);
	void setSHARU1(quint32 value);
	void setSHARU2(quint32 value);

	void setActive(bool on);

private slots:
	void on_pushClose_clicked();
	void on_checkAllow_stateChanged(int state);
	void on_checkBlock_stateChanged(int state);
	void on_checkGsh_stateChanged(int state);
	void on_checkZu_stateChanged(int state);
	void on_checkPilot_stateChanged(int state);
	void on_spinCh1_valueChanged(int nvalue);
	void on_spinCh2_valueChanged(int nvalue);

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);

	virtual void connectedRls();
	virtual void disconnectedRls();
};


#endif // __DLGSETPRM_H__
