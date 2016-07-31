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


#ifndef REAUMUR_H
#define REAUMUR_H

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
    \class Reaumur

    \brief defines a temperature in reaumur.

    Reaumur defines a temperature in reaumur in the \a Conversion utility.

    The Réaumur scale (°Ré, °Re, °r), also known as the "octogesimal
    division", is a temperature scale in which the freezing and boiling
    points of water are set to 0 and 80 degrees respectively. The scale is
    named after René Antoine Ferchault de Réaumur, who first proposed a
    similar scale in 1730.

    Réaumur’s thermometer contained diluted alcohol (ethanol) and was
    constructed on the principle of taking the freezing point of water
    as 0°, and graduating the tube into degrees, each of which was
    one-thousandth of the volume contained by the bulb and tube up to
    the zero mark. He suggested that the concentration of alcohol
    employed be such that it began boiling at 80 °Ré — that is, when it
    had expanded in volume by 8%. He chose alcohol instead of mercury
    because it expands more visibly, but this posed problems: his original
    thermometers were very bulky, and the low boiling point of alcohol made
    them unsuitable for many applications. Instrument-makers generally
    chose different liquids, and then used 80 °Ré to signify the boiling
    point of water, causing much confusion. In 1772 Jean-André Deluc
    studied the several substances then used in thermometers in the
    light of new theories of heat and came to the conclusion that
    mercurial thermometers were the best for practical use; for
    example, if two equal amounts of water at x and y degrees were mixed,
    the temperature of the result was then the average of x and y degrees,
    and this relationship only held reliably when mercury was used. From
    the late 18th century mercury was used almost without exception.
    These thermometers, the stems of which are graduated into eighty
    equal parts between the freezing and boiling points of water, are
    not Réaumur's original thermometers in anything but name. \l
    {"https://en.wikipedia.org/wiki/R%C3%A9aumur_scale}
    {"Wikipedia Réaumur Article"}

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Reaumur :
    public QObject,
    public AbstractTemperatureConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Reaumur( ) :
            AbstractTemperatureConversion( QStringLiteral("Réaumur"),
                                           QStringLiteral("°Ré"),
                                           tr("Temperature measurements on the Réaumur scale")) {

            mAbsoluteValue = -218.52;

        }


};

QT_END_NAMESPACE_CONVERSION

//Q_PLUGIN_METADATA(IID IConversionInterface_iid)

#endif // REAUMUR_H
