#ifndef CHANGEHEAL_H
#define CHANGEHEAL_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "healthinfo.h"
#include "addhinfo.h"

namespace Ui {
class ChangeHeal;
}

class ChangeHeal : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeHeal(QWidget *parent = nullptr);
    ~ChangeHeal();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::ChangeHeal *ui;
    HealthInfo* Hparent;
};

#endif // CHANGEHEAL_H
