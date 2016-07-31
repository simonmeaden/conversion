#-------------------------------------------------
#
# Project created by QtCreator 2016-07-16T09:45:48
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

# global includes.
INCLUDEPATH += $$PWD/../src/include

CONFIG += debug_and_release
CONFIG += debug_and_release_target
CONFIG += build_all
#CONFIG += static # static library
CONFIG += shared # shared dll library
CONFIG += c++11 # C++11 is the newest standard

CONFIG += create_prl # create library info for dependant apps
CONFIG += link_prl # link prl's from dependant libraries

CONFIG -= import_plugins

CONFIG(debug, debug|release) {
    TARGET = conversiond
    DESTDIR = ../../build/conversion
    OBJECTS_DIR = $$DESTDIR/conversion/.objd
    MOC_DIR = $$DESTDIR/conversion/.mocd
    RCC_DIR = $$DESTDIR/conversion/.qrcd
    UI_DIR = $$DESTDIR/conversion/.uid
}

CONFIG(release, debug|release) {
    TARGET = conversion
    DESTDIR = ../../build/conversion
    OBJECTS_DIR = $$DESTDIR/conversion/.obj
    MOC_DIR = $$DESTDIR/conversion/.moc
    RCC_DIR = $$DESTDIR/conversion/.qrc
    UI_DIR = $$DESTDIR/conversion/.ui
}

include("../../common/util/util.pri")
include("conversion.pri")

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}

DISTFILES += \
    conversion.pri

HEADERS +=

unix|win32: LIBS += -lgmp -lgmpxx
