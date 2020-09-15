#ifndef __DLGSKRPILOT_H__
#define __DLGSKRPILOT_H__


#include "ui_skrpilot.h"
#include <../common/dialog.h>

//----------------------------------------------------------------------------------------------------------------

class AskuSpinBox : public QSpinBox
{
Q_OBJECT

public:
	AskuSpinBox(QWidget *parent = 0);
	virtual QString textFromValue(int value) const;
	virtual int valueFromText(const QString & text) const;
};

//----------------------------------------------------------------------------------------------------------------

class DlgSkrPilot : public AskuDialog
{
	Q_OBJECT

	AskuSpinBox *spinSKR;
	AskuSpinBox *spinPS;

public:
	DlgSkrPilot(QWidget *parent = 0);
	~DlgSkrPilot();

private:
	Ui::DlgSkrPilot ui;

protected:
	void sendAction(QString command, QStringList parameters = QStringList());

	void clean();

private slots:
	void on_pushApply_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);

	virtual void connectedRls();
	virtual void disconnectedRls();
};


#endif // __DLGSKRPILOT_H__
