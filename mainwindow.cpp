#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <sqlite_orm.h>
using namespace sqlite_orm;


MainWindow::MainWindow( QWidget *parent )
: QMainWindow{ parent }
, ui{ new Ui::MainWindow }
{
    this->ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    delete this->ui;
}
