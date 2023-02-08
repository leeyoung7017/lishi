#include "protocol.h"
#include "crc16.h"

Protocol::Protocol(QObject *parent) : QObject(parent)
{

}

QByteArray Protocol::Scan_Decode(char status)
{
    QByteArray data;
    data.append(0x16);
    data.append(status);
    data.append(0x0D);
    return data;
}




QByteArray Protocol::Scan_Protocol(QString str)
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

//55AA COMMAND 电机号
QByteArray Protocol::Protocol_Config(uint8_t command, uint32_t motornum, uint32_t step)
{
    uint16_t CRC16 = 0;
    QByteArray data;
    data.resize(13);
    data[0] = 0x55;
    data[1] = 0xAA;

    data[2] = command;

    data[3] = (motornum>>24)&0xff;
    data[4] = (motornum>>16)&0xff;
    data[5] = (motornum>>8)&0xff;
    data[6] = motornum&0xff;

    data[7] = (step>>24)&0xff;
    data[8] =   (step>>16)&0xff;
    data[9] = (step>>8)&0xff;
    data[10] = step&0xff;

    CRC16 = crc16(data, 9);
    data[11] = (CRC16>>8)&0xff;
    data[12] = CRC16&0xff;



//    data[2] = command;
//    data[3] = motornum;
//    data[4] = dir;
//    data[5] = (step>>8)&0xff;
//    data[6] = step&0xff;
//    data[7] = (speed>>8)&0xff;
//    data[8] = speed&0xff;
//    data[9] = run;
//    CRC16 = crc16(data, 9);
//    data[10] = (CRC16>>8)&0xff;
//    data[11] = CRC16&0xff;
    return data;
}

QByteArray Protocol::Protocol_Stop(void)
{
//    QByteArray data = Protocol_Config(0x01,0, 0, 0, 0, 0);

//    55 AA 54 AA
    QByteArray data;
    data.append(0x55);
    data.append(0xAA);
    data.append(0x54);
    data.append(0xAA);

    return data;
}

QByteArray Protocol::Protocol_Continue(void)
{
//    55 AA 54 BB
//    QByteArray data = Protocol_Config(0x02,0, 0, 0, 0, 0);


    QByteArray data;
    data.append(0x55);
    data.append(0xAA);
    data.append(0x54);
    data.append(0xBB);

    return data;
}

QByteArray Protocol::Protocol_Reset(void)
{
//    QByteArray data = Protocol_Config(0x03,0, 0, 0, 0, 0);

    QByteArray data;
    data.append(0x55);
    data.append(0xAA);
    data.append(0x54);
    data.append(0xCC);
    return data;
}

/*
 *     typedef enum{
        MOTOR0 = 0,
        MOTOR1,
        MOTOR2,
        MOTOR3,
        MOTOR4,
        MOTOR5,
        MOTOR6,
        MOTOR7
    }MOTOR;
    typedef enum{
        COUNTERCLOCKWISE = 0,//逆时针
        CLOCKWISE//顺时针
    }DIR;
*/
