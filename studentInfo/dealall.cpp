#include "dealall.h"
#include "ui_dealall.h"
#include "mainwindow.h"
#include "stuinfo.h"
#include "healthinfo.h"
#include "gradeinfo.h"
#include <QMessageBox>

DealAll::DealAll(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DealAll)
{
    ui->setupUi(this);
}

DealAll::~DealAll()
{
    delete ui;
}

void DealAll::on_exit_clicked()
{
    this->hide();
    MainWindow* MW = MainWindow::getIntence();
    MW->show();
}

void DealAll::on_stuInfo_clicked()
{
    this->hide();
    StuInfo* SF = new StuInfo(this);
    SF->show();
}

void DealAll::on_healInfo_clicked()
{
    this->hide();
    HealthInfo* HI = new HealthInfo(this);
    HI->show();
}

void DealAll::on_gradeInfo_clicked()
{
    this->hide();
    GradeInfo* GI = new GradeInfo(this);
    GI->show();
}

void DealAll::on_liceInfo_clicked()
{
    QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("功能暂未开放!"), QMessageBox::Ok);
}
