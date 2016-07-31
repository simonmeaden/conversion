/*!
    \file abstracttemperatureconversion.h

    \author Simon Meaden
    \date   20 July 2016
    \copyright Copyright (c) 2016-2016, Simon Meaden
    \legalese This code is licensed under the GPL Version 3.0

    Normal GPL stuff. You have permission to use, copy, modify,
    distribute  etc. to the limit of the license. There is no
    warranty whatever, however, if your ship sinks or an earthquake
    wipes out your car after using this you are on your own.

    \endlegalese

    Part of the conversion utility.
*/
#ifndef ABSTRACTTEMPERATURECONVERSION_H
#define ABSTRACTTEMPERATURECONVERSION_H

#include <QObject>

#include "conversion_global.h"
#include "abstractconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class AbstractTemperatureConversion

    \brief Base class for temperature conversions

    This handles most of the actual conversion but individual sub classes in
    plugin projects must supply names, symbols, the type (\a Temperature) and
    ranges for the plugin.

    \author Simon Meaden
    \date   16 July 2016
*/
class AbstractTemperatureConversion : public AbstractConversion {
    public:
        AbstractTemperatureConversion(
                const QString &name,
                const QString &symbol,
                const QString &tooltip = QString() );

        virtual mpf_class convert( const shared_conversion_t &from, const qreal &value ) const;
        virtual QString toString( const shared_conversion_t &from, const qreal &value, const bool &showSymbol = false ) const;

        double absolute();

    protected:
        double mAbsoluteValue;

        mpf_class fromKelvin( const qreal &value ) const;
        mpf_class fromCelsius(const qreal &value ) const;
        mpf_class fromRankine( const qreal &value ) const;
        mpf_class fromFahrenheit( const qreal &value ) const;
        mpf_class fromDelisle( const qreal &value ) const;
        mpf_class fromRomer( const qreal &value ) const;
        mpf_class fromReaumur( const qreal &value ) const;
        mpf_class fromNewton( const qreal &value ) const;


};
typedef QSharedPointer<AbstractTemperatureConversion> shared_temperature_conversion_t;

QT_END_NAMESPACE_CONVERSION

#endif // ABSTRACTTEMPERATURECONVERSION_H
