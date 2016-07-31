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

#include "abstractlengthconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class AbstractLengthConversion

    \brief Base class for length conversions.

    [detailed description]

    \author Simon Meaden
    \date   date
*/

/*!
    \fn AbstractLengthConversion::AbstractLengthConversion()

    \brief Base abstract class for length conversions
*/

AbstractLengthConversion::AbstractLengthConversion(
        const QString& baseValue,
        const QString& name,
        const QString& symbol ,
        const QString& tooltip ) :
    AbstractConversion( name, symbol, "Length", tooltip ) {

    mpf_set_default_prec( 500 );

    // initialise gmp integer value
    mpz_t initValue;
    mpz_init( initValue );

    // check for scientific notation
    if ( baseValue.contains( "E", Qt::CaseInsensitive ) ) {
        // split into mantissa and exponent
        QStringList splits = baseValue.split( 'E', QString::KeepEmptyParts, Qt::CaseInsensitive );

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
            throw BadInitialisationException( name, baseValue );
        }
    } else {

        // parse gmp integer string as base 10
        int success = mpz_set_str( initValue, baseValue.toStdString().c_str(), 10 );

        if ( success != 0 ) {
            throw BadInitialisationException( name, baseValue );
        }
    }

    // intialise gmp cpp integer class from integer value
    mBaseValue = mpz_class( initValue );

    mpz_clear( initValue );

}


mpf_class AbstractLengthConversion::convert( const shared_conversion_t& from, const qreal& value ) const {

    // get from base as mpf_class
    mpz_class fromBase = dynamic_cast<AbstractLengthConversion *>( from.data() )->base();
    mpf_class result( fromBase, 500 );
    mpf_class divisor( mBaseValue, 500 );
    result = result / divisor;
    result = result * value;

    return result;
}

QString AbstractLengthConversion::toString( const shared_conversion_t& from, const qreal& value, const bool& showSymbol ) const {

    mpf_class f = convert( from, value );
    mp_exp_t exp;
    std::string s = f.get_str( exp );
    int e = exp - s.length();

    QString rslt;

    if ( showSymbol ) {
        rslt = QString( "%1E%2%3" ).arg( s.c_str() ).arg( e ).arg( mSymbol );
    } else {
        rslt = QString( "%1E%2" ).arg( s.c_str() ).arg( e );
    }

    return rslt;

}

mpz_class AbstractLengthConversion::base() {
    return mBaseValue;
}

QT_END_NAMESPACE_CONVERSION
