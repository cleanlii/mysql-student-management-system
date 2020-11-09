#ifndef GRADEINFO_H
#define GRADEINFO_H

#include <QMainWindow>
#include "dealall.h"

namespace Ui {
class GradeInfo;
}

class GradeInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeInfo(QWidget *parent = nullptr);
    ~GradeInfo();

private slots:
    void on_exit_clicked();

    void on_addfinfo_clicked();

    void on_selectinfo_clicked();

    void on_deleteinfo_clicked();

    void on_changeinfo_clicked();

private:
    Ui::GradeInfo *ui;
    DealAll *Dparent;
};

#endif // GRADEINFO_H
