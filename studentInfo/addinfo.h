#ifndef ADDINFO_H
#define ADDINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "stuinfo.h"

namespace Ui {
class AddInfo;
}

class AddInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = nullptr);
    ~AddInfo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddInfo *ui;
    StuInfo* Sparent;
};

typedef struct stuInfo
{
    QString account;
    QString name;
    QString sex;
    int     age;
    QString identify;
    QString tel;
    QString enroll_time;
    QString leave_time;
    QString scondition;
    QString text;
}my_stu;

#endif // ADDINFO_H
