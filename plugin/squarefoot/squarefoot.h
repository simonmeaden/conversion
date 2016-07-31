#ifndef SQUAREFOOT_H
#define SQUAREFOOT_H

#include "conversion_global.h"
#include "abstractareaconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class SquareFoot
 *
 * \brief defines a length in square feet.
 *
 * SquareFoot (1 foot x 1 foot) defines an area in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT SquareFoot :
        public QObject,
        public AbstractAreaConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        SquareFoot( ) :
            AbstractAreaConversion( QStringLiteral("201168E24"), QStringLiteral("201168E23"),
                                    QStringLiteral("SquareFoot"), QStringLiteral("sq ft"),
                                    tr("Square feet, 1 foot by 1 foot") ) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // SQUAREFOOT_H
