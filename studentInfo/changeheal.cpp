#include "changeheal.h"
#include "ui_changeheal.h"
#include "mysql.h"

ChangeHeal::ChangeHeal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeHeal)
{
    Hparent = (HealthInfo*)parent;
    ui->setupUi(this);
    this->ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringLiteral("提交"));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringLiteral("返回"));
}

ChangeHeal::~ChangeHeal()
{
    delete ui;
}

void ChangeHeal::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        my_heal tran;
        tran.stuaccount = ui->account->text();
        tran.stuname = ui->name->text();
        tran.height = ui->height->text();
        tran.weight = ui->weight->text();
        tran.differentiate = ui->differentiate->currentText();
        tran.left_sight = ui->left_sight->text();
        tran.right_sight = ui->right_sight->text();
        tran.left_ear = ui->left_ear->currentText();
        tran.right_ear = ui->right_ear->currentText();
        tran.legs = ui->legs->currentText();
        tran.pressure = ui->pressure->currentText();
        tran.history = ui->history->toPlainText();
        tran.h_text = ui->h_text->toPlainText();

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
        bool ret = mysql.updateheal(&tran);
        if(ret == false)
        {
            QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("查无此人!"), QMessageBox::Ok);
            this->close();
            Hparent->show();
            return;
        }
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("修改成功!"), QMessageBox::Ok);
        this->close();
        Hparent->show();
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
        Hparent->show();
    }
}
