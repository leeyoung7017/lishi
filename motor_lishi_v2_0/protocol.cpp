#include "protocol.h"
#include "crc16.h"

Protocol::Protocol(QObject *parent) : QObject(parent)
{

}

QByteArray Protocol::Protocol_Config(uint8_t command,uint8_t motornum,uint8_t dir,uint16_t step,uint16_t speed,uint16_t run)
{
//    uint16_t CRC16 = 0;
    QByteArray data;
    data[0] = 0x55;
    data[1] = 0xAA;

    data[2] = 0x49;
    data[3] = 0x60;
    data[4] = (step>>8)&0xff;
    data[5] = step&0xff;
    data[6] = motornum;
    data[7] = dir;
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
