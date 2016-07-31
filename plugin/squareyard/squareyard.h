#ifndef SQUAREYARD_H
#define SQUAREYARD_H

#include "conversion_global.h"
#include "abstractareaconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class SquareYard
 *
 * \brief defines a length in square yards.
 *
 * SquareYard (1 yard x 1 yard) defines an area in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT SquareYard :
        public QObject,
        public AbstractAreaConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        SquareYard( ) :
            AbstractAreaConversion( QStringLiteral("9144E23"), QStringLiteral("9144E23"),
                                    QStringLiteral("SquareYard"), QStringLiteral("sq yd"),
                                    tr("Square yard, 1 yard by 1 yard") ) {
        }

};

QT_END_NAMESPACE_CONVERSION


#endif // SQUAREYARD_H
