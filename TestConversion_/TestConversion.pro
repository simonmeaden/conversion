#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T11:14:05
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG(debug, debug|release) {
    TARGET = testconversiond
    DESTDIR = ../../build/conversion
    OBJECTS_DIR = $$DESTDIR/conversion/.objd
    MOC_DIR = $$DESTDIR/conversion/.mocd
    RCC_DIR = $$DESTDIR/conversion/.qrcd
    UI_DIR = $$DESTDIR/conversion/.uid
}

CONFIG(release, debug|release) {
    TARGET = testconversion
    DESTDIR = ../../build/conversion
    OBJECTS_DIR = $$DESTDIR/conversion/.obj
    MOC_DIR = $$DESTDIR/conversion/.moc
    RCC_DIR = $$DESTDIR/conversion/.qrc
    UI_DIR = $$DESTDIR/conversion/.ui
}


include($$PWD/../conversion/conversion.pri)
#include($$PWD/../bignumber/bignumber.pri)

SOURCES += tst_testconversion.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
