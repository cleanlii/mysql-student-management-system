#include "gradeinfo.h"
#include "ui_gradeinfo.h"
#include "addgradeinfo.h"
#include "changegrade.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QInputDialog>
#include <QHeaderView>
#include "mysql.h"

GradeInfo::GradeInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeInfo)
{
    Dparent = (DealAll*)parent;
    ui->setupUi(this);
}

GradeInfo::~GradeInfo()
{
    delete ui;
}

void GradeInfo::on_exit_clicked()
{
    this->close();
    Dparent->show();
}

void GradeInfo::on_addfinfo_clicked()
{
    this->hide();
    AddGradeInfo * AI = new AddGradeInfo(this);
    AI->show();
}

void GradeInfo::on_selectinfo_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("grade_view");
    model->setSort(0,Qt::AscendingOrder);
    model->setHeaderData(0, Qt::Horizontal,QStringLiteral("学号"));
    model->setHeaderData(1, Qt::Horizontal,QStringLiteral("姓名"));
    model->setHeaderData(2, Qt::Horizontal,QStringLiteral("课程"));
    model->setHeaderData(3, Qt::Horizontal,QStringLiteral("上次考试时间"));
    model->setHeaderData(4, Qt::Horizontal,QStringLiteral("考试次数"));
    model->setHeaderData(5, Qt::Horizontal,QStringLiteral("成绩"));

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

void GradeInfo::on_changeinfo_clicked()
{
    ChangeGrade* CG = new ChangeGrade(this);
    this->hide();
    CG->show();
}

void GradeInfo::on_deleteinfo_clicked()
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
    bool ret = mysql.deletegrade(account);
    if(ret == false)
    {
        QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("查无此人!"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("删除成功!"), QMessageBox::Ok);
    return;
}

