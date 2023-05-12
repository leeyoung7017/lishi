#ifndef SCANCODEGUN_H
#define SCANCODEGUN_H

#include <QObject>

#define RST                 "%%%DEF"
#define VERSION             "%%%VER"
#define SCANMODE_KEY        "%0401D01%"
#define SCANMODE_MASTER     "%0401D05%"
#define SCANMODE_AUTOSENCE  "%0401D07%"
#define LIGHTING_CLOSE      "%9001D00%"
#define LIGHTING_OPEN       "%9001D01%"
#define LIGHTING_AUTO       "%9001D03%"
#define END                 "%END%"
#define DECODE_START        0x54
#define DECODE_END          0x55

class ScanCodeGun : public QObject
{
    Q_OBJECT
public:
    explicit ScanCodeGun(QObject *parent = nullptr);

    QByteArray Scan_Decode(char status);
    QByteArray Scan_Protocol(QString str);  //扫码枪配置
    QByteArray Scan_Decode_End();           //扫描开始
    QByteArray Scan_Decode_Start();         //扫描结束
signals:

};

#endif // SCANCODEGUN_H
