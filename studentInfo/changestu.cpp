#include "changestu.h"
#include "ui_changestu.h"
#include "changestu.h"
#include "mysql.h"

ChangeStu::ChangeStu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeStu)
{
    Sparent = (StuInfo*) parent;
    ui->setupUi(this);
    this->ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringLiteral("提交"));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("返回"));
}

ChangeStu::~ChangeStu()
{
    delete ui;
}

void ChangeStu::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        my_stu tran;
        tran.account = ui->acount->text();
        tran.name = ui->name->text();
        tran.sex = ui->sex->currentText();
        tran.age = ui->age->text().toInt();
        tran.identify = ui->identify->text();
        tran.tel = ui->tel->text();
        tran.enroll_time = ui->enroll->text();
        tran.leave_time = ui->leave->text();
        tran.scondition = ui->condition->currentText();
        tran.text = ui->textEdit->toPlainText();

        QProgressDialog dialog(QStringLiteral("正在修改"),QStringLiteral("取消"), 0, 15000, this);
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
        bool ret = mysql.updatestu(&tran);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("查无此人!"), QMessageBox::Ok);
            this->close();
            Sparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("修改成功!"), QMessageBox::Ok);
        this->close();
        Sparent->show();
        return;
    }
    else if(ui->buttonBox->button(QDialogButtonBox::Cancel) == button)
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
        Sparent->show();
    }
}
