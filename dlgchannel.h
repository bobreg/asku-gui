#ifndef __DLGCHANNEL_H__
#define __DLGCHANNEL_H__

#include <QDialog>
#include "ui_channel.h"
#include "../common/dialog.h"

class DlgChannel : public AskuDialog
{
Q_OBJECT

	QStringList captions;

	void sendRefreshAction();
	void setActive(bool on);

	void refresh(QVariantMap map);
	void refreshCommand(QVariantMap map);

public:
	DlgChannel(QWidget *parent = 0);
	~DlgChannel();

	void sendAction(QString command, QStringList parameters = QStringList());

private:
	Ui::DlgChannel ui;

private slots:
	void on_tableCommand_itemClicked(QTableWidgetItem *item);
	void on_tableTest2_itemClicked(QTableWidgetItem *item);
	void on_tableState_itemClicked(QTableWidgetItem *item);
	void on_tableDC_itemClicked(QTableWidgetItem *item);

	void tableCommand_sectionClicked(int index);
	void tableTest2_sectionClicked(int index);
	void tableState_sectionClicked(int index);
	void tableDC_sectionClicked(int index);

	void on_pushClose_clicked();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);
	virtual void hideEvent(QHideEvent * event);
	virtual void connectedRls();
	virtual void disconnectedRls();
};

#endif // __DLGCHANNEL_H__
