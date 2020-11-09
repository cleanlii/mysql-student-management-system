#ifndef CHANGEGRADE_H
#define CHANGEGRADE_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "gradeinfo.h"
#include "addgradeinfo.h"

namespace Ui {
class ChangeGrade;
}

class ChangeGrade : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeGrade(QWidget *parent = nullptr);
    ~ChangeGrade();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::ChangeGrade *ui;
    GradeInfo* Gparent;
};

#endif // CHANGEGRADE_H
