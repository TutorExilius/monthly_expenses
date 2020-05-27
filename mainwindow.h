#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

private slots:
    void ui_update_difference();
    void ui_update_todays_date();
    void ui_update_todays_day();

private:
    Ui::MainWindow *ui;

    long difference_cents;
};
#endif // MAINWINDOW_H
