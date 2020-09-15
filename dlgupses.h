#ifndef __DLGUPSES_H__
#define __DLGUPSES_H__

#include <QDateTime>
#include "ui_upses.h"
#include "../common/dialog.h"
#include "../common/ctrlstate.h"

//----------------------------------------------------------------------------------------------------------------

typedef QVariantMap AskuCommandSet;

//----------------------------------------------------------------------------------------------------------------

class DlgUpses : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void setActive(bool on);

public:
	DlgUpses(QWidget *parent = 0);
	~DlgUpses();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgUpses ui;

private slots:
	void on_pushClose_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGUPSES_H__
