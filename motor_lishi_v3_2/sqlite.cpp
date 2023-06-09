#include "gv.h"
#include "sqlite.h"
#include <QDir>
#include <QSqlError>
sqlite::sqlite(QObject *parent) : QObject(parent)
{
    Init();
}

void sqlite::Init()
{
    int flag_exist = 1;
    QFileInfo fileInfo(DATABASEPATH);
    if(!fileInfo.isFile()) flag_exist = 0;

    if(QSqlDatabase::drivers().isEmpty()) //判断数据库的驱动是否为空
        QMessageLogger().debug() << "No database drivers found";

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASEPATH);

    if(!db.open())
    {
        QSqlError error = db.lastError();
        QMessageLogger().debug() << error.databaseText();
        QMessageLogger().debug() << error.driverText();
    }
    else
     QMessageLogger().debug() << "db open!"<<QDir::currentPath();

    if(!flag_exist)
    {
        createTable();
    }

//     informationInit(db);       //获取坐标与条形码信息

}

void sqlite::createTable()
{
    QSqlQuery q(db);
    QString str = "create table information (                                                 \
                                            ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,    \
                                            slides_info text,                                 \
                                            tubes_info text,                                  \
                                            scanslides_x integer,                             \
                                            scanslides_y integer,                             \
                                            tubes_x integer,                                  \
                                            tubes_y integer,                                  \
                                            needles_x integer,                                \
                                            needles_y integer,                                \
                                            needle_rm_x integer,                              \
                                            needle_rm_y integer,                              \
                                            tubes integer,                                    \
                                            needle_get_x integer,                             \
                                            needle_get_y integer)";
    q.prepare(str);
    q.exec();
    q.exec("INSERT INTO information VALUES (0, NULL, NULL, NULL,NULL, NULL,NULL, NULL,NULL, NULL,NULL, NULL,NULL, NULL)");
    for(int i=0;i<TESTNUM-1;i++)
    {
         q.exec("INSERT INTO information VALUES (NULL, NULL, NULL, NULL,NULL, NULL,NULL, NULL,NULL, NULL,NULL, NULL,NULL, NULL)");
    }

    str = "create table motor(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name text)";
    q.prepare(str);
    q.exec();
    str = QString("INSERT INTO motor VALUES (0,'%1')").arg("motor20");
    q.exec(str);
    for(int i=0;i<MOTORNUM-1;i++)
    {
        QString name = "motor"+QString::number(i+1);
        str = QString("INSERT INTO motor VALUES (NULL,'%1')").arg(name);
        q.exec(str);
    }
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

        db_loc[i].tubes_loc.y = q.value("tubes").toUInt();

        db_loc[i].scanslides_loc.x = q.value("scanslides_x").toUInt();
        db_loc[i].scanslides_loc.y = q.value("scanslides_y").toUInt();

        db_loc[i].needles_loc.x = q.value("needles_x").toUInt();
        db_loc[i].needles_loc.y = q.value("needles_y").toUInt();

        db_loc[i].needle_rm_loc.x = q.value("needle_rm_x").toUInt();
        db_loc[i].needle_rm_loc.y = q.value("needle_rm_y").toUInt();

        db_loc[i].needle_get_loc.x = q.value("needle_get_x").toUInt();
        db_loc[i].needle_get_loc.y = q.value("needle_get_y").toUInt();
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
    static int ID = 0;
//    for(int i=0;i<TESTNUM;i++)
//    {
//        if(db_loc[i].scanslides_loc.x == slides_x && db_loc[i].scanslides_loc.y == slides_y)
//        {
//            ID = i;
//            break;
//        }
//    }


    db_loc[ID].slide_info = slides_info;
    QString str = QString("update information set slides_info = '%1' where ID = '%2'").arg(slides_info).arg(ID);
    QSqlQuery q(db);
    q.exec(str);
    ID++;
    if(ID==64)ID=0;
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
//根据坐标添加条形码信息，并写入全局结构体中
void sqlite::changeTubesxy_ID(QSqlDatabase db, uint32_t ID, uint32_t tubes_x, uint32_t tubes_y)
{
    QString str = QString("update information set tubes_x = '%1' where ID = '%2'").arg(tubes_x).arg(ID);
    QSqlQuery q(db);
    q.exec(str);

    str = QString("update information set tubes_y = '%1' where ID = '%2'").arg(tubes_y).arg(ID);
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

void sqlite::changeMotor(QSqlDatabase db)
{
    QSqlQuery q(db);
    for(int i=0;i<MOTORNUM;i++)
    {
        QString str = QString("update motor set name = '%1' where id=%2").arg(MotorName[i]).arg(i);
        q.exec(str);
    }

}

