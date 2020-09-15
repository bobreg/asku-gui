#ifndef __DLGAVTOMATICA_H__
#define __DLGAVTOMATICA_H__

#include <QDateTime>
#include "ui_avtomatica.h"
#include "../common/dialog.h"

//----------------------------------------------------------------------------------------------------------------

class DlgAvtomatica : public AskuDialog
{
Q_OBJECT

	void sendRefreshAction();
	void setActive(bool on);

public:
	DlgAvtomatica(QWidget *parent = 0);
	~DlgAvtomatica();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgAvtomatica ui;

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

#endif // __DLGAVTOMATICA_H__
