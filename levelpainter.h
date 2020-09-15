#ifndef __LEVELPAINTER_H__
#define __LEVELPAINTER_H__

#include <QPainter>
#include "settingsui.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------

class AskuLevelPrimitive;
class AskuLevelTitle;
class AskuLevelLine;
class AskuLevelText;
class AskuLevelElement;

//----------------------------------------------------------------------------------------------------------------

class AskuLevelPainter : public QPainter
{
	static qreal m_scaleX;
	static qreal m_scaleY;
	static qreal m_centerX;
	static qreal m_centerY;

	void drawSwitch(AskuLevelElement* element);
	void drawElementText(AskuLevelElement* element);

public:
	AskuLevelPainter(QPaintDevice * device);

	static int optimizeX(int x);
	static int optimizeY(int y);
	static QPolygon optimize(QPolygon polygon);
	static QRect optimize(QRect rect);
	static QPoint optimize(QPoint point);

	static QPoint unoptimize(QPoint point);
	static int unoptimizeX(int x);
	static int unoptimizeY(int y);

	void draw(AskuLevelPrimitive* primitive);
	void draw(AskuLevelTitle* title);
	void draw(AskuLevelText* text);
	void draw(AskuLevelLine* line);
	void draw(AskuLevelElement* element);
};

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels;

//----------------------------------------------------------------------------------------------------------------

#endif // __LEVELPAINTER_H__
