/*!
    \file metre.h

    \author Simon Meaden
    \date   20 July 2016
    \copyright Copyright (c) 2016-2016, Simon Meaden
    \legalese This code is licensed under the GPL Version 3.0

    Normal GPL stuff. You have permission to use, copy, modify,
    distribute  etc. to the limit of the license. There is no
    warranty whatever, however, if your ship sinks or an earthquake
    wipes out your car after using this you are on your own.

    \endlegalese

    Part of the conversion utility.
*/

#ifndef ZETTAMETRE_H
#define ZETTAMETRE_H

#include <QObject>
#include <QString>

#include <gmp.h>
#include <gmpxx.h>

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Zettametre
 *
 * \brief defines a length in zettametres.
 *
 * Zettametre (or 10 \sup{21} metres) defines a length in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Zettametre :
        public QObject,
        public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Zettametre( ) :
            AbstractLengthConversion( "1E45", "Zettametre", "Zm" ) {
        }

};


QT_END_NAMESPACE_CONVERSION


#endif // ZETTAMETRE_H
