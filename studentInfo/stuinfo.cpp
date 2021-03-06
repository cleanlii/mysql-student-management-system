#include "stuinfo.h"
#include "ui_stuinfo.h"
#include "mainwindow.h"
#include "addinfo.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QInputDialog>
#include "mysql.h"
#include "changestu.h"
#include <QHeaderView>

enum studentInfoIndex
{
    studentInfo_stuaccount = 0,
    studentInfo_stuname = 1,
    studentInfo_stusex = 2,
    studentInfo_stuage = 3,
    studentInfo_identify = 4,
    studentInfo_tel = 5,
    studentInfo_enroll_time = 6,
    studentInfo_leave_time = 7,
    studentInfo_scondition = 8,
    studentInfo_stu_text = 9
};

StuInfo::StuInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StuInfo)
{
    Dparent = (DealAll*) parent;
    ui->setupUi(this);
}

StuInfo::~StuInfo()
{
    delete ui;
}

void StuInfo::on_exit_clicked()
{
    this->close();
    Dparent->show();
}

void StuInfo::on_addfinfo_clicked()
{
    AddInfo* AI = new AddInfo(this);
    this->hide();
    AI->show();
}

void StuInfo::on_selectinfo_clicked()
{
    showdata();
}

void StuInfo::showdata()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("studentInfo");
    model->setSort(studentInfo_stuaccount,Qt::AscendingOrder);
    model->setHeaderData(studentInfo_stuaccount,Qt::Horizontal,QStringLiteral("学号"));
    model->setHeaderData(studentInfo_stuname,Qt::Horizontal,QStringLiteral("姓名"));
    model->setHeaderData(studentInfo_stusex,Qt::Horizontal,QStringLiteral("性别"));
    model->setHeaderData(studentInfo_stuage,Qt::Horizontal,QStringLiteral("年龄"));
    model->setHeaderData(studentInfo_identify,Qt::Horizontal,QStringLiteral("身份证号"));
    model->setHeaderData(studentInfo_tel,Qt::Horizontal,QStringLiteral("电话号码"));
    model->setHeaderData(studentInfo_enroll_time,Qt::Horizontal,QStringLiteral("入学时间"));
    model->setHeaderData(studentInfo_leave_time,Qt::Horizontal,QStringLiteral("毕业时间"));
    model->setHeaderData(studentInfo_scondition,Qt::Horizontal,QStringLiteral("学业状态"));
    model->setHeaderData(studentInfo_stu_text,Qt::Horizontal,QStringLiteral("备注"));

    model->select();

    QTableView* view = new QTableView;
    view->setModel(model);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setColumnHidden(studentInfo_stuaccount, true);
    view->resizeColumnsToContents();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *header = view->horizontalHeader();
    header->setStretchLastSection(true);
    view->resize(600, 450);

    view->show();
}

void StuInfo::on_changeinfo_clicked()
{
    ChangeStu* CS = new ChangeStu(this);
    this->hide();
    CS->show();
}

void StuInfo::on_deleteinfo_clicked()
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
    bool ret = mysql.deletestu(account);
    if(ret == false)
    {
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("查无此人!"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("删除成功!"), QMessageBox::Ok);
    return;
}
