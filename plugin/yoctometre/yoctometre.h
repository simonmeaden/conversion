/*!
    \file yoctometre.h

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

#ifndef YOCTOMETRE_H
#define YOCTOMETRE_H

#include <QObject>
#include <QString>

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Yoctometre
 *
 * \brief defines a length in yoctometres.
 *
 * Yoctometres (or 10 \sup{-24}) metres is the smallest size allowed in the
 * \a Conversion utility as this is the base \a integer size allowed. Basically
 * 1 yoctometre == 1 base value. Framkly if you need to work in smaller sizes
 * than 1 yoctometre then you really need to write your own specialist
 * utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Yoctometre : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Yoctometre( ) :
            AbstractLengthConversion( "1", "Yoctometre", "ym" ) {
        }

};

QT_END_NAMESPACE_CONVERSION


#endif // YOCTOMETRE_H
