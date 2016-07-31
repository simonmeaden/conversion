#-------------------------------------------------
#
# Project created by QtCreator 2016-07-20T10:14:10
#
#-------------------------------------------------

QT       += core
QT       -= gui

TEMPLATE = lib
CONFIG += plugin shared

DEFINES += CONVERSION_LIBRARY

CONFIG += c++11 # C++11 is the newest standard

CONFIG(debug, debug|release) {
    TARGET = $$qtLibraryTarget(yoctometred)
    DESTDIR = ../../../build/conversion/plugins
    OBJECTS_DIR = $$DESTDIR/.objd
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = $$qtLibraryTarget(yoctometred)
    DESTDIR = ../../../build/conversion/plugins
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

INCLUDEPATH += $$PWD/../../src

SOURCES +=

HEADERS += \
    $$PWD/yoctometre.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}

DISTFILES +=

unix|win32: LIBS += -lgmp -lgmpxx
