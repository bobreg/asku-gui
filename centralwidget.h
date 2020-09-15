#ifndef _AskuCentralWidget_h_
#define _AskuCentralWidget_h_

#include <QtGlobal>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    #include <QtWidgets>
#else
    #include <QtGui>
#endif
#include <QWidget>
#include <QMenu>
#include <QPixmap>
#include <QCursor>
#include <QEvent>
#include "levelcollection.h"
#include "levelpainter.h"

//----------------------------------------------------------------------------------------------------------------

using AskuLevels::AskuLevelCollection;
using AskuLevels::AskuLevelPainter;
class SettingsUI;

//----------------------------------------------------------------------------------------------------------------

class AskuCentralWidget : public QWidget 
{
	Q_OBJECT

	AskuLevelCollection *m_collection;

	QCursor m_cursorArrow;
	QCursor m_cursorHand;
	QMenu *m_pmnu;
	QPixmap m_pix;

public:
	AskuCentralWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~AskuCentralWidget();

	void setLevelCollection(AskuLevelCollection *coll);

	QMenu* contextMenu();

	void levelUp();
	void levelTop(int showZal);
//	void levelReload();

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void contextMenuEvent(QContextMenuEvent* event);
	void paintEvent(QPaintEvent* event);

public slots:
	void applyGraphic();

signals:
	void sigInfo(qint32 parameter1, qint32 parameter2);
};

//----------------------------------------------------------------------------------------------------------------

#endif //_AskuCentralWidget_h_
