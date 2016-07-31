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


#ifndef CONVERSION_H
#define CONVERSION_H

#include <QMap>
#include <QDir>
#include <QtPlugin>
#include <QPluginLoader>
#include <QStringList>
//#include <QStringListModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>

#include <map>
#include <utility>
#include <exception>

#include "conversion_global.h"
#include "abstracttemperatureconversion.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
    \class Conversion

    \brief A simple unit conversion utility.

    Allows conversion between various units, returning a double value. Actual
    conversion is attained by using one of the convert() methods and supplying
    both input and output unit types and a double value.

    Internally all values are defined in term of multiples of the Yoctometre (1E-24m).

    \author Simon Meaden
    \date   16 July 2016
*/
class CONVERSIONSHARED_EXPORT Converter : public QObject {

    public:
        Converter( QObject *parent );


        /*!
            \fn Conversion::convert()

            \brief Converts two length units.

            Converts a supplied \a double \a value from the \a ConversionFactorLength input type to the
            \a ConversionFactorLength output type.
        */

        mpf_class convert( QString from, QString to, double value );
        QString toString( QString from, QString to, double value , bool showSymbol = false );

        QStringList names( QStringList categories=QStringList() );
        QStringList categories();
        shared_conversion_t plugin(QString name);


    protected:
        QMap<QString, shared_conversion_t> mPlugins;
        QStringList mCategories;
        //        QMap<IConversionInterface::Type, QString> mTypeNames;

        void loadPlugin();
};
typedef QSharedPointer<Converter> shared_converter_t;


class ConverterModel : public QStandardItemModel {
    public:
        ConverterModel( shared_converter_t& converter, QObject *parent = Q_NULLPTR );

        void setFilter( QStringList categories = QStringList() );

    protected:
        shared_converter_t pConverter;

};

struct WrongTypeException : public std::exception {
    WrongTypeException( /*Converter *converter,*/ /*IConversionInterface::Type from*/QString from, /*IConversionInterface::Type to*/QString to ) {
        QString s = QString( "Both converters must have the same type. %1 => %2" ).
                    arg( /*converter->typeName( from )*/from ).
                    arg( /*converter->typeName( to )*/to );
        sprintf( msg, "%s", ( const char * )s.toStdString().c_str()  );
    }

    const char *what () const throw () {
        return msg;
    }

    char msg[200];
};

struct BelowAbsoluteException : public std::exception {
    BelowAbsoluteException( QString converter, QString symbol, double temp, double absolute ) {
        QString s = QString( "Attempt to calculate temperature below Absolute (%1%3 > %2%3) Type : %4." ).
                    arg( absolute ).
                    arg( temp ).
                    arg( symbol ).
                    arg( converter );
        sprintf( msg, "%s", ( const char * )s.toStdString().c_str()  );
    }

    const char *what () const throw () {
        return msg;
    }

    char msg[200];
};


QT_END_NAMESPACE_CONVERSION

Q_DECLARE_METATYPE( Conversion::shared_converter_t )

#endif // CONVERSION_H
