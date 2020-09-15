#ifndef __LEVELFILES_H__
#define __LEVELFILES_H__

#include <QObject>
#include <QList>
#include <QMap>
#include <QStack>
#include <QPainter>

#include "../common/xmlfile.h"
#include "globalvar.h"
#include "levelstructure.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------

class AskuLevelFile : public XmlFile
{
	QString m_index;
	QString m_litera;

	virtual bool checkContent();

	AskuLevelTitle* makeTitle(QDomElement& element, AskuLevel* level);
	AskuLevelLine* makeLine(QDomElement& element, AskuLevel* level);
	AskuLevelText* makeSign(QDomElement& element, AskuLevel* level);
	AskuLevelElement* makeElement(QDomElement& element, AskuLevel* level);

public:
	AskuLevelFile(QString filename = QString());
	AskuLevel* makeLevel(AskuLevelCollection* collection, QString name = QString(), QString litera = QString(), QString index = QString());
};

//----------------------------------------------------------------------------------------------------------------

typedef QMap<QString,AskuLevelFile> AskuLevelFileSet;

//----------------------------------------------------------------------------------------------------------------

typedef struct _FunctionItem
{
	QString type;
	QString level;
	QString element;
	QString function;
	QString parameter;

	_FunctionItem(QString s_type, QString s_level, QString s_element, QString s_function, QString s_parameter)
	{
		type = s_type;
		level = s_level;
		element = s_element;
		function = s_function;
		parameter = s_parameter;
	}
}FunctionItem;

//----------------------------------------------------------------------------------------------------------------

typedef class QList<FunctionItem> FunctionItems;

//----------------------------------------------------------------------------------------------------------------

class AskuLevelFunctionFile : public XmlFile
{
	virtual bool checkContent();

public:
	AskuLevelFunctionFile(QString filename);
	FunctionItems makeFunctions();
};

//----------------------------------------------------------------------------------------------------------------

typedef struct _SchemeItem
{
	QString filename;
	QString name;
	QString index;
	bool isBase;
	bool isZal;

	_SchemeItem(QString s_name, QString s_filename, QString s_index = QString(), bool s_base = false, bool s_zal = false)
	{
		name = s_name;
		filename = s_filename;
		index = s_index;
		isBase = s_base;
		isZal = s_zal;
	}
}SchemeItem;

//----------------------------------------------------------------------------------------------------------------

typedef class QList<SchemeItem> SchemeItems;

//----------------------------------------------------------------------------------------------------------------

class AskuLevelSchemeFile : public XmlFile
{
	virtual bool checkContent();

public:
	AskuLevelSchemeFile(QString filename);
	SchemeItems makeScheme();
};

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------

#endif //__LEVELFILES_H__
