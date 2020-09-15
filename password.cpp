#include <QByteArray>
#include <QMessageBox>
#include "password.h"
#include "globalvar.h"

// ------------------------------------------------------------------
DlgPassChange::DlgPassChange(QWidget *parent, QFont *dialogFont)
	: QDialog(parent)
{
	ui.setupUi(this);
	if(dialogFont)
		setFont((const QFont&)*dialogFont);
}

// ------------------------------------------------------------------
DlgPassChange::~DlgPassChange()
{
	
}

// ------------------------------------------------------------------
void DlgPassChange::on_buttonCancel_clicked()
{
	done(QDialog::Rejected);
}

// ------------------------------------------------------------------
void DlgPassChange::on_buttonChange_clicked()
{
	QString editOld  = ui.editOld->text();
	QString editNew1 = ui.editNew1->text();
	QString editNew2 = ui.editNew2->text();

	if(editNew1 != editNew2)
	{
		QMessageBox::critical(this, QString("АСКУ"), QString("Пароли не совпадают!"));
		return;
	}
	if(!DlgPassword::wasPassword())
	{
//		qDebug("PassChange:: not set");
	}
	else if(!DlgPassword::checkPassword(editOld))
	{
		QMessageBox::critical(this, QString("АСКУ"), QString("Старый пароль неверен!"));
		return;
	}
	if(!DlgPassword::writePassword(editNew1))
	{
		QMessageBox::critical(this, QString("АСКУ"), QString("Ошибка сохранения нового пароля!"));
	}
	else
	{
		QMessageBox::information(this, QString("АСКУ"), QString("Пароль изменен!"));
		hide();
	}
}

// ------------------------------------------------------------------
DlgPassword::DlgPassword(QWidget *parent, QFont *dialogFont)
	: QDialog(parent)
{
	ui.setupUi(this);
	if(dialogFont)
		setFont((const QFont&)*dialogFont);
}

// ------------------------------------------------------------------
DlgPassword::~DlgPassword()
{
	
}

// ------------------------------------------------------------------
void DlgPassword::on_buttonOK_clicked()
{
	QString pass = ui.editPassword->text();

	if(!wasPassword())
		QMessageBox::critical(this, QString("АСКУ"), QString("Пароль не был задан.\nНажмите \"Изменить\" и задайте новый пароль!"));
	else if(checkPassword(pass))
		done(QDialog::Accepted);
	else
		QMessageBox::critical(this, QString("АСКУ"), QString("Неверный пароль!"));
}

// ------------------------------------------------------------------
void DlgPassword::on_buttonCancel_clicked()
{
	done(QDialog::Rejected);
}

// ------------------------------------------------------------------
void DlgPassword::on_buttonChange_clicked()
{
	DlgPassChange dlg;
	dlg.exec();
}

// ------------------------------------------------------------------
QByteArray DlgPassword::readPassword()
{
	QByteArray password;
	QFile file("/home/asku/.password");
	if(file.exists() && file.open(QIODevice::ReadOnly))
	{
		password = file.readAll();
		file.close();
	}
	return password;
}

// ------------------------------------------------------------------
bool DlgPassword::writePassword(QByteArray password)
{
	bool result = false;
	QFile file("/home/asku/.password");
	if(file.open(QIODevice::WriteOnly))
	{
		if(file.write(password)!=-1)
			result = true;
		file.close();
	}
	return result;
}

// ------------------------------------------------------------------
bool DlgPassword::wasPassword()
{
//	qDebug("checking was pass:");
	QByteArray read = readPassword();
//	dbgPrintArray("read   : ", read.data(),    read.size());
//	if(read.isEmpty())
//		qDebug("pass was not set");
//	else
//		qDebug("pass was set");
	return !read.isEmpty();
}

// ------------------------------------------------------------------
bool DlgPassword::checkPassword(QString pass)
{
//	qDebug("checking pass: \"%s\"",qPrintable(pass));
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	QByteArray entered = qCompress(pass.toLatin1());
#else
	QByteArray entered = qCompress(pass.toAscii());
#endif
	QByteArray read = readPassword();
//	dbgPrintArray("entered: ", entered.data(), entered.size());
//	dbgPrintArray("read   : ", read.data(),    read.size());
	return (entered == read);
}

// ------------------------------------------------------------------
bool DlgPassword::writePassword(QString pass)
{
//	qDebug("writing pass: \"%s\"",qPrintable(pass));
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	QByteArray entered = qCompress(pass.toLatin1());
#else
	QByteArray entered = qCompress(pass.toAscii());
#endif
//	dbgPrintArray("entered: ", entered.data(), entered.size());
	return writePassword(entered);
}

// ------------------------------------------------------------------
bool DlgPassword::isBlocked()
{
	QFile file("/home/asku/.nopassword");
	return file.exists();
}

// ------------------------------------------------------------------
