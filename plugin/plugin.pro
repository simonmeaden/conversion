TEMPLATE = subdirs

DEFINES += CONVERSION_LIBRARY

# Disables the namespace
# The problem with declaring namespaces like tjis is that the
# QTCreator method list (Symbols) do not work for some reason
DEFINES += DISABLE_CONVERSION_NAMESPACE

include("../../common/util/util.pri")

SUBDIRS +=  \
# metric
    yoctometre \
    zeptometre \
    attometre \
    femtometre \
    picometre \
    nanometre \
    micrometre \
    millimetre \
    centimetre \
    decimetre \
    metre \
    decametre \
    hectometre \
    kilometre \
    megametre \
    gigametre \
    terametre \
    pettametre \
    exametre \
    zettametre \
    yottametre \
# astrononical
    lightyear \
# imperial
    inch \
    foot \
    yard \
    cable \
    chain \
    fathom \
    furlong \
    league \
    mile \
    link \
    nauticalmile \
    rod \
    tenthou \
    thou \
    mil \
    yard \
# temperature
    kelvin \
    celsius \
    fahrenheit \
    rankine \
    delisle \
    newton \
    reaumer \
    romer \
# area
    hectare \
    acre \
    squarefoot \
    squareyard \
    squaremetre

unix|win32: LIBS += -lgmp
unix|win32: LIBS += -lgmpxx
