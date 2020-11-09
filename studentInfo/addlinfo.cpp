#include "addlinfo.h"
#include "ui_addlinfo.h"
#include "mysql.h"

AddLInfo::AddLInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddLInfo)
{
    Lparent = (LicenInfo*)parent;
    ui->setupUi(this);
    this->ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringLiteral("提交"));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("返回"));
}

AddLInfo::~AddLInfo()
{
    delete ui;
}

void AddLInfo::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        my_licen tran;
        tran.stuaccount = ui->account->text();
        tran.stuname = ui->name->text();
        tran.recv_time = ui->revc_time->text();
        tran.recv_name = ui->recv_name->text();
        tran.l_text = ui->textEdit->toPlainText();

        QProgressDialog dialog(QStringLiteral("正在添加"),QStringLiteral("取消"), 0, 15000, this);
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

        My_Sql mysql;
        bool ret = mysql.addlicen(&tran);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("添加失败!"), QMessageBox::Ok);
            this->close();
            Lparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("添加成功!"), QMessageBox::Ok);
        this->close();
        Lparent->show();
        return;
    }
    else if(ui->buttonBox->button(QDialogButtonBox::Cancel) == button)
    {
        this->close();
        QProgressDialog dialog(QStringLiteral("正在返回主界面"),QStringLiteral("取消"), 0, 3000, this);
        dialog.setWindowTitle(QStringLiteral("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k = 0; k < 3000; k++)
        {
            dialog.setValue(k);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(3000);
        Lparent->show();
    }
}
