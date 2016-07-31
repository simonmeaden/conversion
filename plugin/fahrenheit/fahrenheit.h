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


#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

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
    \class Fahrenheit

    \brief defines a temperature in degrees fahrenheit.

    Celsius defines a temperature in fahrenheit in the \a Conversion utility.

    Fahrenheit is a temperature scale based on one proposed in 1724 by the
    Polish-born German physicist Daniel Gabriel Fahrenheit (1686–1736),
    after whom the scale is named.[1] It uses the degree Fahrenheit (symbol °F)
    as the unit. There exist several accounts of how he originally defined his
    scale. The lower defining point, 0 degrees, was established as the temperature
    of a solution of brine made from equal parts of ice and salt. Further limits
    were established as the melting point of ice (32 degrees) and his best
    estimate of the average human body temperature (96 degrees, about 2.5 degrees
    less than modern measurements).[2] The scale is now usually defined by two
    fixed points: the temperature at which water freezes into ice is defined as
    32 degrees, and the boiling point of water is defined to be 212 degrees, a
    180-degree separation, as defined at sea level and standard atmospheric
    pressure.\l {"https://en.wikipedia.org/wiki/Fahrenheit"}
    {"Wikipedia Fahenheit Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Fahrenheit :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Fahrenheit( ) :
            AbstractTemperatureConversion( QStringLiteral("Fahrenheit"),
                                           QStringLiteral("°F"),
                                           tr("Temperature measurements on the fahrenheit scale")) {
        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // FAHRENHEIT_H
