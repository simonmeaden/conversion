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
#include "abstracttemperatureconversion.h"

#include <string>

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class AbstractTemperatureConversion

    \brief Base class for length conversions

    This handles most of the actual conversion but individual sub classes in
    plugin projects must supply names, symbols, the type (\a "Temperature") and
    ranges for the plugin.

    Sub-classes of this class should never need to be used directly as it
    is designed to be used as a plugin type to a Converter object.


    \author Simon Meaden
    \date   16 July 2016
*/

/*!
    \fn AbstractTemperatureConversion::AbstractTemperatureConversion

    \brief Constructor for AbstractTemperatureConversion.

*/

AbstractTemperatureConversion::AbstractTemperatureConversion(
        const QString &name,
        const QString &symbol,
        const QString &tooltip ) :
    AbstractConversion( name, symbol, "Temperature", tooltip ) {

}

/*!
    \fn AbstractTemperatureConversion::convert

    \brief Get the converted value.

    The returned value will be a GMP \a mpf_class object.
    If preferred use the AbstractTemperatureConversion::toString(shared_conversion_t qreal)
    method which will return a QString object with obtional symbol.

    \sa AbstractTemperatureConversion::toString
*/

mpf_class AbstractTemperatureConversion::convert(const shared_conversion_t &from, const qreal &value ) const {
    QString fromName = from->name();

    if ( fromName == "Celsius" ) {
        return fromCelsius( value );
    } else if ( fromName == "Fahrenheit" ) {
        return fromFahrenheit( value );
    } else if ( fromName == "Kelvin" ) {
        return fromKelvin( value );
    } else if ( fromName == "Rankine" ) {
        return fromRankine( value );
    } else if ( fromName == "Delisle" ) {
        return fromDelisle( value );
    } else if ( fromName == "Rømer" ) {
        return fromRomer( value );
    } else if ( fromName == "Réaumur" ) {
        return fromReaumur( value );
    } else { /*if ( fromName == "Newton" )*/
        return fromNewton( value );
    }
}

/*!

    \fn AbstractTemperatureConversion::toString

    \brief Get the converted value.

    The returned value will depend on the two conversion types. This method
    returns a QString object containing the result in scientific notation
    with an optional to \a to type symbol. If an actual value is required
    use the AbstractTemperatureConversion::convert(shared_conversion_t, qreal, bool)
    method which will return the converted value as a GMP \a mpf_class object.

    \see AbstractTemperatureConversion::convert
*/
QString AbstractTemperatureConversion::toString(const shared_conversion_t &from, const qreal &value, const bool &showSymbol ) const {
    mpf_class f = convert( from, value );
    mp_exp_t exp;
    std::string s = f.get_str( exp );
    int e = exp - s.length();

    QString rslt;

    if ( showSymbol ) {
        rslt = QString( "%1E%2%3" ).arg( s.c_str() ).arg( e ).arg( mSymbol );
    } else {
        rslt = QString( "%1E%2%3" ).arg( s.c_str() ).arg( e ).arg( mSymbol );
    }

    return rslt;
}

/*!
    \fn AbstractTemperatureConversion::absolute

    \brief Returns the value of absolute zero for the sub-class.

    [detailed description including parameter and return types]

    \sa [see also section]
    \note [any note about the function you might have]
    \warning [any warning if necessary]
*/

double AbstractTemperatureConversion::absolute() {
    return mAbsoluteValue;
}


//        Celsius 	[°C] = [K] − 273.15
//        Fahrenheit 	[°F] = [K] × 9⁄5 − 459.67
//        Rankine 	[°R] = [K] × 9⁄5
//        Delisle 	[°De] = (373.15 − [K]) × 3⁄2
//        Newton 	[°N] = ([K] − 273.15) × 33⁄100
//        Réaumur 	[°Ré] = ([K] − 273.15) × 4⁄5
//        Rømer 	[°Rø] = ([K] − 273.15) × 21⁄40 + 7.5
mpf_class AbstractTemperatureConversion::fromKelvin(const qreal &value ) const {
    QString name = mName;
    mpf_class k = value;

    if ( name == "Celsius" ) {
        k = k - 273.15;
    } else if ( name == "Fahrenheit" ) {
        k = ( k * 9 / 5 ) - 459.67;
    }/* else if ( name == "Kelvin" ) {

                return value;
            }*/ else if ( name == "Rankine" ) {
        k = k * 9 / 5;
    } else if ( name == "Delisle" ) {
        k = ( 373.15 - k ) * 3 / 2;
    } else if ( name == "Rømer" ) {
        k = ( ( k - 273.15 ) * 21 / 40 ) + 7.5;
    } else if ( name == "Réaumur" ) {
        k = ( k - 273.15 ) * 4 / 5;
    } else if ( name == "Newton" ) {
        k = ( k - 273.15 ) * 33 / 100;
    }

    return k;
}

//        Fahrenheit 	[°F] = [°C] × 9⁄5 + 32
//        Kelvin 	[K] = [°C] + 273.15
//        Rankine 	[°R] = ([°C] + 273.15) × 9⁄5
//        Delisle 	[°De] = (100 − [°C]) × 3⁄2
//        "Newton" 	[°N] = [°C] × 33⁄100
//        Réaumur 	[°Ré] = [°C] × 4⁄5
//        Rømer 	[°Rø] = [°C] × 21⁄40 + 7.5
mpf_class AbstractTemperatureConversion::fromCelsius( const qreal &value ) const {
    QString name = mName;
    mpf_class c = value;

    if ( name == "Celsius" ) {
    } else if ( name == "Fahrenheit" ) {
        c = ( c * 9 / 5 ) + 32;
    } else if ( name == "Kelvin" ) {
        c = c + 273.15;
    } else if ( name == "Rankine" ) {
        c = ( c + 273.15 ) * 9 / 5;
    } else if ( name == "Delisle" ) {
        c = ( 100 - c ) * 3 / 2;
    } else if ( name == "Rømer" ) {
        c = ( c * 21 / 40 ) + 7.5;
    } else if ( name == "Réaumur" ) {
        c = ( c * 4 / 5 );
    } else if ( name == "Newton" ) {
        c = c * 33 / 100;
    }

    return c;
}

//        Celsius 	[°C] = ([°R] − 491.67) × 5⁄9
//        Fahrenheit 	[°F] = [°R] − 459.67
//        Kelvin 	[K] = [°R] × 5⁄9
//        Delisle 	[°De] = (671.67 − [°R]) × 5⁄6
//        Newton 	[°N] = ([°R] − 491.67) × 11⁄60
//        Réaumur 	[°Ré] = ([°R] − 491.67) × 4⁄9
//        Rømer 	[°Rø] = ([°R] − 491.67) × 7⁄24 + 7.5
mpf_class AbstractTemperatureConversion::fromRankine(const qreal &value ) const {
    QString name = mName;
    mpf_class r = value;

    if ( name == "Celsius" ) {
        r = ( r - 491.67 ) * 5 / 9;
    } else if ( name == "Fahrenheit" ) {
        r = ( r - 459.67 );
    } else if ( name == "Kelvin" ) {
        r = r * 5 / 9;
    }/* else if ( name == "Rankine" ) {

                return r;
            }*/ else if ( name == "Delisle" ) {
        r = ( 671.67 - r ) * 5 / 6;
    } else if ( name == "Rømer" ) {
        r = ( ( r - 491.67 ) * 7 / 24 ) + 7.5;
    } else if ( name == "Réaumur" ) {
        r = ( r - 491.67 ) * 4 / 9;
    } else if ( name == "Newton" ) {
        r = ( r - 491.67 ) * 11 / 60;
    }

    return r;
}

//        Celsius 	[°C] = ([°F] − 32) × 5⁄9
//        Kelvin 	[K] = ([°F] + 459.67) × 5⁄9
//        Rankine 	[°R] = [°F] + 459.67
//        Delisle 	[°De] = (212 − [°F]) × 5⁄6
//        Newton 	[°N] = ([°F] − 32) × 11⁄60
//        Réaumur 	[°Ré] = ([°F] − 32) × 4⁄9
//        Rømer 	[°Rø] = ([°F] − 32) × 7⁄24 + 7.5
mpf_class AbstractTemperatureConversion::fromFahrenheit(const qreal &value ) const {
    QString name = mName;
    mpf_class f = value;

    if ( name == "Celsius" ) {
        f = ( f - 32 ) * 5 / 9;
    }/* else if ( name == "Fahrenheit" ) {

                return f;
            }*/ else if ( name == "Kelvin" ) {
        f = ( f + 459.67 ) * 5 / 9;
    } else if ( name == "Rankine" ) {
        f = ( f + 459.67 );
    } else if ( name == "Delisle" ) {
        f = ( 212 - f ) * 5 / 6;
    } else if ( name == "Rømer" ) {
        f = ( ( f - 32 ) * 7 / 24 ) + 7.5;
    } else if ( name == "Réaumur" ) {
        f = ( f - 32 ) * 4 / 9;
    } else if ( name == "Newton" ) {
        f = ( f - 32 ) * 11 / 60;
    }

    return f;
}

//        "Celsius" 	[°C] = 100 − [°De] × 2⁄3
//        Fahrenheit 	[°F] = 212 − [°De] × 6⁄5
//        Kelvin 	[K] = 373.15 − [°De] × 2⁄3
//        Rankine 	[°R] = 671.67 − [°De] × 6⁄5
//        Newton 	[°N] = 33 − [°De] × 11⁄50
//        Réaumur 	[°Ré] = 80 − [°De] × 8⁄15
//        Rømer 	[°Rø] = 60 − [°De] × 7⁄20
mpf_class AbstractTemperatureConversion::fromDelisle(const qreal &value ) const {
    QString name = mName;
    mpf_class d = value;

    if ( name == "Celsius" ) {
        d =  100 - ( d  * 2 / 3 );
    } else if ( name == "Fahrenheit" ) {
        d = 212 - ( d  * 6 / 5 );
    } else if ( name == "Kelvin" ) {
        d = 373.15 - ( d  * 2 / 3 );
    } else if ( name == "Rankine" ) {
        d = 671.67 - ( d  * 6 / 5 );
    }/* else if ( name == "Delisle" ) {

               return d;
            }*/ else if ( name == "Rømer" ) {
        d = 60 - ( d  * 7 / 20 );
    } else if ( name == "Réaumur" ) {
        d = 80 - ( d  * 8 / 15 );
    } else if ( name == "Newton" ) {
        d = 33 - ( d  * 11 / 50 );
    }

    return d;
}

//        "Celsius" 	[°C] = ([°Rø] − 7.5) × 40⁄21
//        Fahrenheit 	[°F] = ([°Rø] − 7.5) × 24⁄7 + 32
//        "Kelvin" 	[K] = ([°Rø] − 7.5) × 40⁄21 + 273.15
//        Rankine 	[°R] = ([°Rø] − 7.5) × 24⁄7 + 491.67
//        Delisle 	[°De] = (60 − [°Rø]) × 20⁄7
//        Newton 	[°N] = ([°Rø] − 7.5) × 22⁄35
//        Réaumur 	[°Ré] = ([°Rø] − 7.5) × 32⁄21
mpf_class AbstractTemperatureConversion::fromRomer(const qreal &value ) const {
    QString name = mName;
    mpf_class r = value;

    if ( name == "Celsius" ) {
        r = ( r - 7.5 ) * 40 / 21;
    } else if ( name == "Fahrenheit" ) {
        r = ( ( r - 7.5 ) * 24 / 7 ) + 32;
    } else if ( name == "Kelvin" ) {
        r = ( ( r - 7.5 ) * 40 / 21 ) + 273.15;
    } else if ( name == "Rankine" ) {
        r = ( ( r - 7.5 ) * 24 / 7 ) + 491.67;
    } else if ( name == "Delisle" ) {
        r = ( 60 - r ) * 20 / 7;
    }/* else if ( name == "Rømer" ) {

                return r;
            }*/ else if ( name == "Réaumur" ) {
        r = ( r - 7.5 ) * 32 / 21;
    } else if ( name == "Newton" ) {
        r = ( r - 7.5 ) * 22 / 35;
    }

    return r;
}

//        Celsius 	[°C] = [°Ré] × 5⁄4
//        Fahrenheit 	[°F] = [°Ré] × 9⁄4 + 32
//        Kelvin 	[K] = [°Ré] × 5⁄4 + 273.15
//        Rankine 	[°R] = [°Ré] × 9⁄4 + 491.67
//        Delisle 	[°De] = (80 − [°Ré]) × 15⁄8
//        Newton 	[°N] = [°Ré] × 33⁄80
//        Rømer 	[°Rø] = [°Ré] × 21⁄32 + 7.5
mpf_class AbstractTemperatureConversion::fromReaumur(const qreal &value ) const {
    QString name = mName;
    mpf_class r = value;

    if ( name == "Celsius" ) {
        r =  r * 5 / 4;
    } else if ( name == "Fahrenheit" ) {
        r = ( r * 5 / 4 ) + 32;
    } else if ( name == "Kelvin" ) {
        r = ( r * 5 / 4 ) + 273.15;
    } else if ( name == "Rankine" ) {
        r = ( r * 9 / 4 ) + 491.67;
    } else if ( name == "Delisle" ) {
        r = ( 80 - r ) * 15 / 8;
    } else if ( name == "Rømer" ) {
        r = ( r * 21 / 32 ) + 7.5;
    }/* else if ( name == "Réaumur" ) {

                return r;
            }*/ else if ( name == "Newton" ) {
        r = r * 33 / 80;
    }

    return r;
}

//        Celsius 	[°C] = [°N] × 100⁄33
//        Fahrenheit 	[°F] = [°N] × 60⁄11 + 32
//        Kelvin 	[K] = [°N] × 100⁄33 + 273.15
//        Rankine 	[°R] = [°N] × 60⁄11 + 491.67
//        Delisle 	[°De] = (33 − [°N]) × 50⁄11
//        Réaumur 	[°Ré] = [°N] × 80⁄33
//        Rømer 	[°Rø] = [°N] × 35⁄22 + 7.5
mpf_class AbstractTemperatureConversion::fromNewton(const qreal &value ) const {
    QString name = mName;
    mpf_class n = value;

    if ( name == "Celsius" ) {
        n = n * 100 / 33;
    } else if ( name == "Fahrenheit" ) {
        n = ( n * 60 / 11 ) + 32;
    } else if ( name == "Kelvin" ) {
        n = ( n * 100 / 33 ) + 273.15;
    } else if ( name == "Rankine" ) {
        n = ( n * 60 / 11 ) + 491.67;
    } else if ( name == "Delisle" ) {
        n = ( 33 - n ) * 50 / 11;
    } else if ( name == "Rømer" ) {
        n = ( n * 35 / 22 ) + 7.5;
    } else if ( name == "Réaumur" ) {
        n = n * 80 / 33;
    }/* else if ( name == "Newton" ) {

                return n;
            }*/
    return n;
}


QT_END_NAMESPACE_CONVERSION
