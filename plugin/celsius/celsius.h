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

#ifndef CELSIUS_H
#define CELSIUS_H

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
    \class Celsius

    \brief defines a temperature in degrees celsius.

    Celsius defines a temperature in celsius in the \a Conversion utility.

    Celsius, also known as centigrade,[1][2] is a scale and unit of
    measurement for temperature. As an SI derived unit, it is used
    by most countries in the world.

    From 1744 until 1954, 0 °C was defined as the freezing point of water
    and 100 °C was defined as the boiling point of water, both at a pressure
    of one standard atmosphere with mercury being the working material.
    Although these defining correlations are commonly taught in schools today,
    by international agreement the unit "degree Celsius" and the Celsius scale
    are currently defined by two different temperatures: absolute zero, and the
    triple point of VSMOW (specially purified water). This definition also
    precisely relates the Celsius scale to the Kelvin scale, which defines
    the SI base unit of thermodynamic temperature with symbol K. Absolute zero,
    the lowest temperature possible, is defined as being precisely 0 K and
    −273.15 °C. The temperature of the triple point of water is defined as
    precisely 273.16 K and 0.01 °C. \l {"https://en.wikipedia.org/wiki/Celsius"}
    {"Wikipedia celsius Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Celsius :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Celsius( ) :
            AbstractTemperatureConversion( QStringLiteral("Celsius"),
                                           QStringLiteral("°C"),
                                           tr("Temperature measurements on the celsius scale")) {

            mAbsoluteValue = -273.15;

        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // CELSIUS_H
