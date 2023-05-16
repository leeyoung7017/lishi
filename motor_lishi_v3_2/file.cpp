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
        db_loc[i].scanslides_loc.x =info[i].at(3).toUInt();
        db_loc[i].scanslides_loc.y = info[i].at(4).toUInt();
        db_loc[i].needles_loc.x = info[i].at(7).toUInt();
        db_loc[i].needles_loc.y = info[i].at(8).toUInt();
        db_loc[i].needle_rm_loc.x = info[i].at(9).toUInt();
        db_loc[i].needle_rm_loc.y = info[i].at(10).toUInt();
    }

}

void file::informationStore(QString path, db_struct *loc)
{
    QString name = info_write(loc);
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
QString file::info_write(db_struct* loc)
{
    QString name;
    for(int i=0;i<TESTNUM;i++)
    {
        name += QString::number(loc[i].ID);
        name += ",";
        name += loc[i].slide_info;
        name += ",";
        name += loc[i].tubes_info;
        name += ",";
        name += QString::number(loc[i].scanslides_loc.x);
        name += ",";
        name += QString::number(loc[i].scanslides_loc.y);
        name += ",";
        name += QString::number(loc[i].tubes_loc.x);
        name += ",";
        name += QString::number(loc[i].tubes_loc.y);
        name += ",";
        name += QString::number(loc[i].needles_loc.x);
        name += ",";
        name += QString::number(loc[i].needles_loc.y);
        name += ",";
        name += QString::number(loc[i].needle_rm_loc.x);
        name += ",";
        name += QString::number(loc[i].needle_rm_loc.y);
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

void file::logInit()
{
    QString filepath = LOGPATH;
    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    file.close();
}

void file::logWrite(int flag, QByteArray data, QTextEdit *lineedit)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QLocale locale(QLocale::English);
    QString formattedDateTime = locale.toString(currentDateTime, "ddd MMMM d yyyy hh:mm:ss AP");
    QFile file(LOGPATH);
    QString str;
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        // 打开文件失败
        qDebug() << "open file error";
        return ;
    }
    QTextStream stream(&file);
    if(flag)
        str = "[" + formattedDateTime + "] " + "[Write] "+ data.toHex(' ');
    else
        str = "[" + formattedDateTime + "] " + "[Read] "+ data.toHex(' ');

    stream << str << endl;

    // 关闭文件
    file.close();

    logWriteUI(lineedit);

}

void file::logWriteUI(QTextEdit *edit)
{
    QFile file(LOGPATH);
    QString str;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 打开文件失败
        return ;
    }

    QString content = QString(file.readAll());
    edit->setText(content);
    file.close();
}



