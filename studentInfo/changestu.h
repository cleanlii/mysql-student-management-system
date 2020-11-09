#ifndef CHANGESTU_H
#define CHANGESTU_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "stuinfo.h"

namespace Ui {
class ChangeStu;
}

class ChangeStu : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeStu(QWidget *parent = nullptr);
    ~ChangeStu();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::ChangeStu *ui;
    StuInfo* Sparent;
};

#endif // CHANGESTU_H
