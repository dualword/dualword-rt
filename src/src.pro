include("version.pri")

TARGET = dualword-rt
TEMPLATE = app
message(Building: $${TARGET})

QT += widgets
CONFIG += qt thread console lrelease release

DEPENDPATH += .
INCLUDEPATH += . app gui

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXXFLAGS += $$CFLAGS $$CPPFLAGS $$CXXFLAGS
QMAKE_LFLAGS += $$LDFLAGS

HEADERS += \
	global.h \
	app/DualwordRT.h \
	app/Time.h \
	app/Rnd.h \
	gui/Scene.h \
	gui/View.h \
	gui/MainWindow.h

SOURCES += \
	main.cpp \
	app/DualwordRT.cpp \
	gui/Scene.cpp \
	gui/View.cpp \
	gui/MainWindow.cpp

RESOURCES = dualword-rt.qrc
TRANSLATIONS += ../tr/tr_en.ts \
                ../tr/tr_ru.ts \
		../tr/tr_de.ts

unix {	
    QMAKE_LFLAGS += -z now
    QMAKE_CLEAN += $${QMAKE_DEL_DIR} $$PWD/.qm/*
}

OBJECTS_DIR = .build/obj
MOC_DIR     = .build/moc
RCC_DIR     = .build/rcc
UI_DIR      = .build/ui
