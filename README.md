## 环境说明
- 系统环境：Windows 10 专业版
- 数据库管理系统：MySQL
- 设计工具：Navicat for MySQL
- 编程工具：Qt 5.12.3 / VS

## 流程图
- 建立数据库
![流程1](https://img-blog.csdnimg.cn/2020020517274923.png)
- 建立数据表
![流程2](https://img-blog.csdnimg.cn/202002051728001.png)
## 数据字典
- 学生表
![1](https://img-blog.csdnimg.cn/2020020518362544.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 体检表
![2](https://img-blog.csdnimg.cn/20200205183643583.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 成绩表
![3](https://img-blog.csdnimg.cn/20200205183644430.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 课程表
![4](https://img-blog.csdnimg.cn/2020020518370494.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 用户表
![5](https://img-blog.csdnimg.cn/20200205183718539.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
## ER图
- 学生ER图
![1](https://img-blog.csdnimg.cn/20200205184516244.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 体检ER图
![2](https://img-blog.csdnimg.cn/20200205184536726.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 成绩ER图
![3](https://img-blog.csdnimg.cn/20200205184545922.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 课程ER图
![4](https://img-blog.csdnimg.cn/20200205184547594.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 用户ER图
![5](https://img-blog.csdnimg.cn/20200205184605751.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
- 总体ER图
![6](https://img-blog.csdnimg.cn/20200205184614819.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
## 关系模式及规范化
#### 关系模式定义
设计学生信息管理数据库，包括学生信息、体检信息、课程信息、成绩信息、用户信息五个关系，其关系模式中每个实体定义的属性如下：
- 学生信息：（学号，姓名，性别，年龄，身份证号，联系电话，入学时间，毕业时间，学业情况，备注）；
- 体检信息：（学号，身高，体重，辨色，左眼视力，右眼视力，左耳听力，右耳听力，腿长比，血压，病史，备注）；
- 课程信息：（课程号，课程名，备注）；
- 成绩信息：（学号，课程号，上次考试时间，考试次数，分数）；
- 用户信息：（用户名，密码，身份证号）；
#### 规范化（3NF）
- 秉持最优化、最简洁的设计原则，应选择合理的范式规范；
- 在最开始的设计中，我引入了地址、院系、年级、类似“XX1901”的班级命名制度；
- 由于师生信息本身的复杂性，全部消除非主键的部分依赖和传递依赖，需要新增和删改很多表来避免数据冗余，具体操作如下：
- 根据日期的可分性，可分出国家表、地区表等（1NF）；
- 根据年级对班级的部份依赖，将年级更改为入学年份或届数（2NF）；
- 根据班级对院系、专业的部份依赖， 学生表中分出院系表、班级表、专业表（2NF）；
- 根据班级对年级、院系、专业复杂的传递依赖，亦可将几类键分出（3NF）。

## 开发流程
#### Qt设计界面
![1](https://img-blog.csdnimg.cn/20200205202550851.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
![2](https://img-blog.csdnimg.cn/20200205202955108.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
#### Navicat搭建库
![1](https://img-blog.csdnimg.cn/2020020520302370.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
![2](https://img-blog.csdnimg.cn/20200205203012766.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
## 部分后端代码
```cpp
#include "mysql.h"
#include "mainwindow.h"
#include <QDebug>

My_Sql::My_Sql()
{
}

void My_Sql::initsql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("student");
    if(db.open())
     {
         qDebug() << "database is established!";
         createtable();
         return;
     }
     else
     {
         qDebug() << "build error!";
         return;
    }
}

// 创建数据库操作
void My_Sql::createtable()
{
    query = new QSqlQuery;

    //建表
    query->exec("create table user(name VARCHAR(30) UNIQUE NOT NULL, passward VARCHAR(30), identify VARCHAR(30) PRIMARY KEY)");
    query->exec("create table studentInfo(stuaccount VARCHAR(30) PRIMARY KEY UNIQUE NOT NULL, stuname VARCHAR(30), stusex ENUM('Male', 'Female') NOT NULL, stuage INT, identify VARCHAR(30) UNIQUE NOT NULL, tel VARCHAR(20), enroll_time DATE, leave_time DATE, scondition enum('Studying', 'Educated', 'Off'), stu_text TEXT)");
    query->exec("create table healthInfo(stuaccount VARCHAR(30) PRIMARY KEY UNIQUE NOT NULL, stuname VARCHAR(30) NOT NULL, height FLOAT, weight FLOAT, differentiate ENUM('Normal', 'Weak', 'Blind'), left_sight FLOAT, right_sight FLOAT, left_ear ENUM('Normal','Weak'), right_ear ENUM('Normal','Weak'), legs ENUM('Normal','Diff'), pressure ENUM('Normal','High','Low'), history VARCHAR(50), h_text TEXT)");
    query->exec("create table courseInfo(classid INT PRIMARY KEY UNIQUE NOT NULL AUTO_INCREMENT, classname VARCHAR(30), class_text TEXT)");
    query->exec("create table gradeInfo(stuaccount VARCHAR(30) PRIMARY KEY UNIQUE NOT NULL, classid INT NOT NULL, lasttime date, times INT default 1, grade float default 0, constraint grade_acc_fk FOREIGN KEY(stuaccount) REFERENCES studentInfo(stuaccount), constraint grade_cid_fk FOREIGN KEY(classid) REFERENCES courseInfo(classid))");

    //添加管理员
    query->exec("insert into user value('root', '123456', 'root')");

    //索引
    query->exec("create index int_name ON studentInfo(stuname)");
    query->exec("alter table studentInfo ADD INDEX ind_con(scondition)");
    query->exec("create index ind_hname ON healthInfo(stuname)");

    //视图
    query->exec("create VIEW grade_view AS SELECT g.stuaccount, s.stuname, c.classname, g.lasttime, g.times, g.grade FROM studentinfo s, courseinfo c, gradeinfo g WHERE g.stuaccount = s.stuaccount AND g.classid = c.classid");

    //三种触发器
    query->exec("CREATE TRIGGER license_stu AFTER INSERT ON licenseInfo  FOR EACH ROW BEGIN UPDATE studentInfo SET leave_time=NEW.recv_time, scondition = 'Educated' WHERE stuaccount = NEW.stuaccount; END");

    query->exec("CREATE TRIGGER update_name AFTER UPDATE ON studentinfo FOR EACH ROW BEGIN UPDATE healthinfo SET stuname = NEW.stuname WHERE stuaccount = NEW.stuaccount;END");

    query->exec("CREATE TRIGGER delete_stu AFTER DELETE ON studentinfo FOR EACH ROW BEGIN DELETE FROM gradeinfo WHERE stuaccount = OLD.stuaccount; DELETE FROM healthinfo WHERE stuaccount = OLD.stuaccount; DELETE FROM licenseinfo WHERE stuaccount = OLD.stuaccount;END");
}


bool My_Sql::inituser(QString name, QString identify, QString passward)
{
    query = new QSqlQuery;
    QString str = QString("insert into user value('%1', '%2', '%3')").arg(name).arg(identify).arg(passward);
    bool ret = query->exec(str);
    return ret;
}

bool My_Sql::loguser(QString name, QString passward)
{
    query = new QSqlQuery;
    QString str = QString("select * from user where name = '%1' and passward = '%2'").arg(name).arg(passward);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    MainWindow* MW = MainWindow::getIntence();
    MW->passward = query->value(1).toString();
    return true;
}

bool My_Sql::addstu(stuInfo *stu)
{
    query = new QSqlQuery;
    QString str = QString("insert into studentInfo value('%1', '%2', '%3', %4, '%5', '%6', '%7', '%8', '%9', '%10')")
            .arg(stu->account).arg(stu->name).arg(stu->sex).arg(stu->age).arg(stu->identify).arg(stu->tel).arg(stu->enroll_time)
            .arg(stu->leave_time).arg(stu->scondition).arg(stu->text);
    bool ret = query->exec(str);
    return ret;
}

bool My_Sql::deletestu(QString account)
{
    query = new QSqlQuery;
    QString str = QString("select * from studentInfo where stuaccount = '%1'").arg(account);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    str = QString("delete from studentInfo where stuaccount = '%1'").arg(account);
    query->exec(str);
    return true;
}

bool My_Sql::updatestu(my_stu *stu)
{
    query = new QSqlQuery;
    QString str = QString("select * from studentInfo where stuaccount = '%1'").arg(stu->account);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    str = QString("update studentInfo set stuname = '%1', stusex = '%2', stuage = %3, identify = '%4', tel = '%5', enroll_time = '%6', leave_time = '%7', scondition = '%8', stu_text = '%9' where stuaccount = '%10'")
            .arg(stu->name).arg(stu->sex).arg(stu->age).arg(stu->identify).arg(stu->tel).arg(stu->enroll_time).arg(stu->leave_time).arg(stu->scondition).arg(stu->text).arg(stu->account);
    qDebug()<<str;
    bool ret = query->exec(str);
    return ret;
}

bool My_Sql::addheal(my_heal *heal)
{
    query = new QSqlQuery;
    QString str = QString("insert into healthInfo value('%1', '%2', '%3', %4, '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13')")
            .arg(heal->stuaccount).arg(heal->stuname).arg(heal->height).arg(heal->weight).arg(heal->differentiate).arg(heal->left_sight).arg(heal->right_sight)
            .arg(heal->left_ear).arg(heal->right_ear).arg(heal->legs).arg(heal->pressure).arg(heal->history).arg(heal->h_text);
    bool ret = query->exec(str);
    return ret;
}

bool My_Sql::updateheal(my_heal *heal)
{
    query = new QSqlQuery;
    QString str = QString("select * from healthInfo where stuaccount = '%1'").arg(heal->stuaccount);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    str = QString("update healthInfo set stuname = '%1', height = '%2', weight = '%3', differentiate = '%4', left_sight = '%5', right_sight = '%6', left_ear = '%7', right_ear = '%8', legs = '%9', pressure = '%10', history = '%11', h_text = '%12' where stuaccount = '%13'")
            .arg(heal->stuname).arg(heal->height).arg(heal->weight).arg(heal->differentiate).arg(heal->left_sight).arg(heal->right_sight)
            .arg(heal->left_ear).arg(heal->right_ear).arg(heal->legs).arg(heal->pressure).arg(heal->history).arg(heal->h_text).arg(heal->stuaccount);
    qDebug()<<str;
    bool ret = query->exec(str);
    qDebug()<<ret;
    return ret;
}

bool My_Sql::deleteheal(QString account)
{
    query = new QSqlQuery;
    QString str = QString("select * from healthInfo where stuaccount = '%1'").arg(account);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    str = QString("delete from healthInfo where stuaccount = '%1'").arg(account);
    query->exec(str);
    return true;
}

bool My_Sql::addgrade(my_grade *grad)
{
    query = new QSqlQuery;
    QString str = QString("insert into gradeInfo value('%1', %2, %3, %4, %5)")
            .arg(grad->stuaccount).arg(grad->classid).arg(grad->lasttime).arg(grad->times).arg(grad->grade);
    qDebug()<<str;
    bool ret = query->exec(str);
    return ret;
}

bool My_Sql::updategrade(my_grade *grad)
{
    query = new QSqlQuery;
    QString str = QString("select * from gradeInfo where stuaccount = '%1'").arg(grad->stuaccount);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    str = QString("update gradeInfo set classid = '%1', lasttime = %2, times = %3, grade = %4 where stuaccount = '%5'")
            .arg(grad->classid).arg(grad->lasttime).arg(grad->times).arg(grad->grade).arg(grad->stuaccount);

    qDebug()<<str;
    bool ret = query->exec(str);
    return ret;
}

bool My_Sql::deletegrade(QString account)
{
    query = new QSqlQuery;
    QString str = QString("select * from gradeInfo where stuaccount = '%1'").arg(account);
    query->exec(str);
    query->last();
    int record = query->at() + 1;
    if(record == 0)
    {
        return false;
    }
    str = QString("delete from gradeInfo where stuaccount = '%1'").arg(account);
    query->exec(str);
    return true;
}

```

## 数据保护
#### 防止用户直接操作数据库
- 用户在登录时需要输入用户名和密码，才能进行操作；
- 若用户忘记密码，可通过登录页面验证身份证号重置密码；
- 一般用户（学生）只可修改密码，仅管理员才能进行用户的增删查改操作；
- 一般用户用户只能用账号登录，通过应用软件访问数据，而没有其他途径可以操作数据库。
#### 用户帐号密码的加密
- 对用户账号的密码进行加密处理，确保任何地方都不会出现明文；
- 可增加密码难易度检测提醒。
#### 角色与权限
![1](https://img-blog.csdnimg.cn/20200205203551549.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
## 数据优化
![1](https://img-blog.csdnimg.cn/20200205204039466.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
## 系统截图
![1](https://img-blog.csdnimg.cn/2020020520434858.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
![3](https://img-blog.csdnimg.cn/20200205204740283.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
![2](https://img-blog.csdnimg.cn/20200205204409245.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
![3](https://img-blog.csdnimg.cn/20200205204425697.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NsZWFubGlp,size_16,color_FFFFFF,t_70)
## 项目总结
- 本项目舍弃了传统的Web开发，剑走偏锋，改用Qt接口尝试，实际上存在一定的局限性；在数据库方面，目前仅实现了基本的增删查改功能，UI方面也尚未优化；
- 数据库的前期设计工作较为繁琐，但熟练了之后还是能较快的上手；
- 作为数据库课设中最简单的项目，搭建一个XX信息管理系统对于刚入门的同学来说练手再好不过，希望本文能给一些**不会Java但想动手试试搭数据库的朋友**提供帮助；