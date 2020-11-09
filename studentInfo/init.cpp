#include "init.h"
#include "ui_init.h"

Init::Init(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Init)
{
    Mparent = (MainWindow*)parent;
    ui->setupUi(this);
    this->ui->Yesorno->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->Yesorno->button(QDialogButtonBox::Ok)->setText(QStringLiteral("确定"));
    this->ui->Yesorno->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("取消"));
    this->ui->passward1->setEchoMode(QLineEdit::Password);                   //密码方式显示文本
    this->ui->passward2->setEchoMode(QLineEdit::Password);                   //密码方式显示文本
}

Init::~Init()
{
    delete ui;
}

void Init::on_Yesorno_clicked(QAbstractButton *button)
{
    if(ui->Yesorno->button(QDialogButtonBox::Ok) == button)
    {
        if((ui->use_name->text() == "") || (ui->identify->text() == "") || (ui->passward1->text() == "") || (ui->passward2->text() == ""))
        {
            QMessageBox::information(this, QStringLiteral("警告"), QStringLiteral("输入不能为空！!"), QMessageBox::Ok);
            return;
        }
        if(ui->passward1->text() != ui->passward2->text())
        {
            QMessageBox::information(this, QStringLiteral("警告"), QStringLiteral("输入密码错误！!"), QMessageBox::Ok);
            return;
        }

        QString name = ui->use_name->text();
        QString identify = ui->identify->text();
        QString passward = ui->passward1->text();

        QProgressDialog dialog(QStringLiteral("正在注册"),QStringLiteral("取消"), 0, 15000, this);
        dialog.setWindowTitle(QStringLiteral("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k = 0; k < 15000; k++)
        {
            dialog.setValue(k);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(15000);

        My_Sql* mysql = new My_Sql;
        bool ret = mysql->inituser(name, identify, passward);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("用户已被注册!"), QMessageBox::Ok);
            this->close();
            Mparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("注册成功!"), QMessageBox::Ok);
        Mparent->name = name;
        this->close();
        Mparent->show();
    }
    else if(ui->Yesorno->button(QDialogButtonBox::Cancel) == button)
    {
        this->close();
        QProgressDialog dialog(QStringLiteral("正在返回主界面"),QStringLiteral("取消"), 0, 15000, this);
        dialog.setWindowTitle(QStringLiteral("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k = 0; k < 15000; k++)
        {
            dialog.setValue(k);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(15000);
        Mparent->show();
    }
}
