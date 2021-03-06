#include "logging.h"
#include "ui_logging.h"
#include "dealall.h"

Logging::Logging(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Logging)
{
    Mparent = (MainWindow*)parent;
    ui->setupUi(this);
    this->ui->Yesorno->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->Yesorno->button(QDialogButtonBox::Ok)->setText(QStringLiteral("确定"));
    this->ui->Yesorno->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("取消"));
    this->ui->passward->setEchoMode(QLineEdit::Password);                   //密码方式显示文本
    if(Mparent->name != "")
        this->ui->name->addItem(QString("%1").arg(Mparent->name));
}

Logging::~Logging()
{
    delete ui;
}

void Logging::on_Yesorno_clicked(QAbstractButton *button)
{
    if(ui->Yesorno->button(QDialogButtonBox::Ok) == button)
    {
        if((ui->name->currentText() == "") || (ui->passward->text() == ""))
        {
            QMessageBox::information(this, QStringLiteral("警告"), QStringLiteral("输入不能为空！!"), QMessageBox::Ok);
            return;
        }
        QString name = ui->name->currentText();
        QString passward = ui->passward->text();

        QProgressDialog dialog(QStringLiteral("正在登录"),QStringLiteral("取消"), 0, 15000, this);
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
        bool ret = mysql->loguser(name, passward);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("账号密码不匹配!"), QMessageBox::Ok);
            this->close();
            Mparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("登录成功!"), QMessageBox::Ok);
        this->close();
        DealAll* DA = new DealAll(this);
        DA->show();
        return;
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
