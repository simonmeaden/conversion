#ifndef ZEPTOMETRE_H
#define ZEPTOMETRE_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class Zeptometre

    \brief defines a length in zeptometres.

    Zeptometres (or 10 \sup{-21} metres) defines a length in  the \a Conversion utility.

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Zeptometre : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Zeptometre( ) :
            AbstractLengthConversion( "1E3", "Zeptometre", "zm" ) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // ZEPTOMETRE_H
