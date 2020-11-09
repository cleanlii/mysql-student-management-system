#ifndef LOGGING_H
#define LOGGING_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "mysql.h"
#include "mainwindow.h"

namespace Ui {
class Logging;
}

class Logging : public QMainWindow
{
    Q_OBJECT

public:
    explicit Logging(QWidget *parent = 0);
    ~Logging();

private slots:
    void on_Yesorno_clicked(QAbstractButton *button);

private:
    Ui::Logging *ui;
    MainWindow* Mparent;
};

#endif // LOGGING_H
