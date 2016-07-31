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

#ifndef ABSTRACTAREACONVERSION_H
#define ABSTRACTAREACONVERSION_H

#include <QObject>

#include "conversion_global.h"
#include "abstractconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

class AbstractAreaConversion : public AbstractConversion {

    public:
        AbstractAreaConversion( const QString baseX,
                                const QString baseY,
                                const QString name,
                                const QString symbol,
                                const QString& tooltip = QString() );

        virtual mpf_class convert( const shared_conversion_t& from, const qreal& value ) const;
        virtual QString toString( const shared_conversion_t& from, const qreal& value, const bool& showSymbol = false )const;

    protected:
        mpz_class mBaseX, mBaseY;

        mpz_class baseX();
        mpz_class baseY();
        mpz_class initDimension( mpz_t& initValue, QString base );
};

QT_END_NAMESPACE_CONVERSION

#endif // ABSTRACTAREACONVERSION_H
