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

#ifndef MIL_H
#define MIL_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class Conversion::Mil

    \brief defines a length in thousandths of an inch.

    Mil (0.001 inches or 0.0000254 metres) defines a length in  the \a Conversion utility.
    Sometimes also called Thou.

    \author Simon Meaden
    \date   20 July 2016
    \see Conversion::Thou
*/

class CONVERSIONSHARED_EXPORT Mil : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Mil( ) :
            AbstractLengthConversion( QStringLiteral("254E19"),
                                      QStringLiteral("Mil"),
                                      QStringLiteral("mil"),
                                      tr("Thousandths of an inch (also called thou)") ) {
        }

};


QT_END_NAMESPACE_CONVERSION

#endif // MIL_H
