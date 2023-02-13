#include "gv.h"
#include "scancodegun.h"
#include <QDebug>

ScanCodeGun::ScanCodeGun(QObject *parent) : QObject(parent)
{

}


//开始扫描与结束扫描
QByteArray ScanCodeGun::Scan_Decode_Start(void)
{
    QByteArray data;
    data.append(0x16);
    data.append(0x54);
    data.append(0x0D);
    qDebug() << data;
    return data;
}

QByteArray ScanCodeGun::Scan_Decode_End(void)
{
    QByteArray data;
    data.append(0x16);
    data.append(0x55);
    data.append(0x0D);
    qDebug() << data;
    return data;
}



//扫码枪的配置
QByteArray ScanCodeGun::Scan_Protocol(QString str)
{
    QByteArray data;
    data.append(0x16);
    data.append(0x4d);
    data.append(0x0d);
    for(int i=0;i<str.size();i++)
    {
        data.append(str[i].toLatin1());
    }
    data.append(0x2e);
    qDebug() << data;
    return data;
}


