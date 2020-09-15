#ifndef __DLGMEASURE_H__
#define __DLGMEASURE_H__


#include "ui_measure.h"
#include <../common/dialog.h>

//----------------------------------------------------------------------------------------------------------------

class DlgMeasure : public AskuDialog
{
	Q_OBJECT

public:
	DlgMeasure(QWidget *parent = 0);
	~DlgMeasure();

private:
	Ui::DlgMeasure ui;

protected:
	void setOscPhase(double value, bool valid);
	void setAvtoMode(bool avto);
	void setProgress(qint32 value);
	void setStatus(qint32 value, QString text);
	void setUpdate(qint32 n_prd, qint32 n_module, bool avto);

private slots:
	void on_pushSetPhase_clicked();
	void on_pushNext_clicked();
	void on_pushCancel_clicked();

};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGMEASURE_H__
