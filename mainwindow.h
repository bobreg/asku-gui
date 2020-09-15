#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <QStatusBar>
#include <QLabel>
#include <QDateTime>
#include <QPixmap>
#include <QAction>
#include <QToolBar>
#include <QTimer>
#include <QEvent>
#include <QTimerEvent>
#include "actions.h"
#include "config.h"
#include "centralwidget.h"

//----------------------------------------------------------------------------------------------------------------

class AskuCentralWidget;
class SettingsUI;

//----------------------------------------------------------------------------------------------------------------

class AskuTimeWorkLabel : public QLabel 
{
	Q_OBJECT

	QDateTime m_timeWork;

public:
	AskuTimeWorkLabel(QWidget * parent = 0);

protected:
	virtual void timerEvent(QTimerEvent* event);
};

//----------------------------------------------------------------------------------------------------------------

class AskuStatusBar : public QStatusBar
{
	Q_OBJECT

	QLabel *m_statusTip, *m_statusReg, *m_statusNULL;
	AskuTimeWorkLabel *m_statusTimeWork;

public:
	AskuStatusBar(QWidget * parent = 0);

	void setRegimeText(QString text);
	QString regimeText();

	void setTipText(QString text);
	QString tipText();

	QString timeWorkText();
};

//----------------------------------------------------------------------------------------------------------------

class AskuToolBar : public QToolBar
{
	Q_OBJECT

	QTimer *timerTipOn;
	QTimer *timerTipOff;
	QAction *action;
	QPoint point;
	bool isToolTip;

	QString makeToolTipText(QAction *action);

public:
	AskuToolBar(QWidget *parent = 0);

private slots:
	void timeoutOn();
	void timeoutOff();

protected:
	virtual bool event(QEvent *event);
};

//----------------------------------------------------------------------------------------------------------------

class AskuMainWindow : public QMainWindow
{
	Q_OBJECT

protected:
	void closeEvent(QCloseEvent *event);

private:
	AskuToolBar *m_toolBar;
	AskuStatusBar *m_statusBar;
	AskuCentralWidget *m_centralWgt;
	AskuConfig *m_config;
	AskuActions *m_actions;
	AskuRlsConfig m_rlsConfig;
	QString m_rlsName;

	void createToolBar();
	void createStatusBar();
	void createCentralWidget();

	void loadSettingsUI();
	void saveSettingsUI();

public:
	AskuMainWindow(QWidget* pwgt = 0);
	~AskuMainWindow();

	void setLevelCollection(AskuLevelCollection* coll);
	void setActions(AskuActions* actions);
	void setConfig(AskuConfig* config);

	inline QString rlsName() {
		return !m_rlsName.isEmpty() ? m_rlsName + "_" : m_rlsName;
	}
	void setRlsName(QString name);

	void onClose();

	bool checkPassword();

public slots:

	void applyGraphic();
	void applyConfig();
	void applyActions();

	void invokeAction(QString name, QStringList parameters = QStringList());

//слоты действий
	void slotActionShow();
	void slotActionHide();
	void slotActionQuit();
	void slotActionLevelUp();
	void slotActionLevelTop(int showZal);

	void onChangedRegime(QString nameRegime);

signals:
	void sigQuit();
	void sigRaise();
	void sendControlCommand(QString rlsName, QVariantMap data);
};

//----------------------------------------------------------------------------------------------------------------

#endif // __MAINWINDOW_H__
