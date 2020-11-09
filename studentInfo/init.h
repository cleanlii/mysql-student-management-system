#ifndef INIT_H
#define INIT_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "mysql.h"
#include "mainwindow.h"

namespace Ui {
class Init;
}

class Init : public QMainWindow
{
    Q_OBJECT

public:
    explicit Init(QWidget *parent = 0);
    ~Init();

private slots:
    void on_Yesorno_clicked(QAbstractButton *button);

private:
    Ui::Init *ui;
    MainWindow* Mparent;
};

#endif // INIT_H
