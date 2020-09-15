#include <QMessageBox>
#include <QCloseEvent>
#include <QToolTip>
#include "../common/logger.h"
#include "../common/dialog.h"
#include "globalvar.h"
#include "xpmset.h"
#include "mainwindow.h"
#include "settingsui.h"
#include "actions.h"
#include "centralwidget.h"
#include "password.h"

//----------------------------------------------------------------------------------------------------------------
AskuTimeWorkLabel::AskuTimeWorkLabel(QWidget * parent) : QLabel(parent), m_timeWork(QDate::currentDate(), QTime::currentTime())
{
	startTimer(1000);
}

//----------------------------------------------------------------------------------------------------------------
void AskuTimeWorkLabel::timerEvent(QTimerEvent* event)
{
	Q_UNUSED(event);

	QDateTime current = QDateTime::currentDateTime();

	int nSecs = m_timeWork.secsTo(current);
	int nDays = m_timeWork.daysTo(current);

	QTime time;
	QString strTime, strDays;

	strTime = time.addSecs(nSecs).toString("hh:mm:ss");
	strDays.setNum(nDays);
	setText(" " + strDays + " : " + strTime + " ");
}

//----------------------------------------------------------------------------------------------------------------
AskuStatusBar::AskuStatusBar(QWidget * parent) : QStatusBar(parent)
{
	m_statusTip = new QLabel(this);
	m_statusTip->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_statusTip->setText(" ");

	m_statusReg = new QLabel(this);
	m_statusReg->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_statusReg->setText(" ");

	m_statusTimeWork = new AskuTimeWorkLabel(this);
	m_statusTimeWork->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_statusTimeWork->setText(" ");

	m_statusNULL = new QLabel(this);
	m_statusNULL->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_statusNULL->setText(" ");

	addWidget(m_statusTip, 120);
	addWidget(m_statusReg, 120);
	addWidget(m_statusTimeWork, 120);
	addWidget(m_statusNULL, 680);
}

//----------------------------------------------------------------------------------------------------------------
void AskuStatusBar::setRegimeText(QString text)
{
	m_statusReg->setText(text);
}

//----------------------------------------------------------------------------------------------------------------
QString AskuStatusBar::regimeText()
{
	return m_statusReg->text();
}

//----------------------------------------------------------------------------------------------------------------
void AskuStatusBar::setTipText(QString text)
{
	m_statusTip->setText(text);
}

//----------------------------------------------------------------------------------------------------------------
QString AskuStatusBar::tipText()
{
	return m_statusTip->text();
}

//----------------------------------------------------------------------------------------------------------------
QString AskuStatusBar::timeWorkText()
{
	return m_statusTimeWork->text();
}

//----------------------------------------------------------------------------------------------------------------
AskuToolBar::AskuToolBar(QWidget *parent) : QToolBar("Панель инструментов", parent)
{
	action = 0;
	isToolTip = false;
	point.setX(-1);
	point.setY(-1);
	timerTipOn = new QTimer(this);
	connect(timerTipOn,SIGNAL(timeout()),this,SLOT(timeoutOn()));
	timerTipOff = new QTimer(this);
	connect(timerTipOff,SIGNAL(timeout()),this,SLOT(timeoutOff()));

	setAttribute(Qt::WA_AlwaysShowToolTips);
	setMovable(true);
	toggleViewAction()->setVisible(false);
}

//----------------------------------------------------------------------------------------------------------------
QString AskuToolBar::makeToolTipText(QAction *action)
{
	QString toolTipText = QString();

	if(action)
	{
		toolTipText = action->toolTip();
		QString shortCutText = action->shortcut().toString();
		if(!shortCutText.isEmpty())
			toolTipText += QString(" (") + shortCutText + QString(")");
	}

	return toolTipText;
}

//----------------------------------------------------------------------------------------------------------------
void AskuToolBar::timeoutOn()
{
	if(action)
	{
		QToolTip::showText(mapToGlobal(point),makeToolTipText(action),this);
		isToolTip = true;
		timerTipOn->stop();
		timerTipOff->start(5000);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuToolBar::timeoutOff()
{
	timerTipOn->stop();
	timerTipOff->stop();
	isToolTip = false;
	QToolTip::showText(mapToGlobal(point),QString(),this);
}

//----------------------------------------------------------------------------------------------------------------
bool AskuToolBar::event(QEvent *e)
{
	if(e->type() == QEvent::HoverEnter || e->type() == QEvent::HoverLeave || e->type() == QEvent::HoverMove)
	{
		QHoverEvent *ev = (QHoverEvent*)e;
		QAction *a = actionAt(ev->pos());
		if(a)
		{
			if(a != action || ev->pos()!=point)
			{
				if(isToolTip && a == action)
				{
					QToolTip::showText(mapToGlobal(point),QString(),this);
					QToolTip::showText(mapToGlobal(ev->pos()),makeToolTipText(action),this);
				}
				else
				{
					timeoutOff();
					timerTipOn->stop();
					timerTipOn->start(1500);
				}
			}
		}
		else
		{
			timeoutOff();
		}
		point = ev->pos();
		action = a;
	}
	return QToolBar::event(e);
}

//----------------------------------------------------------------------------------------------------------------
AskuMainWindow :: AskuMainWindow(QWidget* pwgt) : QMainWindow(pwgt)
{
	m_config = NULL;
	m_rlsName = QString();
	m_rlsConfig.clear();

	if(settingsUI)
		setFont(settingsUI->getDialogFont());

//Создать панель инструментов
	m_toolBar = new AskuToolBar(this);
	addToolBar(m_toolBar);

//Создать строку состояния
	m_statusBar = new AskuStatusBar(this);
	setStatusBar(m_statusBar);

//Создание центрального виджета
	m_centralWgt = new AskuCentralWidget(this);
	setCentralWidget(m_centralWgt);
}

//-----------------------------------------------------------------------------
AskuMainWindow::~AskuMainWindow() 
{
}

//-------------------------------------------------------------------------------
void AskuMainWindow::setRlsName(QString name)
{
	m_rlsName = name;
}

//-------------------------------------------------------------------------------
void AskuMainWindow::setLevelCollection(AskuLevelCollection * coll)
{
	if(m_centralWgt)
		m_centralWgt->setLevelCollection(coll);
}

//-------------------------------------------------------------------------------
void AskuMainWindow::applyConfig()
{
	if(!m_config)
		return;

	m_rlsConfig = m_config->makeRlsConfig();

	AskuMainWindowConfig cfg = m_config->makeMainWindowConfig();

	if(cfg.contains("name"))
	{
		setObjectName(cfg["name"].toString());
	}

	if(cfg.contains("header"))
	{
		if(!m_rlsConfig.text(m_rlsName).isEmpty())
			setWindowTitle(m_rlsConfig.text(m_rlsName) + " - " + cfg["header"].toString());
		else
			setWindowTitle(cfg["header"].toString());
	}
	else
	{
		if(!m_rlsConfig.text(m_rlsName).isEmpty())
			setWindowTitle(m_rlsConfig.text(m_rlsName) + " - " + "ASKU");
		else
			setWindowTitle("ASKU");
		LogError("AskuMainWindowConfig: set default title");
	}

	if(cfg.contains("pixmap"))
	{
		QString a_pixmap = cfg["pixmap"].toString();
		if(m_pixmaps.contains(a_pixmap))
			setWindowIcon(m_pixmaps[a_pixmap]);
 		else
 		{
			LogError("AskuMainWindowConfig: config pixmap (%s) not found", qPrintable(a_pixmap));
		}
	}
	else
	{
		LogError("AskuMainWindowConfig: config has no pixmap");
	}

	if(cfg.contains("central_name"))
	{
		QString a_central_name = cfg["central_name"].toString();
		if(!a_central_name.isEmpty())
			m_centralWgt->setObjectName(a_central_name);
	}

	if(cfg.contains("toolbar_name"))
	{
		QString a_toolbar_name = cfg["toolbar_name"].toString();
		if(!a_toolbar_name.isEmpty())
			m_toolBar->setObjectName(a_toolbar_name);
	}

	if(cfg.contains("menu_name"))
	{
		QString a_menu_name = cfg["menu_name"].toString();
		if(!a_menu_name.isEmpty())
			m_centralWgt->contextMenu()->setObjectName(a_menu_name);
	}

	if(cfg.contains("statusbar_name"))
	{
		QString a_statusbar_name = cfg["statusbar_name"].toString();
		if(!a_statusbar_name.isEmpty())
			m_statusBar->setObjectName(a_statusbar_name);
	}
}

//-------------------------------------------------------------------------------
void AskuMainWindow::setConfig(AskuConfig* config)
{
	if(!config)
		return;

	m_config = config;

	connect(config,SIGNAL(updated()),this,SLOT(applyConfig()));

	applyConfig();
}

//-------------------------------------------------------------------------------
void AskuMainWindow::applyActions()
{
	if(!m_config || !m_actions)
		return;

	m_actions->addActions(this, NULL, m_config->makeMainWindowActions(m_rlsName));
	m_actions->addActions(this, m_centralWgt->contextMenu(), m_config->makeMainContextMenuActions(m_rlsName));
	m_actions->addActions(this, m_toolBar, m_config->makeMainToolBarActions(m_rlsName));

	if(m_setup.main.shema)
	{
		QAction *action = m_actions->value(rlsName() + "act_level_zal");
		if(action)
			action->setChecked(true);
	}
	else
	{
		QAction *action = m_actions->value(rlsName() + "act_level_base");
		if(action)
			action->setChecked(true);
	}
}

//-------------------------------------------------------------------------------
void AskuMainWindow::setActions(AskuActions *actions)
{
	if(!actions)
		return;

	m_actions = actions;
	connect(actions, SIGNAL(updated()), this, SLOT(applyActions()));
	connect(actions, SIGNAL(invokeAction(QString, QStringList)), this, SLOT(invokeAction(QString, QStringList)));

	applyActions();
}

//-------------------------------------------------------------------------------
void AskuMainWindow::invokeAction(QString name, QStringList parameters)
{
	Q_UNUSED(parameters);
//	LogInfo("AskuMainWindow::invokeAction : \"%s\"", qPrintable(name));

	if(name.startsWith(rlsName() + "act_main_show"))
		slotActionShow();
	else if(name.startsWith(rlsName() + "act_main_hide"))
		slotActionHide();
	else if(name.startsWith("act_quit"))
		slotActionQuit();
	else if(name.startsWith(rlsName() + "act_level_up"))
		slotActionLevelUp();
	else if(name.startsWith(rlsName() + "act_level_base"))
		slotActionLevelTop(0);
	else if(name.startsWith(rlsName() + "act_level_zal"))
		slotActionLevelTop(1);
}

//-------------------------------------------------------------------------------
//Завершение работы программы (вызов окна с запросом)
void AskuMainWindow::slotActionQuit()
{
	close();
}

//-------------------------------------------------------------------------------
//Завершение работы программы (подтвержденное)
void AskuMainWindow::onClose()
{
	emit sigQuit();
}

//-------------------------------------------------------------------------------
//Событие завершение работы программы
void AskuMainWindow::closeEvent(QCloseEvent *event)
{
	if(/*m_setup.main.shutdown || m_setup.main.reboot ||*/ m_setup.main.terminate)
	{
		//onClose();
		event->accept();
		return;
	}

/*	if(!checkPassword())
	{
		event->ignore();
		return;
	}
*/
	int button = QMessageBox::question(this, "АСКУ", "Завершить работу?", "Да", "Нет");

	if(button == QMessageBox::AcceptRole) //yes
	{
		m_setup.main.terminate = 1;
		onClose();
		event->accept();
	}
	else if(button == QMessageBox::RejectRole)//no
	{
		event->ignore();
	}
}

//-------------------------------------------------------------------------------
//На уровень вверх
void AskuMainWindow::slotActionLevelUp()
{
	m_centralWgt->levelUp();
}

//-------------------------------------------------------------------------------
//Схема зала или структурная
void AskuMainWindow::slotActionLevelTop(int showZal)
{
	m_setup.main.shema = showZal;
	m_centralWgt->levelTop(showZal);
}

//-------------------------------------------------------------------------------
void AskuMainWindow::onChangedRegime(QString nameRegime)
{
	m_statusBar->setRegimeText(nameRegime);
}

//-------------------------------------------------------------------------------
void AskuMainWindow::slotActionHide()
{
	hide();
}

//-------------------------------------------------------------------------------
void AskuMainWindow::slotActionShow()
{
	showMaximized();
	raise();
	activateWindow();
	emit sigRaise();
}

//----------------------------------------------------------------------------------------------------------------
void AskuMainWindow::applyGraphic()
{
	setFont(settingsUI->getDialogFont());
	m_centralWgt->applyGraphic();
}

//-------------------------------------------------------------------------------
bool AskuMainWindow::checkPassword()
{
	DlgPassword dlg;

	if(dlg.isBlocked())
		return true;

	int result = dlg.exec();

	if(result == QDialog::Accepted)
		return true;
	else
		return false;
}

//----------------------------------------------------------------------------------------------------------------
