/*************************************************************************************************/
/*                                                                                               */
/*                            КЛАСС НАСТРОЕК ГРАФИКИ - Файл реализации                           */
/*                                                                                               */
/*     Имя файла: settingsui.cpp                                                                 */
/*     Версия:    1.1.1.0                                                                        */
/*     Платформа: Не зависит (Qt 4.4.3)                                                          */
/*                                                                                               */
/*************************************************************************************************/

//	ИСТОРИЯ:
//
//	10.2009	-	Версия 1.0.1.0 (для интерфейса 1.0).
//	12.2009 -	Версия 1.1.1.0 (для интерфейса 1.1).

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

#include "settingsui.h"
#include "xpmset.h"

//Глобальная переменная
SettingsUI *settingsUI = NULL;

// Параметры схемы по умолчанию
#define DEFAULT_MAINFONT				QFont("sans serif", 9)
#define DEFAULT_HEADERFONT				QFont("sans serif", 16)
#define DEFAULT_DIALOGFONT				QFont("sans serif", 10)
#define DEFAULT_HEADERFONT_COLOR		QColor(0,  0,  0  )
#define DEFAULT_BACKGROUND_COLOR		QColor(255,255,255)
#define DEFAULT_LINE_COLOR				QColor(0,  0,  0  )

#define DEFAULT_NORMAL_BODYCOLOR		QColor(0,  255,0  )	// Зеленый
#define DEFAULT_NORMAL_TEXTCOLOR		QColor(0,  0,  0  )
#define DEFAULT_WORSENING_BODYCOLOR		QColor(255,128,128)	// Бледно-красный
#define DEFAULT_WORSENING_TEXTCOLOR		QColor(0,  0,  0  )
#define DEFAULT_DENY_BODYCOLOR			QColor(255,0,  0  )	// Красный
#define DEFAULT_DENY_TEXTCOLOR			QColor(0,  0,  0  )
#define DEFAULT_TURNOFF_BODYCOLOR		QColor(128,128,128)	// Серый
#define DEFAULT_TURNOFF_TEXTCOLOR		QColor(0,  0,  0  )
#define DEFAULT_OUTOFSERVICE_BODYCOLOR	QColor(192,192,192)	// Светло-серый
#define DEFAULT_OUTOFSERVICE_TEXTCOLOR	QColor(0,  0,  0  )
#define DEFAULT_SUBSTRATE_BODYCOLOR		QColor(0,  128,128)	// Бледно-зеленый
#define DEFAULT_SUBSTRATE_TEXTCOLOR		QColor(0,  0,  0  )
#define DEFAULT_LOCAL_BODYCOLOR			QColor(255,255,0  )	// Желтый
#define DEFAULT_LOCAL_TEXTCOLOR			QColor(0,  0,  0  )


// Структура цветовой схемы
// ************************

tagSchemeStruct::tagSchemeStruct()
{
	setToDefault();
}

bool tagSchemeStruct::loadFromFile(QString path)
{
	bool result = false;
	if (!path.isNull() && !path.isEmpty())
	{
		QFile file(path);
		if (file.exists() && file.open(QIODevice::ReadOnly))
		{
			QDataStream stream(&file);
			stream >> MainFont;
			stream >> HeaderFont;
			stream >> DialogFont;
			stream >> HeaderFontColor;
			stream >> BackgroundColor;
			stream >> LineColor;
			stream >> Items[SCHEMEITEM_NORMAL].BodyColor;
			stream >> Items[SCHEMEITEM_NORMAL].TextColor;
			stream >> Items[SCHEMEITEM_WORSENING].BodyColor;
			stream >> Items[SCHEMEITEM_WORSENING].TextColor;
			stream >> Items[SCHEMEITEM_DENY].BodyColor;
			stream >> Items[SCHEMEITEM_DENY].TextColor;
			stream >> Items[SCHEMEITEM_TURNOFF].BodyColor;
			stream >> Items[SCHEMEITEM_TURNOFF].TextColor;
			stream >> Items[SCHEMEITEM_OUTOFSERVICE].BodyColor;
			stream >> Items[SCHEMEITEM_OUTOFSERVICE].TextColor;
			stream >> Items[SCHEMEITEM_SUBSTRATE].BodyColor;
			stream >> Items[SCHEMEITEM_SUBSTRATE].TextColor;
			stream >> Items[SCHEMEITEM_LOCAL].BodyColor;
			stream >> Items[SCHEMEITEM_LOCAL].TextColor;
			file.close();
			result = true;
		}
	}
	else
	{
		setToDefault();
		result = true;
	}
	return result;
}

bool tagSchemeStruct::saveToFile(QString path)
{
	bool result = false;
	if (!path.isNull() && !path.isEmpty())
	{
		QFile file(path);
		if (file.open(QIODevice::WriteOnly))
		{
			QDataStream stream(&file);
			stream << MainFont;
			stream << HeaderFont;
			stream << DialogFont;
			stream << HeaderFontColor;
			stream << BackgroundColor;
			stream << LineColor;
			stream << Items[SCHEMEITEM_NORMAL].BodyColor;
			stream << Items[SCHEMEITEM_NORMAL].TextColor;
			stream << Items[SCHEMEITEM_WORSENING].BodyColor;
			stream << Items[SCHEMEITEM_WORSENING].TextColor;
			stream << Items[SCHEMEITEM_DENY].BodyColor;
			stream << Items[SCHEMEITEM_DENY].TextColor;
			stream << Items[SCHEMEITEM_TURNOFF].BodyColor;
			stream << Items[SCHEMEITEM_TURNOFF].TextColor;
			stream << Items[SCHEMEITEM_OUTOFSERVICE].BodyColor;
			stream << Items[SCHEMEITEM_OUTOFSERVICE].TextColor;
			stream << Items[SCHEMEITEM_SUBSTRATE].BodyColor;
			stream << Items[SCHEMEITEM_SUBSTRATE].TextColor;
			stream << Items[SCHEMEITEM_LOCAL].BodyColor;
			stream << Items[SCHEMEITEM_LOCAL].TextColor;
			file.flush();
			file.close();
			result = true;
		}
	}
	return result;
}

void tagSchemeStruct::setToDefault()
{
	MainFont        = DEFAULT_MAINFONT;
	HeaderFont      = DEFAULT_HEADERFONT;
	DialogFont      = DEFAULT_DIALOGFONT;
	HeaderFontColor = DEFAULT_HEADERFONT_COLOR;
	BackgroundColor = DEFAULT_BACKGROUND_COLOR;
	LineColor       = DEFAULT_LINE_COLOR;

	Items[SCHEMEITEM_NORMAL].BodyColor			= DEFAULT_NORMAL_BODYCOLOR;
	Items[SCHEMEITEM_NORMAL].TextColor			= DEFAULT_NORMAL_TEXTCOLOR;
	Items[SCHEMEITEM_WORSENING].BodyColor		= DEFAULT_WORSENING_BODYCOLOR;
	Items[SCHEMEITEM_WORSENING].TextColor		= DEFAULT_WORSENING_TEXTCOLOR;
	Items[SCHEMEITEM_DENY].BodyColor			= DEFAULT_DENY_BODYCOLOR;
	Items[SCHEMEITEM_DENY].TextColor			= DEFAULT_DENY_TEXTCOLOR;
	Items[SCHEMEITEM_TURNOFF].BodyColor			= DEFAULT_TURNOFF_BODYCOLOR;
	Items[SCHEMEITEM_TURNOFF].TextColor			= DEFAULT_TURNOFF_TEXTCOLOR;
	Items[SCHEMEITEM_OUTOFSERVICE].BodyColor	= DEFAULT_OUTOFSERVICE_BODYCOLOR;
	Items[SCHEMEITEM_OUTOFSERVICE].TextColor	= DEFAULT_OUTOFSERVICE_TEXTCOLOR;
	Items[SCHEMEITEM_SUBSTRATE].BodyColor		= DEFAULT_SUBSTRATE_BODYCOLOR;
	Items[SCHEMEITEM_SUBSTRATE].TextColor		= DEFAULT_SUBSTRATE_TEXTCOLOR;
	Items[SCHEMEITEM_LOCAL].BodyColor			= DEFAULT_LOCAL_BODYCOLOR;
	Items[SCHEMEITEM_LOCAL].TextColor			= DEFAULT_LOCAL_TEXTCOLOR;
}


// Класс настроек графики
// **********************

SettingsUI::SettingsUI(QWidget* parent) : AskuDialog("dialog_settings_ui", parent)
{
	// Интерфейс
	ui.setupUi(this);
	setWindowIcon(m_pixmaps["palette.xpm"]);

	header  = scene.addSimpleText(trUtf8( "\xd0\x97\xd0\xb0\xd0\xb3\xd0\xbe\xd0\xbb\xd0\xbe\xd0\xb2\xd0\xbe\xd0\xba" ));
	header->setPos(10.0, 10.0);
	element = scene.addRect(60.0, 65.0, 200.0, 100.0);
	rect    = scene.addRect(65.0, 70.0, 190.0,  90.0, QPen(Qt::NoPen));
	rect->hide();
	text    = scene.addSimpleText("");
	element->setZValue(0);
	rect->setZValue   (1);
	text->setZValue   (2);
	ui.view->setScene(&scene);
	ui.view->setSceneRect(0.0, 0.0, 320.0, 220.0);

    connect( ui.okBtn,     SIGNAL( clicked() ), this, SLOT( accept()              ) );
    connect( ui.applyBtn,  SIGNAL( clicked() ), this, SLOT( slotApplyBtnClicked() ) );
    connect( ui.cancelBtn, SIGNAL( clicked() ), this, SLOT( reject()              ) );
    connect( ui.mainFontBtn,   SIGNAL( clicked() ), this, SLOT( slotTextFontChanged()   ) );
    connect( ui.headerFontBtn, SIGNAL( clicked() ), this, SLOT( slotHeaderFontChanged() ) );
    connect( ui.dlgFontBtn,    SIGNAL( clicked() ), this, SLOT( slotDlgFontChanged()    ) );
	connect( ui.headerColorBtn, SIGNAL( clicked() ), this, SLOT( slotHeaderColorChanged() ) );
	connect( ui.lineColorBtn,   SIGNAL( clicked() ), this, SLOT( slotLineColorChanged()   ) );
    connect( ui.bgColorBtn,     SIGNAL( clicked() ), this, SLOT( slotBgColorChanged() ) );
    connect( ui.schemeCBox, SIGNAL( activated(int) ), this, SLOT( slotSchemeChanged(int) ) );
    connect( ui.saveAsBtn,  SIGNAL( clicked()      ), this, SLOT( slotSaveAsBtnClicked() ) );
    connect( ui.deleteBtn,  SIGNAL( clicked()      ), this, SLOT( slotDeleteBtnClicked() ) );
    connect( ui.elemCBox,         SIGNAL( activated(int) ), this, SLOT( slotElemChanged(int)       ) );
    connect( ui.elemColorBtn,     SIGNAL( clicked()      ), this, SLOT( slotElemColorChanged()     ) );
    connect( ui.elemFontColorBtn, SIGNAL( clicked()      ), this, SLOT( slotElemFontColorChanged() ) );
    connect( ui.scaleXSBox, SIGNAL( valueChanged(int) ), this, SLOT( slotScaleXChanged(int) ) );
    connect( ui.scaleYSBox, SIGNAL( valueChanged(int) ), this, SLOT( slotScaleYChanged(int) ) );

	// Схема
	on_edit = false;
	setToDefault(true);
	modified = current;
	directory = DEFAULT_SCHEME_DIR;

	if(settingsUI != NULL)
		qDebug("Warning: double creation settings_ui dialog");

	settingsUI = this;
}

SettingsUI::~SettingsUI()
{

}


int SettingsUI::exec()
{
	beginEdit();
	loadSchemeNamesFromDir();
	selectScheme();
	ui.scaleXSBox->setMinimum(SCHEME_MIN_SCALE_X);
	ui.scaleXSBox->setMaximum(SCHEME_MAX_SCALE_X);
	ui.scaleYSBox->setMinimum(SCHEME_MIN_SCALE_Y);
	ui.scaleYSBox->setMaximum(SCHEME_MAX_SCALE_Y);
	ui.scaleXSBox->setValue(getScaleX());
	ui.scaleYSBox->setValue(getScaleY());
	repaint();
	return QDialog::exec();
}


void SettingsUI::slotSchemeChanged( int id )
{
	if (id && !loadScheme(directory, ui.schemeCBox->currentText()))
	{
		QMessageBox::critical(this, trUtf8( "\xd0\x9e\xd1\x88\xd0\xb8\xd0\xb1\xd0\xba\xd0\xb0" ),
			trUtf8( "\xd0\x9d\xd0\xb5\x20\xd1\x83\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xbe\xd1\x81\xd1\x8c\x20\xd0\xb7\xd0\xb0\xd0\xb3\xd1\x80\xd1\x83\xd0\xb7\xd0\xb8\xd1\x82\xd1\x8c\x20\xd1\x81\xd1\x85\xd0\xb5\xd0\xbc\xd1\x83" ), QMessageBox::Ok, QMessageBox::NoButton);
		ui.schemeCBox->removeItem(id);
		ui.schemeCBox->setCurrentIndex(0);
		id = 0;
	}
	if (!id)
		setToDefault();
	ui.deleteBtn->setEnabled(id);
	ui.applyBtn->setEnabled(true);
	repaint();
}

void SettingsUI::slotSaveAsBtnClicked()
{
	QString file = getCurrentFile();
	if (file.isNull() || file.isEmpty())
		file = QString("new.") + QString(SCHEME_FILE_EXT);
	QFileInfo info(QDir(directory), file);
	file = QFileDialog::getSaveFileName(this, "", info.absoluteFilePath(), QString("Scheme files (") + QString(SCHEME_FILE_MASK) + QString(")"), 0, QFileDialog::DontUseNativeDialog);
	if (!file.isNull() && !file.isEmpty())
	{
		if (saveScheme(file))
		{
			info.setFile(file);
			directory = info.absolutePath();
			setCurrentFile(info.fileName());
			loadSchemeNamesFromDir();
			selectScheme();
			ui.applyBtn->setEnabled(true);
			repaint();
		}
		else
		{
			QMessageBox::critical(this, trUtf8( "\xd0\x9e\xd1\x88\xd0\xb8\xd0\xb1\xd0\xba\xd0\xb0" ),
				trUtf8( "\xd0\x9d\xd0\xb5\xd0\xb2\xd0\xbe\xd0\xb7\xd0\xbc\xd0\xbe\xd0\xb6\xd0\xbd\xd0\xbe\x20\xd1\x81\xd0\xbe\xd1\x85\xd1\x80\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x82\xd1\x8c\x20\xd1\x81\xd1\x85\xd0\xb5\xd0\xbc\xd1\x83" ), QMessageBox::Ok);
		}
	}
}

void SettingsUI::slotDeleteBtnClicked()
{
	if (ui.schemeCBox->currentIndex() &&
		(QMessageBox::question(this, trUtf8( "\xd0\xa3\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd1\x81\xd1\x85\xd0\xb5\xd0\xbc\xd1\x8b" ), 
			trUtf8( "\xd0\x92\xd1\x8b\x20\xd0\xb4\xd0\xb5\xd0\xb9\xd1\x81\xd1\x82\xd0\xb2\xd0\xb8\xd1\x82\xd0\xb5\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe\x20\xd1\x85\xd0\xbe\xd1\x82\xd0\xb8\xd1\x82\xd0\xb5\x20\xd1\x83\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb8\xd1\x82\xd1\x8c\x20\xd1\x82\xd0\xb5\xd0\xba\xd1\x83\xd1\x89\xd1\x83\xd1\x8e\x20\xd1\x81\xd1\x85\xd0\xb5\xd0\xbc\xd1\x83\x3f" ), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes))
	{
		if (deleteScheme(directory, ui.schemeCBox->currentText()))
		{
			ui.schemeCBox->removeItem(ui.schemeCBox->currentIndex());
			ui.schemeCBox->setCurrentIndex(0);
			ui.deleteBtn->setEnabled(false);
			ui.applyBtn->setEnabled(true);
			repaint();
		}
		else
		{
			QMessageBox::critical(this, trUtf8( "\xd0\x9e\xd1\x88\xd0\xb8\xd0\xb1\xd0\xba\xd0\xb0" ),
				trUtf8( "\xd0\x9d\xd0\xb5\x20\xd1\x83\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xbe\xd1\x81\xd1\x8c\x20\xd1\x83\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb8\xd1\x82\xd1\x8c\x20\xd1\x81\xd1\x85\xd0\xb5\xd0\xbc\xd1\x83" ), QMessageBox::Ok);
		}
	}
}

void SettingsUI::slotElemChanged(int /*id*/ )
{
	repaint();
}

void SettingsUI::slotElemColorChanged()
{
	bool ok = false;
	QRgb rgb = QColorDialog::getRgba(getItemBodyColor(ui.elemCBox->currentIndex()).rgb(), &ok, this);
	if (ok)
	{
		setItemBodyColor(ui.elemCBox->currentIndex(), QColor(rgb));
		ui.applyBtn->setEnabled(true);
		repaint();
	}
}

void SettingsUI::slotElemFontColorChanged()
{
	bool ok = false;
	QRgb rgb = QColorDialog::getRgba(getItemTextColor(ui.elemCBox->currentIndex()).rgb(), &ok, this);
	if (ok)
	{
		setItemTextColor(ui.elemCBox->currentIndex(), QColor(rgb));
		ui.applyBtn->setEnabled(true);
		repaint();
	}
}

void SettingsUI::slotTextFontChanged()
{
	setMainFont(QFontDialog::getFont(0, getMainFont(), this));
	ui.applyBtn->setEnabled(true);
	repaint();
}

void SettingsUI::slotHeaderFontChanged()
{
	setHeaderFont(QFontDialog::getFont(0, getHeaderFont(), this));
	ui.applyBtn->setEnabled(true);
	repaint();
}

void SettingsUI::slotDlgFontChanged()
{
	setDialogFont(QFontDialog::getFont(0, getDialogFont(), this));
	ui.applyBtn->setEnabled(true);
	repaint();
}

void SettingsUI::slotHeaderColorChanged()
{
	bool ok = false;
	QRgb rgb = QColorDialog::getRgba(getHeaderFontColor().rgb(), &ok, this);
	if (ok)
	{
		setHeaderFontColor(QColor(rgb));
		ui.applyBtn->setEnabled(true);
		repaint();
	}
}

void SettingsUI::slotLineColorChanged()
{
	bool ok = false;
	QRgb rgb = QColorDialog::getRgba(getLineColor().rgb(), &ok, this);
	if (ok)
	{
		setLineColor(QColor(rgb));
		ui.applyBtn->setEnabled(true);
		repaint();
	}
}

void SettingsUI::slotBgColorChanged()
{
	bool ok = false;
	QRgb rgb = QColorDialog::getRgba(getBackgroundColor().rgb(), &ok, this);
	if (ok)
	{
		setBackgroundColor(QColor(rgb));
		ui.applyBtn->setEnabled(true);
		repaint();
	}
}

void SettingsUI::slotScaleXChanged( int value )
{
	setScaleX((unsigned char)value);
	ui.applyBtn->setEnabled(true);
}

void SettingsUI::slotScaleYChanged( int value )
{
	setScaleY((unsigned char)value);
	ui.applyBtn->setEnabled(true);
}


void SettingsUI::slotApplyBtnClicked()
{
	endEdit(true);
	emit changed();
	ui.applyBtn->setEnabled(false);
	beginEdit();
}

void SettingsUI::accept()
{
	endEdit(true);
	emit changed();
	QDialog::accept();
}

void SettingsUI::reject()
{
	endEdit(false);
	QDialog::reject();
}


void SettingsUI::repaint()
{
	setFont(modified.Scheme.DialogFont);
	scene.setBackgroundBrush(modified.Scheme.BackgroundColor);
	header->setFont (modified.Scheme.HeaderFont);
	header->setBrush(modified.Scheme.HeaderFontColor);
	element->setPen  (modified.Scheme.LineColor);
	element->setBrush(modified.Scheme.Items[ui.elemCBox->currentIndex()].BodyColor);
	if (ui.elemCBox->currentIndex() == SCHEMEITEM_LOCAL)
	{
		rect->setBrush(modified.Scheme.BackgroundColor);
		rect->show();
	}
	else
	{
		rect->hide();
	}
	text->setFont (modified.Scheme.MainFont);
	text->setBrush(modified.Scheme.Items[ui.elemCBox->currentIndex()].TextColor);
	text->setText(ui.elemCBox->currentText());
	text->setPos(160.0 - text->boundingRect().width() / 2, 115.0 - text->boundingRect().height() / 2);
}


void SettingsUI::loadSchemeNamesFromDir()
{
	int i = ui.schemeCBox->count() - 1;
	while (i)
	{
		ui.schemeCBox->removeItem(i);
		i--;
	}
	QDir dir(directory, QString(SCHEME_FILE_MASK), QDir::Name | QDir::IgnoreCase, QDir::Files | QDir::NoSymLinks | QDir::TypeMask);
	for (i = 0; i < (int)dir.count(); i++)
		ui.schemeCBox->addItem(dir[i]);
}

void SettingsUI::selectScheme()
{
	int n = ui.schemeCBox->findText(getCurrentFile(), Qt::MatchFixedString);
	if (n != -1)
	{
		ui.schemeCBox->setCurrentIndex(n);
	}
	else
	{
		ui.schemeCBox->setCurrentIndex(0);
		setToDefault();
	}
	ui.deleteBtn->setEnabled(n != -1);
}



// Чтение, запись, удаление схем
bool SettingsUI::loadScheme(QString path)
{
	if (path.isNull())
		return loadScheme(getCurrentDir(), getCurrentFile());
	if (path.isEmpty())
		return loadScheme(getCurrentDir(), "");
	QFileInfo info(path);
	return loadScheme(info.absolutePath(), info.fileName());
}

bool SettingsUI::saveScheme(QString path)
{
	if (path.isNull())
		return saveScheme(getCurrentDir(), getCurrentFile());
	QFileInfo info(path);
	return saveScheme(info.absolutePath(), info.fileName());
}

bool SettingsUI::deleteScheme(QString path)
{
	if (path.isNull())
		return deleteScheme(getCurrentDir(), getCurrentFile());
	QFileInfo info(path);
	return deleteScheme(info.absolutePath(), info.fileName());
}

bool SettingsUI::loadScheme(QString dir, QString file)
{
	bool result = false;
	if (file.isEmpty())
	{
		setToDefault();
		result = true;
	}
	else
	{
		if (dir.isNull() || dir.isEmpty())
			dir  = getCurrentDir();
		if (file.isNull())
			file = getCurrentFile();
		QDir directory(dir);
		QFileInfo info(directory, file);
		if (on_edit)
			result = modified.Scheme.loadFromFile(info.absoluteFilePath());
		else
			result = current.Scheme.loadFromFile (info.absoluteFilePath());
//		qDebug("LOAD: %s = %d", info.absFilePath().ascii(), result);
		if (result)
		{
			setCurrentDir (info.absolutePath());
			setCurrentFile(info.fileName());
		}
	}
	return result;
}

bool SettingsUI::saveScheme(QString dir, QString file)
{
	bool result = false;
	if (dir.isNull() || dir.isEmpty())
		dir  = getCurrentDir();
	if (file.isNull() || file.isEmpty())
		file = getCurrentFile();
	QDir directory(dir);
	QFileInfo info(directory, file);
	if (on_edit)
		result = modified.Scheme.saveToFile(info.absoluteFilePath());
	else
		result = current.Scheme.saveToFile (info.absoluteFilePath());
//	qDebug("SAVE: %s = %d", info.absFilePath().ascii(), result);
	if (result)
	{
		setCurrentDir (info.absolutePath());
		setCurrentFile(info.fileName());
	}
	return result;
}

bool SettingsUI::deleteScheme(QString dir, QString file)
{
	bool result = false;
	if (dir.isNull() || dir.isEmpty())
		dir  = getCurrentDir();
	if (file.isNull() || file.isEmpty())
		file = getCurrentFile();
	QDir directory(dir);
	QFileInfo info(directory, file);
	result = QFile::remove(info.absoluteFilePath());
//	qDebug("DELETE: %s = %d", info.absFilePath().ascii(), result);
	if (result && (dir == getCurrentDir()) && (file == getCurrentFile()))
	{
		setToDefault();
		setCurrentFile("");
	}
	return result;
}

// Установка схемы по умолчанию
void SettingsUI::setToDefault(bool defaultScales /* = false */)
{
	if (on_edit)
	{
		modified.Scheme.setToDefault();
		modified.FileName = "";
		if (defaultScales)
		{
			modified.ScaleX = DEFAULT_SCHEME_SCALE_X;
			modified.ScaleY = DEFAULT_SCHEME_SCALE_Y;
		}
	}
	else
	{
		current.Scheme.setToDefault();
		current.FileName = "";
		if (defaultScales)
		{
			current.ScaleX = DEFAULT_SCHEME_SCALE_X;
			current.ScaleY = DEFAULT_SCHEME_SCALE_Y;
		}
	}
}

// Получение и установка текущей директории и файла
QString SettingsUI::getCurrentDir()
{
	return directory;
}

void SettingsUI::setCurrentDir(QString dir)
{
	directory = dir;
}

QString SettingsUI::getCurrentFile()
{
	if (on_edit)
		return modified.FileName;
	return current.FileName;
}

void SettingsUI::setCurrentFile(QString fileName)
{
	if (on_edit)
		modified.FileName = fileName;
	else
		current.FileName  = fileName;
}

// Режим редактирования
bool SettingsUI::beginEdit()
{
	if (on_edit)
		return false;
	modified = current;
	on_edit = true;
	return true;
}

bool SettingsUI::onEdit()
{
	return on_edit;
}

bool SettingsUI::endEdit(bool apply)
{
	if (!on_edit)
		return false;
	on_edit = false;
	if (apply)
	{
		current = modified;
		saveScheme();
	}
	else
	{
		modified = current;
	}
	return true;
}


// Получение настроек графики
QFont SettingsUI::getMainFont(bool getModified /* = false */)
{
	if (on_edit && getModified)
		return modified.Scheme.MainFont;
	return current.Scheme.MainFont;
}

QFont SettingsUI::getHeaderFont(bool getModified /* = false */)
{
	if (on_edit && getModified)
		return modified.Scheme.HeaderFont;
	return current.Scheme.HeaderFont;
}

QFont SettingsUI::getDialogFont(bool getModified /* = false */)
{
	if (on_edit && getModified)
		return modified.Scheme.DialogFont;
	return current.Scheme.DialogFont;
}

QColor SettingsUI::getHeaderFontColor(bool getModified /* = false */)
{
	if (on_edit && getModified)
		return modified.Scheme.HeaderFontColor;
	return current.Scheme.HeaderFontColor;
}

QColor SettingsUI::getBackgroundColor(bool getModified /* = false */)
{
	if (on_edit && getModified)
		return modified.Scheme.BackgroundColor;
	return current.Scheme.BackgroundColor;
}

QColor SettingsUI::getLineColor(bool getModified /* = false */)
{
	if (on_edit && getModified)
		return modified.Scheme.LineColor;
	return current.Scheme.LineColor;
}

unsigned char SettingsUI::getScaleX(bool getModified /* = false */)
{
	unsigned char result;
	if (on_edit && getModified)
		result = modified.ScaleX;
	else
		result = current.ScaleX;
	if (result < SCHEME_MIN_SCALE_X)
		result = SCHEME_MIN_SCALE_X;
	if (result > SCHEME_MAX_SCALE_X)
		result = SCHEME_MAX_SCALE_X;
	return result;
}

unsigned char SettingsUI::getScaleY(bool getModified /* = false */)
{
	unsigned char result;
	if (on_edit && getModified)
		result = modified.ScaleY;
	else
		result = current.ScaleY;
	if (result < SCHEME_MIN_SCALE_Y)
		result = SCHEME_MIN_SCALE_Y;
	if (result > SCHEME_MAX_SCALE_Y)
		result = SCHEME_MAX_SCALE_Y;
	return result;
}

QColor SettingsUI::getItemBodyColor(unsigned char id, bool getModified /* = false */)
{
	if (id < SCHEME_ITEMCOUNT)
	{
		if (on_edit && getModified)
			return modified.Scheme.Items[id].BodyColor;
		return current.Scheme.Items[id].BodyColor;
	}
	return QColor(255, 255, 255);
}

QColor SettingsUI::getItemTextColor(unsigned char id, bool getModified /* = false */)
{
	if (id < SCHEME_ITEMCOUNT)
	{
		if (on_edit && getModified)
			return modified.Scheme.Items[id].TextColor;
		return current.Scheme.Items[id].TextColor;
	}
	return QColor(255, 255, 255);
}

// Задание настроек графики
void SettingsUI::setMainFont(QFont value)
{
	if (on_edit)
		modified.Scheme.MainFont = value;
	else
		current.Scheme.MainFont  = value;
}

void SettingsUI::setHeaderFont(QFont value)
{
	if (on_edit)
		modified.Scheme.HeaderFont = value;
	else
		current.Scheme.HeaderFont  = value;
}

void SettingsUI::setDialogFont(QFont value)
{
	if (on_edit)
		modified.Scheme.DialogFont = value;
	else
		current.Scheme.DialogFont  = value;
}

void SettingsUI::setHeaderFontColor(QColor value)
{
	if (on_edit)
		modified.Scheme.HeaderFontColor = value;		
	else
		current.Scheme.HeaderFontColor  = value;
}

void SettingsUI::setBackgroundColor(QColor value)
{
	if (on_edit)
		modified.Scheme.BackgroundColor = value;
	else
		current.Scheme.BackgroundColor  = value;
}

void SettingsUI::setLineColor(QColor value)
{
	if (on_edit)
		modified.Scheme.LineColor = value;
	else
		current.Scheme.LineColor  = value;
}


void SettingsUI::setScaleX(unsigned char value)
{
	if (value < SCHEME_MIN_SCALE_X)
		value = SCHEME_MIN_SCALE_X;
	if (value > SCHEME_MAX_SCALE_X)
		value = SCHEME_MAX_SCALE_X;
	if (on_edit)
		modified.ScaleX = value;
	else
		current.ScaleX  = value;
}

void SettingsUI::setScaleY(unsigned char value)
{
	if (value < SCHEME_MIN_SCALE_Y)
		value = SCHEME_MIN_SCALE_Y;
	if (value > SCHEME_MAX_SCALE_Y)
		value = SCHEME_MAX_SCALE_Y;
	if (on_edit)
		modified.ScaleY = value;
	else
		current.ScaleY  = value;
}

void SettingsUI::setItemBodyColor(unsigned char id, QColor value)
{
	if (id < SCHEME_ITEMCOUNT)
	{
		if (on_edit)
			modified.Scheme.Items[id].BodyColor = value;
		else
			current.Scheme.Items[id].BodyColor  = value;
	}
}

void SettingsUI::setItemTextColor(unsigned char id, QColor value)
{
	if (id < SCHEME_ITEMCOUNT)
	{
		if (on_edit)
			modified.Scheme.Items[id].TextColor = value;		
		else
			current.Scheme.Items[id].TextColor  = value;
	}
}
