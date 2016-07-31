/**
 ** This file is part of the ConversionUtility project.
 ** Copyright 2016 Simon Meaden <simonmeaden@smelecomp.co.uk>.
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


#ifndef FURLONG_H
#define FURLONG_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Furlong
 *
 * \brief defines a length in furlongs.
 *
 * Furlongs (or /sup {1} / /sub {8} mile, 10 chains, 220 yards) defines a length in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Furlong : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Furlong( ) :
            AbstractLengthConversion( QStringLiteral("201168E24"),
                                      QStringLiteral("Furlong"),
                                      QStringLiteral("fur"),
                                      tr("1 Furlong = 220 yards = 1/10 mile")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // FURLONG_H
