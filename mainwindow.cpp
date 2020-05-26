#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <sqlite_orm.h>
using namespace sqlite_orm;


MainWindow::MainWindow( QWidget *parent )
: QMainWindow{ parent }
, ui{ new Ui::MainWindow }
, difference_cents{ 0 }
{
    this->ui->setupUi( this );

    QString difference_str{ QString::number( this->difference_cents / 100, 'f', 2 ) + " €" };

    this->ui->label_difference_amount->setText( difference_str.replace('.', ',') );

    if( this->difference_cents > 0)
    {
        this->ui->label_difference_amount->setStyleSheet( "color: green;" );
    }
    else if( this->difference_cents < 0)
    {
        this->ui->label_difference_amount->setStyleSheet( "color: red;" );
    }
    else
    {
        this->ui->label_difference_amount->setStyleSheet( "color: black;" );
    }
}

MainWindow::~MainWindow()
{
    delete this->ui;
}
