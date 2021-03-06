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

/* 创建数据库操作 */
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



