#ifndef __DLGPHASE_H__
#define __DLGPHASE_H__


#include "ui_phase.h"
#include <../common/dialog.h>

//----------------------------------------------------------------------------------------------------------------

class DlgPhase : public AskuDialog
{
	Q_OBJECT

	QVariantMap m_selectors;

	qint32 checkPhaseCode(QString text, quint32 * phaseCode = NULL);
	qint32 checkPhaseValue(QString text, double * phaseValue = NULL);

	QVariantList phaseCodes(QTableWidget * table, qint32 * errorCode);
	QVariantList phaseValues(QTableWidget * table, qint32 * errorCode);

	double targetPhaseValue(QLineEdit * line, qint32 * error);
	quint32 calc_phase_code(double target, double phase, quint32 nowcode);
	double calc_middle_value(QVariantList list);
	void updatePhaseCodes(QTableWidget *table, double phaseTarget, QVariantList list);
	void calcPhaseCodes(QTableWidget *table);

	void updateModuleInfo(int n_prd, int n_module, bool valid, QString serial, int phase, int sv_phase);
	void updatePhaseValue(int n_prd, int n_module, double value);

	QStringList actionParameters();
	void sendAction(QString command, QStringList parameters = QStringList());
	void sendActionMap(QString command, QVariantMap parameters);

	void updateModuleInfo(QVariantList & info);

	void prepareTables();
	void refreshSelectors();
	void setActive(bool on);

public:
	DlgPhase(QWidget *parent = 0);
	~DlgPhase();

private:
	Ui::DlgPhase ui;

protected slots:
	void on_pushClearPhase1_clicked();
	void on_pushClearPhase2_clicked();
	void on_pushRefresh_clicked();
	void on_pushClose_clicked();
	void on_pushApply_clicked();
	void on_pushClear1_clicked();
	void on_pushClear2_clicked();
	void on_pushPhase_clicked();
	void on_pushMiddle_clicked();
	void on_pushMeasure_clicked();
	void on_pushCalculate_clicked();
	void on_tablePhase1_cellChanged(int row, int col);
	void on_tablePhase2_cellChanged(int row, int col);

public slots:
	virtual qint32 processInfo(QVariantMap data);

	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);

	virtual void connectedRls();
	virtual void disconnectedRls();
};


#endif // __DLGPHASE_H__
