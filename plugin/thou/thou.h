#ifndef THOU_H
#define THOU_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class Conversion::Thou

    \brief defines a length in thousandths of an inch.

    Thou (0.001 inches or 0.0000254 metres) defines a length in  the \a Conversion utility.
    Sometimes also called Mil.

    \author Simon Meaden
    \date   20 July 2016
    \see Conversion::Mil
*/

class CONVERSIONSHARED_EXPORT Thou : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Thou( ) :
            AbstractLengthConversion( "254E19", "Thou", "thou", "Thousandths of an inch (also called mil)" ) {
        }

};



QT_END_NAMESPACE_CONVERSION

#endif // THOU_H
