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

#ifndef NAUTICAL_MILE_H
#define NAUTICAL_MILE_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class NauticalMile
 *
 * \brief defines a length in nautical miles.
 *
 * Nautical Miles (defined as 1852 meters (approximately 6,080 feet or 1.2 statute miles))
 * defines a length in  the \a Conversion utility. Historically, it was defined as one
 * 60th of the distance between two lines of latitude. Today it is an SI derived unit,
 * being rounded to an even number of meters and remains in use for both air and marine
 * navigation[3] and for the definition of territorial waters.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT NauticalMile : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        NauticalMile( ) :
            AbstractLengthConversion( QStringLiteral("1852E24"),
                                      QStringLiteral("Nautical Mile"),
                                      QStringLiteral("knot"),
                                      tr("1852 metres")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // NAUTICAL_MILE_H
