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


#ifndef CONVERSIONINTERFACE_H
#define CONVERSIONINTERFACE_H

#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QDebug>

#include <iostream>
#include <sstream>
#include <exception>

#include <gmpxx.h>

#include "conversion_global.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

class IConversionInterface;
typedef QSharedPointer<IConversionInterface> shared_conversion_t;

class IConversionInterface {
    public:

        virtual ~IConversionInterface() {}
        virtual mpf_class convert( const shared_conversion_t& from, const qreal& value ) const = 0;
        virtual QString toString( const shared_conversion_t& from, const qreal& value, const bool& showSymbol = false ) const = 0;
        virtual const QString name() const = 0;
        virtual const QString symbol() const = 0;
        virtual const QString category() const = 0;
        virtual QString tooltip() const = 0;

    protected:
};

struct BadInitialisationException : public std::exception {
    BadInitialisationException( QString name, QString value ) {
        QString s = QString( "Unable to initialise %1 from string value %2." ).
                    arg( name ).
                    arg( value );
        sprintf( msg, "%s", ( const char * )s.toStdString().c_str()  );
    }

    const char *what () const throw () {
        return msg;
    }

    char msg[200];
};


QT_END_NAMESPACE_CONVERSION

/*
    This shit needs to be done OUTSIDE of the namespace.
*/
#define IConversionInterface_iid "uk.co.smelecomp.ConversionInterface"

Q_DECLARE_INTERFACE( Conversion::IConversionInterface, IConversionInterface_iid )
Q_DECLARE_METATYPE( Conversion::shared_conversion_t )

#endif // CONVERSIONINTERFACE_H
