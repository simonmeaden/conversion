/*!
    \file abstractconversion.cpp

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
#include "abstractconversion.h"

#include <stringutil.h>


#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

AbstractConversion::AbstractConversion( const QString &name, const QString &symbol, const QString &category, const QString &tooltip ) :
    mCategory( category ),
    mName( name ),
    mSymbol( symbol ),
    mTooltip( tooltip ) {

}

const QString AbstractConversion::category() const {
    return mCategory;
}

const QString AbstractConversion::name() const {
    return mName;
}

const QString AbstractConversion::symbol() const {
    return mSymbol;
}

QStringList AbstractConversion::importer() const {
    QStringList values;

    values << mName;

    return values;
}

QString AbstractConversion::tooltip() const {
    return mTooltip;
}

QT_END_NAMESPACE_CONVERSION
