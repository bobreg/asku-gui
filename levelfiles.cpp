#include "globalvar.h"
#include "../common/logger.h"
#include "levelfiles.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------
AskuLevelSchemeFile::AskuLevelSchemeFile(QString filename) : XmlFile(filename)
{
	LogInfo("Loading level scheme: %s", qPrintable(filename));
	if(wasError())
		LogError("Error loading level scheme: %s", qPrintable(lastErrorMessage()));
}

//----------------------------------------------------------------------------------------------------------------
SchemeItems AskuLevelSchemeFile::makeScheme()
{
	SchemeItems items;

	if(wasError())
		return items;

	bool found = false, found_base = false, found_zal = false;
	for(QDomElement tag_level = documentElement().firstChildElement("level"); !tag_level.isNull(); tag_level = tag_level.nextSiblingElement("level"))
	{
		found = true;

		QString a_name = tag_level.attribute("name","");
		QString a_file = tag_level.attribute("file","");
		QString a_index = tag_level.attribute("index","");
		QString a_base = tag_level.attribute("base","false");
		QString a_zal  = tag_level.attribute("zal","false");

		if(a_name.isEmpty() || a_file.isEmpty())
		{
			LogError("ASKU_scheme: empty name or file attribute");
		}
		else
		{
			items.append(SchemeItem(a_name, a_file, a_index, a_base == "true", a_zal == "true"));
		}

		if(a_base == "true")
			found_base = true;

		if(a_zal == "true")
			found_zal = true;
	}

	if(!found)
	{
		LogError("ASKU_scheme: no level tag found");
	}
	else
	{
		if(!found_base)
			LogInfo("ASKU_scheme: no base found");
		if(!found_zal)
			LogInfo("ASKU_scheme: no zal found");
	}

	return items;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelSchemeFile::checkContent()
{
	if(doctype().name() != "ASKU_scheme")
	{
		LogError("ASKU_scheme: not an ASKU_scheme");
		return false;
	}

	if(documentElement().tagName() != "scheme")
	{
		LogError("ASKU_scheme: no scheme tag");
		return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelFunctionFile::AskuLevelFunctionFile(QString filename) : XmlFile(filename)
{
	LogInfo("Loading level function: %s", qPrintable(filename));
	if(wasError())
		LogError("Error loading level function: %s", qPrintable(lastErrorMessage()));
}

//----------------------------------------------------------------------------------------------------------------
FunctionItems AskuLevelFunctionFile::makeFunctions()
{
	FunctionItems items;

	if(wasError())
		return items;

	for(QDomElement tag_trip = documentElement().firstChildElement("trip"); !tag_trip.isNull(); tag_trip = tag_trip.nextSiblingElement("trip"))
	{
		QString a_level = tag_trip.attribute("level","");
		QString a_element = tag_trip.attribute("element","");
		QString a_to = tag_trip.attribute("to","");

		if(a_level.isEmpty() || a_element.isEmpty() || a_to.isEmpty())
		{
			LogError("ASKU_function: empty level, element or to attribute");
		}
		else
		{
			items.append(FunctionItem(tag_trip.tagName(), a_level, a_element, QString(), a_to));
		}
	}

	for(QDomElement tag_enter = documentElement().firstChildElement("enter"); !tag_enter.isNull(); tag_enter = tag_enter.nextSiblingElement("enter"))
	{
		QString a_level = tag_enter.attribute("level","");
		QString a_function = tag_enter.attribute("function","");
		QString a_parameter = tag_enter.attribute("parameters","");

		if(a_level.isEmpty() || a_function.isEmpty())
		{
			LogError("ASKU_function: empty level, function attribute");
		}
		else
		{
			items.append(FunctionItem(tag_enter.tagName(), a_level, QString(), a_function, a_parameter));
		}
	}

	for(QDomElement tag_leave = documentElement().firstChildElement("leave"); !tag_leave.isNull(); tag_leave = tag_leave.nextSiblingElement("leave"))
	{
		QString a_level = tag_leave.attribute("level","");
		QString a_function = tag_leave.attribute("function","");
		QString a_parameter = tag_leave.attribute("parameters","");

		if(a_level.isEmpty() || a_function.isEmpty())
		{
			LogError("ASKU_function: empty level, function attribute");
		}
		else
		{
			items.append(FunctionItem(tag_leave.tagName(), a_level, QString(), a_function, a_parameter));
		}
	}

	for(QDomElement tag_click = documentElement().firstChildElement("click"); !tag_click.isNull(); tag_click = tag_click.nextSiblingElement("click"))
	{
		QString a_level = tag_click.attribute("level","");
		QString a_element = tag_click.attribute("element","");
		QString a_function = tag_click.attribute("function","");
		QString a_parameter = tag_click.attribute("parameters","");

		if(a_level.isEmpty() || a_element.isEmpty() || a_function.isEmpty())
		{
			LogError("ASKU_function: empty level, element or function attribute");
		}
		else
		{
			items.append(FunctionItem(tag_click.tagName(), a_level, a_element, a_function, a_parameter));
		}
	}

	return items;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelFunctionFile::checkContent()
{
	if(doctype().name() != "ASKU_function")
	{
		LogError("ASKU_function: not an ASKU_function");
		return false;
	}

	if(documentElement().tagName() != "function")
	{
		LogError("ASKU_function: no function tag");
		return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelFile::AskuLevelFile(QString filename) : XmlFile(filename)
{
	m_index = QString();
	m_litera = QString();

	if(!filename.isEmpty())
	{
		LogInfo("Loading level file: %s", qPrintable(filename));
		if(wasError())
			LogError("Error loading level file: %s", qPrintable(lastErrorMessage()));
	}
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelFile::checkContent()
{
	if(doctype().name() != "ASKU_level")
	{
		LogError("ASKU_level: not an ASKU_level");
		return false;
	}

	QDomElement root = documentElement();
	if(root.tagName() != "level")
	{
		LogError("ASKU_level: no level tag");
		return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelTitle* AskuLevelFile::makeTitle(QDomElement& tag_title, AskuLevel* level)
{
	AskuLevelTitle* title = new AskuLevelTitle(level);

	QString a_visible = tag_title.attribute("visible","true");

	if(a_visible == "true")
		title->setVisibility(Visible);
	else
		title->setVisibility(Hidden);

	QDomElement tag_point = tag_title.firstChildElement("point");
	if(!tag_point.isNull())
	{
		QString a_x = tag_point.attribute("x","0");
		QString a_y = tag_point.attribute("y","0");
		title->setPoint(QPoint(a_x.toUInt(),a_y.toUInt()));
	}

	QDomElement tag_text = tag_title.firstChildElement("text");
	if(!tag_text.isNull())
	{
		QString a_lang = tag_text.attribute("lang", "ru");
		QString a_text = textFromElement(tag_text,"\n");
		a_text.replace("%index%", m_index);
		a_text.replace("%litera%", m_litera);
		title->setText(a_text);
	}

	return title;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelLine* AskuLevelFile::makeLine(QDomElement& tag_line, AskuLevel* level)
{
	AskuLevelLine* line = new AskuLevelLine(level);

	QString a_visible = tag_line.attribute("visible","true");

	if(a_visible == "true")
		line->setVisibility(Visible);
	else
		line->setVisibility(Hidden);

	QDomElement tag_point1 = tag_line.firstChildElement("point");
	if(!tag_point1.isNull())
	{
		QString a_x = tag_point1.attribute("x","0");
		QString a_y = tag_point1.attribute("y","0");
		QString a_m = tag_point1.attribute("marker","none");

		line->setPointBegin(QPoint(a_x.toUInt(),a_y.toUInt()));

		if(a_m != "none")
			line->setForm(ArrowLeft);
	}

	QDomElement tag_point2 = tag_point1.nextSiblingElement("point");
	if(!tag_point2.isNull())
	{
		QString a_x = tag_point2.attribute("x","0");
		QString a_y = tag_point2.attribute("y","0");
		QString a_m = tag_point2.attribute("marker","none");

		line->setPointEnd(QPoint(a_x.toUInt(),a_y.toUInt()));

		if(a_m != "none")
		{
			if(line->form() == NoArrow)
				line->setForm(ArrowRight);
			else
				line->setForm(ArrowBoth);
		}
	}

	return line;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelText* AskuLevelFile::makeSign(QDomElement& tag_sign, AskuLevel* level)
{
	AskuLevelText* sign = new AskuLevelText(level);

	QString a_orientation = tag_sign.attribute("orientation", "horizontal");
	QString a_align = tag_sign.attribute("align", "bottomleft");
	QString a_visible = tag_sign.attribute("visible","true");

	TextAligns e_align = AlignNone;

	if(a_align.contains("left"))
		e_align |= AlignLeft;
	else if(a_align.contains("right"))
		e_align |= AlignRight;
	else if(a_align.contains("center"))
		e_align |= AlignHCenter;

	if(a_align.contains("top"))
		e_align |= AlignTop;
	else if(a_align.contains("bottom"))
		e_align |= AlignBottom;
	else if(a_align.contains("center"))
		e_align |= AlignVCenter;

	sign->setAlign(e_align);

	TextOrientation e_orientation = OrientationHorizontal;

	if(a_orientation == "vertical")
		e_orientation = OrientationVertical;
	else if(a_orientation == "horizontal")
		e_orientation = OrientationHorizontal;
	else if(a_orientation == "reversevertical")
		e_orientation = OrientationReverseVertical;
	else if(a_orientation == "reversehorizontal")
		e_orientation = OrientationReverseHorizontal;

	sign->setOrientation(e_orientation);

	Visibility e_visibility = Visible;

	if(a_visible == "true")
		e_visibility = Visible;
	else
		e_visibility = Hidden;

	sign->setVisibility(e_visibility);

	QDomElement tag_point = tag_sign.firstChildElement("point");
	if(!tag_point.isNull())
	{
		QString a_x = tag_point.attribute("x","0");
		QString a_y = tag_point.attribute("y","0");
		sign->setPoint(QPoint(a_x.toUInt(),a_y.toUInt()));
	}

	QDomElement tag_text = tag_sign.firstChildElement("text");
	if(!tag_text.isNull())
	{
		QString a_lang = tag_text.attribute("lang", "ru");
		QString a_text = textFromElement(tag_text,"\n");
		a_text.replace("%index%", m_index);
		a_text.replace("%litera%", m_litera);
		sign->setText(a_text);
	}

	return sign;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelElement* AskuLevelFile::makeElement(QDomElement& tag_element, AskuLevel* level)
{
	AskuLevelElement* element = new AskuLevelElement(level);

	QString a_form = tag_element.attribute("form", "");
	QString a_visible = tag_element.attribute("visible","true");
	QString a_id = tag_element.attribute("id","0");
	QString a_name = tag_element.attribute("name","");
	QString a_state = tag_element.attribute("state","");
	QString a_radius = tag_element.attribute("round","0");
	QString a_condition = tag_element.attribute("condition","");
	QString a_userstate = tag_element.attribute("userstate","");
	QString a_uservalue = tag_element.attribute("uservalue","");

	if(a_form == "rectangle")
		element->setForm(Rectangle);
	else if(a_form == "ellipse")
		element->setForm(Ellipse);
	else if(a_form == "switch")
		element->setForm(Switch);
	else if(a_form == "dashedrectangle")
		element->setForm(DashedRectangle);
	else if(a_form == "polygon")
		element->setForm(Polygon);
	else
		element->setForm(TextOnly);

	element->setId(a_id.toUInt());
	element->setName(a_name);
	element->setRadius(a_radius.toUInt());
	element->setUserState(a_userstate);
	element->setSavedUserState(a_userstate);
	element->setUserValue(a_uservalue);

	if(a_state == "norma")
		element->setState(Norma);
	else if(a_state == "error")
		element->setState(Error);
	else if(a_state == "avar")
		element->setState(Avar);
	else if(a_state == "mest")
		element->setState(Mest);
	else if(a_state == "disable")
		element->setState(Disable);
	else if(a_state == "substrate")
		element->setState(Substrate);
	else //if(a_state == "not")
		element->setState(Not);

	element->setSavedState(element->state());

	if(a_visible == "true")
		element->setVisibility(Visible);
	else if(a_visible == "condition")
		element->setVisibility(Condition);
	else
		element->setVisibility(Hidden);

	QList<ElementState> listCondition;
	foreach(QString e_condition, a_condition.split(","))
	{
		if(e_condition == "norma")
			listCondition << Norma << NormaMest;
		else if(e_condition == "error")
			listCondition << Error << ErrorMest;
		else if(e_condition == "avar")
			listCondition << Avar << AvarMest;
		else if(e_condition == "not")
			listCondition << Not << NotMest;
		else if(e_condition == "mest")
			listCondition << Mest;
		else if(e_condition == "disable")
			listCondition << Disable;
		else if(e_condition == "substrate")
			listCondition << Substrate;
	}

	element->setConditions(VisibilityConditions(listCondition));

	if(element->form() == Polygon)
	{
		for(QDomElement tag_point = tag_element.firstChildElement("point"); !tag_point.isNull(); tag_point = tag_point.nextSiblingElement("point"))
		{
			QString a_x = tag_point.attribute("x","0");
			QString a_y = tag_point.attribute("y","0");
			element->appendPolygonPoint(QPoint(a_x.toUInt(),a_y.toUInt()));
		}
	}
	else
	{
		QDomElement tag_point1 = tag_element.firstChildElement("point");
		if(!tag_point1.isNull())
		{
			QString a_x = tag_point1.attribute("x","0");
			QString a_y = tag_point1.attribute("y","0");
			element->setTopLeft(QPoint(a_x.toUInt(),a_y.toUInt()));
		}

		QDomElement tag_point2 = tag_point1.nextSiblingElement("point");
		if(!tag_point2.isNull())
		{
			QString a_x = tag_point2.attribute("x","0");
			QString a_y = tag_point2.attribute("y","0");
			element->setBottomRight(QPoint(a_x.toUInt(),a_y.toUInt()));
		}
	}

	QDomElement tag_sign = tag_element.firstChildElement("sign");
	if(!tag_sign.isNull())
	{
		QString a_format = tag_sign.attribute("format","all");
		QString a_align = tag_sign.attribute("align","center");
		QString a_wrap = tag_sign.attribute("wrap","word");
		QString a_clip = tag_sign.attribute("clip","true");
		QString a_extern = tag_sign.attribute("external","false");
		QString a_orientation = tag_sign.attribute("orientation", "horizontal");

		if(a_format == "individual")
			element->setTextForm(Individual);
		else if(a_format == "separate")
			element->setTextForm(SeparateLine);
		else //if(a_format == "all")
			element->setTextForm(AllAsOne);

		ElementTexts elemtexts;
		elemtexts.clear();

		for(QDomElement tag_text = tag_sign.firstChildElement("text"); !tag_text.isNull(); tag_text = tag_text.nextSiblingElement("text"))
		{
			QString a_lang = tag_text.attribute("lang", "ru");
			QString a_text = textFromElement(tag_text,"\n");
			QString a_x = tag_text.attribute("x","0");
			QString a_y = tag_text.attribute("y","0");
			QString a_talign = tag_text.attribute("align","none");
			QString a_twrap = tag_text.attribute("wrap","word");
			QString a_tclip = tag_text.attribute("clip","true");
			QString a_textern = tag_text.attribute("external","false");
			QString a_tcondition = tag_text.attribute("condition","");
			QString a_tuserstates = tag_text.attribute("userstate","");
			QString a_tuservalues = tag_text.attribute("uservalue","");
			QString a_torientation = tag_sign.attribute("orientation", "horizontal");

			if(element->textform() != Individual)
			{
				a_talign = a_align;
				a_twrap = a_wrap;
				a_tclip = a_clip;
				a_textern = a_extern;
				a_torientation = a_orientation;
			}

			TextAligns e_align = AlignNone;

			if(a_twrap.contains("word"))
				e_align |= TextWordWrap;
			else if(a_twrap.contains("any"))
				e_align |= TextWrapAnywhere;
			else if(a_twrap.contains("line"))
				e_align |= TextSingleLine;

			if(a_tclip == "false")
				e_align |= TextDontClip;

			if(a_textern == "true")
			{
				e_align |= AlignExternal;

				if(a_talign.startsWith("center"))
				{
					e_align |= AlignExtTopOrBottom;
					e_align |= AlignVCenter;
				}
				else if(a_talign.startsWith("top"))
				{
					e_align |= AlignExtTopOrBottom;
					e_align |= AlignTop;
				}
				else if(a_talign.startsWith("bottom"))
				{
					e_align |= AlignExtTopOrBottom;
					e_align |= AlignBottom;
				}
				else if(a_talign.startsWith("left"))
				{
					e_align |= AlignExtLeftOrRight;
					e_align |= AlignLeft;
				}
				else if(a_talign.startsWith("right"))
				{
					e_align |= AlignExtLeftOrRight;
					e_align |= AlignRight;
				}

				if(e_align & AlignExtTopOrBottom)
				{
					if(a_talign.endsWith("left"))
						e_align |= AlignLeft;
					else if(a_talign.endsWith("right"))
						e_align |= AlignRight;
					else if(a_talign.endsWith("center"))
						e_align |= AlignHCenter;
				}

				if(e_align & AlignExtLeftOrRight)
				{
					if(a_talign.endsWith("top"))
						e_align |= AlignTop;
					else if(a_talign.endsWith("bottom"))
						e_align |= AlignBottom;
					else if(a_talign.endsWith("center"))
						e_align |= AlignVCenter;
				}
			}
			else
			{
				if(a_talign.contains("left"))
					e_align |= AlignLeft;
				else if(a_talign.contains("right"))
					e_align |= AlignRight;
				else if(a_talign.contains("center"))
					e_align |= AlignHCenter;

				if(a_talign.contains("top"))
					e_align |= AlignTop;
				else if(a_talign.contains("bottom"))
					e_align |= AlignBottom;
				else if(a_talign.contains("center"))
					e_align |= AlignVCenter;
			}

			TextOrientation e_orientation = OrientationHorizontal;

			if(a_torientation == "vertical")
				e_orientation = OrientationVertical;
			else if(a_torientation == "horizontal")
				e_orientation = OrientationHorizontal;
			else if(a_torientation == "reversevertical")
				e_orientation = OrientationReverseVertical;
			else if(a_torientation == "reversehorizontal")
				e_orientation = OrientationReverseHorizontal;

			a_text.replace("%index%", m_index);
			a_text.replace("%litera%", m_litera);

			QList<ElementState> listCondition;
			foreach(QString a_condition, a_tcondition.split(","))
			{
				if(a_condition == "norma")
					listCondition << Norma << NormaMest;
				else if(a_condition == "error")
					listCondition << Error << ErrorMest;
				else if(a_condition == "avar")
					listCondition << Avar << AvarMest;
				else if(a_condition == "not")
					listCondition << Not << NotMest;
				else if(a_condition == "mest")
					listCondition << Mest;
				else if(a_condition == "disable")
					listCondition << Disable;
				else if(a_condition == "substrate")
					listCondition << Substrate;
				else if(a_condition == "user")
					listCondition << User;
			}

			QStringList listUserStates = a_tuserstates.split(",",QString::SkipEmptyParts);

			ElementText elemtext(a_text, e_align, e_orientation, QPoint(a_x.toInt(), a_y.toInt()), VisibilityConditions(listCondition, listUserStates));
			elemtext.setStateForVisible(element->state(), element->userState());
			elemtexts.append(elemtext);
		}

		element->setTexts(elemtexts);
		element->setSavedTexts(elemtexts);
	}

	return element;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel* AskuLevelFile::makeLevel(AskuLevelCollection* collection, QString name, QString litera, QString index)
{
	if(wasError())
		return NULL;

	QDomElement tag_level = documentElement();

	if(name.isEmpty())
		name = tag_level.attribute("name","");

	m_index = index;
	m_litera = litera;

	AskuLevel *level = new AskuLevel(collection, name);

	for(QDomElement tag_element = tag_level.firstChildElement("element"); !tag_element.isNull(); tag_element = tag_element.nextSiblingElement("element"))
		makeElement(tag_element, level);

	for(QDomElement tag_line = tag_level.firstChildElement("line"); !tag_line.isNull(); tag_line = tag_line.nextSiblingElement("line"))
		makeLine(tag_line, level);

	for(QDomElement tag_sign = tag_level.firstChildElement("sign"); !tag_sign.isNull(); tag_sign = tag_sign.nextSiblingElement("sign"))
		makeSign(tag_sign, level);

	QDomElement tag_title = tag_level.firstChildElement("title");
	if(!tag_title.isNull())
		makeTitle(tag_title, level);

	return level;
}

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------
