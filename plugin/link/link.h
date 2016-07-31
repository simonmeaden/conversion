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

#ifndef LINK_H
#define LINK_H

#include "conversion_global.h"
#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class Link

    \brief defines a length in links.

    Link (A link is exactly /sup {66} / /sub {100} of a foot,[1] or exactly 7.92 inches)
    defines a length in  the \a Conversion utility.

    \list
    \li Twenty-five links make a rod, pole or perch (16.5 feet).
    \li One hundred links make a chain.
    \li One thousand links make a furlong.
    \li Eight thousand links make a mile.
    \endlist

    \author Simon Meaden
    \date   20 July 2016
*/

class CONVERSIONSHARED_EXPORT Link : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Link( ) :
            AbstractLengthConversion( QStringLiteral("201168E21"),
                                      QStringLiteral("Link"),
                                      QStringLiteral("lk"),
                                      tr("Link = 7.92 inches o <sup>66</sup>/<sub>100</sub> foot")) {
        }

};

QT_END_NAMESPACE_CONVERSION

#endif // LINK_H
