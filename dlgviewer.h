#ifndef __DLGVIEWER_H__
#define __DLGVIEWER_H__

#include "ui_viewer.h"
#include <../common/dialog.h>
#include "globalvar.h"

//----------------------------------------------------------------------------------------------------------------

class DlgViewer : public AskuDialog
{
	Q_OBJECT

	bool m_connected[MAX_ACTIVE_GPR];
	bool m_currentLoaded[MAX_ACTIVE_GPR];
	QString m_loadedFileName[MAX_ACTIVE_GPR];

public:
	DlgViewer(QWidget *parent = 0);
	~DlgViewer();

private:
	Ui::Viewer ui;

protected:
	void sendAction(quint32 toGpr, QString command, QStringList parameters = QStringList());

	void clean(quint32 n);
	void prepare(quint32 n);

	void processList(quint32 numGpr, QVariantMap & info);
	void processList(quint32 n, QStringList & list);

	void processContent(quint32 numGpr, QVariantMap & info);
	void processContent(quint32 n, QVariantList & list, QString & name, bool & current, qint32 & errorCode, QString & errorString);
	
	void processMessage(quint32 numGpr, QVariantMap & info);
	void processMessage(quint32 n, QStringList & line);

	void processChangedDate(quint32 numGpr);

	void addContentLine(QTableWidget *table, QStringList & line);
	void clearContent(quint32 n);

	void addListItem(QListWidget *list, QString & item);
	void selectListCurrent(quint32 n, QString name = QString());
	void clearList(quint32 n);

	void showInformation(quint32 n, QString text = QString());
	void showDate(quint32 n, QString text = QString());
	QString dateText(quint32 n);
	void checkLastMessage(quint32 n);
	void checkCurrent(quint32 n);
	void checkSelect(quint32 n);
	void setFilesChecked(QPushButton *pushFiles, bool on);

	static QString nameToDate(QString name);

	void loadFile(quint32 n, QString name = QString());

private slots:
	void on_pushCurrent1_clicked();
	void on_pushSelect1_clicked();
	void on_pushFiles1_clicked();
	void on_checkLast1_stateChanged(int state);

	void on_pushCurrent2_clicked();
	void on_pushSelect2_clicked();
	void on_pushFiles2_clicked();
	void on_checkLast2_stateChanged(int state);

	void on_list1_itemDoubleClicked(QListWidgetItem * item);
	void on_list2_itemDoubleClicked(QListWidgetItem * item);

	void on_list1_itemSelectionChanged();
	void on_list2_itemSelectionChanged();

public slots:
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);

	virtual void connected(quint32 numGpr);
	virtual void disconnected(quint32 numGpr);
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGVIEWER_H__
