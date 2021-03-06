#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logging.h"
#include "init.h"
#include "mysql.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow *MainWindow::getIntence()
{
    if(MW == nullptr)
    {
        MW = new MainWindow();
    }
    return MW;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_init_clicked()
{
    this->hide();
    Init *IT = new Init(this);
    IT->show();
}

void MainWindow::on_log_clicked()
{
    this->hide();
    Logging *LG = new Logging(this);
    LG->show();
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

void MainWindow::on_forget_clicked()
{
    bool ok;
    QInputDialog ecf;
    name = ecf.getText(this, QStringLiteral("忘记密码"),QStringLiteral("请输入用户名："),QLineEdit::Normal, nullptr,&ok);
    identify = ecf.getText(this, QStringLiteral("忘记密码"),QStringLiteral("请输入证件号："),QLineEdit::Normal, nullptr,&ok);
    My_Sql mysql;
    bool ret = mysql.loguser(name, identify);
    if(ret == false)
    {
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("信息不匹配!"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("请妥善保管您的密码:%1").arg(passward), QMessageBox::Ok);
    return;
}
