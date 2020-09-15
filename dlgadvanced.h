#ifndef __DLGADVANCED_H__
#define __DLGADVANCED_H__

#include <QDialog>
#include "ui_cadvance.h"
#include "../common/dialog.h"

class DlgAdvanced : public AskuDialog
{
Q_OBJECT

	void refresh(QVariantMap data);

public:
	DlgAdvanced(QWidget *parent = 0);
	~DlgAdvanced();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgAdvanced ui;
};

#endif // __DLGADVANCED_H__
