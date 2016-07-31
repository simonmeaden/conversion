# ***************************************************************************
# Copyright (c) 2016-2016, Simon Meaden
# ***************************************************************************
#
# Simonsoft - Conversion Plugin Library
# Config PRI File
#
# Simple unit conversion utility plugin library.
#
# This code is licensed under the GPL Version 3.0
# ***************************************************************************

DEFINES += CONVERSION_LIBRARY

SUBDIRS += \
    $$PWD/../conversion/conversion_global.h \
    $$PWD/../conversion/conversioninterface.h \
    $$PWD/../conversion/abstractconversion \
    $$PWD/../conversion/yoctometre \
    $$PWD/../conversion/centimetre \
    $$PWD/../conversion/decimetre \
    $$PWD/../conversion/metre

