#include "ini.h"

void passwd_changed(QString str)
{
    QSettings *configIniWrite = new QSettings("passwd.ini", QSettings::IniFormat);
    str = passwd_key_codec(str);
    configIniWrite->setValue("/serial/passwd",str);
    delete configIniWrite;
}

bool passwd_cmp(QString str)
{
    QSettings *configIniRead = new QSettings("passwd.ini", QSettings::IniFormat);
    QString passwd = configIniRead->value("/serial/passwd").toString();
    passwd = passwd_key_codec(passwd);
    delete configIniRead;
    if(str == passwd) return true;
    else return false;
}


QString passwd_key_codec(QString str, QChar key)
{
    int len = str.length();
    for(int i=0;i<len;i++)
        str[i] = str[i].toLatin1() ^ key.toLatin1();
    return str;
}


QString passwd_codec(QString str,bool flag)
{

    if(flag)
    {
        return QCryptographicHash::hash(str.toLatin1(), QCryptographicHash::Md4);
    }
    else {
        QCryptographicHash hash(QCryptographicHash::Md4);
        hash.addData(str.toUtf8());
        return hash.result();
    }
}


QStringList file_op(QString path)
{
    QStringList name;
    QFile inFile(path);
    if (inFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inFile);
        in.setCodec("GBK"); // 设置文件的编码格式为GBK
        QString line = in.readLine();
        for(int i=0;i<line.size();i++)
            name = line.split(",");/*列数据*/
    }

    inFile.close();
    return name;
}

void file_write(QString path,QString name)
{
    QFile inFile(path);
    if (inFile.open(QIODevice::WriteOnly))
    {
        inFile.write(name.toLocal8Bit());
    }

    inFile.close();
}

