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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>

#include "../src/conversion_global.h"
#include "../src/abstractconversion.h"
#include "../src/abstractareaconversion.h"
#include "../plugin/acre/acre.h"
#include "../plugin/hectare/hectare.h"
#include <gmpxx.h>

CONVERSION_USE_NAMESPACE

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    pConverter( new Converter( this ) ),
    ui( new Ui::MainWindow ) {

    ui->setupUi( this );

    //########################
    //    mpf_class f;
    //    mp_exp_t exp;
    //    std::string s;
    //    QString st, rslt;
    //    QString stout = QString( "%1e%2" );
    //    int e;

    //    f = "1234.56789";
    //    s = f.get_str( exp );
    //    st = QString( s.c_str() );
    //    e = exp - st.length();
    //    rslt = stout.arg( st ).arg( e );

    //    f = "0.000123456789";
    //    s = f.get_str( exp );
    //    st = QString( s.c_str() );
    //    e = exp - st.length();
    //    rslt = stout.arg( st ).arg( e );

    //    f = "1.023456789";
    //    s = f.get_str( exp );
    //    st = QString( s.c_str() );
    //    e = exp - st.length();
    //    rslt = stout.arg( st ).arg( e );
    //########################

    pTypeModel = new QStandardItemModel( this );
    QStringList categories = pConverter->categories();
    int row = 0;

    foreach ( QString category, categories ) {
        QStandardItem *item = new QStandardItem( category );
        item->setCheckable( true );
        item->setCheckState( Qt::Unchecked );
        pTypeModel->setItem( row++, item );
    }

    ui->categoryView->setModel( pTypeModel );

    pPluginModel = new ConverterModel( pConverter, this );

    ui->fromList->setModel( pPluginModel );
    ui->toList->setModel( pPluginModel );

    ui->fromList->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->fromList->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->toList->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->toList->setSelectionMode( QAbstractItemView::SingleSelection );

    ui->valueEdit->setValidator( &validator );

    Conversion::shared_conversion_t acre = Conversion::shared_conversion_t(new Conversion::Acre());
    Conversion::shared_conversion_t hectare = Conversion::shared_conversion_t(new Conversion::Hecatre());
    qreal value = 1.0;
    mpf_class result = acre->convert(hectare, value);


    connect( ui->fromList, &QListView::clicked, this, &MainWindow::fromSelectionChanged );
    connect( ui->toList, &QListView::clicked, this, &MainWindow::toSelectionChanged );
    connect( ui->convertBtn, &QPushButton::clicked, this, &MainWindow::convert );
    connect( ui->categoryView, &QListView::clicked, this, &MainWindow::typeClicked );

    ui->convertBtn->setDefault( true );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::fromSelectionChanged( const QModelIndex& index ) {
    QString item = pPluginModel->data( index, Qt::DisplayRole ).toString();
    fromType = item;
    bool isGood = ( !fromType.isEmpty() && !toType.isEmpty() /*&& ( fromType != toType )*/ );
    ui->convertBtn->setEnabled( isGood );
}

void MainWindow::toSelectionChanged( const QModelIndex& index ) {
    QString item = pPluginModel->data( index, Qt::DisplayRole ).toString();
    toType = item;
    bool isGood = ( !fromType.isEmpty() && !toType.isEmpty() /*&& ( fromType != toType )*/ );
    ui->convertBtn->setEnabled( isGood );
}

void MainWindow::typeClicked( const QModelIndex& /*index*/ ) {

    QStringList categories;

    for ( int row = 0; row < pTypeModel->rowCount(); row++ ) {
        QStandardItem *item = pTypeModel->item( row, 0 );

        if ( item && item->checkState() == Qt::Checked ) {
            categories.append( item->text() );
        }
    }

    pPluginModel->setFilter( categories );
}

void MainWindow::convert() {
    QString v = ui->valueEdit->text();
    double d = v.toDouble();

    try {
        if ( fromType.isEmpty() || toType.isEmpty() ) {
            return;
        }

        QString value = pConverter->toString( fromType, toType, d, true ); // true indicates show symbol
        ui->resultLbl->setText( value );
    } catch ( WrongTypeException const& wte ) {
        QMessageBox msgBox;
        msgBox.setWindowTitle( tr( "Conversion problem!" ) );
        msgBox.setText( tr( "There was a problem with this conversion." ) );
        const char *txt = wte.what();
        QString info = QString( txt );
        msgBox.setInformativeText( info );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    } catch ( BelowAbsoluteException const& bae ) {
        QMessageBox msgBox;
        msgBox.setWindowTitle( tr( "Conversion problem!" ) );
        msgBox.setText( tr( "There was a problem with this conversion." ) );
        const char *txt = bae.what();
        QString info = QString( txt );
        msgBox.setInformativeText( info );
        msgBox.setStandardButtons( QMessageBox::Ok );
        msgBox.exec();
    }

}
