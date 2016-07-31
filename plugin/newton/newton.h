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


#ifndef NEWTON_H
#define NEWTON_H

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
    \class Newton

    \brief defines a temperature in newton.

    Newton defines a length in newton in the \a Conversion utility.

    The Newton scale is a temperature scale devised by Isaac Newton in 1701.

    Newton used linseed oil as thermometric material and measured its change
    of volume against his reference points. He set as 0 on his scale "the heat
    of air in winter at which water begins to freeze" (Calor aeris hyberni ubi
    aqua incipit gelu rigescere), reminiscent of the standard of the modern
    Celsius scale (i.e. 0 °N = 0 °C), but he has no single second reference point;
    he does give the "heat at which water begins to boil" as 33, but this is not a
    defining reference; the values for body temperature and the boiling point of
    water suggest a conversion factor between the Newton and the Celsius scale
    of between about 3.08 (12 °N = 37 °C) and 3.03 (33 °N = 100 °C) but since the
    objectively verifiable reference points given result in irreconcilable data
    (especially for high temperatures), no unambiguous "conversion" between the
    scales is possible.\l {"https://en.wikipedia.org/wiki/Newton_scale"}
    {"Wikipedia Newton Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Newton :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Newton( ) :
            AbstractTemperatureConversion( QStringLiteral("Newton"),
                                           QStringLiteral("°N"),
                                           tr("Temperature measurements on the newton scale")) {

            mAbsoluteValue = -90.14;

        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // NEWTON_H
