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

#include "abstractareaconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class AbstractAreaConversion

    \brief Base class for area conversions

    This handles most of the actual conversion but individual sub classes in
    plugin projects must supply two conversion values (lengths in attometres),
    one for each dimension, x and y, of the area, a name and a symbol and
    optionally a tooltip.

    \author Simon Meaden
    \date   16 July 2016
*/

/*!
    \fn AbstractAreaConversion::AbstractAreaConversion

    \brief [brief description]

    [detailed description including parameter and return types]

    \sa [see also section]
    \note [any note about the function you might have]
    \warning [any warning if necessary]
*/

AbstractAreaConversion::AbstractAreaConversion(
    const QString baseX,
    const QString baseY,
    const QString name,
    const QString symbol,
    const QString& tooltip ) : AbstractConversion( name, symbol, "Area", tooltip ) {

    mpf_set_default_prec( 500 );

    // intialise gmp cpp integer class from integer value
    mpz_t initValue;
    mpz_init( initValue );

    mBaseX = initDimension( initValue, baseX );
    mBaseY = initDimension( initValue, baseY );

    mpz_clear( initValue );

}

mpz_class AbstractAreaConversion::initDimension( mpz_t& initValue, QString base ) {

    // check for scientific notation
    if ( baseX.contains( "E", Qt::CaseInsensitive ) ) {
        // split into mantissa and exponent
        QStringList splits = base.split( 'E', QString::KeepEmptyParts, Qt::CaseInsensitive );

        mpz_class val( 10 );
        QString s;
        bool ok;

        s = splits.at( 1 );
        unsigned long l = s.toULong( &ok ) ;

        if ( ok ) {
            // do 10^exponent
            mpz_pow_ui( initValue, val.get_mpz_t(), l );

            s = splits.at( 0 );

            // if mantissa != 1 then multiply value by mantissa.
            if ( s.toLongLong( &ok ) != 1 ) {
                val = s.toStdString().c_str();
                mpz_mul( initValue, initValue, val.get_mpz_t() );
            }

        } else {
            throw BadInitialisationException( name, base );
        }

    } else {

        // parse gmp integer string as base 10
        int success = mpz_set_str( initValue, base.toStdString().c_str(), 10 );

        if ( success != 0 ) {
            throw BadInitialisationException( name, base );
        }
    }

    return initValue;
}

mpf_class AbstractAreaConversion::convert( const shared_conversion_t& from, const qreal& value ) const {
    mpf_class f;
    return f;
}

QString AbstractAreaConversion::toString( const shared_conversion_t& from, const qreal& value, const bool& showSymbol = false ) const {
    QString result;
    return result;
}

QT_END_NAMESPACE_CONVERSION
