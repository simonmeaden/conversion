# ***************************************************************************
# Copyright (c) 2016-2016, Simon Meaden
# ***************************************************************************
#
# Simonsoft - Conversion Library
# Config PRI File
#
# Simple unit conversion utility.
#
# This code is licensed under the GPL Version 3.0
# ***************************************************************************

INCLUDEPATH += $$PWD/../include

DEFINES += CONVERSION_LIBRARY

HEADERS +=\
    $$PWD/../src/converter.h \
    $$PWD/../src/abstractconversion.h \
    $$PWD/../src/abstractlengthconversion.h \
    $$PWD/../src/abstracttemperatureconversion.h \
    $$PWD/../src/conversion_global.h \
    $$PWD/../src/conversioninterface.h
    
SOURCES += \
    $$PWD/../src/converter.cpp \
    $$PWD/../src/abstractconversion.cpp \
    $$PWD/../src/abstractlengthconversion.cpp \
    $$PWD/../src/abstracttemperatureconversion.cpp

DISTFILES += \
    $$PWD/../src/converter.qdocconf

