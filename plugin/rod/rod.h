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

#ifndef ROD_H
#define ROD_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Rod
 *
 * \brief defines a length in rods.
 *
 * Rods, sometimes called perches or poles,equal to 5½ yards,
 * 16½ feet, /sup {1}///sub {320} of a statute mile defines a length
 * in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Rod : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Rod( ) :
            AbstractLengthConversion( QStringLiteral("50292E23"),
                                      QStringLiteral("Rod"),
                                      QStringLiteral("rod"),
                                      tr("Rods, Poles or Perches 5½ yards or <sup>1</sup>/<sub>320</sub> mile")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // ROD_H
