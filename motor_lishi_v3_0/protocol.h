#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include <QDebug>


#define RST                 "%%%DEF"
#define VERSION             "%%%VER"
#define SCANMODE_KEY        "%0404D01%"
#define SCANMODE_MASTER     "%0404D05%"
#define SCANMODE_AUTOSENCE  "%0404D07%"
#define LIGHTING_CLOSE      "%0605D00%"
#define LIGHTING_OPEN       "%0605D01%"
#define LIGHTING_AUTO       "%0605D02%"
#define END                 "%END%"
#define DECODE_START        0x54
#define DECODE_END          0x55

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    QByteArray Scan_Protocol(QString str);
    QByteArray Scan_Decode(char status);

    QByteArray Protocol_Config(uint8_t command,uint32_t motornum,uint32_t step);
    QByteArray Protocol_Reset(void);
    QByteArray Protocol_Stop(void);
    QByteArray Protocol_Continue(void);
signals:

public slots:

private:

};

#endif // PROTOCOL_H
