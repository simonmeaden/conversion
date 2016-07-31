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


#ifndef KELVIN_H
#define KELVIN_H

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
    \class Kelvin

    \brief defines a temperature in degrees kelvin.

    Kelvin defines a temperature in kelvin in the \a Conversion utility.

    The kelvin is a unit of measure for temperature based upon an absolute
    scale. It is one of the seven base units in the International System of
    Units (SI) and is assigned the unit symbol K. The Kelvin scale is an
    absolute, thermodynamic temperature scale using as its null point absolute
    zero, the temperature at which all thermal motion ceases in the classical
    description of thermodynamics. The kelvin is defined as the fraction 1⁄273.16
    of the thermodynamic temperature of the triple point of water (exactly 0.01 °C
    or 32.018 °F).[1] In other words, it is defined such that the triple point of
    water is exactly 273.16 K. \l {"https://en.wikipedia.org/wiki/Kelvin"}
    {"Wikipedia Kelvin Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Kelvin :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Kelvin( ) :
            AbstractTemperatureConversion( QStringLiteral("Kelvin"),
                                           QStringLiteral("K"),
                                           tr("Temperature measurements on the kelvin scale") ) {

            mAbsoluteValue = 0;

        }

};

QT_END_NAMESPACE_CONVERSION

#endif // KELVIN_H
