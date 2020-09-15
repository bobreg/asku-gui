#include "../common/logger.h"
#include "globalvar.h"
#include "centralwidget.h"
#include "settingsui.h"

//----------------------------------------------------------------------------------------------------------------
AskuCentralWidget::AskuCentralWidget(QWidget * parent, Qt::WindowFlags f) : 
	QWidget(parent, f),	m_cursorArrow(Qt::ArrowCursor),	m_cursorHand(Qt::PointingHandCursor)
{
	setMouseTracking(true);

//Пиксмап для рисования
	QRect rc = QApplication::desktop()->screenGeometry(this);
	m_pix = QPixmap(rc.width(),rc.height());
	m_pix.fill(settingsUI->getBackgroundColor());

//Контекстное меню
	m_pmnu = new QMenu(this);
	m_pmnu->setFont(settingsUI->getDialogFont());

//Схемы
	m_collection = NULL;
}

//----------------------------------------------------------------------------------------------------------------
AskuCentralWidget::~AskuCentralWidget() 
{
	delete m_pmnu;
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::setLevelCollection(AskuLevelCollection *coll)
{
	m_collection = coll;
	if(m_collection)
		connect(m_collection, SIGNAL(changed()), this, SLOT(update()));
}

//----------------------------------------------------------------------------------------------------------------
QMenu* AskuCentralWidget::contextMenu()
{
	return m_pmnu;
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::contextMenuEvent(QContextMenuEvent* event)
{
	m_pmnu->exec(event->globalPos());
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::mousePressEvent(QMouseEvent* event)
{
	if(m_collection != NULL && event->button() == Qt::LeftButton)
	{
		if(m_collection->mousePress(event->pos()))
		{
			if(m_collection->mouseMove(event->pos()))
				setCursor(m_cursorHand);
			else
				setCursor(m_cursorArrow);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::mouseMoveEvent(QMouseEvent* event)
{
	if(m_collection != NULL && m_collection->mouseMove(event->pos()))
		setCursor(m_cursorHand);
	else
		setCursor(m_cursorArrow);
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	if(m_collection != NULL && m_collection->needUpdate())
	{
		m_pix.fill(settingsUI->getBackgroundColor());
		AskuLevelPainter paint(&m_pix);
		m_collection->draw(&paint);
	}

	QPainter(this).drawPixmap(0, 0, m_pix);
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::levelUp()
{
	setCursor(m_cursorArrow);
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::levelTop(int showZal)
{
	Q_UNUSED(showZal);

	setCursor(m_cursorArrow);
}

//----------------------------------------------------------------------------------------------------------------
void AskuCentralWidget::applyGraphic()
{
	setFont(settingsUI->getMainFont());
	m_pmnu->setFont(settingsUI->getDialogFont());
}

//-----------------------------------------------------------------------------
