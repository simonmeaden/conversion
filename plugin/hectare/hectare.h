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


#ifndef HECTARE_H
#define HECTARE_H

#include "conversion_global.h"
#include "abstractareaconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Hectare
 *
 * \brief defines a length in hectares.
 *
 * Hectares (10,000 square metres) defines an area in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Hecatre :
        public QObject,
        public AbstractAreaConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Hecatre( ) :
            AbstractAreaConversion( QStringLiteral("1000E24"), QStringLiteral("1000E24"),
                                    QStringLiteral("Hectare"), QStringLiteral("ha"),
                                    tr("1 Hectare, 100 metres x 1000metres")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // ATTOMETER_H
