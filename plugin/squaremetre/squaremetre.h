#ifndef SQUAREMETRE_H
#define SQUAREMETRE_H

#include "conversion_global.h"
#include "abstractareaconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class SquareMetre
 *
 * \brief defines a length in square metres.
 *
 * SquareMetre (1 metre x 1 metre) defines an area in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT SquareMetre :
        public QObject,
        public AbstractAreaConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        SquareMetre( ) :
            AbstractAreaConversion( QStringLiteral("1E24"), QStringLiteral("1E24"),
                                    QStringLiteral("SquareMetre"), QStringLiteral("sq m"),
                                    tr("Square metre, 1 metre by 1 metre") ) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // SQUAREMETRE_H
