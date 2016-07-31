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
#ifndef ABSTRACTCONVERSION_H
#define ABSTRACTCONVERSION_H

#include "conversion_global.h"
#include "conversioninterface.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

/*!
 * \class Converter::AbstractConversion
 *
 * \brief Abstract base class of all other conversion classes.
 *
 * [detailed description]
 *
 * \author Simon Meaden
 * \date   date
 */

class AbstractConversion : public IConversionInterface {
    public:
        AbstractConversion() {}
        AbstractConversion( const QString &name, const QString &symbol, const QString &category, const QString &tooltip = QString() );
        ~AbstractConversion() {}

        virtual const QString category() const;
        virtual const QString name() const;
        virtual const QString symbol() const;
        virtual QString tooltip() const;

        virtual QStringList importer() const;

    protected:
        QString mCategory, mName, mSymbol, mTooltip;

};

QT_END_NAMESPACE_CONVERSION

#endif // ABSTRACTCONVERSION_H
