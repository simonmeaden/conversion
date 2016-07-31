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

#ifndef FATHOM_H
#define FATHOM_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Fathom
 *
 * \brief defines a length in fathoms.
 *
 * Fathoms (or 6 feet) defines a length in  the \a Conversion utility.
 *
 * \author Simon Meaden
 * \date   20 July 2016
 */

class CONVERSIONSHARED_EXPORT Fathom : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Fathom( ) :
            AbstractLengthConversion( QStringLiteral("18288E23"),
                                      QStringLiteral("Fathom"),
                                      QStringLiteral("ftm"),
                                      tr("Fathoms = 6 feet")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // FATHOM_H
