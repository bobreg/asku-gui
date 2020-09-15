#ifndef __DLGABOUT_H__
#define __DLGABOUT_H__

#include <QDialog>
#include "ui_about.h"
#include "globalvar.h"
#include "../common/dialog.h"

//----------------------------------------------------------------------------------------------------------------

class DlgAbout : public AskuDialog
{
	Q_OBJECT

	bool m_connected[MAX_ACTIVE_GPR];

public:
	DlgAbout(QWidget *parent = 0);
	~DlgAbout();

private:
	Ui::DlgAbout ui;

protected:
	void sendAction(quint32 toGpr, QString command, QStringList parameters = QStringList());

	void clean(quint32 n);
	void setVersionGpr(qint32 numGpr, QVariantMap info);

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);

	virtual void connected(quint32 numGpr);
	virtual void disconnected(quint32 numGpr);
};

//----------------------------------------------------------------------------------------------------------------

#endif // DLGABOUT_H
