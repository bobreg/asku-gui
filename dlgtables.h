#ifndef __DLGTABLES_H__
#define __DLGTABLES_H__

#include "ui_tables.h"
#include "../common/dialog.h"

//----------------------------------------------------------------------------------------------------------------

class DlgTables : public AskuDialog
{
	Q_OBJECT

	Ui::DlgDASDTables ui;

	bool m_loadedSwitch;
	bool m_loadedMode;
	bool m_loadedRipch;
	bool m_loadedDisable;

	qint32 errorIndex;
	qint32 errorTab;
	qint32 errorRow;
	qint32 errorCol;

	qint32 ripchMaxRow;
	qint32 modeMaxRow;
	qint32 switchMaxRow;
	qint32 disableMaxRow;

	QVariantMap m_tableSwitch;
	QVariantMap m_tableMode;
	QVariantMap m_tableRipch;
	QVariantMap m_tableDisable;

	bool update();
	void clear();

	void clearTables();
	void clearTable(QTableWidget* table);
	void setUnselectable(QTableWidget* table, int col);

	void sendAction(QString command, QVariantMap tables = QVariantMap());
	void setHeaderLabels(QTableWidget* table, QVariantMap header);
	void setTable(QTableWidget* table, QVariantList list);
	void setTable1(QTableWidget* table, QVariantList list);

	bool checkInputValue(QString value, QVariantMap headerItem);
	bool checkTable(QTableWidget* table);

	bool checkTables();
	bool checkTableSwitch();
	bool checkTableMode();
	bool checkTableRipch();
	bool checkTableDisable();

	QVariantList makeEmptyRow(QVariantMap header);
	void setBackground(QTableWidgetItem* item, bool error);

public:
	DlgTables(QWidget *parent = 0);
	~DlgTables();

	bool isLoaded();

private slots:
	void on_pushClose_clicked();
	void on_pushRefresh_clicked();
	void on_pushRefreshFiles_clicked();
	void on_pushSaveFiles_clicked();
	void on_pushSaveModule_clicked();

	void updateButtonsSwitch();
	void updateButtonsMode();
	void updateButtonsRipch();
	void updateButtonsDisable();

	void on_pushSwitchAdd_clicked();
	void on_pushSwitchDelete_clicked();
	void on_pushSwitchUp_clicked();
	void on_pushSwitchDown_clicked();

	void on_pushModeAdd_clicked();
	void on_pushModeDelete_clicked();
	void on_pushModeUp_clicked();
	void on_pushModeDown_clicked();

	void on_pushRipchAdd_clicked();
	void on_pushRipchDelete_clicked();
	void on_pushRipchUp_clicked();
	void on_pushRipchDown_clicked();

	void on_pushDisableAdd_clicked();
	void on_pushDisableDelete_clicked();
	void on_pushDisableUp_clicked();
	void on_pushDisableDown_clicked();

	void on_comboSwitch_activated(int index);
	void on_comboMode_activated(int index);
	void on_comboRipch_activated(int index);
	void onDisable_activated();

	void on_tableSwitch_cellChanged(int row, int col);
	void on_tableMode_cellChanged(int row, int col);
	void on_tableRipch_cellChanged(int row, int col);
	void on_tableDisable_cellChanged(int row, int col);

public slots:
	void refreshRipch(QVariantMap table);
	void refreshMode(QVariantMap table);
	void refreshSwitch(QVariantMap table);
	void refreshDisable(QVariantMap table);
	void results(QString message);

	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);

	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGTABLES_H__
