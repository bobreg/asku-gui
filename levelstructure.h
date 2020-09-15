#ifndef __LEVELSTRUCTURE_H__
#define __LEVELSTRUCTURE_H__

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QPoint>
#include <QRect>
#include <QLine>
#include <QPolygon>
#include <QPixmap>
#include <QTimer>

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------

class AskuLevel;
class AskuLevelPainter;
class AskuLevelCollection;

//----------------------------------------------------------------------------------------------------------------

enum TextAlign {
	AlignNone			= 0x00000000,
	AlignLeft			= 0x00000001,
	AlignRight			= 0x00000002,
	AlignHCenter		= 0x00000004,
	AlignTop			= 0x00000010,
	AlignBottom			= 0x00000020,
	AlignVCenter		= 0x00000040,
	AlignCenter			= 0x00000044,
	AlignExternal		= 0x00000080,
	TextDontClip		= 0x00000100,
	TextSingleLine		= 0x00010000,
	TextWordWrap		= 0x00020000,
	TextWrapAnywhere	= 0x00040000,

	AlignExtTopOrBottom	= 0x01000000,
	AlignExtTopLeft		= 0x01000091,
	AlignExtTopRight	= 0x01000092,
	AlignExtTopCenter	= 0x01000094,
	AlignExtBottomLeft	= 0x010000A1,
	AlignExtBottomRight	= 0x010000A2,
	AlignExtBottomCenter= 0x010000A4,
	AlignExtCenterLeft	= 0x010000C1,
	AlignExtCenterRight	= 0x010000C2,
	AlignExtCenter		= 0x010000C4,

	AlignExtLeftOrRight	= 0x02000000,
	AlignExtLeftTop		= 0x02000091,
	AlignExtLeftCenter	= 0x02000092,
	AlignExtLeftBottom	= 0x02000094,
	AlignExtRightTop	= 0x020000A1,
	AlignExtRightCenter	= 0x020000A2,
	AlignExtRightBottom	= 0x020000A4
};

Q_DECLARE_FLAGS(TextAligns, TextAlign);

enum TextOrientation {
	OrientationHorizontal = 0,
	OrientationVertical = 1,
	OrientationReverseHorizontal = 2,
	OrientationReverseVertical = 3
};

enum LineForm {
	NoArrow = 0,
	ArrowLeft = 1,
	ArrowRight = 2,
	ArrowBoth = 3
};

enum ElementTextForm {
	Individual = 0,
	AllAsOne = 1,
	SeparateLine = 2
};

enum ElementForm {
	TextOnly = 0,
	Rectangle = 1,
	Ellipse = 2,
	Switch = 3,
	DashedRectangle = 4,
	Polygon = 5
};

enum ElementState {
	Norma = 0,
	Error = 1,
	Avar = 2,
	Not = 3,
	Disable = 4,
	Substrate = 5,
	Mest = 6,
	NormaMest = 10,
	ErrorMest = 11,
	AvarMest = 12,
	NotMest = 13,
	User = 255
};

enum Visibility {
	Hidden = 0,
	Visible = 1,
	Condition = 2
};

//----------------------------------------------------------------------------------------------------------------

ElementState stateFromString(QString state);

QRect rectRotate(TextOrientation orientation, QRect rect);
QPoint pointRotate(TextOrientation orientation, QPoint point);
qreal angleRotate(TextOrientation orientation, bool set);

//----------------------------------------------------------------------------------------------------------------

class AskuLevelPrimitive : public QObject
{
Q_OBJECT

	Q_ENUMS(Visibility);
	Q_PROPERTY(Visibility visible READ visibility WRITE setVisibility);
	Q_PROPERTY(QString name READ name WRITE setName);

public:
	AskuLevelPrimitive(AskuLevel * parent, QString name = QString());
	virtual ~AskuLevelPrimitive();

	void hide();
	void show();

	void setName(QString name);
	void setVisibility(Visibility visibility);
	void setBoundingRect(QRect rect);

	QString name();
	Visibility visibility();
	QRect boundingRect();

	bool isVisible();

	AskuLevel* parent();

protected:
	AskuLevel *m_level;
	Visibility m_visibility;
	QString m_name;
	QRect m_boundingRect;

signals:
	void changed();
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevelTitle : public AskuLevelPrimitive
{
Q_OBJECT

	Q_PROPERTY(QPoint point READ point WRITE setPoint);
	Q_PROPERTY(QString text READ text WRITE setText);

public:
	AskuLevelTitle(AskuLevel *parent);
	AskuLevelTitle(AskuLevel *parent, QString text, QPoint point, Visibility visibility = Visible);

	void setText(QString text);
	void setPoint(QPoint point);
	QString text();
	QPoint point();

private:
	QPoint m_point;
	QString m_text;
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevelText : public AskuLevelPrimitive
{
Q_OBJECT

	Q_FLAGS(TextAlign TextAligns);
	Q_PROPERTY(TextOrientation orientation READ orientation WRITE setOrientation);
	Q_PROPERTY(TextAligns align READ align WRITE setAlign);
	Q_PROPERTY(QPoint point READ point WRITE setPoint);
	Q_PROPERTY(QRect rect READ rect WRITE setRect);
	Q_PROPERTY(QString text READ text WRITE setText);

public:

	static int alignToQt(TextAligns ta);
	static TextAligns alignFromQt(int qa);

	AskuLevelText(AskuLevel *parent);
	AskuLevelText(AskuLevel *parent, QString text, QPoint point, TextAligns align, TextOrientation orientation = OrientationHorizontal, Visibility visibility = Visible);
	AskuLevelText(AskuLevel *parent, QString text, QRect rect, TextAligns align, TextOrientation orientation = OrientationHorizontal, Visibility visibility = Visible);

	void setText(QString text);
	void setPoint(QPoint point);
	void setRect(QRect rect);
	void setAlign(TextAligns align);
	void setOrientation(TextOrientation orient);
	QString text();
	QPoint point();
	QRect rect();
	TextAligns align();
	TextOrientation orientation();

private:
	TextOrientation m_orientation;
	TextAligns m_align;
	QPoint m_point;
	QRect m_rect;
	QString m_text;
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevelLine : public AskuLevelPrimitive
{
Q_OBJECT

	Q_ENUMS(LineForm);
	Q_PROPERTY(LineForm form READ form WRITE setForm);
	Q_PROPERTY(QPoint pointBegin READ pointBegin WRITE setPointBegin); 
	Q_PROPERTY(QPoint pointEnd READ pointEnd WRITE setPointEnd);
	Q_PROPERTY(QLine line READ line WRITE setLine);

public:

	AskuLevelLine(AskuLevel *parent);
	AskuLevelLine(AskuLevel *parent, LineForm form, QPoint pointBegin, QPoint pointEnd, Visibility visibility = Visible);
	AskuLevelLine(AskuLevel *parent, LineForm form, QLine line, Visibility visibility = Visible);

	void setPointBegin(QPoint pointBegin);
	void setPointEnd(QPoint pointEnd);
	void setPoints(QPoint pointBegin, QPoint pointEnd);
	void setLine(QLine line);
	void setForm(LineForm form);
	QPoint pointBegin();
	QPoint pointEnd();
	QLine line();
	LineForm form();

private:
	LineForm m_form;
	QPoint m_pointBegin; 
	QPoint m_pointEnd;
};

//----------------------------------------------------------------------------------------------------------------

typedef QList<ElementState> ElementStates;

//----------------------------------------------------------------------------------------------------------------

class VisibilityConditions
{
public:
	VisibilityConditions();
	VisibilityConditions(ElementStates states, QStringList userStates);
	VisibilityConditions(ElementStates states);
	VisibilityConditions(QStringList userStates);

	bool setStateForVisible(ElementState state, QString userState);

	ElementStates states();
	QStringList userStates();
	bool isVisible();

private:
	bool m_visible;
	ElementStates m_states;
	QStringList m_userStates;
};

//----------------------------------------------------------------------------------------------------------------

class ElementText
{
public:
	ElementText(const ElementText & elemtext);
	ElementText(QString text, TextAligns align = AlignCenter, TextOrientation orientation = OrientationHorizontal, QPoint point = QPoint(), VisibilityConditions conditions = VisibilityConditions());

	bool isVisible();
	bool setStateForVisible(ElementState state, QString userValue);

	void setOrientation(TextOrientation orientation);
	void setAlign(TextAligns align);
	void setText(QString text);
	void setPoint(QPoint point);
	void setConditions(VisibilityConditions conditions);

	TextOrientation orientation();
	TextAligns align();
	QString text();
	QPoint point();
	VisibilityConditions conditions();

private:
	TextOrientation m_orientation;
	TextAligns m_align;
	QString m_text;
	QPoint m_point;
	VisibilityConditions m_conditions;
};

//----------------------------------------------------------------------------------------------------------------

class ElementTexts : public QList<ElementText>
{
public:
	ElementTexts();
	ElementTexts(const QStringList texts);
	ElementTexts& operator=(const QStringList & texts);

	QStringList toStringList();
	QString toString(QString separator);
	bool setStateForVisible(ElementState state, QString userValue);
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevelElement : public AskuLevelPrimitive
{
Q_OBJECT

	Q_ENUMS(ElementForm);
	Q_ENUMS(ElementState);

	Q_PROPERTY(quint32 id READ id WRITE setId);
	Q_PROPERTY(QRect rect READ rect WRITE setRect);
	Q_PROPERTY(QPolygon polygon READ polygon WRITE setPolygon);
	Q_PROPERTY(quint32 radius READ radius WRITE setRadius);
	Q_PROPERTY(QStringList texts READ texts);
	Q_PROPERTY(ElementState state READ state WRITE setState);
	Q_PROPERTY(ElementState pureState READ pureState);
	Q_PROPERTY(ElementForm form READ form WRITE setForm);
	Q_PROPERTY(ElementTextForm textform READ textform WRITE setTextForm);
	Q_PROPERTY(QString userState READ userState WRITE setUserState);
	Q_PROPERTY(QString userValue READ userValue WRITE setUserValue);
	Q_PROPERTY(ElementState savedState READ savedState WRITE setSavedState);
	Q_PROPERTY(QString savedUserState READ savedUserState WRITE setSavedUserState);

public:
	AskuLevelElement(AskuLevel *parent);
	AskuLevelElement(AskuLevel *parent, QString name, quint32 id, ElementForm form, ElementState state, QRect rect, quint32 radius, Visibility visibility, VisibilityConditions conditions, ElementTextForm textform, ElementTexts texts, QString userState, QString userValue);
	AskuLevelElement(AskuLevel *parent, QString name, quint32 id, ElementForm form, ElementState state, QPolygon polygon, quint32 radius, Visibility visibility, VisibilityConditions conditions, ElementTextForm textform, ElementTexts texts, QString userState, QString userValue);

	void setId(quint32 id);
	void setTopLeft(QPoint point);
	void setBottomRight(QPoint point);
	void setRect(QRect rect);
	void setPolygon(QPolygon polygon);
	void setRadius(quint32 radius);
	void setForm(ElementForm form);
	void setTextForm(ElementTextForm textform);
	void setState(ElementState state);
	void setSavedState(ElementState savedstate);
	void setTexts(ElementTexts texts);
	void setTexts(QStringList texts);
	void setSavedTexts(ElementTexts texts);
	//void setText(QString text, qint32 index = -1);
	void setUserState(QString userState);
	void setSavedUserState(QString savedUserState);
	void setUserValue(QString userValue);
	void setStateFull(ElementState state, ElementTexts texts, QString userState);
	void setConditions(VisibilityConditions conditions);
	void restoreSavedState();

	quint32 id();
	QRect rect();
	quint32 radius();
	QPolygon polygon();
	ElementForm form();
	ElementTextForm textform();
	ElementState state();
	ElementState savedState();
	bool isMestState();
	ElementState pureState();
	QStringList texts();
	ElementTexts savedTexts();
	TextAligns aligns();
	TextOrientation orientations();
	ElementTexts etexts();
	QString userState();
	QString savedUserState();
	QString userValue();
	VisibilityConditions conditions();

	void appendPolygonPoint(QPoint point);
	void clearPolygon();

	bool isVisible();

private:
	quint32 m_id;
	QRect m_rect;
	QPolygon m_polygon;
	quint32 m_radius;
	ElementTexts m_texts;
	ElementTexts m_savedTexts;
	ElementState m_state;
	ElementState m_savedState;
	ElementForm m_form;
	ElementTextForm m_textform;
	QString m_userState;
	QString m_savedUserState;
	QString m_userValue;
	VisibilityConditions m_conditions;
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevelWarning : public AskuLevelElement
{
Q_OBJECT

	Q_PROPERTY(quint32 blinkTime READ blinkTime WRITE setBlinkTime);
	Q_PROPERTY(ElementState state1 READ state1 WRITE setState1);
	Q_PROPERTY(ElementState state2 READ state2 WRITE setState2);

public:
	AskuLevelWarning(AskuLevel * parent);
	AskuLevelWarning(AskuLevel * parent, QString name, ElementState state1, ElementState state2, quint32 blinkTime, QRect rect, quint32 radius, Visibility visibility, VisibilityConditions conditions, ElementTextForm textform, QStringList texts, QString userState, QString userValue);

	void setState1(ElementState state1);
	void setState2(ElementState state2);
	void setBlinkTime(quint32 blinkTime);

	ElementState state1();
	ElementState state2();
	quint32 blinkTime();

protected slots:
	void timeout();

private:
	ElementState m_state1;
	ElementState m_state2;
	quint32 m_blinkTime;

	QTimer timer;
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevelPixmap : public AskuLevelPrimitive
{
Q_OBJECT

	Q_PROPERTY(bool foreground READ foreground WRITE setForeground);
	Q_PROPERTY(QPoint point READ point WRITE setPoint);
	Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap);

public:
	AskuLevelPixmap(AskuLevel *parent);
	AskuLevelPixmap(AskuLevel *parent, QString name, QPixmap pixmap, QPoint point, bool foreground = false, Visibility visibility = Visible);

	void setPixmap(QPixmap pixmap);
	void setPoint(QPoint point);
	void setForeground(bool foreground);
	QPixmap pixmap();
	QPoint point();
	bool foreground();

private:
	bool m_foreground;
	QPoint m_point;
	QPixmap m_pixmap;
};

//----------------------------------------------------------------------------------------------------------------

class AskuLevel : public QObject
{
Q_OBJECT

	Q_PROPERTY(quint32 id READ id WRITE setId);
	Q_PROPERTY(QString name READ name WRITE setName);
	Q_PROPERTY(quint32 textCount READ textCount);
	Q_PROPERTY(quint32 lineCount READ lineCount);
	Q_PROPERTY(quint32 elementCount READ elementCount);

public:
	AskuLevel(AskuLevelCollection * parent, QString name = QString(), quint32 id = 0);
	~AskuLevel();

	void appendPrimitive(AskuLevelPrimitive * primitive);
	void removePrimitive(AskuLevelPrimitive * primitive);
	AskuLevelPrimitive* existsPrimitive(QString name);

	void restoreDefaultState();

	void clear();

	void draw(AskuLevelPainter * painter);
	QString elementByPoint(QPoint point);

	quint32 textCount();
	quint32 lineCount();
	quint32 elementCount();

	quint32 id();
	QString name();

	void setId(quint32 id);
	void setName(QString name);

	void loadFromFile(QString name);
	void load(QIODevice* device);
	void saveToFile(QString name);
	void save(QIODevice* device);

private:
	AskuLevelCollection* m_collection;
	quint32 m_id;
	QString m_name;
	QList<AskuLevelPrimitive*> m_primitives;

signals:
	void changed();
};

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------

#endif //__LEVELSTRUCTURE_H__

