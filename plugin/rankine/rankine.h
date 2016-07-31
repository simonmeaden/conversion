/**
 ** This file is part of the ConversionUtility project.
 ** Copyright 2016 Simon <simonmeaden@smelecomp.co.uk>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/


#ifndef RANKINE_H
#define RANKINE_H

#include <QObject>
#include <QString>

#include <gmp.h>
#include <gmpxx.h>

#include "conversion_global.h"
#include "abstracttemperatureconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class Rankine

    \brief defines a temperature in rankine.

    Rankine defines a length in rankine in the \a Conversion utility.

    Rankine is a thermodynamic temperature based on an absolute scale
    named after the Glasgow University engineer and physicist William
    John Macquorn Rankine, who proposed it in 1859. (The Kelvin scale
    was first proposed in 1848.)

    The symbol for degrees Rankine is °R (or °Ra if necessary to
    distinguish it from the Rømer and Réaumur scales). By analogy with
    kelvin, some authors call the unit rankine, omitting the degree
    symbol.Zero on both the Kelvin and Rankine scales is absolute zero,
    but the Rankine degree is defined as equal to one degree Fahrenheit,
    rather than the one degree Celsius used by the Kelvin scale. A
    temperature of -459.67 °F is exactly equal to 0 °R. \l
    {"https://en.wikipedia.org/wiki/Rankine_scale"}
    {"Wikipedia Rankine Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Rankine :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Rankine( ) :
            AbstractTemperatureConversion( QStringLiteral("Rankine"),
                                           QStringLiteral("°R"),
                                           tr("Temperature measurements on the rankine scale")) {

            mAbsoluteValue = 0;

        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // RANKINE_H
