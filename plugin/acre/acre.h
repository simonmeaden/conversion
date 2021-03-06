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

#ifndef ACRE_H
#define ACRE_H

#include "conversion_global.h"
#include "abstractareaconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Acre
 *
 * \brief defines a length in acres.
 *
 * Acres (1 furlong x 1 chain) defines an area in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Acre :
        public QObject,
        public AbstractAreaConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Acre( ) :
            AbstractAreaConversion( QStringLiteral("201168E24"),
                                    QStringLiteral("201168E23"),
                                    QStringLiteral("Acre"), QStringLiteral("ac"),
                                    tr("Acre, 1 furlong by 1 chain, ⅛ mile x 22 yards") ) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // ACRE_H
