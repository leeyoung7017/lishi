#include "protocol.h"
#include "crc16.h"

Protocol::Protocol(QObject *parent) : QObject(parent)
{

}

QByteArray Protocol::Protocol_Config(uint8_t motornum,uint8_t dir,uint16_t step)
{
    uint16_t CRC16 = 0;
    QByteArray data;
    data[0] = 0x55;
    data[1] = 0xAA;
    data[2] = motornum;
    data[3] = dir;
    data[4] = (step>>8)&0xff;
    data[5] = step&0xff;
    CRC16 = crc16(data, 6);
    data[6] = (CRC16>>8)&0xff;
    data[7] = CRC16&0xff;
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
