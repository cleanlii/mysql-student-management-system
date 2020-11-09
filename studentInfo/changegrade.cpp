#include "changegrade.h"
#include "ui_changegrade.h"
#include "mysql.h"

ChangeGrade::ChangeGrade(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeGrade)
{
    Gparent = (GradeInfo*)parent;
    ui->setupUi(this);
    this->ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringLiteral("提交"));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("返回"));
}

ChangeGrade::~ChangeGrade()
{
    delete ui;
}

void ChangeGrade::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        my_grade tran;
        tran.stuaccount = ui->account->text();
        tran.classid = ui->classid->text().toInt();
        tran.times = ui->times->text().toInt();
        tran.grade = ui->grade->text().toFloat();

        if(ui->lasttime->text() == "")
        {
            tran.lasttime = "NULL";
        }
        else
        {
            tran.lasttime = ui->lasttime->text();
        }

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
        bool ret = mysql.updategrade(&tran);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("查无此人!"), QMessageBox::Ok);
            this->close();
            Gparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("修改成功!"), QMessageBox::Ok);
        this->close();
        Gparent->show();
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
        Gparent->show();
    }
}
