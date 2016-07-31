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

#include "converter.h"

#include <gmp.h>
#include <gmpxx.h>

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

using namespace std;

/*!
    \page howto.html howto
    \title How to do stuff with Converter.

    \brief Simple how to for the converter module.

    First why I created the module.

    I wanted to play around with plugins for an application and this seemed like a useful
    start. It is not an exhaustive set of converter plugins as I never actually intended
    to use it in a conversion utility. I also do not claim that this is the only way
    of achieving this task, nor is it definitly the best way. There are undoubtedly
    better ways. Hoewever it DOES work.

    All plugins are created as individual libraries. There are supposed to be ways
    to wrap multiple plugins in one library but I couldn't get it to work and I ran out
    of time so this uses the one plugin to a library method.

    The build method I use creates a build directory at the same level as the ConversionUtility
    subdirectory. I inherited this method from a company that I used to work for and it
    works for me. Feel free to reorganise it as you want, but I warn you it will be a pain,
    because EVERY *.pro file will need to be altered.

    All length/area/volume are based on lengths in Attometres (1<sup>-24</sup> metres)
    which is a VERY small length. For this reason (plus the fact I wanted to play around
    with the \link {"https://gmplib.org"} {The GMP multiple precision library}) all results
    are either \link QString objects or GMP \link {https://gmplib.org/manual/C_002b_002b-Interface-Floats.html#C_002b_002b-Interface-Floats}
    {mpf_class} objects.

    NOTE It uses Attometre INTEGER values not floating point.

    I did say I was playing around didn't I.

    To do a conversion create a converter.

    \code

    CONVERSION_USE_NAMESPACE // Macro for 'using namespace Conversion;'

    Conversion::shared_converter_t pConverter;
    pConverter = shared_converter_t( new Converter(this) );

    \endcode

    This is equivalent to  \code pConverter = QSHaredPointer<Converter>( new Converter( this ) ); \endcode

    The types are defined as \link QString objects and a conversion is done in one of two
    ways.

    \code
    QString result, fromType = "Metre", toType = "Mile";
    bool withSymbol = true;

    result = pConverter->toString( fromType, toType, value, withSymbol );
    \endcode

    or

    \code
    #include <gmpxx.h> // GMP C++ class wrapper.

    ...

    QString result, fromType = "Metre", toType = "Mile";
    mpf_class result;

    result = pConverter->convert( fromType, toType, value );
    \endcode

    The result will be in miles.

    It is also possible to use the conversion classes directly if you only want to use
    one or two of them.

    \code
    #include <gmpxx.h> // GMP C++ class wrapper.

    ...

    IConversionInterface *miles = new Mile();
    IConversionInterface *metres = new Metre();

    mpf_class result = miles->convert( metres, 19357.265 );

    \endcode

    but you will need to include various files into your project, namely
    /list
    /l conversioninterface.h
    /l abstractconversion.h abstractconversion.cpp
    /list
      /l At least some of
      /l abstractlengthconversion.h abstractlengthconversion.cpp
      /l abstracttemperatureconversion.h abstracttemperatureconversion.cpp
      /l abstractareaconversion.h abstractareaconversion.cpp
      /l abstractvolumeconversion.h abstractvolumeconversion.cpp
    /endlist
    /l mile.h metre.h plus any others you use.
    /endlist

    It should be noted that the conversion plugins will throw cpp exceptions
    if there are problems. I know Qt doesn't use them but - I did say playing around.

    There are three possible exceptions thrown which you will need to catch.

    \list
    \l BadInitialisationException - This is only thrown if the supplied initialisation value,
        which is supplied as a QString is not valid, so should only ever happen when you are
        subclassing for a new type of converter. It should have been weeded out in existing
        classes. It is thrown by AbstractLengthConversion, AbstractAreaConversion and
        AbstractVolumeConversion so far. It is caused by the conversion values not being in
        correct form either as an integer ("195632") or scientific notation integer ("1.7E-24").
    \l WrongTypeException - This is thrown if you supply incompatible types. For example if you
        try to convert degrees celsius to metres. Obviously this is not a valid conversion.
    \l BelowAbsoluteException - This is thrown by temperature conversions if you try to
        convert a temperature below absolute zero. This doesn't make sense.
    \endlist

    I might add others later if I write other types.

    The \link Conversion::Converter class has some useful methods.

    \list
    \l names() which returns a QStringList containing the names of all the plugins
        that were successfully loaded.
    \l categories() which returns a QStringList containing all of the categories.
        currently "Length", "Area", "Volume" and "Temperature"
    \l plugin(QString) which returns a particular plugin if you need it.
    \endlist

    A Conversion::ConverterModel utility is supplied which extends QStandardItemModel
    and supplies a model for a QListView object.

    It takes a single parameter in the constructor a /a shared_converter_t and has one
    extra method setFilter(QStringList) which allows one or more of the cataegory names
    to be used as filters for the model. In the example below only volume and area
    converter names will be returned.

    \code
    pPluginModel = new ConverterModel( pConverter );

    ui->fromList->setModel( pPluginModel );
    ui->toList->setModel( pPluginModel );

    QStringList list << "Area << "Volume";
    pluginModel->setFilter(list);
    \endcode

    <underline><bold>Subclassing from an existing category</bold></underline>

    To subclass for a new plugin of an existing category you will need to subclass
    the relevant abstract type and \link QObject.

    \code
    class CONVERSIONSHARED_EXPORT Chain : public QObject, public AbstractLengthConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        Chain( ) :
            AbstractLengthConversion( QStringLiteral("201168E23"),
                                      QStringLiteral("Chain"),
                                      QStringLiteral("ch"),
                                      tr("1 Chain = 22 yards")) {
        }

    };
    \endcode

    The first parameter is the length of one of this type in Attometres, the second
    is the required type name which should be unique. and the third is the standard
    symbol for your type. The fourth is an optional tooltip which is used by the
    \link Conversion::ConvertModel class. See later for this.

    The various abstract classes have different constructor forms because they each
    require different information so look at the documentation for the class you
    wish to subclass.

    <underline><bold>Subclassing from a new category</bold></underline>

    To subclass with a new category you will nedd to create a new abstract class
    based on \link Conversion::AbstractConversion. Well technically you could start
    on your own from IConversionInterface but that generally doesn't make much sense.

    You will need to supply a name for you catagory. The case of this doesn't matter
    as the internal tests are case insensitive "Wobbles", "wobbLes" and "WOBBLES" are
    considered the same - assuming your category i "Wobbles" of course.

    \link Conversion::AbstractConversion requires four QString parameters. A name for your
    conversion, an accepted symbol for your type, a ctaegory and an optional tooltip.

    You will also need to supply convert() and toString() methods. Everything else is supplied in the AbstractConversion
    class.

    \code
    AbstractWobbleConversion::AbstractWobbleConversion(
        const QString& wobbleBase,
        const QString& name,
        const QString& symbol ,
        const QString& tooltip ) :
    AbstractConversion( name, symbol, "Length", tooltip ) {

        // put your initialisation shit for baseValue here.

    }

    mpf_class AbstractWobbleConversion::convert( const shared_conversion_t& from, const qreal& value ) const {

        // do your conversion shit to mpf_class here.

        return result;
    }

    QString AbstractWobbleConversion::toString( const shared_conversion_t& from, const qreal& value, const bool& showSymbol ) const {

        // do your conversion shit to string here.

        return rslt;

    }
    \endcode

    then start making concrete types of your abstract form.

    \code
    class CONVERSIONSHARED_EXPORT LeftWobble : public QObject, public AbstractWobbleConversion {
        Q_OBJECT
        Q_PLUGIN_METADATA( IID IConversionInterface_iid )
        Q_INTERFACES( Conversion::IConversionInterface )
    public:
        LeftWobble( ) :
            AbstractWobbleConversion( QStringLiteral("201168E23"),
                                      QStringLiteral("Chain"),
                                      QStringLiteral("ch"),
                                      tr("1 Chain = 22 yards")) :
        {}

    };
    \endcode


*/

/*!
    \namespace Conversion

    \brief Contains miscellaneous identifiers used throughout the Conversion namespace.

    \a {Conversion::IConversionInterface} is the base interface for all converter plugins.
    For convenience there is a \a typedef for a QSharedPointer<IConversionInterface> called
    \a shared_conversion_t which is declared as a metatype with \a Q_DECLARE_METEATYPE so
    can be inserted in QVariant.


*/

/*!
    \module Conversion

    \title Conversion utility

    \brief This module consists of various classes for unit conversion.

    There is one primary class \link Conversion::Convert which manages conversions
    between the various types and a number of plugin libraries, eand containing a
    single conversion type.
*/


/*!
    \class Conversion::Converter

    \inmodule Conversion
    \since 5.0

    \brief Handles conversions between different conversion types.

    This class handles the loading of \a Conversion::IConversionInterface
    plugins and conversions between them.

    \author Simon Meaden
    \date   16 July 2016
*/

/*!
    \fn Conversion::Converter(QObject *parent)

    \brief Constructor for Converter objects.
*/
Converter::Converter( QObject *parent ) : QObject( parent ) {

    loadPlugin();

}

//const map<Conversion::ConversionFactorLength, ttmath::Int<10> > Conversion::mLengthFactor = {

//    // Roman
//    {Conversion::RomanDigitus, int( 185E20 )  }, // 1 digitus (finger) = 18.5mm
//    {Conversion::RomanUncia, int( 246E20 )  }, // 1 uncia (inch) = 24.6mm
//    {Conversion::RomanPalmus, int( 74E21 )  },  // 1 palmus (palm width) = 74mm
//    {Conversion::RomanPalmusMajor, int( 222E21 )  }, // 1 palmus major (palm length) = 222mm
//    {Conversion::RomanPes, int( 296E21 )  }, // 1 pes (foot) = 296mm
//    {Conversion::RomanPalmipes, int( 370E21 )  }, // 1 palmipes = 370mm
//    {Conversion::RomanCubitus, int( 444E21 )  }, // 1 cubitus (cubit) = 444mm
//    {Conversion::RomanGradus, int( 74E22 )  },  // 1 gradus (step) = 0.74m
//    {Conversion::RomanPassus, int( 148E22 )  }, // 1 passus (pace) = 1.4m
//    {Conversion::RomanPertica, int( 296E22 )  }, // 1 pertica (perch) = 2.96m
//    {Conversion::RomanActus, int( 355E23 )  }, // 1 actus = 35.5m
//    {Conversion::RomanStadium, int( 185E24 )  }, // 1 stadium = 185m
//    {Conversion::RomanMillePassus, int( 1480E24 )  }, // 1 mille passus (1000 passus or 8 stadium) = 1.48km
//    {Conversion::RomanLuega, int( 2220E24 )  }, // 1 luega = 2.22km
//    // Astronomical

//    {Conversion::AU, int( 149597870700E24 )  }, // 149,597,870,700 m
//    {Conversion::Parsec, int( 308567758149137E26 )  }, // 3.08567758149137E16 m
//};

//QString Converter::typeName( IConversionInterface::Type type ) {
//    return mTypeNames.value( type );
//}

//QMap<IConversionInterface::Type, QString> Converter::typeNames() {
//    return mTypeNames;
//}


/*
    Loads the plugins from the plugin directory.
*/
void Converter::loadPlugin() {

    QDir pluginsDir( QDir::currentPath() );
    pluginsDir.cd( "plugins" );

    try {
        foreach ( QString fileName, pluginsDir.entryList( QDir::Files ) ) {
            QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );
            QObject *plugin = pluginLoader.instance();

            if ( plugin ) {
                IConversionInterface *interface = qobject_cast<IConversionInterface *>( plugin );
                shared_conversion_t shared = shared_conversion_t( interface );
                mPlugins.insert( shared->name(), shared );
                QString category = shared->category();

                if ( !mCategories.contains( category, Qt::CaseInsensitive ) ) {
                    mCategories.append( category );
                }
            }
        }
    } catch ( BadInitialisationException const& e ) {
        QMessageBox msgBox;
        msgBox.setWindowTitle( tr( "Conversion problem!" ) );
        msgBox.setText( tr( "There was a problem with this conversion." ) );
        const char *txt = e.what();
        QString info = QString( txt );
        msgBox.setInformativeText( info );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }

}

/*!
    \fn Converter::names( QStringList )

    \brief A list of the names of the various individual plugins.

*/

QStringList Converter::names( QStringList categories ) {
    if ( categories.isEmpty() ) {
        return mPlugins.keys();
    } else {
        QStringList list;

        foreach ( shared_conversion_t plugin, mPlugins.values() ) {
            if ( categories.contains( plugin->category() ) ) {
                list.append( plugin->name() );
            }
        }

        return list;
    }
}

/*!
    \fn Converter::plugin( QString )

    \brief Returns an individual plugin when supplied with it's name or Q_NULLPTR if
    an invalid name is supplied.

*/

shared_conversion_t Converter::plugin( QString name ) {
    return mPlugins.value( name );
}

/*!
    \fn Converter::convert( QString , QString , double )

    \brief Converts from one type to another.

    Takes as parameters the from type, the to type and a double value to be converted.
    Throws a conversion::WrongTypeException if both types
    are NOT in the same category. Temperature => length conversions do not make sense.

    If temperature conversions are made a Conversion::BelowAbsoluteException is thrown
    if a temperature below absolute zero is converted. Again it doesn't make sense.

    Both exceptions are subclasses of std::exception.

    Return value is a GMP floating point GMP
    \link {https://gmplib.org/manual/C_002b_002b-Interface-Floats.html#C_002b_002b-Interface-Floats}
    {mpf_class} objects.
*/

mpf_class Converter::convert( QString from, QString to, double value ) {
    shared_conversion_t fromPlugin = mPlugins.value( from );
    shared_conversion_t toPlugin = mPlugins.value( to );

    if ( fromPlugin->category() != toPlugin->category() ) {
        throw WrongTypeException( /*this,*/ fromPlugin->category(), toPlugin->category() );
    }

    shared_temperature_conversion_t p = qSharedPointerDynamicCast<AbstractTemperatureConversion>( fromPlugin );

    if ( !p.isNull() && value < p->absolute() ) {
        throw BelowAbsoluteException( p->name(), p->symbol(), value, p->absolute() );
    }

    mpf_class converted = toPlugin->convert( fromPlugin, value );

    return converted;

}

/*!
    \fn Converter::toString( QString , QString , double, bool )

    \brief Converts from one type to another.

    Takes as parameters the from type, the to type and a double value to be converted and
    an optional boolean flag (default false) allowing the symbol to be appended to the
    converted string.Throws a conversion::WrongTypeException if both types
    are NOT in the same category. Temperature => length conversions do not make sense.

    If temperature conversions are made a Conversion::BelowAbsoluteException is thrown
    if a temperature below absolute zero is converted. Again it doesn't make sense.

    Both exceptions are subclasses of std::exception.

    Return value is a \link QString object.
*/

QString Converter::toString( QString from, QString to, double value, bool showSymbol ) {
    shared_conversion_t fromPlugin = mPlugins.value( from );
    shared_conversion_t toPlugin = mPlugins.value( to );

    if ( fromPlugin->category() != toPlugin->category() ) {
        throw WrongTypeException( /*this,*/ fromPlugin->category(), toPlugin->category() );
    }

    shared_temperature_conversion_t p = qSharedPointerDynamicCast<AbstractTemperatureConversion>( fromPlugin );

    if ( !p.isNull() && value < p->absolute() ) {
        throw BelowAbsoluteException( p->name(), p->symbol(), value, p->absolute() );
    }

    QString converted = toPlugin->toString( fromPlugin, value, showSymbol );

    return converted;
}

/*!
    \fn Converter::categories()

    \brief Returns a QStringList of category names.
*/

QStringList Converter::categories() {
    return mCategories;
}

//#################################################################################################

/*!
 * \class Conversion::ConverterModel
 *
 * \brief A model for a \link QListView object that takes it's data from a Converter.
 *
 * The \link Conversion::Converter is passed in a \link QSharedPointer, for which
 * a typdef Conversion::shared_converter_t is supplied.
 *
 * \code
 * CONVERSION_USE_NAMESPACE
 *
 * shared_converter_t pConverter = shared_converter_t( new Converter(this) );
 * ConverterModel *pModel = new ConverterModel( pConverter, this );
 * QListView *pView = new QListView( this );
 * pView->setModel(pView);
 *
 * // Possible values can be found by using the pConverter->categories(); method
 * QStringList list << "Temperature" << "Volume";
 * pModel->setFilter( list );
 *
 * \endcode
 *
 * \author Simon Meaden
 * \date   31 July 2016
 */

/*!
* \fn ConverterModel::ConverterModel( shared_converter_t& converter )
*
* \brief Constructor for ConverterModel.
*
* Takes as a single parameter a \link Convertion::shared_converter_t, plus an optional parent.
*/
ConverterModel::ConverterModel(shared_converter_t& converter , QObject *parent) :
    QStandardItemModel( parent ),
    pConverter( converter.data() ) {

    setFilter(  ); // This basically indicates all types
}


/*!
* \fn ConverterModel::setFilter( QStringList )
*
* \brief Filters the model data.
*
* A single parameter of a QStringList of required categories. Invalid categories
* are ignored.
*/
void ConverterModel::setFilter( QStringList categories ) {

    QStringList names = pConverter->names( categories );

    int row = 0;
    clear(); // clear existing model data.

    // make up new set.
    foreach ( QString name, names ) {
        QStandardItem *item = new QStandardItem( name );
        shared_conversion_t plugin = pConverter->plugin( name );
        item->setToolTip( plugin->tooltip() );
        item->setData( QVariant::fromValue<shared_conversion_t>( plugin ) ); // this could be useful
        setItem( row++, item );
    }

}

QT_END_NAMESPACE_CONVERSION
