#ifndef ADDHINFO_H
#define ADDHINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "healthinfo.h"

namespace Ui {
class AddHInfo;
}

class AddHInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddHInfo(QWidget *parent = 0);
    ~AddHInfo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddHInfo *ui;
    HealthInfo* Hparent;
};

typedef struct heal
{
    QString stuaccount;
    QString stuname;
    QString height;
    QString weight;
    QString differentiate;
    QString left_sight;
    QString right_sight;
    QString left_ear;
    QString right_ear;
    QString legs;
    QString pressure;
    QString history;
    QString h_text;
}my_heal;

#endif // ADDHINFO_H
