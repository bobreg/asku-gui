#ifndef __SMALLWINDOW_H__
#define __SMALLWINDOW_H__

#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QList>
#include <QAction>
#include "settingsui.h"
#include "mainwindow.h"

//----------------------------------------------------------------------------------------------------------------

// ASKU Small Window's Frame
// *************************

class AskuSmallWindowFrame : public QWidget
{
	Q_OBJECT

public:
	enum Type
	{
		Date = 0,
		Time = 1,
		User = 2
	};

	AskuSmallWindowFrame(Type type, QString name, QString text, QString initialState, QWidget* parent = 0, Qt::WindowFlags f = 0);
	~AskuSmallWindowFrame();

	SettingsUI* sui() const     { return f_sui;  }
	void setSUI(SettingsUI* sui);

	QString       name () const { return objectName(); }
	Type          type () const { return f_type; }
	QString       text () const { return f_text; }
	unsigned char state() const { return f_sid;  }
	unsigned char pureState () const;
	bool          controlled() const;
	bool          local     () const;

	QString inlineText(Type type);

public slots:
	void applyGraphic();
	void setName(QString name);
	void setText(QString text);
	void setInlineText();
	void setState(unsigned char state);
	void setPureState(unsigned char pureState);
	void setControlled(bool controlled);
	void setLocal(bool local);

protected:
	Type          f_type; // Type of frame (see enum "Type")
	QString       f_text; // Text displayed in frame
	SettingsUI*   f_sui;  // Pointer to UI settings class
	unsigned char f_sid;  // ID of state

	QPen          f_lp;   // Line pen
	QPen          f_tp;   // Text pen
	QBrush        f_bb;   // Body brush
	QBrush        f_fb;   // Frame brush (for "Local")

	virtual void paintEvent(QPaintEvent* event);
};

//----------------------------------------------------------------------------------------------------------------

// ASKU Small Window
// *****************

class AskuSmallWindow : public QWidget
{
	Q_OBJECT

public:
	AskuSmallWindow(QWidget* parent = 0);
	~AskuSmallWindow();

	void setActions(AskuActions *actions);
	void setConfig(AskuConfig* config);

public slots:
	void applyGraphic();
	void applyConfig();
	void applyActions();

	void invokeAction(QString name, QStringList parameters = QStringList());
	void slotActionReloadConfig();
	void slotActionQuit();

	void setText (QString name, QString text);
	void setState(QString name, unsigned char state);
	void setState(QString name, QString state);
	void setPureState(QString name, unsigned char state);

	static unsigned char stringToState(QString state);

protected:
	virtual void mousePressEvent(QMouseEvent* e);
	virtual void mouseMoveEvent (QMouseEvent* e);
	virtual void closeEvent(QCloseEvent* event);
	virtual void paintEvent(QPaintEvent* event);
	virtual void hideEvent(QHideEvent* event);

	AskuSmallWindowFrame* item(QString name);

	void setWindowItems(QVariantList rows);
	AskuSmallWindowFrame* setWindowItem(QVariantMap element);

	void setGeometry(QString width = QString(), QString height = QString());
	void setWindowAlign(QString align = QString(), QString x = QString(), QString y = QString());
	void clear();

private:
	QList<AskuSmallWindowFrame*> f_frames;
	SettingsUI*                  f_sui;
	QMenu*                       f_menu;
	QTimer*                      f_timer;
	int move_x;
	int move_y;

	AskuConfig* m_config;
	AskuActions* m_actions;

signals:
	void sigReloadConfig();
	void sigQuit();
};

//----------------------------------------------------------------------------------------------------------------

#endif // __SMALLWINDOW_H__
