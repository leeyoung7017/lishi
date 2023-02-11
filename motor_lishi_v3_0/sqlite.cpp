#include "sqlite.h"
#include "sqlite.h"

sqlite::sqlite(QObject *parent) : QObject(parent)
{
    Init();
}

void sqlite::Init()
{
     if(QSqlDatabase::drivers().isEmpty()) //判断数据库的驱动是否为空
         qDebug() << "No database drivers found";

     db.setDatabaseName("F:\\Project\\motor_lishi\\DataBase\\leeyoung7017.db");
     if(!db.open())
         qDebug() << "db not open";

     informationInit(db);       //获取坐标与条形码信息

//     changeSlidesInfo_Tubes(db, "slides", "tubes_info");
//     changeTubesInfo_Slides(db, "tubes", "slides");

//    addData(db,"1234567890","0987654321","lishuyang");
//    rmData(db,"lishuyang");
//    getCount(db);
//    clearData(db);
}


void sqlite::informationInit(QSqlDatabase db)
{
    int i=0;
    QSqlQuery q(db);
    q.exec("select * from information");
    while(q.next())
    {
        db_loc[i].ID = q.value("ID").toInt();
        db_loc[i].slide_info = q.value("slides_info").toString();
        db_loc[i].tubes_info = q.value("tubes_info").toString();
        db_loc[i].tubes_loc.x = q.value("tubes_x").toUInt();
        db_loc[i].tubes_loc.y = q.value("tubes_y").toUInt();
        db_loc[i].slides_loc.x = q.value("slides_x").toUInt();
        db_loc[i].slides_loc.y = q.value("slides_y").toUInt();
        db_loc[i].needles_loc.x = q.value("needles_x").toUInt();
        db_loc[i].needles_loc.y = q.value("needles_y").toUInt();
        db_loc[i].needle_rm_loc.x = q.value("needle_rm_x").toUInt();
        db_loc[i].needle_rm_loc.y = q.value("needle_rm_y").toUInt();
        i++;
    }
}

//一般不用，用时需要修改
void sqlite::clearData(QSqlDatabase db)
{
    QSqlQuery q(db);
    q.exec("delete from information");
}

//一般不用，用时需要修改
void sqlite::addData(QSqlDatabase db,QString tubes,QString slides,QString name)
{
    QString str = QString("INSERT INTO information VALUES (NULL, '%1', '%2', '%3')")
            .arg(tubes)
            .arg(slides)
            .arg(name);
    QSqlQuery q(db);
    q.exec(str);
}

void sqlite::addTube(QSqlDatabase db, QString tubes)
{
    QString str = QString("INSERT INTO information VALUES (NULL, '%1', NULL, NULL)").arg(tubes);
    QSqlQuery q(db);
    q.exec(str);
}


//根据坐标添加条形码信息，并写入全局结构体中
void sqlite::changeSlidesInfo_xy(QSqlDatabase db, QString slides_info, uint32_t slides_x, uint32_t slides_y)
{
    int ID = 0;
    for(int i=0;i<TESTNUM;i++)
    {
        if(db_loc[i].slides_loc.x == slides_x && db_loc[i].slides_loc.y == slides_y)
        {
            ID = i;
            break;
        }
    }

    db_loc[ID].slide_info = slides_info;
    QString str = QString("update information set slides_info = '%1' where ID = '%2'").arg(slides_info).arg(ID);
    QSqlQuery q(db);
    q.exec(str);
}
void sqlite::changeSlidesInfo_Tubes(QSqlDatabase db, QString slides_info, QString tubes_info)
{
    for(int i=0;i<TESTNUM;i++)
    {
        if(db_loc[i].tubes_info == tubes_info)
        {
            db_loc[i].slide_info = slides_info;
            break;
        }
    }
    QString str = QString("update information set slides_info = '%1' where tubes_info = '%2'").arg(slides_info).arg(tubes_info);
    QSqlQuery q(db);
    q.exec(str);
}

//根据坐标添加条形码信息，并写入全局结构体中
void sqlite::changeTubesInfo_xy(QSqlDatabase db, QString tubes_info, uint32_t tubes_x, uint32_t tubes_y)
{
    int ID = 0;
    for(int i=0;i<TESTNUM;i++)
    {
        if(db_loc[i].tubes_loc.x == tubes_x && db_loc[i].tubes_loc.y == tubes_y)
        {
            ID = i;
            break;
        }
    }
    db_loc[ID].tubes_info = tubes_info;
    QString str = QString("update information set tubes_info = '%1' where ID = '%2'").arg(tubes_info).arg(ID);
    QSqlQuery q(db);
    q.exec(str);
}
void sqlite::changeTubesInfo_Slides(QSqlDatabase db, QString tubes_info, QString slides_info)
{
    for(int i=0;i<TESTNUM;i++)
    {
        if(db_loc[i].slide_info == slides_info)
        {
            db_loc[i].tubes_info = tubes_info;
            break;
        }
    }
    QString str = QString("update information set tubes_info = '%1' where slides_info = '%2'").arg(tubes_info).arg(slides_info);
    QSqlQuery q(db);
    q.exec(str);
}

void sqlite::addSlide(QSqlDatabase db, QString tubes, QString slides)
{
    QString str = QString("update information set slides = '%1' where tubes='%2'").arg(slides),arg(tubes);

    QSqlQuery q(db);
    q.exec(str);
}

void sqlite::rmData(QSqlDatabase db, QString  name)
{
    name = QString("delete from information where name = '%1'").arg(name);
    QSqlQuery q(db);
    q.exec(name);
}

uint32_t sqlite::getCount(QSqlDatabase db)
{
    uint32_t count;
    QSqlQuery q(db);
    q.exec("select count(id) from information");
    while(q.next())
    {
        count = q.value(0).toUInt();
//        qDebug() << count;
    }
    return count;
}

QStringList sqlite::getMotor(QSqlDatabase db)
{
    QStringList name;
    QSqlQuery q(db);
    QString str = QString("select * from motor");
    q.exec(str);
    while(q.next())
    {
        name.append(q.value("name").toString());
    }
    return name;
}

void sqlite::clearMotor(QSqlDatabase db)
{
    QSqlQuery q(db);
    q.exec("delete from motor");
}

void sqlite::changeMotor(QSqlDatabase db, int num, QString name)
{
    QSqlQuery q(db);
    QString str = QString("update motor set name = '%1' where id=%2").arg(name).arg(num);
    q.exec(str);
}

