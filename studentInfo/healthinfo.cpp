#include "healthinfo.h"
#include "ui_healthinfo.h"
#include "addhinfo.h"
#include "changeheal.h"
#include "mysql.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QInputDialog>
#include <QHeaderView>

HealthInfo::HealthInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HealthInfo)
{
    Dparent = (DealAll*) parent;
    ui->setupUi(this);
}

HealthInfo::~HealthInfo()
{
    delete ui;
}

void HealthInfo::on_exit_clicked()
{
    this->close();
    Dparent->show();
}

void HealthInfo::on_addfinfo_clicked()
{
    AddHInfo* AH = new AddHInfo(this);
    this->hide();
    AH->show();
}

void HealthInfo::on_selectinfo_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("healthInfo");
    model->setSort(0,Qt::AscendingOrder);
    model->setHeaderData(0, Qt::Horizontal,QStringLiteral("学号"));
    model->setHeaderData(1, Qt::Horizontal,QStringLiteral("姓名"));
    model->setHeaderData(2, Qt::Horizontal,QStringLiteral("身高"));
    model->setHeaderData(3, Qt::Horizontal,QStringLiteral("体重"));
    model->setHeaderData(4, Qt::Horizontal,QStringLiteral("辨色"));
    model->setHeaderData(5, Qt::Horizontal,QStringLiteral("左眼视力"));
    model->setHeaderData(6 ,Qt::Horizontal,QStringLiteral("右眼视力"));
    model->setHeaderData(7, Qt::Horizontal,QStringLiteral("左耳听力"));
    model->setHeaderData(8, Qt::Horizontal,QStringLiteral("右耳听力"));
    model->setHeaderData(9, Qt::Horizontal,QStringLiteral("腿长是否相等"));
    model->setHeaderData(10,Qt::Horizontal,QStringLiteral("血压"));
    model->setHeaderData(11,Qt::Horizontal,QStringLiteral("病史"));
    model->setHeaderData(12,Qt::Horizontal,QStringLiteral("备注"));

    model->select();

    QTableView* view = new QTableView;
    view->setModel(model);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setColumnHidden(0, true);
    view->resizeColumnsToContents();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *header = view->horizontalHeader();
    header->setStretchLastSection(true);
    view->resize(600, 450);

    view->show();
}

void HealthInfo::on_changeinfo_clicked()
{
    this->hide();
    ChangeHeal* CH = new ChangeHeal(this);
    CH->show();
}

void HealthInfo::on_deleteinfo_clicked()
{
    bool ok;
    QInputDialog ecf;
    QString account = ecf.getText(this, QStringLiteral("删除信息"),QStringLiteral("请输入学号："),QLineEdit::Normal, NULL,&ok);
    QProgressDialog dialog(QStringLiteral("正在删除"),QStringLiteral("取消"), 0, 15000, this);
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
    bool ret = mysql.deleteheal(account);
    if(ret == false)
    {
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("查无此人!"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("删除成功!"), QMessageBox::Ok);
    return;
}
