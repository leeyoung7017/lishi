#ifndef SQLITE_H
#define SQLITE_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "gv.h"

class sqlite : public QObject
{
    Q_OBJECT
public:
    explicit sqlite(QObject *parent = nullptr);
    void Init();

    void clearData(QSqlDatabase db);//清空表格
    void addData(QSqlDatabase db, QString tubes, QString slides, QString name);//添加数据
    void addTube(QSqlDatabase db, QString tubes);//添加数据
    void addSlide(QSqlDatabase db, QString tubes, QString slides);//添加数据
    void rmData(QSqlDatabase db, QString name);//根据姓名添加数据
    uint32_t getCount(QSqlDatabase db);//获取数据总数

    QStringList getMotor(QSqlDatabase db);
    void changeMotor(QSqlDatabase db, int num, QString name);  //修改num对应的电机号的名称
    void clearMotor(QSqlDatabase db);
    void informationInit(QSqlDatabase db);
    void changeSlidesInfo_Tubes(QSqlDatabase db, QString slides_info, QString tubes_info);    //根据试管信息修改玻片信息
    void changeTubesInfo_Slides(QSqlDatabase db, QString tubes_info, QString slides_info);       //根据玻片信息修改试管信息
    void changeTubesInfo_xy(QSqlDatabase db, QString tubes_info, uint32_t tubes_x, uint32_t tubes_y);           //根据试管坐标修改试管信息
    void changeSlidesInfo_xy(QSqlDatabase db, QString slides_info, uint32_t slides_x, uint32_t slides_y);       //根据玻片坐标修改玻片信息
signals:

};

#endif // SQLITE_H
