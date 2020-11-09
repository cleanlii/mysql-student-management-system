#ifndef ADDGRADEINFO_H
#define ADDGRADEINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "gradeinfo.h"


namespace Ui {
class AddGradeInfo;
}

class AddGradeInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddGradeInfo(QWidget *parent = nullptr);
    ~AddGradeInfo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddGradeInfo *ui;
    GradeInfo* Gparent;
};

typedef struct Grade
{
    QString stuaccount;
    int     classid;
    QString lasttime;
    int     times;
    float   grade;
}my_grade;

#endif // ADDGRADEINFO_H
