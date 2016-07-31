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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QStringList>
#include <QStringListModel>
#include <QDoubleValidator>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QMessageBox>

#include <gmp.h>
#include <gmpxx.h>

#include "conversion_global.h"
#include "converter.h"

namespace Ui {
class MainWindow;
}

CONVERSION_USE_NAMESPACE

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow( QWidget *parent = 0 );
        ~MainWindow();

    protected:
        Conversion::shared_converter_t pConverter;
        ConverterModel *pPluginModel;
        QStandardItemModel *pTypeModel;
        QString fromType, toType;
        QDoubleValidator validator;


        void convert();
        void fromSelectionChanged(const QModelIndex &index );
        void toSelectionChanged(const QModelIndex &index );
        void typeClicked(const QModelIndex &index );

    private:
        Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
