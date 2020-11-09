#ifndef DEALALL_H
#define DEALALL_H

#include <QMainWindow>

namespace Ui {
class DealAll;
}

class DealAll : public QMainWindow
{
    Q_OBJECT

public:
    explicit DealAll(QWidget *parent = nullptr);
    ~DealAll();

private slots:
    void on_exit_clicked();

    void on_stuInfo_clicked();

    void on_healInfo_clicked();

    void on_gradeInfo_clicked();

    void on_liceInfo_clicked();

private:
    Ui::DealAll *ui;
};

#endif // DEALALL_H
