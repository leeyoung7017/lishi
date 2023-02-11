#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include <QDebug>
#include <stdint.h>
#include <QByteArray>



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

    uint16_t crc16(QByteArray buf, int len);
signals:

public slots:

private:

};

#endif // PROTOCOL_H
