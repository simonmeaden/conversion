#-------------------------------------------------
#
# Project created by QtCreator 2016-07-20T08:33:10
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = examples
TEMPLATE = app

CONFIG += debug_and_release
CONFIG += debug_and_release_target
CONFIG += build_all
#CONFIG += static # static library
#CONFIG += shared # shared dll library
CONFIG += c++11 # C++11 is the newest standard

CONFIG(debug, debug|release) {
    TARGET = exampled
    DESTDIR = ../../build/conversion
    OBJECTS_DIR = $$DESTDIR/conversion/.objd
    MOC_DIR = $$DESTDIR/conversion/.mocd
    RCC_DIR = $$DESTDIR/conversion/.qrcd
    UI_DIR = $$DESTDIR/conversion/.uid
}

CONFIG(release, debug|release) {
    TARGET = example
    DESTDIR = ../../build/conversion
    OBJECTS_DIR = $$DESTDIR/conversion/.obj
    MOC_DIR = $$DESTDIR/conversion/.moc
    RCC_DIR = $$DESTDIR/conversion/.qrc
    UI_DIR = $$DESTDIR/conversion/.ui
}

INCLUDEPATH += $$PWD/../src

SOURCES += \
        main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/ -lconversion
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/ -lconversiond
else:unix:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/ -lconversion
else:unix:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/ -lconversiond

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../conversion/libconversion.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../conversion/libconversiond.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../conversion/conversion.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../conversion/conversiond.lib
#else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../conversion/libconversion.a
#else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../conversion/libconversiond.a


unix|win32: LIBS += -lgmp -lgmpxx
