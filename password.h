#ifndef __PASSWORD_H__
#define __PASSWORD_H__

#include <QDialog>
#include "ui_password.h"
#include "ui_passchange.h"

class DlgPassChange : public QDialog
{
Q_OBJECT

	Ui::DlgPassChange ui;

public:
	DlgPassChange(QWidget *parent = 0, QFont *dialogFont = NULL);
	~DlgPassChange();

private slots:
	void on_buttonCancel_clicked();
	void on_buttonChange_clicked();
};

class DlgPassword : public QDialog
{
Q_OBJECT

	Ui::DlgPassword ui;

	static QByteArray readPassword();
	static bool writePassword(QByteArray password); 

public:
	DlgPassword(QWidget *parent = 0, QFont *dialogFont = NULL);
	~DlgPassword();

	static bool wasPassword();
	static bool checkPassword(QString pass);
	static bool writePassword(QString pass); 
	static bool isBlocked();

private slots:
	void on_buttonOK_clicked();
	void on_buttonCancel_clicked();
	void on_buttonChange_clicked();
};

#endif // __PASSWORD_H__
