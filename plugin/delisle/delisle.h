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


#ifndef DELISLE_H
#define DELISLE_H

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
    \class Delisle

    \brief defines a temperature in delisle.

    Kelvin defines a length in delisle in the \a Conversion utility.

    The Delisle scale (°D) is a temperature scale invented in 1732
    by the French astronomer Joseph-Nicolas Delisle (1688–1768).

    In 1732, Delisle built a thermometer that used mercury as a
    working fluid. Delisle chose his scale using the temperature of
    boiling water as the fixed zero point and measured the contraction
    of the mercury (with lower temperatures) in hundred-thousandths.
    \l {"https://en.wikipedia.org/wiki/Delisle_scale"}
    {"Wikipedia Delisle Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Delisle :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Delisle( ) :
            AbstractTemperatureConversion( QStringLiteral("Delisle"),
                                           QStringLiteral("°D"),
                                           tr("Temperature measurements on the Delisle scale")) {

            mAbsoluteValue = 559.73;

        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // DELISLE_H
