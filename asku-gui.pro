CONFIG += asku-gui
TARGET = asku-gui
DEFINES += APPNAME=\\\"$${TARGET}\\\"

include (../asku.pri)

unix {
	target.files += $${TARGET}
	target.path = $$[QT_INSTALL_BINS]
	icons.files += ../install/*.png
	icons.path = /usr/share/$${TARGET}
	INSTALLS += target icons
}

HEADERS += ../common/global.h \
	../common/application.h \
	../common/module.h \
	../common/tcpnetwork.h \
	../common/logger.h \
	../common/protocol.h \
	../common/parser.h \
	../common/connection.h \
	../common/xmlfile.h \
	../common/dialog.h \
	../common/stateset.h \
	../common/ctrlstate.h \
	../common/sectortable.h \
	globalvar.h \
	xpmset.h \
	guiapplication.h \
	guimodule.h \
	mainwindow.h \
	centralwidget.h \
	smallwindow.h \
	settingsui.h \
	dlgabout.h \
	config.h \
	actions.h \
	password.h \
	levelstructure.h \
	levelfiles.h \
	levelcollection.h \
	levelpainter.h \
	rlscontrol.h \
	control.h \
	howl.h \
	dialogcollection.h \
	dlgdasd.h \
	dlgtables.h \
	dlgctrlpanel.h \
	dlgviewer.h \
	dlgphase.h \
	dlgmeasure.h \
	dlgskrpilot.h \
	dlgsetprm.h \
	dlglistrgdv.h \
	dlgctrlprd.h \
	dlgctrlelk.h \
	dlgcoolers.h \
	dlgdrives.h \
	dlgupses.h \
	dlgdeses.h \
	dlgchannel.h \
	dlgadvanced.h \
	dlglogger.h \
	dlgpowermeter.h \
	dlgavtomatica.h

SOURCES += ../common/global.cpp \
	../common/application.cpp \
	../common/module.cpp \
	../common/tcpnetwork.cpp \
	../common/logger.cpp \
	../common/protocol.cpp \
	../common/parser.cpp \
	../common/connection.cpp \
	../common/xmlfile.cpp \
	../common/dialog.cpp \
	../common/stateset.cpp \
	../common/ctrlstate.cpp \
	../common/sectortable.cpp \
	globalvar.cpp \
	xpmset.cpp \
	guiapplication.cpp \
	main.cpp \
	guimodule.cpp \
	mainwindow.cpp \
	centralwidget.cpp \
	smallwindow.cpp \
	settingsui.cpp \
	dlgabout.cpp \
	config.cpp \
	actions.cpp \
	password.cpp \
	levelstructure.cpp \
	levelfiles.cpp \
	levelcollection.cpp \
	levelpainter.cpp \
	rlscontrol.cpp \
	control.cpp \
	howl.cpp \
	dialogcollection.cpp \
	dlgdasd.cpp \
	dlgtables.cpp \
	dlgctrlpanel.cpp \
	dlgviewer.cpp \
	dlgphase.cpp \
	dlgmeasure.cpp \
	dlgskrpilot.cpp \
	dlgsetprm.cpp \
	dlglistrgdv.cpp \
	dlgctrlprd.cpp \
	dlgctrlelk.cpp \
	dlgcoolers.cpp \
	dlgdrives.cpp \
	dlgupses.cpp \
	dlgdeses.cpp \
	dlgchannel.cpp \
	dlgadvanced.cpp \
	dlglogger.cpp \
	dlgpowermeter.cpp \
	dlgavtomatica.cpp

FORMS += about.ui \
	settingsui.ui \
	password.ui \
	passchange.ui \
	dasd.ui \
	tables.ui \
	ctrlpanel.ui \
	viewer.ui \
	phase.ui \
	measure.ui \
	skrpilot.ui \
	setprm.ui \
	listrgdv.ui \
	ctrlprd.ui \
	ctrlelk.ui \
	coolers.ui \
	drives.ui \
	upses.ui \
	deses.ui \
	channel.ui \
	cadvance.ui \
	logger.ui \
	powermeter.ui \
	avtomatica.ui
