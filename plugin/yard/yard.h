#ifndef YARD_H
#define YARD_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Yard
 *
 * \brief defines a length in attometres.
 *
 * Yards (or 0.9144 metres) defines a length in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Yard : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Yard( ) :
            AbstractLengthConversion( "9144E23", "Yard", "yd" ) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // YARD_H
