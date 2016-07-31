#ifndef TENTHS_H
#define TENTHS_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Tenths
 *
 * \brief defines a length in ten thousandths of an inch.
 *
 * Tenths (or 1 ten thousandths of an onch ) defines a length in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Tenths : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Tenths( ) :
            AbstractLengthConversion( "254E18", "Tenths", "tenths" ) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // TENTHS_H
