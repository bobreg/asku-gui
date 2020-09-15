#ifndef __DLGLISTRGDV_H__
#define __DLGLISTRGDV_H__

#include <QDialog>
#include <../common/dialog.h>
#include "ui_listrgdv.h"
#include "globalvar.h"

//----------------------------------------------------------------------------------------------------------------

class DlgListRGDV : public AskuDialog
{
Q_OBJECT

public:
	DlgListRGDV(QWidget *parent = 0);
	~DlgListRGDV();

private:
	Ui::DlgListRGDV ui;
	
	QString m_stateRgdv;

	void updateLabelState(QLabel *label, QString state);
	void cleanTable();

protected:
	void sendAction(QString command, QStringList parameters = QStringList());
	void refreshListRgdv(QVariantList & info, bool full = true);
	void addLine(QString name, QString element, QString source, QString text = QString(), QString value = QString());
	void updateLine(QString name, QString element, QString source, QString text = QString(), QString value = QString());
	void updateRgdvState(QString state, QString text);
	void clean();

/*
	void initialize();
	void addListRGDV(const char element[], const char source[]);
	void addListHeader(const char header[]);
*/

protected slots:
	void on_pushClose_clicked();

public slots:
    void applyGraphic();
/*
    void setListRGDV(const char element[], const char source[]);
    void setListRGDV(const char element[], const char source[], const char text[], quint8 state);
    void setStateRGDV(quint8 state, QString textRGDV);
*/
	virtual qint32 processInfo(QVariantMap data);
	virtual void showEvent(QShowEvent * event);

	virtual void connectedRls();
	virtual void disconnectedRls();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __DLGLISTRGDV_H__
