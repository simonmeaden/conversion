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


#ifndef ROMER_H
#define ROMER_H

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
    \class Romer

    \brief defines a temperature in romer.

    Romer defines a length in romer in the \a Conversion utility.

    Rømer is a temperature scale named after the Danish astronomer
    Ole Christensen Rømer, who proposed it in 1701. It is based on the
    freezing point of pure water being 7.5 degrees and the boiling point
    of water as 60 degrees.

    In this scale, the zero was initially set using freezing brine.
    The boiling point of water was defined as 60 degrees. Rømer then
    saw that the freezing point of pure water was roughly one eighth
    of the way (about 7.5 degrees) between these two points, so he
    redefined the lower fixed point to be the freezing point of water
    at precisely 7.5 degrees. This did not greatly change the scale
    but made it easier to calibrate by defining it by reference to pure
    water. Thus the unit of this scale, a Rømer degree, is 100/52.5 = 40/21
    of a kelvin (or of a Celsius degree). The symbol is sometimes given as °R,
    but since that is also sometimes used for the Rankine scale, the other
    symbol °Rø is to be preferred. The name should not be confused with Réaumur.
    \l {"https://en.wikipedia.org/wiki/R%C3%B8mer_scale}
    {"Wikipedia Rømer Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Romer :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Romer( ) :
            AbstractTemperatureConversion( QStringLiteral("Rømer"),
                                           QStringLiteral("°Rø"),
                                           tr("Temperature measurements on the Rømer scale")) {

            mAbsoluteValue = -135.9;

        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // ROMER_H
