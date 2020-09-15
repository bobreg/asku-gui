#include "../common/logger.h"
#include "levelstructure.h"
#include "levelpainter.h"
#include "levelcollection.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------
ElementState stateFromString(QString a_state)
{
	if(!a_state.compare("norma", Qt::CaseInsensitive))
		return Norma;
	else if(!a_state.compare("error", Qt::CaseInsensitive))
		return Error;
	else if(!a_state.compare("avar", Qt::CaseInsensitive))
		return Avar;
	else if(!a_state.compare("not", Qt::CaseInsensitive))
		return Not;
	else if(!a_state.compare("mest", Qt::CaseInsensitive))
		return Mest;
	else if(!a_state.compare("disable", Qt::CaseInsensitive))
		return Disable;
	else if(!a_state.compare("substrate", Qt::CaseInsensitive))
		return Substrate;
	else if(!a_state.compare("normamest", Qt::CaseInsensitive))
		return NormaMest;
	else if(!a_state.compare("errormest", Qt::CaseInsensitive))
		return ErrorMest;
	else if(!a_state.compare("avarmest", Qt::CaseInsensitive))
		return AvarMest;
	else if(!a_state.compare("notmest", Qt::CaseInsensitive))
		return NotMest;
	else
	{
		LogError("stateFromString: unknown element state %s", qPrintable(a_state));
	}
	return Not;
}

//----------------------------------------------------------------------------------------------------------------
QRect rectRotate(TextOrientation orientation, QRect rect)
{
	int x1, y1, x2, y2;
	rect.getCoords(&x1, &y1, &x2, &y2);

	switch(orientation)
	{
		case OrientationHorizontal:
			return rect;
			break;

		case OrientationVertical:
			return QRect(QPoint(-y2, x1), QPoint(-y1, x2));
			break;

		case OrientationReverseHorizontal:
			return QRect(QPoint(-y2, -x2), QPoint(-y1, -x1));
			break;

		case OrientationReverseVertical:
			return QRect(QPoint(y1, -x2), QPoint(y2, -x1));
			break;
	}

	return QRect();
}

//----------------------------------------------------------------------------------------------------------------
QPoint pointRotate(TextOrientation orientation, QPoint point)
{
	switch(orientation)
	{
		case OrientationHorizontal:
			return point;
			break;

		case OrientationVertical:
			return QPoint(-point.y(), point.x());
			break;

		case OrientationReverseHorizontal:
			return QPoint(-point.x(), -point.y());
			break;

		case OrientationReverseVertical:
			return QPoint(point.y(), -point.x());
			break;
	}

	return QPoint();
}

//----------------------------------------------------------------------------------------------------------------
qreal angleRotate(TextOrientation orientation, bool set)
{
	qreal angle = 0;

	switch(orientation)
	{
		case OrientationHorizontal:
			angle = 0;
			break;

		case OrientationVertical:
			angle = set ? -90 : 90;
			break;

		case OrientationReverseHorizontal:
			angle = set ? -180 : 180;
			break;

		case OrientationReverseVertical:
			angle = set ? 90 : -90;
			break;
	}

	return angle;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelPrimitive::AskuLevelPrimitive(AskuLevel * parent, QString name) : QObject(parent)
{
	m_level = parent;
	m_name = name;
	m_visibility = Hidden;
	m_boundingRect = QRect();

	if(m_level)
		m_level->appendPrimitive(this);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelPrimitive::~AskuLevelPrimitive()
{
	if(m_level)
		m_level->removePrimitive(this);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPrimitive::hide()
{
	setVisibility(Hidden);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPrimitive::show()
{
	setVisibility(Visible);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPrimitive::setName(QString name)
{
	m_name = name;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPrimitive::setVisibility(Visibility visibility)
{
	m_visibility = visibility;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPrimitive::setBoundingRect(QRect rect)
{
	m_boundingRect = rect;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelPrimitive::isVisible()
{
	return (m_visibility == Visible);
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelPrimitive::name()
{
	return m_name;
}

//----------------------------------------------------------------------------------------------------------------
Visibility AskuLevelPrimitive::visibility()
{
	return m_visibility;
}

//----------------------------------------------------------------------------------------------------------------
QRect AskuLevelPrimitive::boundingRect()
{
	return m_boundingRect;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel* AskuLevelPrimitive::parent()
{
	return m_level;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelTitle::AskuLevelTitle(AskuLevel * parent) : AskuLevelPrimitive(parent)
{
	m_point = QPoint(0,0);
	m_text = "";
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelTitle::AskuLevelTitle(AskuLevel * parent, QString text, QPoint point, Visibility visibility) : AskuLevelPrimitive(parent)
{
	m_point = point;
	m_text = text;
	setVisibility(visibility);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelTitle::setText(QString text)
{
	m_text = text;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelTitle::setPoint(QPoint point)
{
	m_point = point;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelTitle::text()
{
	return m_text;
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelTitle::point()
{
	return m_point;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelText::AskuLevelText(AskuLevel * parent) : AskuLevelPrimitive(parent)
{
	m_orientation = OrientationHorizontal;
	m_align = AlignCenter;
	m_point = QPoint();
	m_rect = QRect();
	m_text = "";
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelText::AskuLevelText(AskuLevel * parent, QString text, QPoint point, TextAligns align, TextOrientation orientation, Visibility visibility) : AskuLevelPrimitive(parent)
{
	m_orientation = orientation;
	m_align = align;
	m_point = point;
	m_rect = QRect();
	m_text = text;
	setVisibility(visibility);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelText::AskuLevelText(AskuLevel * parent, QString text, QRect rect, TextAligns align, TextOrientation orientation, Visibility visibility) : AskuLevelPrimitive(parent)
{
	m_orientation = orientation;
	m_align = align;
	m_point = QPoint();
	m_rect = rect;
	m_text = text;
	setVisibility(visibility);
}

//----------------------------------------------------------------------------------------------------------------
int AskuLevelText::alignToQt(TextAligns ta)
{
	int qa = 0;

	if(ta & AlignLeft)			qa |= Qt::AlignLeft;
	if(ta & AlignRight)			qa |= Qt::AlignRight;
	if(ta & AlignHCenter)		qa |= Qt::AlignHCenter;
	if(ta & AlignTop)			qa |= Qt::AlignTop;
	if(ta & AlignBottom)		qa |= Qt::AlignBottom;
	if(ta & AlignVCenter)		qa |= Qt::AlignVCenter;

	if(ta & TextDontClip)		qa |= Qt::TextDontClip;
	if(ta & TextSingleLine)		qa |= Qt::TextSingleLine;
	if(ta & TextWordWrap)		qa |= Qt::TextWordWrap;
	if(ta & TextWrapAnywhere)	qa |= Qt::TextWrapAnywhere;

	return qa;
}

//----------------------------------------------------------------------------------------------------------------
TextAligns AskuLevelText::alignFromQt(int qa)
{
	TextAligns ta = 0;

	if(qa & Qt::AlignLeft)			ta |= AlignLeft;
	if(qa & Qt::AlignRight)			ta |= AlignRight;
	if(qa & Qt::AlignHCenter)		ta |= AlignHCenter;
	if(qa & Qt::AlignTop)			ta |= AlignTop;
	if(qa & Qt::AlignBottom)		ta |= AlignBottom;
	if(qa & Qt::AlignVCenter)		ta |= AlignVCenter;

	if(qa & Qt::TextDontClip)		ta |= TextDontClip;
	if(qa & Qt::TextSingleLine)		ta |= TextSingleLine;
	if(qa & Qt::TextWordWrap)		ta |= TextWordWrap;
	if(qa & Qt::TextWrapAnywhere)	ta |= TextWrapAnywhere;

	return ta;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelText::setText(QString text)
{
	m_text = text;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelText::setPoint(QPoint point)
{
	m_point = point;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelText::setRect(QRect rect)
{
	m_rect = rect;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelText::setAlign(TextAligns align)
{
	m_align = align;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelText::setOrientation(TextOrientation orientation)
{
	m_orientation = orientation;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelText::text()
{
	return m_text;
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelText::point()
{
	return m_point;
}

//----------------------------------------------------------------------------------------------------------------
QRect AskuLevelText::rect()
{
	return m_rect;
}

//----------------------------------------------------------------------------------------------------------------
TextAligns AskuLevelText::align()
{
	return m_align;
}

//----------------------------------------------------------------------------------------------------------------
TextOrientation AskuLevelText::orientation()
{
	return m_orientation;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelLine::AskuLevelLine(AskuLevel * parent) : AskuLevelPrimitive(parent)
{
	m_form = NoArrow;
	m_pointBegin = QPoint();
	m_pointEnd = QPoint();
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelLine::AskuLevelLine(AskuLevel * parent, LineForm form, QPoint pointBegin, QPoint pointEnd, Visibility visibility) : AskuLevelPrimitive(parent)
{
	m_form = form;
	m_pointBegin = pointBegin;
	m_pointEnd = pointEnd;
	setVisibility(visibility);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelLine::AskuLevelLine(AskuLevel * parent, LineForm form, QLine line, Visibility visibility) : AskuLevelPrimitive(parent)
{
	m_form = form;
	m_pointBegin = line.p1();
	m_pointEnd = line.p2();
	setVisibility(visibility);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelLine::setPointBegin(QPoint pointBegin)
{
	m_pointBegin = pointBegin;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelLine::setPointEnd(QPoint pointEnd)
{
	m_pointEnd = pointEnd;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelLine::setPoints(QPoint pointBegin, QPoint pointEnd)
{
	m_pointBegin = pointBegin;
	m_pointEnd = pointEnd;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelLine::setLine(QLine line)
{
	m_pointBegin = line.p1();
	m_pointEnd = line.p2();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelLine::setForm(LineForm form)
{
	m_form = form;
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelLine::pointBegin()
{
	return m_pointBegin;
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelLine::pointEnd()
{
	return m_pointEnd;
}

//----------------------------------------------------------------------------------------------------------------
QLine AskuLevelLine::line()
{
	return QLine(m_pointBegin, m_pointEnd);
}

//----------------------------------------------------------------------------------------------------------------
LineForm AskuLevelLine::form()
{
	return m_form;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelElement::AskuLevelElement(AskuLevel * parent) : AskuLevelPrimitive(parent)
{
	m_id = 0;
	m_rect = QRect();
	m_polygon = QPolygon();
	m_radius = 0;
	m_texts.clear();
	m_savedTexts.clear();
	m_textform = AllAsOne;
	m_state = Not;
	m_savedState = Not;
	m_form = TextOnly;
	m_userState = QString();
	m_savedUserState = QString();
	m_userValue = QString();
	m_visibility = Hidden;
	m_conditions = VisibilityConditions();
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelElement::AskuLevelElement(AskuLevel * parent, QString name, quint32 id, ElementForm form, ElementState state, QRect rect, quint32 radius, Visibility visibility, VisibilityConditions conditions, ElementTextForm textform, ElementTexts texts, QString userState, QString userValue) : AskuLevelPrimitive(parent, name)
{
	m_id = id;
	m_rect = rect;
	m_polygon = QPolygon();
	m_radius = radius;
	m_texts = texts;
	m_savedTexts = texts;
	m_state = state;
	m_savedState = state;
	m_form = form;
	m_textform = textform;
	m_userState = userState;
	m_savedUserState = userState;
	m_userValue = userValue;
	m_visibility = visibility;
	m_conditions = conditions;

	m_conditions.setStateForVisible(m_state, m_userState);
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelElement::AskuLevelElement(AskuLevel * parent, QString name, quint32 id, ElementForm form, ElementState state, QPolygon polygon, quint32 radius, Visibility visibility, VisibilityConditions conditions, ElementTextForm textform, ElementTexts texts, QString userState, QString userValue) : AskuLevelPrimitive(parent, name)
{
	m_id = id;
	m_rect = polygon.boundingRect();
	m_polygon = polygon;
	m_radius = radius;
	m_texts = texts;
	m_savedTexts = texts;
	m_state = state;
	m_savedState = state;
	m_form = form;
	m_textform = textform;
	m_userState = userState;
	m_savedUserState = userState;
	m_userValue = userValue;
	m_visibility = visibility;
	m_conditions = conditions;

	m_conditions.setStateForVisible(m_state, m_userState);
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setId(quint32 id)
{
	m_id = id;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setTopLeft(QPoint point)
{
	m_rect.setTopLeft(point);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setBottomRight(QPoint point)
{
	m_rect.setBottomRight(point);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setRect(QRect rect)
{
	m_rect = rect;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setPolygon(QPolygon polygon)
{
	m_polygon = polygon;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::appendPolygonPoint(QPoint point)
{
	m_polygon.append(point);
	m_rect = m_polygon.boundingRect();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::clearPolygon()
{
	m_polygon.clear();
	m_rect = QRect();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setRadius(quint32 radius)
{
	m_radius = radius;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setForm(ElementForm form)
{
	m_form = form;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setTextForm(ElementTextForm textform)
{
	m_textform = textform;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setState(ElementState state)
{
	m_state = state;
	m_conditions.setStateForVisible(m_state, m_userState);
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setSavedState(ElementState state)
{
	m_savedState = state;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setTexts(QStringList texts)
{
	m_texts = texts;
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setTexts(ElementTexts texts)
{
	m_texts = texts;
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setSavedTexts(ElementTexts texts)
{
	m_savedTexts = texts;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setUserState(QString userState)
{
	m_userState = userState;
	m_conditions.setStateForVisible(m_state, m_userState);
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setSavedUserState(QString userState)
{
	m_savedUserState = userState;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setUserValue(QString userValue)
{
	m_userValue = userValue;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setConditions(VisibilityConditions conditions)
{
	m_conditions = conditions;
	m_conditions.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::setStateFull(ElementState state, ElementTexts texts, QString userState)
{
	m_state = state;
	m_texts = texts;
	m_userState = userState;
	m_conditions.setStateForVisible(m_state, m_userState);
	m_texts.setStateForVisible(m_state, m_userState);
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevelElement::id()
{
	return m_id;
}

//----------------------------------------------------------------------------------------------------------------
QRect AskuLevelElement::rect()
{
	return m_rect;
}

//----------------------------------------------------------------------------------------------------------------
QPolygon AskuLevelElement::polygon()
{
	return m_polygon;
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevelElement::radius()
{
	return m_radius;
}

//----------------------------------------------------------------------------------------------------------------
ElementForm AskuLevelElement::form()
{
	return m_form;
}

//----------------------------------------------------------------------------------------------------------------
ElementTextForm AskuLevelElement::textform()
{
	return m_textform;
}

//----------------------------------------------------------------------------------------------------------------
ElementState AskuLevelElement::state()
{
	return m_state;
}

//----------------------------------------------------------------------------------------------------------------
ElementState AskuLevelElement::savedState()
{
	return m_savedState;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelElement::isMestState()
{
	return (m_state >= NormaMest);
}

//----------------------------------------------------------------------------------------------------------------
ElementState AskuLevelElement::pureState()
{
	return isMestState() ? (ElementState)(m_state - NormaMest) : m_state;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuLevelElement::texts()
{
	return m_texts.toStringList();
}

//----------------------------------------------------------------------------------------------------------------
ElementTexts AskuLevelElement::savedTexts()
{
	return m_savedTexts;
}

//----------------------------------------------------------------------------------------------------------------
TextAligns AskuLevelElement::aligns()
{
	return m_texts.first().align();
}

//----------------------------------------------------------------------------------------------------------------
TextOrientation AskuLevelElement::orientations()
{
	return m_texts.first().orientation();
}

//----------------------------------------------------------------------------------------------------------------
ElementTexts AskuLevelElement::etexts()
{
	return m_texts;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelElement::userState()
{
	return m_userState;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelElement::savedUserState()
{
	return m_savedUserState;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelElement::userValue()
{
	return m_userValue;
}

//----------------------------------------------------------------------------------------------------------------
VisibilityConditions AskuLevelElement::conditions()
{
	return m_conditions;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelElement::isVisible()
{
	bool visible = false;

	if(m_visibility == Visible)
		visible = true;
	else if(m_visibility == Condition)
		visible = m_conditions.isVisible();
	else /*if(m_visibility == Hidden)*/
		visible = false;

	return visible;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelElement::restoreSavedState()
{
	setStateFull(savedState(), savedTexts(), savedUserState());
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelWarning::AskuLevelWarning(AskuLevel * parent) : AskuLevelElement(parent)
{
	connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));

	m_state1 = Not;
	m_state2 = Not;
	m_blinkTime = 0;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelWarning::AskuLevelWarning(AskuLevel * parent, QString name, ElementState state1, ElementState state2, quint32 blinkTime, QRect rect, quint32 radius, Visibility visibility, VisibilityConditions conditions, ElementTextForm textform, QStringList texts, QString userState, QString userValue)
	: AskuLevelElement(parent, name, 0, Rectangle, state1, rect, radius, visibility, conditions, textform, texts, userState, userValue)
{
	connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));

	m_state1 = state1;
	m_state2 = state2;
	m_blinkTime = blinkTime;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelWarning::timeout()
{
	if(state() == m_state1) 
		setState(m_state2);
	else
		setState(m_state1);
	emit changed();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelWarning::setState1(ElementState state1)
{
	m_state1 = state1;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelWarning::setState2(ElementState state2)
{
	m_state2 = state2;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelWarning::setBlinkTime(quint32 blinkTime)
{
	m_blinkTime = blinkTime;
}

//----------------------------------------------------------------------------------------------------------------
ElementState AskuLevelWarning::state1()
{
	return m_state1;
}

//----------------------------------------------------------------------------------------------------------------
ElementState AskuLevelWarning::state2()
{
	return m_state2;
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevelWarning::blinkTime()
{
	return m_blinkTime;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelPixmap::AskuLevelPixmap(AskuLevel *parent) : AskuLevelPrimitive(parent)
{
	m_foreground = false;
	m_point = QPoint();
	m_pixmap = QPixmap();
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelPixmap::AskuLevelPixmap(AskuLevel *parent, QString name, QPixmap pixmap, QPoint point, bool foreground, Visibility visibility) : AskuLevelPrimitive(parent, name)
{
	m_foreground = foreground;
	m_point = point;
	m_pixmap = pixmap;
	setVisibility(visibility);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPixmap::setPixmap(QPixmap pixmap)
{
	m_pixmap = pixmap;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPixmap::setPoint(QPoint point)
{
	m_point = point;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelPixmap::setForeground(bool foreground)
{
	m_foreground = foreground;
}

//----------------------------------------------------------------------------------------------------------------
QPixmap AskuLevelPixmap::pixmap()
{
	return m_pixmap;
}

//----------------------------------------------------------------------------------------------------------------
QPoint AskuLevelPixmap::point()
{
	return m_point;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelPixmap::foreground()
{
	return m_foreground;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel::AskuLevel(AskuLevelCollection * parent, QString name, quint32 id) : QObject(parent)
{
	m_collection = parent;
	m_id = id;
	m_name = name;
	m_primitives.clear();

	if(m_collection)
		m_collection->appendLevel(this);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel::~AskuLevel()
{
	m_primitives.clear();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::appendPrimitive(AskuLevelPrimitive* primitive)
{
	m_primitives.append(primitive);
	connect(primitive, SIGNAL(changed()), this, SIGNAL(changed()));
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::removePrimitive(AskuLevelPrimitive* primitive)
{
	m_primitives.removeAll(primitive);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelPrimitive* AskuLevel::existsPrimitive(QString name)
{
	foreach(AskuLevelPrimitive* primitive, m_primitives)
		if(primitive->name() == name)
			return primitive;

	return NULL;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::clear()
{
	m_primitives.clear();
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevel::id()
{
	return m_id;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevel::name()
{
	return m_name;
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevel::textCount()
{
	return 0;
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevel::lineCount()
{
	return 0;
}

//----------------------------------------------------------------------------------------------------------------
quint32 AskuLevel::elementCount()
{
	return 0;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::setId(quint32 id)
{
	m_id = id;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::setName(QString name)
{
	m_name = name;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::loadFromFile(QString name)
{
	Q_UNUSED(name);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::load(QIODevice* device)
{
	Q_UNUSED(device);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::saveToFile(QString name)
{
	Q_UNUSED(name);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::save(QIODevice* device)
{
	Q_UNUSED(device);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::draw(AskuLevelPainter* painter)
{
	foreach(AskuLevelPrimitive* primitive, m_primitives)
	{
		AskuLevelElement* element = qobject_cast<AskuLevelElement*>(primitive);
		if(element && element->isVisible())
			painter->draw(primitive);
	}

	foreach(AskuLevelPrimitive* primitive, m_primitives)
	{
		if(primitive->isVisible())
		{
			AskuLevelElement* element = qobject_cast<AskuLevelElement*>(primitive);
			if(!element)
				painter->draw(primitive);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevel::elementByPoint(QPoint point)
{
	QString elementName = QString();
	QPoint mousePoint = AskuLevelPainter::unoptimize(point);

	foreach(AskuLevelPrimitive* primitive, m_primitives)
	{
		AskuLevelElement* element = qobject_cast<AskuLevelElement*>(primitive);
		if(element && element->isVisible() && element->rect().contains(mousePoint))
			elementName = element->name();
	}

	return elementName;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevel::restoreDefaultState()
{
	foreach(AskuLevelPrimitive* primitive, m_primitives)
	{
		AskuLevelElement* element = qobject_cast<AskuLevelElement*>(primitive);
		if(element)
			element->restoreSavedState();
	}
}

//----------------------------------------------------------------------------------------------------------------
VisibilityConditions::VisibilityConditions()
{
	m_states.clear();
	m_userStates.clear();
	m_visible = false;
}

//----------------------------------------------------------------------------------------------------------------
VisibilityConditions::VisibilityConditions(ElementStates states, QStringList userStates)
{
	m_states = states;
	m_userStates = userStates;
	m_visible = false;
}

//----------------------------------------------------------------------------------------------------------------
VisibilityConditions::VisibilityConditions(ElementStates states)
{
	m_states = states;
	m_userStates.clear();
	m_visible = false;
}

//----------------------------------------------------------------------------------------------------------------
VisibilityConditions::VisibilityConditions(QStringList userStates)
{
	m_states.clear();
	m_states << User;
	m_userStates = userStates;
	m_visible = false;
}

//----------------------------------------------------------------------------------------------------------------
QList<ElementState> VisibilityConditions::states()
{
	return m_states;
}

//----------------------------------------------------------------------------------------------------------------
QStringList VisibilityConditions::userStates()
{
	return m_userStates;
}

//----------------------------------------------------------------------------------------------------------------
bool VisibilityConditions::isVisible()
{
	return m_visible;
}

//----------------------------------------------------------------------------------------------------------------
bool VisibilityConditions::setStateForVisible(ElementState state, QString userState)
{
	bool changed = false;
	bool nowvisible = true;

	if(!m_states.isEmpty())
	{
		if(m_states.contains(User))
		{
			if(m_userStates.isEmpty())
			{
				if(userState.isEmpty())
					nowvisible = true;
				else
					nowvisible = false;
			}
			else
			{
				if(m_userStates.contains("*"))
					nowvisible = true;
				else if(userState.isEmpty())
					nowvisible = false;
				else if(m_userStates.contains(userState))
					nowvisible = true;
				else
					nowvisible = false;
			}
		}
		else
		{
			if(!m_states.contains(state))
				nowvisible = false;
			else
				nowvisible = true;
		}
	}
	else
		nowvisible = true;

	if(m_visible != nowvisible)
		changed = true;
	m_visible = nowvisible;

	return changed;
}

//----------------------------------------------------------------------------------------------------------------
ElementText::ElementText(const ElementText & elemtext)
{
	m_text = elemtext.m_text;
	m_align = elemtext.m_align;
	m_point = elemtext.m_point;
	m_orientation = elemtext.m_orientation;
	m_conditions = elemtext.m_conditions;
}

//----------------------------------------------------------------------------------------------------------------
ElementText::ElementText(QString text, TextAligns align, TextOrientation orientation, QPoint point, VisibilityConditions conditions)
{
	m_text = text;
	m_align = align;
	m_point = point;
	m_orientation = orientation;
	m_conditions = conditions;
}

//----------------------------------------------------------------------------------------------------------------
bool ElementText::setStateForVisible(ElementState state, QString userState)
{
	return m_conditions.setStateForVisible(state, userState);
}

//----------------------------------------------------------------------------------------------------------------
bool ElementText::isVisible()
{
	return m_conditions.isVisible();
}

//----------------------------------------------------------------------------------------------------------------
void ElementText::setOrientation(TextOrientation orientation)
{
	m_orientation = orientation;
}

//----------------------------------------------------------------------------------------------------------------
void ElementText::setAlign(TextAligns align)
{
	m_align = align;
}

//----------------------------------------------------------------------------------------------------------------
void ElementText::setText(QString text)
{
	m_text = text;
}

//----------------------------------------------------------------------------------------------------------------
void ElementText::setPoint(QPoint point)
{
	m_point = point;
}

//----------------------------------------------------------------------------------------------------------------
void ElementText::setConditions(VisibilityConditions conditions)
{
	m_conditions = conditions;
}

//----------------------------------------------------------------------------------------------------------------
TextOrientation ElementText::orientation()
{
	return m_orientation;
}

//----------------------------------------------------------------------------------------------------------------
TextAligns ElementText::align()
{
	return m_align;
}

//----------------------------------------------------------------------------------------------------------------
QString ElementText::text()
{
	return m_text;
}

//----------------------------------------------------------------------------------------------------------------
QPoint ElementText::point()
{
	return m_point;
}

//----------------------------------------------------------------------------------------------------------------
VisibilityConditions ElementText::conditions()
{
	return m_conditions;
}

//----------------------------------------------------------------------------------------------------------------
ElementTexts::ElementTexts() : QList<ElementText>()
{
	clear();
}

//----------------------------------------------------------------------------------------------------------------
ElementTexts::ElementTexts(const QStringList texts) : QList<ElementText>()
{
	clear();

	foreach(QString string, texts)
		append(ElementText(string));
}

//----------------------------------------------------------------------------------------------------------------
ElementTexts& ElementTexts::operator=(const QStringList & texts)
{
	clear();

	foreach(QString string, texts)
		append(ElementText(string));

	return *this;
}

//----------------------------------------------------------------------------------------------------------------
bool ElementTexts::setStateForVisible(ElementState state, QString userState)
{
	bool changed = false;

	ElementTexts::iterator i;
	for(i = begin(); i != end(); ++i)
		if((*i).setStateForVisible(state, userState))
			changed = true;

	return changed;
}

//----------------------------------------------------------------------------------------------------------------
QStringList ElementTexts::toStringList()
{
	QStringList list;

	foreach(ElementText element, (ElementTexts)*this)
		if(element.isVisible())
			list << element.text();

	return list;
}

//----------------------------------------------------------------------------------------------------------------
QString ElementTexts::toString(QString separator)
{
	return toStringList().join(separator);
}

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------
