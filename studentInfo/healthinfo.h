#ifndef HEALTHINFO_H
#define HEALTHINFO_H

#include <QMainWindow>
#include "dealall.h"

namespace Ui {
class HealthInfo;
}

class HealthInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit HealthInfo(QWidget *parent = nullptr);
    ~HealthInfo();

private slots:
    void on_exit_clicked();

    void on_addfinfo_clicked();

    void on_selectinfo_clicked();

    void on_changeinfo_clicked();

    void on_deleteinfo_clicked();

private:
    Ui::HealthInfo *ui;
    DealAll *Dparent;
};

#endif // HEALTHINFO_H
