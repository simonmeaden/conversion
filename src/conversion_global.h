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

#ifndef CONVERSION_GLOBAL_H
#define CONVERSION_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>

//  Disables the namespace
//  The problem with declaring namespaces like hjis is that the
//  QTCreator method list (Symbols) do not work for some reason,
//  probably in the qtcreator parser.
//#define DISABLE_CONVERSION_NAMESPACE

#define QT_BEGIN_NAMESPACE_CONVERSION namespace Conversion {
#define QT_END_NAMESPACE_CONVERSION }
#define CONVERSION_USE_NAMESPACE using namespace Conversion;


#if defined(CONVERSION_LIBRARY)
    #define CONVERSIONSHARED_EXPORT Q_DECL_EXPORT
#else
    #define CONVERSIONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CONVERSION_GLOBAL_H
