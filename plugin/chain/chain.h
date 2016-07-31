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

#ifndef CHAIN_H
#define CHAIN_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Chain
 *
 * \brief defines a length in chains.
 *
 * Chains (or 66 feet, or 22 yards, or 100 links, or 4 rods) defines a length in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Chain : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Chain( ) :
            AbstractLengthConversion( QStringLiteral("201168E23"),
                                      QStringLiteral("Chain"),
                                      QStringLiteral("ch"),
                                      tr("1 Chain = 22 yards")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // CHAIN_H
