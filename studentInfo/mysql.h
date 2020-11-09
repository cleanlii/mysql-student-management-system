#ifndef MYSQL_H
#define MYSQL_H

#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "logging.h"
#include "mainwindow.h"
#include "init.h"
#include "addinfo.h"
#include "addhinfo.h"
#include "addgradeinfo.h"

class My_Sql
{
    QSqlQuery *query;
public:
    My_Sql();
    void initsql();                                                         //初始化连接数据库
    void createtable();                                                     //建立数据库
    bool inituser(QString name, QString identify, QString passward);        //注册
    bool loguser(QString name, QString passward);                           //登录
    bool addstu(my_stu* stu);                                               //添加学生信息
    bool deletestu(QString account);                                        //删除学生信息
    bool updatestu(my_stu* stu);                                            //修改学生信息
    bool addheal(my_heal* heal);                                            //添加体检信息
    bool updateheal(my_heal* heal);                                         //修改体检信息
    bool deleteheal(QString account);                                       //删除体检信息
    bool addgrade(my_grade* grad);                                          //添加成绩
    bool updategrade(my_grade* grad);                                       //修改成绩
    bool deletegrade(QString account);                                      //删除成绩
};

#endif // MYSQL_H
