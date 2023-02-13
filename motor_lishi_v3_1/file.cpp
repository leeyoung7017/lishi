#include "file.h"
#include "gv.h"

file::file(QObject *parent) : QObject(parent)
{
    Init();
}


void file::Init()
{
    informationInit(INFORMATIONPATH);
}

//将数据从文件中读取
void file::informationInit(QString path)
{
    QStringList name;
    QStringList info[TESTNUM];
    QFile inFile(path);
    if (inFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inFile);
        in.setCodec("GBK"); // 设置文件的编码格式为GBK
        QString line = in.readAll();
        for(int i=0;i<line.size();i++)
            name = line.split("\n");/*列数据*/
        int j=name.size();
        for(int k=0;k<j;k++)
            for(int i=0;i<name.at(k).size();i++)
            {
                info[k] = name.at(k).split(",");
            }
    }
    for(int i=0;i<TESTNUM;i++)
    {
        db_loc[i].ID = info[i].at(0).toUInt();
        db_loc[i].slide_info = info[i].at(1);
        db_loc[i].tubes_info =info[i].at(2);
        db_loc[i].tubes_loc.x = info[i].at(5).toUInt();
        db_loc[i].tubes_loc.y =info[i].at(6).toUInt();
        db_loc[i].slides_loc.x =info[i].at(3).toUInt();
        db_loc[i].slides_loc.y = info[i].at(4).toUInt();
        db_loc[i].needles_loc.x = info[i].at(7).toUInt();
        db_loc[i].needles_loc.y = info[i].at(8).toUInt();
        db_loc[i].needle_rm_loc.x = info[i].at(9).toUInt();
        db_loc[i].needle_rm_loc.y = info[i].at(10).toUInt();
    }

}

void file::informationStore(QString path, db_struct *db_loc)
{
    QString name = info_write(db_loc);
    file_write(path, name);
}

QString file::file_read(QString path)
{
    QString name;
    QFile inFile(path);
    if (inFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inFile);
        in.setCodec("GBK"); // 设置文件的编码格式为GBK
        name  = in.readAll();
    }
    inFile.close();
    return name;
}

//整理csv文件的字符串
QString file::info_write(db_struct* db_loc)
{
    QString name;
    for(int i=0;i<TESTNUM;i++)
    {
        name += QString::number(db_loc[i].ID);
        name += ",";
        name += db_loc[i].slide_info;
        name += ",";
        name += db_loc[i].tubes_info;
        name += ",";
        name += QString::number(db_loc[i].slides_loc.x);
        name += ",";
        name += QString::number(db_loc[i].slides_loc.y);
        name += ",";
        name += QString::number(db_loc[i].tubes_loc.x);
        name += ",";
        name += QString::number(db_loc[i].tubes_loc.y);
        name += ",";
        name += QString::number(db_loc[i].needles_loc.x);
        name += ",";
        name += QString::number(db_loc[i].needles_loc.y);
        name += ",";
        name += QString::number(db_loc[i].needle_rm_loc.x);
        name += ",";
        name += QString::number(db_loc[i].needle_rm_loc.y);
        name += "\n";
    }
    return name;
}


void file::file_write(QString path,QString name)
{
    QFile inFile(path);
    if (inFile.open(QIODevice::WriteOnly))
    {
        inFile.write(name.toLocal8Bit());
    }

    inFile.close();
}


void file::motorStore(QString path)
{
    QString name;

    for(int i=0;i<MOTORNUM;i++)
    {
        name += (MotorName[i]+'\n');
    }

    file_write(path,name);
}

QStringList file::motorRead(QString path)
{
    QStringList namelist;
    QString name = file_read(path);
    for(int i=0;i<name.size();i++)
    {
        namelist = name.split("\n");
    }
    return namelist;

}


