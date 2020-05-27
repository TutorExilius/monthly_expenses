#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <sqlite_orm.h>
using namespace sqlite_orm;


MainWindow::MainWindow( QWidget *parent )
: QMainWindow{ parent }
, ui{ new Ui::MainWindow }
, difference_cents{ 0 }
{
    this->ui->setupUi( this );
    this->ui_update_difference();
    this->ui_update_todays_date();
    this->ui_update_todays_day();
}

void MainWindow::ui_update_difference()
{
    QString difference_str{ QString::number( this->difference_cents / 100, 'f', 2 ) + " €" };

    this->ui->label_difference_amount->setText( difference_str.replace('.', ',') );

    if( this->difference_cents > 0 )
    {
        this->ui->label_difference_amount->setStyleSheet( "color: green;" );
    }
    else if( this->difference_cents < 0 )
    {
        this->ui->label_difference_amount->setStyleSheet( "color: red;" );
    }
    else
    {
        this->ui->label_difference_amount->setStyleSheet( "color: black;" );
    }
}

void MainWindow::ui_update_todays_date()
{
    QDateTime now{ QDateTime::currentDateTime() };
    QString date_str{ now.date().toString("dd. MMM yyyy")};
    this->ui->label_today->setText(date_str);
}

void MainWindow::ui_update_todays_day()
{
    QDateTime now{ QDateTime::currentDateTime() };
    QString date_str{ now.date().toString("MMM yyyy")};
    this->ui->label_month->setText(date_str);
}

MainWindow::~MainWindow()
{
    delete this->ui;
}
