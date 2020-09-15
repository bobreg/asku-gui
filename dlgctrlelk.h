#ifndef __DLGCTRLELK_H__
#define __DLGCTRLELK_H__

#include <QDateTime>
#include "ui_ctrlelk.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;

//----------------------------------------------------------------------------------------------------------------

class DlgCtrlElk : public AskuDialog
{
Q_OBJECT

	AskuCommandSet m_commands;
	QMap<QString, AskuPanelButtonState> m_buttons;

	void processButtonAction(QPushButton * button);
	void activateButtonAction(QString command, QStringList parameters = QStringList());

	void sendRefreshAction();

	void refreshSelectors();
	void verifyButtons();
	void verifyCommands();
	void setActive(bool on);

public:
	DlgCtrlElk(QWidget *parent = 0);
	~DlgCtrlElk();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgCtrlElk ui;

private slots:
	void on_pushOsvPerimOff_clicked();
	void on_pushOsvPerimOn_clicked();
	void on_pushTestHowl_clicked();
	void on_pushFireOff_clicked();
	void on_pushFireOn_clicked();
	void on_pushGuardOff_clicked();
	void on_pushGuardOn_clicked();
	void on_pushCondOff_clicked();
	void on_pushCondOn_clicked();
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

#endif // __DLGCTRLELK_H__
