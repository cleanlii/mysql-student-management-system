#ifndef STUINFO_H
#define STUINFO_H

#include <QMainWindow>
#include "dealall.h"

namespace Ui {
class StuInfo;
}

class StuInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit StuInfo(QWidget *parent = nullptr);
    ~StuInfo();
    void showdata();

private slots:
    void on_exit_clicked();

    void on_addfinfo_clicked();

    void on_selectinfo_clicked();

    void on_changeinfo_clicked();

    void on_deleteinfo_clicked();

private:
    Ui::StuInfo *ui;
    DealAll *Dparent;
};

#endif // STUINFO_H
