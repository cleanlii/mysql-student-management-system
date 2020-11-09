#include "mainwindow.h"
#include <QApplication>
#include "mysql.h"

MainWindow* MainWindow::MW = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    My_Sql MS;
    MS.initsql();
    MainWindow* w = MainWindow::getIntence();
    w->show();

    return a.exec();
}
