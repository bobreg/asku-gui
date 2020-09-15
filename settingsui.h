/*************************************************************************************************/
/*                                                                                               */
/*                           КЛАСС НАСТРОЕК ГРАФИКИ - Заголовочный файл                          */
/*                                                                                               */
/*     Имя файла: settingsui.h                                                                   */
/*     Версия:    1.1                                                                            */
/*     Описание:  содержит класс с настройками графики для схем АСКУ, такими, как шрифты, цвета  */
/*                линий, элементов, фона и масштаб отображения схемы в главном окне              */
/*     Требует:   Qt (4.4.3)                                                                     */
/*                                                                                               */
/*************************************************************************************************/

//	ИСТОРИЯ:
//
//	10.2009	-	Версия 1.0.
//	12.2009 -	Версия 1.1:
//				- Структура настроек графики объединена с интерфейсом (диалогом настроек)
//              - В структуру настроек добавлен шрифт диалогов

#ifndef SETTINGSUI_H
#define SETTINGSUI_H


#include <QFont>
#include <QColor>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>

#include <QDialog>
#include "ui_settingsui.h"
#include "../common/dialog.h"


// Маска с расширением файлов схемы
#define SCHEME_FILE_EXT		"schm"
#define SCHEME_FILE_MASK	"*.schm"

// Допустимые значения масштаба
#define SCHEME_MIN_SCALE_X	60
#define SCHEME_MAX_SCALE_X	120
#define SCHEME_MIN_SCALE_Y	60
#define SCHEME_MAX_SCALE_Y	120

// Значения по умолчанию
#ifdef Q_OS_WIN32
	#define DEFAULT_SCHEME_DIR			QString("D:\\DocumASKU\\scheme")
#endif
#ifdef Q_OS_LINUX
	#define DEFAULT_SCHEME_DIR			QString("/home/observer/scheme")
#endif

#define DEFAULT_SCHEME_FILE				QString("")
#define DEFAULT_SCHEME_SCALE_X			100
#define DEFAULT_SCHEME_SCALE_Y			100



// Структура цветовой схемы
// ************************

#define SCHEME_ITEMCOUNT		7	// Количество элементов схемы

#define SCHEMEITEM_NORMAL		0	// Норма
#define SCHEMEITEM_WORSENING	1	// Ухудшение
#define SCHEMEITEM_DENY			2	// Отказ
#define SCHEMEITEM_TURNOFF		3	// Выключен
#define SCHEMEITEM_OUTOFSERVICE	4	// Не обслуживается
#define SCHEMEITEM_SUBSTRATE	5	// Подложка
#define SCHEMEITEM_LOCAL		6	// Местное


typedef struct tagSchemeItemStruct
{
	QColor	BodyColor;
	QColor	TextColor;

} SchemeItemStruct;


typedef struct tagSchemeStruct
{
	QFont				MainFont;
	QFont				HeaderFont;
	QFont				DialogFont;
	QColor				HeaderFontColor;
	QColor				BackgroundColor;
	QColor				LineColor;
	SchemeItemStruct	Items[SCHEME_ITEMCOUNT];

	tagSchemeStruct();
	bool loadFromFile(QString path = QString::null);
	bool saveToFile  (QString path);
	void setToDefault();

} SchemeStruct;



// Класс настроек графики
// **********************

class SettingsUI : public AskuDialog
{
	Q_OBJECT
// Интерфейс
private:
	Ui::SettingsUI           ui;
	QGraphicsScene           scene;
	QGraphicsSimpleTextItem* header;
	QGraphicsRectItem*       element;
	QGraphicsRectItem*       rect;
	QGraphicsSimpleTextItem* text;

private slots:
	void slotSchemeChanged( int id );
	void slotSaveAsBtnClicked();
	void slotDeleteBtnClicked();
	void slotElemChanged( int id );
	void slotElemColorChanged();
	void slotElemFontColorChanged();
	void slotTextFontChanged();
	void slotHeaderFontChanged();
	void slotDlgFontChanged();
	void slotHeaderColorChanged();
	void slotLineColorChanged();
	void slotBgColorChanged();
	void slotScaleXChanged( int value );
	void slotScaleYChanged( int value );
	void slotApplyBtnClicked();
	void repaint();
	void loadSchemeNamesFromDir();
	void selectScheme();

// Схема
private:
	struct SettingsUIStruct
	{
		SchemeStruct	Scheme;		// Цветовая схема
		QString			FileName;	// Имя файла
		unsigned char	ScaleX;		// Масштаб по X
		unsigned char	ScaleY;		// Масштаб по Y

	} current, modified;			// Текущая и модифицированная схемы

	QString			directory;		// Директория с файлами схем
	bool			on_edit;		// Схема в процессе редактирования

public:
	SettingsUI(QWidget* parent = 0);
	~SettingsUI();

// Чтение, запись, удаление схем
	bool loadScheme  (QString path = QString::null);
	bool saveScheme  (QString path = QString::null);
	bool deleteScheme(QString path = QString::null);
	bool loadScheme  (QString dir, QString file);
	bool saveScheme  (QString dir, QString file);
	bool deleteScheme(QString dir, QString file);

// Установка схемы по умолчанию
	void setToDefault(bool defaultScales = false);

// Получение и установка текущей директории и файла
	QString getCurrentDir();
	void    setCurrentDir(QString dir);

	QString getCurrentFile();
	void    setCurrentFile(QString fileName);

// Режим редактирования
	bool beginEdit();
	bool onEdit   ();
	bool endEdit  (bool apply);

// Получение настроек графики
	QFont getMainFont  (bool getModified = false);
	QFont getHeaderFont(bool getModified = false);
	QFont getDialogFont(bool getModified = false);

	QColor getHeaderFontColor(bool getModified = false);
	QColor getBackgroundColor(bool getModified = false);
	QColor getLineColor      (bool getModified = false);

	unsigned char getScaleX(bool getModified = false);
	unsigned char getScaleY(bool getModified = false);

	QColor getItemBodyColor(unsigned char id, bool getModified = false);
	QColor getItemTextColor(unsigned char id, bool getModified = false);

// Задание настроек графики
	void setMainFont  (QFont value);
	void setHeaderFont(QFont value);
	void setDialogFont(QFont value);

	void setHeaderFontColor(QColor value);
	void setBackgroundColor(QColor value);
	void setLineColor      (QColor value);

	void setScaleX(unsigned char value);
	void setScaleY(unsigned char value);

	void setItemBodyColor(unsigned char id, QColor value);
	void setItemTextColor(unsigned char id, QColor value);

signals:
	void changed();

public slots:
	virtual void accept();
	virtual void reject();
	virtual int exec();
};

//Глобальная переменная

extern SettingsUI *settingsUI;

#endif	// SETTINGSUI_H
