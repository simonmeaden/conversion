#-------------------------------------------------
#
# Project created by QtCreator 2016-07-23T10:05:58
#
#-------------------------------------------------

QT       += core
QT       -= gui

TEMPLATE = lib
CONFIG += plugin shared

DEFINES += CONVERSION_LIBRARY

CONFIG += c++11 # C++11 is the newest standard

CONFIG(debug, debug|release) {
    TARGET = $$qtLibraryTarget(terametred)
    DESTDIR = ../../../build/conversion/plugins
    OBJECTS_DIR = $$DESTDIR/.objd
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = $$qtLibraryTarget(terametre)
    DESTDIR = ../../../build/conversion/plugins
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

SOURCES +=

HEADERS += \
    $$PWD/../../src/conversion_global.h \
    $$PWD/../../src/conversioninterface.h \
    $$PWD/../../src/abstractconversion.h \
    $$PWD/../../src/terametre.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}

DISTFILES +=

unix|win32: LIBS += -lgmp -lgmpxx
