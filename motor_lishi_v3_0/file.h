#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
#include "sqlite.h"



class file : public QObject
{
    Q_OBJECT
public:
    explicit file(QObject *parent = nullptr);
    void Init(void);
    QString info_write(db_struct *db_loc);//结构体中数据整理成字符串
    void informationInit(QString path);//文件中读取信息到结构体中
    void informationStore(QString path, db_struct *db_loc);//将结构体中数据保存至文件中
    QStringList motorRead(QString path);
    void motorStore(QList<QCheckBox *> motor_list, QString path);
    QString file_read(QString path);//读取文件数据
    void file_write(QString path,QString name);//将字符串写入文件

signals:

};

#endif // FILE_H
