#ifndef __DLGD2VK028_H__
#define __DLGD2VK028_H__

#include <../common/dialog.h>
#include "ui_dasd.h"
#include "globalvar.h"

//----------------------------------------------------------------------------------------------------------------

class DlgDASD : public AskuDialog
{
Q_OBJECT

	QChar counter;
	quint32 m_activeGpr;
	bool m_connected[MAX_ACTIVE_GPR];

public:
	DlgDASD(QWidget *parent = 0);
	~DlgDASD();

	void sendAction(quint32 toGpr, QString command, QStringList parameters = QStringList());
	void setEnablePage(quint32 page, bool on);

private:
	Ui::DlgDASD ui;

	void counterNext();
	void setLabelClear(QLabel *lbl);
	void setSpinValue(QSpinBox *spn, quint32 data);

private slots:
	void on_pushButtonSettings_toggled(bool on);
	void on_pushButtonClose_clicked();
	void on_pushButtonReset_clicked();
	void on_pushButtonResetTables_clicked();
	void on_pushModuleCtrl1_clicked();
	void on_pushModuleCtrl2_clicked();
	void on_pushModuleCtrl3_clicked();
	void on_pushFormerCtrl1_clicked();
	void on_pushFormerCtrl2_clicked();
	void on_pushFormerCtrl3_clicked();
	void on_pushFormerCtrl5_clicked();
	void on_spinFormerCtrl17_valueChanged(int value);
	void on_pushAzimCtrl1_clicked();
	void on_pushAzimCtrl3_clicked();
	void on_pushAzimCtrl4_clicked();
	void on_pushAzimCtrl5_clicked();
	void on_pushAzimCtrl6_clicked();
	void on_pushTimerCtrl1_clicked();
	void on_pushSharuCtrl3_clicked();
	void on_pushErrorZu1_clicked();
	void on_pushErrorZu2_clicked();
	void on_pushSKR3_clicked();
	void on_pushSKR4_clicked();
	void on_pushPS3_clicked();
	void on_pushPS4_clicked();
	void on_pushGSH3_clicked();
	void on_pushGSH4_clicked();
	void on_pushZU3_clicked();
	void on_pushZU4_clicked();
	void on_pushTimerState2_clicked();
	void on_spinOffset1_valueChanged(int value);
	void on_spinOffset2_valueChanged(int value);
	void on_spinStepDopler1_valueChanged(int value);
	void on_spinFreqDeviation1_valueChanged(int value);
	void on_spinAmpDelayPilot1_valueChanged(int value);
	void on_spinAmpDelayPilot2_valueChanged(int value);
	void on_spinSyncr1_valueChanged(int value);
	void on_comboGpr_currentIndexChanged(int index);

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);

	virtual void connected(quint32 numGpr);
	virtual void disconnected(quint32 numGpr);
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGDASD_H__
