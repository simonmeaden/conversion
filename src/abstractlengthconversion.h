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

#ifndef ABSTRACTLENGTHCONVERSION_H
#define ABSTRACTLENGTHCONVERSION_H

#include <QObject>

#include "conversion_global.h"
#include "abstractconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class AbstractLengthConversion

    \brief Base class for length conversions

    This handles most of the actual conversion but individual sub classes in
    plugin projects must supply a conversion value (length in attometres),
    names and a symbol and optionally a tooltip.

    \author Simon Meaden
    \date   16 July 2016
*/
class AbstractLengthConversion : public AbstractConversion {

    public:

        AbstractLengthConversion( const QString& baseValue,
                                  const QString& name,
                                  const QString& symbol,
                                  const QString& tooltip = QString() );

        virtual mpf_class convert( const shared_conversion_t& from, const qreal& value ) const;
        virtual QString toString( const shared_conversion_t& from, const qreal& value, const bool& showSymbol = false )const;

    protected:
        mpz_class mBaseValue;

        mpz_class base();

};

QT_END_NAMESPACE_CONVERSION

#endif // ABSTRACTLENGTHCONVERSION_H
