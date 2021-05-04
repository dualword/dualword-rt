include("version.pri")

TARGET = dualword-rt
TEMPLATE = app
message(Building: $${TARGET})

CONFIG += qt thread console release

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
				
OBJECTS_DIR = .build/obj
MOC_DIR     = .build/moc
RCC_DIR     = .build/rcc
UI_DIR      = .build/ui
