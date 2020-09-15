#ifndef __DLGCTRLPANEL_H__
#define __DLGCTRLPANEL_H__

#include <QDateTime>
#include "ui_ctrlpanel.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;
typedef QVariantMap AskuRafStatus;
typedef QVariantList AskuRafMessage;

//----------------------------------------------------------------------------------------------------------------

class DlgCtrlPanel : public AskuDialog, public AskuControlPanel
{
Q_OBJECT

	bool m_visibleRaf;

	AskuCommandSet m_commands;
	AskuRafStatus m_rafStatus;
	AskuRafMessage m_rafMessages;
	QDateTime m_rafMessagesUpdated;

	void processButtonAction(QPushButton * button);
	void activateButtonAction(QString command, QStringList parameters = QStringList());

	void setStateRaf(QString state, QString text = QString());
	void setStateRgdv(QString state, QString text = QString());
	void updateLabelState(QLabel *label, QString state);

	void verifyButtons();
	void verifyCommands();

	void updateRafStatus();
	void updateRafMessages();

	void setVisibleRaf(bool on);

	void setActive(bool on);

public:
	DlgCtrlPanel(QWidget *parent = 0);
	~DlgCtrlPanel();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgControlPanel ui;

protected:
	void clean();

private slots:
	void on_closeButton_clicked();

	void on_rgdvButtonOff_clicked();
	void on_rgdvButtonOn_clicked();

	void on_rafButtonOff_clicked();
	void on_rafButtonOn_clicked();

	void on_howlButtonOff_clicked();
	void on_howlButtonOn_clicked();
	void on_howlButtonReset_clicked();

	void on_prlObrButton1_clicked();
	void on_prlObrButton2_clicked();

	void on_prlAutoButtonOff_clicked();
	void on_prlAutoButtonOn_clicked();

	void on_azimuthButton1_clicked();
	void on_azimuthButton2_clicked();

	void on_overviewButton1_clicked();
	void on_overviewButton2_clicked();

	void on_prvButtonOff_clicked();
	void on_prvButtonOn_clicked();

	void on_prdButtonOff_clicked();
	void on_prdButtonOn_clicked();
	void on_pumiButton1_clicked();
	void on_pumiButton2_clicked();

	void on_mvrlObrButton1_clicked();
	void on_mvrlObrButton2_clicked();

	void on_vrlAutoButtonOff_clicked();
	void on_vrlAutoButtonOn_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);

	virtual void connectedRls();
	virtual void disconnectedRls();

	void applyGraphic();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGCTRLPANEL_H__
