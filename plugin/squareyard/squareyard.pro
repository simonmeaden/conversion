#-------------------------------------------------
#
# Project created by QtCreator 2016-07-28T11:55:54
#
#-------------------------------------------------


QT       += core
QT       -= gui

TEMPLATE = lib
CONFIG += plugin shared

DEFINES += CONVERSION_LIBRARY

CONFIG += c++11 # C++11 is the newest standard

CONFIG(debug, debug|release) {
    TARGET = $$qtLibraryTarget(squareyardd)
    DESTDIR = ../../../build/conversion/plugins
    OBJECTS_DIR = $$DESTDIR/.objd
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = $$qtLibraryTarget(squareyard)
    DESTDIR = ../../../build/conversion/plugins
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

INCLUDEPATH += $$PWD/../../src

SOURCES +=

HEADERS += \
    $$PWD/squareyard.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}

DISTFILES +=

unix|win32: LIBS += -lgmp -lgmpxx
