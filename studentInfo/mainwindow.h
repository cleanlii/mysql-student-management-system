#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow* getIntence();
    ~MainWindow();
    QString name;
    QString passward;
    QString identify;

private slots:
    void on_init_clicked();

    void on_log_clicked();

    void on_exit_clicked();

    void on_forget_clicked();

private:
    static MainWindow* MW;
    explicit MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
