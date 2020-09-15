#include <QString>
#include "../common/logger.h"
#include "levelpainter.h"
#include "levelstructure.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------

const qreal EtalonScreenX = 1280;
const qreal EtalonScreenY = 1024;

qreal AskuLevelPainter::m_scaleX = 0.0;
qreal AskuLevelPainter::m_scaleY = 0.0;
qreal AskuLevelPainter::m_centerX = 0.0;
qreal AskuLevelPainter::m_centerY = 0.0;

//----------------------------------------------------------------------------------------------------------------
AskuLevelPainter::AskuLevelPainter(QPaintDevice * device) : QPainter(device)
{
	m_centerX = this->device()->width() / 2;
	m_centerY = this->device()->height() / 2;
	m_scaleX = this->device()->width()  * (qreal)settingsUI->getScaleX() / 100 / EtalonScreenX;
	m_scaleY = this->device()->height() * (qreal)settingsUI->getScaleY() / 100 / EtalonScreenY;
}

//----------------------------------------------------------------------------------------------------------------
QPolygon AskuLevelPainter::optimize(QPolygon polygon)
{
	QPolygon poly;
	foreach(QPoint pt, polygon.toList())
		poly.append(optimize(pt));
	return poly;
}

//----------------------------------------------------------------------------------------------------------------
QRect AskuLevelPainter::optimize(QRect rect)
{
	return QRect(optimize(rect.topLeft()), optimize(rect.bottomRight()));
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelPainter::optimize(QPoint point)
{
	return QPoint(optimizeX(point.x()), optimizeY(point.y()));
}

//----------------------------------------------------------------------------------------------------------------
int AskuLevelPainter::optimizeX(int x)
{
	qreal nx = x - EtalonScreenX / 2;
	return (int)(nx * m_scaleX + m_centerX);
}

//----------------------------------------------------------------------------------------------------------------
int AskuLevelPainter::optimizeY(int y)
{
	return (int)((qreal)y * m_scaleY);
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelPainter::unoptimize(QPoint point)
{
	return QPoint(unoptimizeX(point.x()), unoptimizeY(point.y()));
}

//----------------------------------------------------------------------------------------------------------------
int AskuLevelPainter::unoptimizeX(int x)
{
	if(m_scaleX == 0)
		return 0;

	int nx = ((qreal)(x - m_centerX)) / m_scaleX;
	return (nx + EtalonScreenX / 2);
}

//----------------------------------------------------------------------------------------------------------------
int AskuLevelPainter::unoptimizeY(int y)
{
	return m_scaleY != 0.0 ? (int)((qreal)y / m_scaleY) : 0;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::draw(AskuLevelPrimitive* primitive)
{
	AskuLevelElement* element = qobject_cast<AskuLevelElement*>(primitive);
	if(element)
	{
		draw(element);
		return;
	}

	AskuLevelText* text = qobject_cast<AskuLevelText*>(primitive);
	if(text)
	{
		draw(text);
		return;
	}

	AskuLevelLine* line = qobject_cast<AskuLevelLine*>(primitive);
	if(line)
	{
		draw(line);
		return;
	}

	AskuLevelTitle* title = qobject_cast<AskuLevelTitle*>(primitive);
	if(title)
	{
		draw(title);
		return;
	}

	LogDrawError("AskuLevelPainter: unknown primitive type");
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::draw(AskuLevelTitle* title)
{
	setPen(settingsUI->getHeaderFontColor());
	setFont(settingsUI->getHeaderFont());

	QRect rh = boundingRect(0, 0, 0, 0, 0, title->text());
	rh.moveBottomLeft(optimize(title->point() + QPoint(0,5)));
	drawText(rh, Qt::AlignTop | Qt::AlignLeft, title->text());
	title->setBoundingRect(rh);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::draw(AskuLevelText* text)
{
	setPen(settingsUI->getLineColor());
	setFont(settingsUI->getMainFont());

	TextOrientation orientation = text->orientation();
	rotate(angleRotate(orientation, true));

	QPoint pt = optimize(text->point() + QPoint(0,5));
	pt = pointRotate(orientation, pt);

	QRect rh = boundingRect(0, 0, 0, 0, 0, text->text());
	TextAligns align = text->align();

	rh.moveCenter(pt);

	if(align & AlignLeft)
		rh.moveLeft(pt.x());
	else if(align & AlignRight)
		rh.moveRight(pt.x());

	if(align & AlignTop)
		rh.moveTop(pt.y());
	else if(align & AlignBottom)
		rh.moveBottom(pt.y());

	drawText(rh, Qt::AlignCenter, text->text());

	rotate(angleRotate(orientation, false));
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::draw(AskuLevelLine* line)
{
	QPoint ptB1, ptB2, ptE1, ptE2;
	QPoint ptB = optimize(line->pointBegin());
	QPoint ptE = optimize(line->pointEnd());
	const int arrowSize = 5;

	setPen(settingsUI->getLineColor());
	drawLine(ptB, ptE);

/*******/
//Номера линий на схеме(для отладки)
/*
	QString string = QString("%1(%2 %3-%4)").arg(line->name()).arg((int)line->form()).arg(line->pointBegin().y()).arg(line->pointEnd().y());
	int x1 = ptB.x();
	int x2 = ptE.x();
	int y1 = ptB.y();
	int y2 = ptE.y();
	drawText(qMin(x1,x2)+abs((x2-x1)/2),qMin(y1,y2)+abs((y2-y1)/2), string);
*/
/*******/

	if(line->form()==ArrowBoth || line->form()==ArrowLeft)
	{
		if(line->pointBegin().y() == line->pointEnd().y())
		{
			ptB1 = optimize(line->pointBegin() + QPoint( arrowSize, arrowSize));
			ptB2 = optimize(line->pointBegin() + QPoint( arrowSize,-arrowSize));
		}
		else
		{
			ptB1 = optimize(line->pointBegin() + QPoint( arrowSize, arrowSize));
			ptB2 = optimize(line->pointBegin() + QPoint(-arrowSize, arrowSize));
		}

		drawLine(ptB, ptB1);
		drawLine(ptB, ptB2);
	}

	if(line->form()==ArrowBoth || line->form()==ArrowRight)
	{
		if(line->pointBegin().y() == line->pointEnd().y())
		{
			ptE1 = optimize(line->pointEnd() + QPoint(-arrowSize,-arrowSize));
			ptE2 = optimize(line->pointEnd() + QPoint(-arrowSize, arrowSize));
		}
		else
		{
			ptE1 = optimize(line->pointEnd() + QPoint( arrowSize,-arrowSize));
			ptE2 = optimize(line->pointEnd() + QPoint(-arrowSize,-arrowSize));
		}

		drawLine(ptE, ptE1);
		drawLine(ptE, ptE2);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::drawSwitch(AskuLevelElement* element)
{
	int nDW = element->rect().width() / 5;
	int nDH = element->rect().height() / 4;

	QRect rt(optimize(element->rect().topLeft() + QPoint(nDW, nDH + 1)), optimize(element->rect().bottomRight() + QPoint(-nDW, -nDH)));

	drawRect(rt);

	setBrush(settingsUI->getItemBodyColor(element->pureState()));
	setFont(settingsUI->getMainFont());

	switch(element->pureState())
	{
		case Norma:
		{
			QRect rn(optimize(element->rect().topLeft() + QPoint(nDW, nDH + 1)), optimize(element->rect().bottomRight() + QPoint(-nDW, -element->rect().height()/2)));
			drawRect(rn);
			break;
		}

		case Avar:
		{
			QRect re(optimize(element->rect().topLeft() + QPoint(nDW, 1 + element->rect().height()/2)), optimize(element->rect().bottomRight() + QPoint(-nDW, - nDH)));
			drawRect(re);
			break;
		}

		default:
			drawRect(rt);
			break;
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::draw(AskuLevelElement* element)
{
	QRect r = optimize(element->rect());
	QRect rn = optimize(QRect(element->rect().topLeft() + QPoint(5, 6), element->rect().bottomRight() + QPoint(-5, -5)));
	QPolygon poly = optimize(element->polygon());
	bool rounded = (bool)element->radius();
	qreal rad_x = optimizeX(element->radius());
	qreal rad_y = optimizeY(element->radius());
	bool mest = element->isMestState();

	switch(element->state())
	{
		case NormaMest:
		case ErrorMest:
		case AvarMest:
		case NotMest:
		case Norma:
		case Error:
		case Avar:
		case Not:
		case Disable:
		case Substrate:
		case Mest:

			switch(element->form())
			{
				case DashedRectangle:

					if(mest)
					{
						setBrush(settingsUI->getItemBodyColor(SCHEMEITEM_LOCAL));
						setPen(QPen(settingsUI->getLineColor(), 2, Qt::DashLine));

						if(rounded)
							drawRoundedRect(r, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(r);

						setBrush(settingsUI->getItemBodyColor(element->pureState()));
						setPen(settingsUI->getLineColor());

						if(rounded)
							drawRoundedRect(rn, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(rn);
					}
					else
					{
						setBrush(settingsUI->getItemBodyColor(element->pureState()));
						setPen(QPen(settingsUI->getLineColor(), 2, Qt::DashLine));

						if(rounded)
							drawRoundedRect(r, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(r);

						setPen(settingsUI->getLineColor());
					}

					break;

				case Rectangle:

					if(mest)
					{
						setBrush(settingsUI->getItemBodyColor(SCHEMEITEM_LOCAL));
						setPen(settingsUI->getLineColor());

						if(rounded)
							drawRoundedRect(r, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(r);

						setBrush(settingsUI->getItemBodyColor(element->pureState()));

						if(rounded)
							drawRoundedRect(rn, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(rn);
					}
					else
					{
						setBrush(settingsUI->getItemBodyColor(element->pureState()));
						setPen(settingsUI->getLineColor());

						if(rounded)
							drawRoundedRect(r, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(r);
					}

					break;

				case Ellipse:

					if(mest)
					{
						setBrush(settingsUI->getItemBodyColor(SCHEMEITEM_LOCAL));
						setPen(settingsUI->getLineColor());
						drawEllipse(r);

						setBrush(settingsUI->getItemBodyColor(element->pureState()));
						drawEllipse(rn);
					}
					else
					{
						setBrush(settingsUI->getItemBodyColor(element->pureState()));
						setPen(settingsUI->getLineColor());
						drawEllipse(r);
					}

					break;

				case Switch:

					if(mest)
					{
						setBrush(settingsUI->getItemBodyColor(SCHEMEITEM_LOCAL));
						setPen(settingsUI->getLineColor());

						if(rounded)
							drawRoundedRect(r, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(r);

						setBrush(settingsUI->getItemBodyColor(SCHEMEITEM_SUBSTRATE));

						if(rounded)
							drawRoundedRect(rn, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(rn);

						drawSwitch(element);
					}
					else
					{
						setBrush(settingsUI->getItemBodyColor(SCHEMEITEM_SUBSTRATE));
						setPen(settingsUI->getLineColor());

						if(rounded)
							drawRoundedRect(r, rad_x, rad_y, Qt::AbsoluteSize);
						else
							drawRect(r);
	
						drawSwitch(element);
					}

					break;

				case Polygon:

					setBrush(settingsUI->getItemBodyColor(element->pureState()));
					setPen(settingsUI->getLineColor());
					drawPolygon(poly);

					break;

				case TextOnly:

					break;

				default:
					LogDrawError("AskuLevelPainter: unknown element form");
			}

			break;
			
		default:
			LogDrawError("AskuLevelPainter: unknown element state");
	}

	if(!element->texts().isEmpty())
		drawElementText(element);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPainter::drawElementText(AskuLevelElement* element)
{
	QRect r = optimize(element->rect());
	QString text;
	TextOrientation orientation;
	TextAligns align;

	setPen(settingsUI->getItemTextColor(element->pureState()));
	setFont(settingsUI->getMainFont());

	switch(element->textform())
	{
		case AllAsOne:
		case SeparateLine:

			text = element->etexts().toString(element->textform() == SeparateLine ? "\n" : " ");

			if(text.isEmpty())
				break;

			align = element->aligns();
			orientation = element->orientations();

			rotate(angleRotate(orientation, true));
			drawText(rectRotate(orientation, r), AskuLevelText::alignToQt(align), text);
			rotate(angleRotate(orientation, false));

			break;

		case Individual:

			foreach(ElementText etext, element->etexts())
			{
				if(!etext.isVisible())
					continue;

				QPoint pt = optimize(etext.point());
				align = etext.align();
				text = etext.text();
				orientation = element->orientations();

				rotate(angleRotate(orientation, true));

				if(align & AlignExternal)
				{
					QRect rh = rectRotate(orientation, boundingRect(0, 0, 0, 0, 0, text));

					pt = r.center();
					rh.moveCenter(pt);

					if((align & AlignExtTopOrBottom) == AlignExtTopOrBottom)
					{
						if(align & AlignTop)
						{
							pt.setY(r.top() - 5);
							rh.moveBottom(pt.y());
						}
						else if(align & AlignBottom)
						{
							pt.setY(r.bottom() + 5);
							rh.moveTop(pt.y());
						}

						if(align & AlignLeft)
						{
							pt.setX(r.left() + 5);
							rh.moveLeft(pt.x());
						}
						else if(align & AlignRight)
						{
							pt.setX(r.right() - 5);
							rh.moveRight(pt.x());
						}
					}

					if((align & AlignExtLeftOrRight) == AlignExtLeftOrRight)
					{
						if(align & AlignLeft)
						{
							pt.setX(r.left() - 5);
							rh.moveRight(pt.x());
						}
						else if(align & AlignRight)
						{
							pt.setX(r.right() + 5);
							rh.moveLeft(pt.x());
						}

						if(align & AlignTop)
						{
							pt.setY(r.top() + 5);
							rh.moveTop(pt.y());
						}
						else if(align & AlignBottom)
						{
							pt.setY(r.bottom() - 5);
							rh.moveBottom(pt.y());
						}
					}

					drawText(rectRotate(orientation, rh), Qt::AlignCenter, text);
				}
				else
				{
					if(align == AlignNone)
					{
						drawText(pointRotate(orientation, pt), text);
					}
					else
					{
						drawText(rectRotate(orientation, r), AskuLevelText::alignToQt(align), text);
					}
				}

				rotate(angleRotate(orientation, false));
			}

			break;
	}
}

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------
