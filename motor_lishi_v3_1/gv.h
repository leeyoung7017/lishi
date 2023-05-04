#ifndef GV_H
#define GV_H

#include <stdint.h>
#include <QtGlobal>
#include <QSqlDatabase>
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


#define MOTORPATH "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_1\\files\\QCheckBox.csv"
//#define MOTORPATH           ":/files/QCheckBox.csv"
#define INFORMATIONPATH    "G:\\USER\\Project\\FilmProduct\\lishi\\motor_lishi_v3_1\\files\\information.csv"
//":/files/information.csv"
#define DATABASEPATH             "G:\\USER\\Project\\FilmProduct\\lishi\\DataBase\\leeyoung7017.db"
// ":/../DataBase/leeyoung7017.db"


typedef struct{
    uint32_t x;
    uint32_t y;
    uint32_t z;
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

typedef struct
{
    uint32_t x;
    uint32_t y;
}needle_rm_location;

typedef struct
{
    uint32_t ID;
    QString slide_info;
    QString tubes_info;
    slides_location slides_loc;
    tubes_location tubes_loc;
    needles_location needles_loc;
    needle_rm_location needle_rm_loc;

}db_struct;


extern location loc;//坐标位置
extern db_struct db_loc[TESTNUM];//数据库中坐标信息
extern QString MotorName[MOTORNUM];

extern uint8_t flag_continue;  //继续指令反馈标志位
extern uint8_t flag_reset;     //复位指令反馈标志位
extern uint8_t flag_stop;      //暂停指令反馈标志位
extern uint8_t flag_run;       //运动指令反馈标志位

extern uint8_t flag_scan_tube;  //试管扫码枪扫描标志位
extern uint8_t flag_scan_slide; //载波片扫码枪扫描标志位

extern QSqlDatabase db;

extern uint32_t motor_g;
extern uint32_t step_g;

#endif // GV_H
//全局变量的设置
