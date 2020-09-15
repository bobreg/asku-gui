#include <QDate>
#include <QTime>
#include <QMenu>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDesktopWidget>

#include "../common/logger.h"
#include "globalvar.h"
#include "xpmset.h"
#include "smallwindow.h"
#include "actions.h"

//----------------------------------------------------------------------------------------------------------------

// ASKU Small Window's Frame
// *************************

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindowFrame::AskuSmallWindowFrame(Type type, QString name, QString text, QString initialState, QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	f_type = type;
	f_text = (type == User) ? text : inlineText(type);
	f_sui  = settingsUI;
	f_sid  = AskuSmallWindow::stringToState(initialState);

	setObjectName(name);

	f_lp.setStyle(Qt::SolidLine);
	f_tp.setStyle(Qt::SolidLine);
	f_bb.setStyle(Qt::SolidPattern);
	f_fb.setStyle(Qt::SolidPattern);

	if (f_sui)
	{
		connect(f_sui, SIGNAL(changed()), this, SLOT(applyGraphic()));
		setFont(f_sui->getMainFont());
	}
}

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindowFrame::~AskuSmallWindowFrame()
{

}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::applyGraphic()
{
	if(f_sui)
		setFont(f_sui->getMainFont());

	repaint();
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setSUI(SettingsUI* sui)
{
	if (f_sui)
		disconnect(f_sui, SIGNAL(changed()), this, SLOT(repaint()));
	f_sui = sui;
	if (f_sui)
		connect(f_sui, SIGNAL(changed()), this, SLOT(repaint()));
	repaint();
}

//----------------------------------------------------------------------------------------------------------------
inline unsigned char AskuSmallWindowFrame::pureState() const
{
	return (f_sid % 10);
}

//----------------------------------------------------------------------------------------------------------------
inline bool AskuSmallWindowFrame::controlled() const
{
	return (f_sid != SCHEMEITEM_OUTOFSERVICE);
}

//----------------------------------------------------------------------------------------------------------------
inline bool AskuSmallWindowFrame::local() const
{
	return (f_sid > 9);
}

//----------------------------------------------------------------------------------------------------------------
QString AskuSmallWindowFrame::inlineText(Type type)
{
	QString result;
	switch (type)
	{
		case Date:	result = QDate::currentDate().toString("dd.MM.yyyy");
					break;
		case Time:	result = QTime::currentTime().toString("hh:mm:ss");
					break;
		case User:	result = f_text;
					break;
	}
	return result;
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setName(QString name)
{
	setObjectName(name);
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setText(QString text)
{
	if (f_text != text)
	{
		f_text = text;
		repaint();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setInlineText()
{
	QString text = inlineText(f_type);
	if (f_text != text)
	{
		f_text = text;
		repaint();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setState(unsigned char state)
{
	if ((f_sid != SCHEMEITEM_OUTOFSERVICE) && (f_sid != state))
	{
		f_sid = state;
		repaint();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setPureState(unsigned char pureState)
{
	if (f_sid != SCHEMEITEM_OUTOFSERVICE)
	{
		pureState = pureState % 10;
		pureState = pureState + 10 * (int)(f_sid > 9);
		if (f_sid != pureState)
		{
			f_sid = pureState;
			repaint();
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setControlled(bool controlled)
{
	if (f_sid != SCHEMEITEM_OUTOFSERVICE && !controlled)
	{
		f_sid = SCHEMEITEM_OUTOFSERVICE;
		repaint();
	}
	else if (f_sid == SCHEMEITEM_OUTOFSERVICE && controlled)
	{
		f_sid = SCHEMEITEM_TURNOFF;
		repaint();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::setLocal(bool local)
{
	if (f_sid != SCHEMEITEM_OUTOFSERVICE)
	{
		if (f_sid > 9 && !local)
		{
			f_sid = f_sid % 10;
			repaint();
		}
		else if (f_sid < 10 && local)
		{
			f_sid += 10;
			repaint();
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindowFrame::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	int w = width()  - 1;
	int h = height() - 1;
	int d = (int)((w + h) / 30);
	if (d < 1)
		d = 1;
	// Get pens and brushes from UI settings (if any)
	if (f_sui)
	{
		f_lp.setColor(f_sui->getLineColor());
		f_tp.setColor(f_sui->getItemTextColor(pureState()));
		f_bb.setColor(f_sui->getItemBodyColor(pureState()));
		f_fb.setColor(f_sui->getItemBodyColor(SCHEMEITEM_LOCAL));
	}
	else
	{
		f_lp.setColor(Qt::black);
		f_tp.setColor(Qt::black);
		f_fb.setColor(Qt::yellow);
		switch (pureState())
		{
			case SCHEMEITEM_NORMAL:			f_bb.setColor(QColor(0,  255,0  ));
											break;
			case SCHEMEITEM_WORSENING:		f_bb.setColor(QColor(255,128,128));
											break;
			case SCHEMEITEM_DENY:			f_bb.setColor(QColor(255,0,  0  ));
											break;
			case SCHEMEITEM_TURNOFF:		f_bb.setColor(QColor(128,128,128));
											break;
			case SCHEMEITEM_OUTOFSERVICE:	f_bb.setColor(QColor(192,192,192));
											break;
			case SCHEMEITEM_SUBSTRATE:		f_bb.setColor(QColor(0,  128,128));
											break;
			default:						f_bb.setColor(QColor(255,255,255));
		}
	}
	// Frame for "Local"
	if (local())
	{
		painter.setPen  (f_lp);
		painter.setBrush(f_fb);
		painter.drawRect(0, 0, w, h);
	}
	// Body
	painter.setBrush(f_bb);
	if (local())
	{
		painter.setPen(f_lp);
		painter.drawRect(d, d, w - 2 * d, h - 2 * d);
	}
	else
	{
		painter.setPen(f_lp);
		painter.drawRect(0, 0, w, h);
	}
	if (!f_text.isNull() && !f_text.isEmpty())
	{
		painter.setPen(f_tp);
		painter.drawText(0, 0, w, h, Qt::AlignCenter, f_text);
	}
}

//----------------------------------------------------------------------------------------------------------------

// ASKU Small Window
// *****************

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindow::AskuSmallWindow(QWidget* parent) : QWidget(parent, Qt::Window | Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint
#if defined(ASTRA_LINUX)
 | Qt::X11BypassWindowManagerHint
#endif
 )
{
	f_sui = settingsUI;
	m_config = NULL;
	m_actions = NULL;

//	setWindowIcon(m_pixmaps["icon.xpm"]);
//	setWindowTitle("АСКУ");

	// Window geometry
/*	QDesktopWidget dw;
	QRect rc = dw.screenGeometry();
	int sizeX = (int)(rc.width()  /  5);
	int sizeY = (int)(rc.height() / 13);
	move(QPoint(rc.right() - sizeX, rc.bottom() - sizeY));
	sizeX--;
	sizeY--;
	resize(sizeX, sizeY);
	setMinimumSize(sizeX, sizeY);
	setMaximumSize(sizeX, sizeY);
*/
/*
	// Item's layouts
	QVBoxLayout* l = new QVBoxLayout();
	f_ltop = new QHBoxLayout();
	f_lbot = new QHBoxLayout();
	f_ltop->setSpacing(3);
	f_lbot->setSpacing(3);
	l->addLayout(f_ltop);
	l->addLayout(f_lbot);
	l->setSpacing(3);
	l->setContentsMargins(2,2,2,2);
	setLayout(l);
*/
	// Timer
	f_timer  = new QTimer(this);
	connect(f_timer, SIGNAL(timeout()), this, SLOT(update()));

/*	// Window items
	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::Time, f_sui, SCHEMEITEM_OUTOFSERVICE, this));
	connect(f_timer, SIGNAL(timeout()), f_frames[0], SLOT(setInlineText()));
	f_lbot->addWidget(f_frames[0]);
	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::Date, f_sui, SCHEMEITEM_OUTOFSERVICE, this));
	connect(f_timer, SIGNAL(timeout()), f_frames[1], SLOT(setInlineText()));
	f_lbot->addWidget(f_frames[1]);
	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::RLS,  f_sui, SCHEMEITEM_TURNOFF,      this));
	f_ltop->addWidget(f_frames[2]);
//	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::MOD,  f_sui, SCHEMEITEM_TURNOFF,      this));
//	f_ltop->addWidget(f_frames[3]);
//	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::LS,   f_sui, SCHEMEITEM_TURNOFF,      this));
//	f_ltop->addWidget(f_frames[4]);
	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::UUVK, f_sui, SCHEMEITEM_TURNOFF,      this));
	f_ltop->addWidget(f_frames[3]);
	f_frames.append(new AskuSmallWindowFrame(AskuSmallWindowFrame::PS,   f_sui, SCHEMEITEM_TURNOFF,      this));
	f_ltop->addWidget(f_frames[4]);
*/
	// Popup menu
	f_menu = new QMenu(this);
	f_menu->setFont(f_sui->getDialogFont());

	connect(f_sui, SIGNAL(changed()), this, SLOT(applyGraphic()));

	f_timer->start(500);
}

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindow::~AskuSmallWindow()
{
	f_timer->stop();
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setConfig(AskuConfig* config)
{
	if(!config)
		return;

	m_config = config;
	connect(config,SIGNAL(updated()),this,SLOT(applyConfig()));

	applyConfig();
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::applyConfig()
{
	if(!m_config)
		return;

	clear();

	AskuSmallWindowConfig cfg = m_config->makeSmallWindowConfig();

	if(cfg.contains("name"))

	{
		setObjectName(cfg["name"].toString());
	}

	if(cfg.contains("header"))
	{
		setWindowTitle(cfg["header"].toString());
	}
	else
	{
		setWindowTitle("ASKU");
		LogError("AskuSmallWindowConfig: set default title");
	}

	if(cfg.contains("pixmap"))
	{
		QString a_pixmap = cfg["pixmap"].toString();
		if(m_pixmaps.contains(a_pixmap))
			setWindowIcon(m_pixmaps[a_pixmap]);
 		else
 		{
			LogError("AskuSmallWindowConfig: config pixmap (%s) not found", qPrintable(a_pixmap));
		}
	}
	else
	{
		LogError("AskuSmallWindowConfig: config has no pixmap");
	}

	if(cfg.contains("width") && cfg.contains("height"))
	{
		QString a_width = cfg["width"].toString();
		QString a_height = cfg["height"].toString();
		setGeometry(a_width, a_height);
	}
	else
	{
		LogError("AskuSmallWindowConfig: config has no width or height");
		setGeometry();
	}

	if(cfg.contains("align"))
	{
		QString a_align = cfg["align"].toString();
		QString a_x = QString();
		QString a_y = QString();

		if(cfg.contains("x") && cfg.contains("y"))
		{
			a_x = cfg["x"].toString();
			a_y = cfg["y"].toString();
		}

		setWindowAlign(a_align, a_x, a_y);
	}
	else
	{
		LogError("AskuSmallWindowConfig: config has no align");
		setWindowAlign();
	}

	if(cfg.contains("menu_name"))
	{
		QString a_menu_name = cfg["menu_name"].toString();
		if(!a_menu_name.isEmpty())
			f_menu->setObjectName(a_menu_name);
	}

	if(cfg.contains("rows"))
	{
		QVariantList rows = cfg["rows"].toList();
		setWindowItems(rows);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setGeometry(QString a_width, QString a_height)
{
	qint32 sizeX = 0, sizeY = 0;
	QRect rc = QDesktopWidget().screenGeometry();

	if(!a_width.isEmpty() && !a_height.isEmpty())
	{
		if(a_width.contains('%'))
		{
			a_width.remove('%');
			bool ok = false;
			float w = a_width.toFloat(&ok);
			if(!ok)
			{
				LogError("AskuSmallWindowConfig: invalid width (%s%%)", qPrintable(a_width));
			}
			else
			{
				sizeX = (qint32)((float)rc.width() * w / 100.0f);
			}
		}
		else
		{
			bool ok = false;
			sizeX = a_width.toUInt(&ok);
			if(!ok)
			{
				LogError("AskuSmallWindowConfig: invalid width (%s)", qPrintable(a_width));
			}
		}
	
		if(a_height.contains('%'))
		{
			a_height.remove('%');
			bool ok = false;
			float h = a_height.toFloat(&ok);
			if(!ok)
			{
				LogError("AskuSmallWindowConfig: invalid height (%s%%)", qPrintable(a_height));
			}
			else
			{
				sizeY = (qint32)((float)rc.height() * h / 100.0f);
			}
		}
		else
		{
			bool ok = false;
			sizeY = a_height.toUInt(&ok);
			if(!ok)
			{
				LogError("AskuSmallWindowConfig: invalid width (%s)", qPrintable(a_width));
			}
		}
	}

	if(sizeX == 0 || sizeY == 0)
	{
		sizeX = (int)(rc.width()  /  5);
		sizeY = (int)(rc.height() / 13);
	}

	sizeX--;
	sizeY--;
	resize(sizeX, sizeY);
	setMinimumSize(sizeX, sizeY);
	setMaximumSize(sizeX, sizeY);
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setWindowAlign(QString a_align, QString a_x, QString a_y)
{
	QRect wr = QRect(0, 0, width() + 1, height() + 1);
	QRect rc = QDesktopWidget().screenGeometry();

	if(a_align == "position")
	{
		bool ok_x = false, ok_y = false;

		qint32 x = a_x.toUInt(&ok_x);
		qint32 y = a_y.toUInt(&ok_y);

		if(!ok_x || !ok_y)
		{
			LogError("AskuSmallWindowConfig: invalid position (%s,%s)", qPrintable(a_x), qPrintable(a_y));
			x = y = 0;
		}

		wr.moveTopLeft(QPoint(x, y));
	}
	else if(a_align == "topleft")
	{
		wr.moveTopLeft(QPoint(rc.left(), rc.top()));
	}
	else if(a_align == "topright")
	{
		wr.moveTopRight(QPoint(rc.right(), rc.top()));
	}
	else if(a_align == "topcenter")
	{
		wr.moveCenter(rc.center());
		wr.moveTop(rc.top());
	}
	else if(a_align == "bottomleft")
	{
		wr.moveBottomLeft(QPoint(rc.left(), rc.bottom()));
	}
	else if(a_align == "bottomright")
	{
		wr.moveBottomRight(QPoint(rc.right(), rc.bottom()));
	}
	else if(a_align == "bottomcenter")
	{
		wr.moveCenter(rc.center());
		wr.moveBottom(rc.bottom());
	}
	else if(a_align == "centerleft")
	{
		wr.moveCenter(rc.center());
		wr.moveLeft(rc.left());
	}
	else if(a_align == "centerright")
	{
		wr.moveCenter(rc.center());
		wr.moveRight(rc.right());
	}
	else if(a_align == "center")
	{
		wr.moveCenter(rc.center());
	}
	else
	{
		LogError("AskuSmallWindowConfig: invalid align (%s)", qPrintable(a_align));
		wr.moveBottomRight(QPoint(rc.right(), rc.bottom()));
	}

	move(wr.topLeft());
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::clear()
{
	if(!f_frames.isEmpty())
	{
		qDeleteAll(f_frames);
		f_frames.clear();
	}

	QLayout *oldLayout = layout();
	if(oldLayout)
		delete oldLayout;
}

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindowFrame* AskuSmallWindow::setWindowItem(QVariantMap element)
{
	QString a_type = QString();
	QString a_name = QString();
	QString a_state = QString();
	QString a_text = QString();

	AskuSmallWindowFrame::Type e_type = AskuSmallWindowFrame::User;

	if(element.contains("type"))
	{
		a_type = element["type"].toString();

		if(a_type == "date")
			e_type = AskuSmallWindowFrame::Date;
		else if(a_type == "time")
			e_type = AskuSmallWindowFrame::Time;
		else
			e_type = AskuSmallWindowFrame::User;
	}

	if(element.contains("name"))
		a_name = element["name"].toString();

	if(element.contains("state"))
		a_state = element["state"].toString();

	if(element.contains("text"))
		a_text = element["text"].toString();

	AskuSmallWindowFrame* frame = new AskuSmallWindowFrame(e_type, a_name, a_text, a_state, this);

	f_frames.append(frame);

	if(e_type == AskuSmallWindowFrame::Time || e_type == AskuSmallWindowFrame::Date)
		connect(f_timer, SIGNAL(timeout()), frame, SLOT(setInlineText()));

	return frame;
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setWindowItems(QVariantList rows)
{
//	int rowCount = 0, colCount = 0;

	QVBoxLayout* lv = new QVBoxLayout();
	lv->setSpacing(3);
	lv->setContentsMargins(2, 2, 2, 2);

	if(rows.isEmpty())
	{
		LogError("AskuSmallWindowConfig: config has no rows");
	}
	else
	{
//		rowCount = rows.count();

		foreach(QVariant row, rows)
		{
			QHBoxLayout* lh = new QHBoxLayout();
			lh->setSpacing(3);

			QVariantList cols = row.toList();
			if(cols.isEmpty())
			{
				LogError("AskuSmallWindowConfig: config has no cols");
			}
			else
			{
//				colCount = cols.count();

				foreach(QVariant col, cols)
				{
					QVariantMap element = col.toMap();
					if(!element.isEmpty())
					{
						AskuSmallWindowFrame * f = setWindowItem(element);
						if(f)
							lh->addWidget(f);
					}
				}
			}

			lv->addLayout(lh);
		}
	}

	setLayout(lv);
	update();
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::applyActions()
{
	if(!m_config || !m_actions)
		return;

	m_actions->addActions(this, NULL, m_config->makeSmallWindowActions());
	m_actions->addActions(this, f_menu, m_config->makeSmallContextMenuActions());
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setActions(AskuActions * actions)
{
	if(!actions)
		return;

	m_actions = actions;
	connect(actions,SIGNAL(updated()),this,SLOT(applyActions()));
	connect(actions, SIGNAL(invokeAction(QString, QStringList)), this, SLOT(invokeAction(QString, QStringList)));

	applyActions();
}

//-------------------------------------------------------------------------------
void AskuSmallWindow::invokeAction(QString name, QStringList parameters)
{
	Q_UNUSED(parameters);
//	LogInfo("AskuSmallWindow::invokeAction : \"%s\"", qPrintable(name));

	if(name.startsWith("act_quit"))
		slotActionQuit();
	else if(name.startsWith("act_reload_config"))
		slotActionReloadConfig();
}

//-------------------------------------------------------------------------------
void AskuSmallWindow::slotActionReloadConfig()
{
	if(m_config && m_config->isDefault())
		emit sigReloadConfig();
}
//-------------------------------------------------------------------------------
void AskuSmallWindow::slotActionQuit()
{
	if(m_config && m_config->isDefault())
	{
		close();
		emit sigQuit();
	}
}

//----------------------------------------------------------------------------------------------------------------
AskuSmallWindowFrame* AskuSmallWindow::item(QString name)
{
	foreach(AskuSmallWindowFrame* frame, f_frames)
		if(frame->objectName() == name)
			return frame;
	return NULL;
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setText(QString name, QString text)
{
	AskuSmallWindowFrame* frame = item(name);
	if(frame)
		frame->setText(text);
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setState(QString name, unsigned char state)
{
	AskuSmallWindowFrame* frame = item(name);
	if(frame)
		frame->setState(state);
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setPureState(QString name, unsigned char state)
{
	AskuSmallWindowFrame* frame = item(name);
	if(frame)
		frame->setPureState(state);
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		f_menu->exec(event->globalPos());
	}
	else if(event->button() == Qt::LeftButton)
	{
		move_x = event->x();
		move_y = event->y();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::mouseMoveEvent(QMouseEvent* event)
{
	move(QPoint(event->globalX() - move_x, event->globalY() - move_y));
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::closeEvent(QCloseEvent* event)
{
	event->ignore();
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::hideEvent(QHideEvent* event)
{
	event->ignore();
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setPen(QPen(f_sui->getLineColor()));
	painter.drawRect(0, 0, width() - 1, height() - 1);
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::applyGraphic()
{
	f_menu->setFont(f_sui->getDialogFont());
}

//----------------------------------------------------------------------------------------------------------------
unsigned char AskuSmallWindow::stringToState(QString state)
{
	unsigned char f_state = SCHEMEITEM_OUTOFSERVICE;

	if(state == "not")
		f_state = SCHEMEITEM_TURNOFF;
	else if(state == "avar")
		f_state = SCHEMEITEM_DENY;
	else if(state == "error")
		f_state = SCHEMEITEM_WORSENING;
	else if(state == "norma")
		f_state = SCHEMEITEM_NORMAL;
	else if(state == "mest")
		f_state = SCHEMEITEM_LOCAL;
	else if(state == "notmest")
		f_state = SCHEMEITEM_TURNOFF + 10;
	else if(state == "avarmest")
		f_state = SCHEMEITEM_DENY + 10;
	else if(state == "errormest")
		f_state = SCHEMEITEM_WORSENING + 10;
	else if(state == "normamest")
		f_state = SCHEMEITEM_NORMAL + 10;
	else if(state == "disable")
		f_state = SCHEMEITEM_OUTOFSERVICE;
	else if(state == "substrate")
		f_state = SCHEMEITEM_SUBSTRATE;

	return f_state;
}

//----------------------------------------------------------------------------------------------------------------
void AskuSmallWindow::setState(QString name, QString state)
{
	setState(name, stringToState(state));
}

//----------------------------------------------------------------------------------------------------------------
