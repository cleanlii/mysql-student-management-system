#include "addinfo.h"
#include "ui_addinfo.h"
#include "mysql.h"

AddInfo::AddInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddInfo)
{
    Sparent = (StuInfo*) parent;
    ui->setupUi(this);
    this->ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringLiteral("提交"));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("返回"));
}

AddInfo::~AddInfo()
{
    delete ui;
}

void AddInfo::on_buttonBox_clicked(QAbstractButton *button)
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

        QProgressDialog dialog(QStringLiteral("正在添加"),QStringLiteral("取消"), 0, 15000, this);
        dialog.setWindowTitle(QStringLiteral("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k = 0; k < 30000; k++)
        {
            dialog.setValue(k);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(30000);

        My_Sql mysql;
        bool ret = mysql.addstu(&tran);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("添加失败!"), QMessageBox::Ok);
            this->close();
            Sparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("添加成功!"), QMessageBox::Ok);
        this->close();
        Sparent->show();
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
        Sparent->show();
    }
}
