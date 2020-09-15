#ifndef __DLGCTRLPRD_H__
#define __DLGCTRLPRD_H__

#include <QDateTime>
#include "ui_ctrlprd.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;

//----------------------------------------------------------------------------------------------------------------

class DlgCtrlPrd : public AskuDialog
{
Q_OBJECT

	AskuCommandSet m_commands;
	AskuCommandSet m_selectors;
	QMap<QString, AskuPanelButtonState> m_buttons;

	void processButtonAction(QPushButton * button);
	void activateButtonAction(QString command, QStringList parameters = QStringList());

	QStringList actionParameters();
	void sendRefreshAction();

	void refreshSelectors();
	void verifyButtons();
	void verifyCommands();
	void setActive(bool on);

public:
	DlgCtrlPrd(QWidget *parent = 0);
	~DlgCtrlPrd();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgCtrlPrd ui;

private slots:
	void on_comboSelectPrd_currentIndexChanged(int index);
	void on_comboSelectModule_currentIndexChanged(int index);
	void on_pushPowerOn_clicked();
	void on_pushPowerOff_clicked();
	void on_pushPumi1_clicked();
	void on_pushPumi2_clicked();
	void on_pushHotResOn_clicked();
	void on_pushHotResOff_clicked();
	void on_pushModule380On_clicked();
	void on_pushModule380Off_clicked();
	void on_pushModuleOn_clicked();
	void on_pushModuleOff_clicked();
	void on_pushSVChOn_clicked();
	void on_pushSVChOff_clicked();
	void on_pushReset_clicked();
	void on_pushClose_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGCTRLPRD_H__
