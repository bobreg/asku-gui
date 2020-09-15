#include <QDir>
#include "globalvar.h"
#include "../common/logger.h"
#include "../common/module.h"
#include "levelcollection.h"
#include "levelpainter.h"
#include "levelfiles.h"

//----------------------------------------------------------------------------------------------------------------

namespace AskuLevels
{

//----------------------------------------------------------------------------------------------------------------
AskuLevelCollection::AskuLevelCollection(QObject* parent) : QObject(parent)
{
	m_config = NULL;
	m_actions = NULL;
	m_rlsName = QString();
	m_litera = QString();
	m_rlsConfig.clear();

	m_needUpdate = true;
	currentName = baseName = zalName = "";
	levels.clear();
	functions.clear();
	levelStack.clear();
	makeSupportLevels();
	m_connectionStatus = QString();
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelCollection::~AskuLevelCollection()
{
	cleanAll();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::setConfig(AskuConfig * config)
{
	if(!config)
		return;

	m_config = config;
	connect(config, SIGNAL(updated()), this, SLOT(applyConfig()));

	applyConfig();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::applyConfig()
{
	if(!m_config)
		return;

	m_rlsConfig = m_config->makeRlsConfig();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::setActions(AskuActions *actions)
{
	if(!actions)
		return;

	m_actions = actions;
	connect(actions, SIGNAL(updated()), this, SLOT(applyActions()));
	connect(actions, SIGNAL(invokeAction(QString, QStringList)), this, SLOT(invokeAction(QString, QStringList)));

	applyActions();
}

//-------------------------------------------------------------------------------
void AskuLevelCollection::applyActions()
{
	
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::applyGraphic()
{
	invalidate();
}

//-------------------------------------------------------------------------------
void AskuLevelCollection::invokeAction(QString action, QStringList parameters)
{
	Q_UNUSED(parameters);
//	LogInfo("AskuLevelCollection::invokeAction : \"%s\"", qPrintable(action));

	if(action.startsWith(rlsName() + "act_level_up"))
		levelUp();
	else if(action.startsWith(rlsName() + "act_level_base"))
		levelTop(0);
	else if(action.startsWith(rlsName() + "act_level_zal"))
		levelTop(1);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::actionReloadLevels(QString levelPath)
{
	clear();
	loadFromPath(levelPath);
	levelTop(m_setup.main.shema);
	refreshConnectionStatus();
	requestRefresh();
}

//----------------------------------------------------------------------------------------------------------------
qint32 AskuLevelCollection::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("LevelCollection: empty info data!");
		return result;
	}

	bool needInvalidate = false;
	QVariantMap state = data["StateSet"].toMap();
	foreach(QString name, state.keys())
	{
		QString levelName = name.section('@', 0, 0);
		QString elementName = name.section('@', 1);
		QStringList strings = state[name].toStringList();

//		qDebug() << "Level=" << levelName << "Element=" << elementName << "Values=" << strings;

		if(levelName == "status_window")
		{
			if(!elementName.isEmpty() && strings.count() > 0)
			{
				QString a_state = strings.first();
				emit setStatusWindowState(rlsName() + elementName, a_state);
			}
		}
		else if(!levelName.isEmpty())
		{
			AskuLevel* level = existsLevel(levelName);
			if(level != NULL)
			{
				if(currentName == levelName)
					needInvalidate = true;

				AskuLevelPrimitive *primitive = existsLevelPrimitive(levelName, elementName);
				if(primitive != NULL)
				{
					AskuLevelElement *element = dynamic_cast<AskuLevelElement*>(primitive);

					if(element != NULL)
					{
						if(strings.count() > 0)
						{
							QString a_state = strings.first();
							ElementState elState = stateFromString(a_state);
							element->setState(elState);

							if(strings.count() > 1)
							{
								QString a_userstate = strings[1];
								if(!a_userstate.isNull())
									element->setUserState(a_userstate);
							}
							if(strings.count() > 2)
							{
								QString a_text = strings[2];
								if(!a_text.isNull())
									element->setTexts(QStringList() << a_text);
							}

						}
						else
						{
							LogError("AskuLevelCollection: element state is empty (%s)", qPrintable(name));
						}
					}
					else
					{
						LogError("AskuLevelCollection: element incorrect type (%s)", qPrintable(name));
					}
				}
				else
				{
					LogError("AskuLevelCollection: element not found (%s)", qPrintable(name));
				}
			}
			else
			{
				LogError("AskuLevelCollection: level not found (%s)", qPrintable(levelName));
			}
		}
	}

	if(needInvalidate)
		invalidate();

	result = AskuModule::CommandSuccess;

	return result;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::sendRequest(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "algorithm";
	data["ModuleFrom"] = "level";
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit sendControlCommand(m_rlsName, data);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::sendFunction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "control";
	data["ModuleFrom"] = "level";
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit sendControlCommand(m_rlsName, data);
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::requestRefresh()
{
	sendRequest("refreshState");
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::requestReload()
{
	sendRequest("reloadLevels");
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::executeFunction(QStringList function)
{
	if(function.first() == "enter_umi")
	{
		sendFunction("monitorModule", function.mid(1));
	}
	else if(function.first() == "leave_umi")
	{
		sendFunction("monitorModule");
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::makeSupportLevels()
{
	errorName = "__error_level__";
	warningName = "__warning_level__";

	AskuLevel* errorLevel = new AskuLevel(this, errorName);
	new AskuLevelTitle(errorLevel, "Схема не найдена", QPoint(15,25), Visible);
	new AskuLevelElement(errorLevel, "__error_message__", 1, Rectangle, Avar, QRect(440,150,400,100), 10, Visible, VisibilityConditions(), AllAsOne, QStringList() << QString("Ошибка! Схема не найдена"), QString(), QString());

	AskuLevel* warningLevel = new AskuLevel(this, warningName);
	new AskuLevelWarning(warningLevel, "__warning_message__", Avar, Error, 1000, QRect(440,150,400,100), 10, Hidden, VisibilityConditions(), AllAsOne, QStringList() << QString("Нет связи с РЛС"), QString(), QString());
	new AskuLevelWarning(warningLevel, "__warning_gpr1__", Avar, Error, 1000, /*AskuLevelPainter::optimize(*/QRect(/*395*/465,5,150,20)/*)*/, 10, Hidden, VisibilityConditions(), AllAsOne, QStringList() << QString("Нет связи с ГПР1"), QString(), QString());
	new AskuLevelWarning(warningLevel, "__warning_gpr2__", Avar, Error, 1000, /*AskuLevelPainter::optimize(*/QRect(/*595*/665,5,150,20)/*)*/, 10, Hidden, VisibilityConditions(), AllAsOne, QStringList() << QString("Нет связи с ГПР2"), QString(), QString());
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::refreshConnectionStatus()
{
	AskuLevel *level = warningLevel();
	if(level)
	{
		AskuLevelPrimitive *gpr1 = level->existsPrimitive("__warning_gpr1__");
		AskuLevelPrimitive *gpr2 = level->existsPrimitive("__warning_gpr2__");

		if(gpr1)
			gpr1->setVisibility((m_connectionStatus == "0" || m_connectionStatus == "2") ? Visible : Hidden);
		if(gpr2)
			gpr2->setVisibility((m_connectionStatus == "0" || m_connectionStatus == "1") ? Visible : Hidden);
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::setConnectionStatus(QString status)
{
	m_connectionStatus = status;

	if(m_connectionStatus == "0")
		restoreSaved();

	refreshConnectionStatus();

	invalidate();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::appendLevel(AskuLevel* level)
{
	if(level)
	{
		removeLevel(level->name());
		levels.insert(level->name(),level);
		connect(level, SIGNAL(changed()), this, SLOT(levelChanged()));
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::removeAll()
{
	QMapIterator<QString, AskuLevel*> i(levels);
//	qDebug() << levels.count();
	while(i.hasNext())
	{
//		qDebug() << i.key();
		i.next();
		if(i.key() != errorName && i.key() != warningName)
		{
//			qDebug("remove");
			removeLevel(i.value());
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::cleanAll()
{
	foreach(QString key, levels.keys())
	{
		AskuLevel* level = levels.take(key);
		if(level)
			level->deleteLater();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::removeLevel(QString name)
{
	if(levels.contains(name))
	{
		AskuLevel* level = levels.take(name);
		level->deleteLater();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::removeLevel(AskuLevel* level)
{
	if(level)
		removeLevel(level->name());
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelCollection::loadFromPath(QString levelPath)
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	AskuLevelSchemeFile levelScheme(QDir::toNativeSeparators(levelPath + "/scheme.xml"));
#else
	AskuLevelSchemeFile levelScheme(QDir::convertSeparators(levelPath + "/scheme.xml"));
#endif
	if(levelScheme.wasError())
		return false;

	AskuLevelFileSet levelSet;

	bool found_base = false;
	bool found_zal = false;

	foreach(SchemeItem item, levelScheme.makeScheme())
	{
		QString filename = item.filename;
		QString name = item.name;
		QString index = item.index;

		if(!levelSet.contains(filename))
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
			levelSet[filename] = AskuLevelFile(QDir::toNativeSeparators(levelPath + "/" + filename));
#else
			levelSet[filename] = AskuLevelFile(QDir::convertSeparators(levelPath + "/" + filename));
#endif

		if(existsLevel(name))
		{
			LogError("AskuLevelCollection: duplicate level name (%s) in scheme", qPrintable(name));
		}

		levelSet[filename].makeLevel(this, name, m_litera, index);

		if(item.isBase)
		{
			if(found_base)
			{
				LogError("AskuLevelCollection: duplicate base level (%s) ignored", qPrintable(name));
			}
			else
			{
				LogInfo("AskuLevelCollection: set base level (%s)", qPrintable(name));
				found_base = true;
				baseName = name;
			}
		}

		if(item.isZal)
		{
			if(found_zal)
			{
				LogError("AskuLevelCollection: duplicate zal level (%s) ignored", qPrintable(name));
			}
			else
			{
				LogInfo("AskuLevelCollection: set zal level (%s)", qPrintable(name));
				found_zal = true;
				zalName = name;
			}
		}
	}

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	AskuLevelFunctionFile levelFunction(QDir::toNativeSeparators(levelPath + "/function.xml"));
#else
	AskuLevelFunctionFile levelFunction(QDir::convertSeparators(levelPath + "/function.xml"));
#endif
	if(levelFunction.wasError())
		return false;

	functions = levelFunction.makeFunctions();

	foreach(FunctionItem item, functions)
	{
		if(!item.level.isEmpty())
		{
			AskuLevel *level = existsLevel(item.level);
			if(!level)
			{
				LogError("AskuLevelCollection: function (%s) for level (%s) which is not in collection", qPrintable(item.type), qPrintable(item.level));
			}
			else
			{
				if(!item.element.isEmpty())
				{
					if(!level->existsPrimitive(item.element))
					{
						LogError("AskuLevelCollection: function (%s) for element (%s,%s) which is not in level", qPrintable(item.type), qPrintable(item.level), qPrintable(item.element));
					}
					else
					{
						if(item.type == "trip")
						{
							if(!item.parameter.isEmpty())
							{
								AskuLevel *level = existsLevel(item.parameter);
								if(!level)
								{
									LogError("AskuLevelCollection: function (%s) for element (%s,%s) to level (%s) which is not in collection", qPrintable(item.type), qPrintable(item.level), qPrintable(item.element), qPrintable(item.parameter));
								}
								else
								{
									int count = 0;
									foreach(FunctionItem ci, functions)
									{
										if(ci.type == item.type && ci.level == item.level && ci.element == item.element)
										{
											if(ci.parameter == item.parameter)
											{
												count++;
												if(count > 1)
												{
													LogError("AskuLevelCollection: duplicate function (%s) for element (%s,%s) to level (%s) found", qPrintable(item.type), qPrintable(item.level), qPrintable(item.element), qPrintable(item.parameter));
												}
											}
											else
											{
												LogError("AskuLevelCollection: differ function (%s) for element (%s,%s) to level (%s) found", qPrintable(item.type), qPrintable(item.level), qPrintable(item.element), qPrintable(ci.parameter));
											}
										}
									}
								}
							}
							else
							{
								LogError("AskuLevelCollection: function (%s) for element (%s,%s) to empty level", qPrintable(item.type), qPrintable(item.level), qPrintable(item.element));
							}
						}
					}
				}
			}
		}
		else
		{
			LogError("AskuLevelCollection: function (%s) for empty level", qPrintable(item.type));
		}
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::clear()
{
	LogInfo("AskuLevelCollection: cleanup");
	levels.clear();
	functions.clear();
	levelStack.clear();
	makeSupportLevels();
	invalidate();
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelCollection::needUpdate()
{
	return m_needUpdate;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelCollection::invalidate()
{
	LogInfo("AskuLevelCollection: invalidate");
	if(!m_needUpdate)
	{
		m_needUpdate = true;
		emit changed();
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::restoreSaved()
{
	QMapIterator<QString, AskuLevel*> i(levels);
	while(i.hasNext())
	{
		i.next();
		if(i.key() != errorName && i.key() != warningName)
		{
			i.value()->restoreDefaultState();
		}
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::levelChanged()
{
	AskuLevel *level = qobject_cast<AskuLevel*>(sender());
	if(level && (level->name() == currentName || level->name() == warningName))
	{
		invalidate();
		emit changed();
	}
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::levelUp()
{
	LogInfo("AskuLevelCollection: set up level");
	if(doTrip(TripUp))
		invalidate();
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::levelTop(int showZal)
{
	if(showZal)
	{
		LogInfo("AskuLevelCollection: set top zal(%s)", qPrintable(zalName));
		if(doTrip(TripTop, zalName))
			invalidate();
	}
	else
	{
		LogInfo("AskuLevelCollection: set top base(%s)", qPrintable(baseName));
		if(doTrip(TripTop, baseName))
			invalidate();
	}
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelCollection::mousePress(QPoint point)
{
	AskuLevel *level = currentLevel();
	if(level)
	{
		QString elementName = level->elementByPoint(point);
		if(!elementName.isEmpty())
		{
			QStringList clickName = findClick(level->name(), elementName);
			if(!clickName.isEmpty())
			{
				LogInfo("AskuLevelCollection: function click (%s)", qPrintable(clickName.first()));
			}
			QString tripName = findTrip(level->name(), elementName);
			if(!tripName.isEmpty())
			{
				LogInfo("AskuLevelCollection: set down level (%s)", qPrintable(tripName));
				if(doTrip(TripDown, tripName))
					invalidate();
				return true;
			}
		}
	}
	return false;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelCollection::mouseMove(QPoint point)
{
	AskuLevel *level = currentLevel();
	if(level)
	{
		QString elementName = level->elementByPoint(point);
		if(!elementName.isEmpty())
			if(!findTrip(level->name(), elementName).isEmpty())
				return true;
	}
	return false;
}

//----------------------------------------------------------------------------------------------------------------
void AskuLevelCollection::draw(AskuLevelPainter* painter)
{
	AskuLevel *level = currentLevel();
	if(!level)
		level = errorLevel();
	if(level)
		level->draw(painter);
	level = warningLevel();
	if(level)
		level->draw(painter);

	m_needUpdate = false;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevelPrimitive* AskuLevelCollection::existsLevelPrimitive(QString levelName, QString primitiveName)
{
	AskuLevel* level = existsLevel(levelName);
	if(level)
		return level->existsPrimitive(primitiveName);

	return NULL;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuLevelCollection::levelNameList()
{
	return levels.keys();
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel* AskuLevelCollection::existsLevel(QString levelName)
{
	if(levels.contains(levelName))
		return levels[levelName];

	return NULL;
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel* AskuLevelCollection::warningLevel()
{
	return existsLevel(warningName);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel* AskuLevelCollection::errorLevel()
{
	return existsLevel(errorName);
}

//----------------------------------------------------------------------------------------------------------------
AskuLevel* AskuLevelCollection::currentLevel()
{
	if(!levelStack.isEmpty())
	{
		QString levelname = levelStack.last();

		if(!levelname.isEmpty())
			return existsLevel(levelname);
	}

	return NULL;
}

//----------------------------------------------------------------------------------------------------------------
QString AskuLevelCollection::findTrip(QString levelName, QString elementName)
{
	QString tripName = QString();

	foreach(FunctionItem func, functions)
	{
		if(func.type == "trip" && func.level == levelName && func.element == elementName)
		{
			tripName = func.parameter;
		}
	}

	return tripName;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuLevelCollection::findEnter(QString levelName)
{
	QStringList enterFunc = QStringList();

	foreach(FunctionItem func, functions)
	{
		if(func.type == "enter" && func.level == levelName)
		{
			enterFunc << func.function << func.parameter.split(",", QString::SkipEmptyParts);
		}
	}

	return enterFunc;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuLevelCollection::findLeave(QString levelName)
{
	QStringList leaveFunc = QStringList();

	foreach(FunctionItem func, functions)
	{
		if(func.type == "leave" && func.level == levelName)
		{
			leaveFunc << func.function << func.parameter.split(",", QString::SkipEmptyParts);
		}
	}

	return leaveFunc;
}

//----------------------------------------------------------------------------------------------------------------
QStringList AskuLevelCollection::findClick(QString levelName, QString element)
{
	QStringList clickFunc = QStringList();

	foreach(FunctionItem func, functions)
	{
		if(func.type == "click" && func.level == levelName && func.element == element)
		{
			clickFunc << func.function << func.parameter.split(",", QString::SkipEmptyParts);
		}
	}

	return clickFunc;
}

//----------------------------------------------------------------------------------------------------------------
bool AskuLevelCollection::doTrip(TripDirection direction, QString levelName)
{
	bool changed = false;
	QString oldLevelName;

	if(!levelStack.isEmpty()) 
		oldLevelName = levelStack.last();

	if(direction == TripUp)
	{
		if(levelStack.count() > 1)
		{
			levelStack.pop();
			changed = true;
		}
	}
	else
	{
		if(direction == TripTop)
			levelStack.clear();

		levelStack.push(levelName);

		if(levelName != oldLevelName)
			changed = true;
	}

	QString newLevelName;

	if(!levelStack.isEmpty()) 
		newLevelName = levelStack.last();

	if(changed)
	{
		QStringList funcLeave = findLeave(oldLevelName);
		if(!funcLeave.isEmpty())
		{
			LogInfo("AskuLevelCollection: function leave (%s)", qPrintable(funcLeave.first()));
			executeFunction(funcLeave);
		}

		LogInfo("AskuLevelCollection: do trip from (%s) to (%s)", qPrintable(oldLevelName), qPrintable(newLevelName));

		QStringList funcEnter = findEnter(newLevelName);
		if(!funcEnter.isEmpty())
		{
			LogInfo("AskuLevelCollection: function enter (%s)", qPrintable(funcEnter.first()));
			executeFunction(funcEnter);
		}

		currentName = newLevelName;
	}

	return changed;
}

//----------------------------------------------------------------------------------------------------------------

}; //namespace AskuLevels

//----------------------------------------------------------------------------------------------------------------
