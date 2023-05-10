#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
#include "gv.h"
#include <QDateTime>
#include <QTextEdit>

#define LOGPATH "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_1\\log.txt"
#define WRITE 1
#define READ  0

class file : public QObject
{
    Q_OBJECT
public:
    explicit file(QObject *parent = nullptr);
    void Init(void);
    QString info_write(db_struct *loc);//结构体中数据整理成字符串
    void informationInit(QString path);//文件中读取信息到结构体中
    void informationStore(QString path, db_struct *loc);//将结构体中数据保存至文件中
    QStringList motorRead(QString path);
    void motorStore(QString path);
    QString file_read(QString path);//读取文件数据
    void file_write(QString path,QString name);//将字符串写入文件

    void logInit();
    void logWriteUI(QTextEdit *edit);
    void logWrite(int flag, QByteArray data, QTextEdit *edit);
signals:

};

#endif // FILE_H
