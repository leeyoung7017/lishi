#ifndef GV_H
#define GV_H

#include <stdint.h>
#include <QtGlobal>
#include <QSqlDatabase>
#include <QMap>
#include <scancodegun.h>
#include <QSerialPort>
//#include "ini.h"
//#include "process.h"
//#include "scancodegun.h"
//#include "serial.h"
//#include "sqlite.h"
//#include "file.h"


//#define CSV
#define SQL

#define MOTORNUM   (20)
#define TESTNUM 64


// #define MOTORPATH    "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_2\\files\\QCheckBox.csv"
// #define INFORMATIONPATH    "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_2\\files\\information.csv"
#define LOGPATH         "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_2\\log\\"
#define DATABASEPATH             "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_2\\db\\leeyoung7017.db"

#define MOTORPATH           ":/files/QCheckBox.csv"
#define INFORMATIONPATH      ":/files/information.csv"
//#define DATABASEPATH          "./leeyoung.db"
//#define LOGPATH             ":/log/log.txt"

typedef struct{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t tube;
}location;

typedef struct{
    uint32_t x;
    uint32_t y;
}slides_location;

typedef struct{
    uint32_t x;
    uint32_t y;
}tubes_location;

typedef struct{
    uint32_t x;
    uint32_t y;
}needles_location;

typedef struct{
    uint32_t x;
    uint32_t y;
}needles_get_location;

typedef struct
{
    uint32_t x;
    uint32_t y;
}needle_rm_location;

typedef struct
{
    uint32_t ID;                            //编码ID号
    QString slide_info;                     //玻片信息
    QString tubes_info;                     //试管信息
    slides_location scanslides_loc;         //扫码玻片坐标
    tubes_location tubes_loc;               //试管坐标
    needles_location needles_loc;           //滴液坐标
    needle_rm_location needle_rm_loc;       //弃针坐标
    needles_get_location needle_get_loc;    //取针坐标
}db_struct;

typedef struct{
    QString com;
    QSerialPort::BaudRate baud;
    QSerialPort::DataBits data;
    QSerialPort::StopBits stop;
    QSerialPort::Parity parity;
}SerialStruct;

extern SerialStruct serialstruct;

//功能码cmd
#define CMD_MOTORY      0x49
#define CMD_MOTORXZ     0x60
#define CMD_PL          0x47
#define CMD_YY          0x45
#define CMD_CQ          0x39
#define CMD_STOP        0x54
#define CMD_CONTINUE    0xAA
#define CMD_RESET       0x77
#define FB_OK0           0xFF
#define FB_OK1           0xAA
#define FB_RESET0        0x99
#define FB_RESET1        0x10
#define FB_CRC0          0xCC
#define FB_CRC1          0xDD


extern location loc;//坐标位置
extern db_struct db_loc[TESTNUM];//数据库中坐标信息
extern QString MotorName[MOTORNUM];

extern uint8_t flag_continue;  //继续指令反馈标志位
extern uint8_t flag_reset;     //复位指令反馈标志位
extern uint8_t flag_stop;      //暂停指令反馈标志位
extern uint8_t flag_run;       //运动指令反馈标志位
extern uint8_t flag_crc;       //crc指令错误标志位
extern uint8_t flag_dialog;    //日志窗体开启标志位

extern uint8_t flag_scan_tube;  //试管扫码枪扫描标志位
extern uint8_t flag_scan_slide; //载波片扫码枪扫描标志位

extern QSqlDatabase db;

extern uint32_t motor_g;
extern uint32_t step_g;

extern uint8_t tubes_times;
extern QMap<QString, int> slides_map;
extern QMap<QString, tubes_location> tubes_map;

extern tubes_location tube_loc[TESTNUM];

extern ScanCodeGun *scan;
extern QString loc_str;//发送的坐标所平行轴

extern uint32_t step;//坐标

#endif // GV_H
//全局变量的设置
