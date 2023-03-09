#include "mythread.h"
#include "file.h"
#include "sqlite.h"
#include <processthreadsapi.h>
#include <QTimer>



infoThread::infoThread(QObject *parent) : QObject(parent)
{

}

void infoThread::infoInit()
{
    QStringList name;
#ifdef CSV
    //信息读取
    csv = new file();
    //csv文件读取，命名各个电机
    name = csv->motorRead(MOTORPATH);
#endif

#ifdef SQL
    //信息读取
    sql = new sqlite();
    //数据库读取，命名各个电机
    name = sql->getMotor(db);
#endif

    for(int i=0;i<MOTORNUM;i++)
    {
        MotorName[i] = name.at(i);//电机名导入结构体
    }
    emit motornameinit();   //电机名称初始化
}

void infoThread::infoStore(QString str)
{
//    flag_scan_tube = 1;
#ifdef SQL
    //将数据导入到数据库中
    if(flag_scan_tube)
    {
        flag_scan_tube = 0;
        sql->changeTubesInfo_xy(db,str,loc.x,loc.y);//试管的位置
        //试管的位置需要确认
    }
    if(flag_scan_slide)
    {
        flag_scan_slide = 0;
        sql->changeSlidesInfo_xy(db,str,loc.x,loc.y);
        //玻片的位置主要是根据x，y轴进行分析。
    }
#endif
#ifdef CSV
    //将数据导入csv文件中
    if(flag_scan_tube)
    {
        flag_scan_tube = 0;
        db_loc[0].tubes_info = str;
        csv->informationStore(INFORMATIONPATH, db_loc);//将结构体中数据保存至文件中
    }
    if(flag_scan_slide)
    {
        flag_scan_slide = 0;
        db_loc[getIndexSildeFromxy(INFORMATIONPATH,loc)].slide_info = str; //根据坐标设置
        csv->informationStore(INFORMATIONPATH, db_loc);//将结构体中数据保存至文件中
    }
#endif

}

void infoThread::motorStore()
{
    #ifdef CSV
    //电机名保存
    csv->motorStore(MOTORPATH);
    #endif
    #ifdef SQL
    //电机名保存
    sql->changeMotor(db);
    #endif
}

int infoThread::getIndexSildeFromxy(QString path,location loc)
{
    int index = 0;
    uint32_t x = loc.x;
    uint32_t y = loc.y;

    for(int i=0;i<TESTNUM;i++)
    {
        if(x == db_loc[i].slides_loc.x && y == db_loc[i].slides_loc.y)
        {
            index = i;
        }
    }
    return index;
}

int infoThread::getIndexTubeFromxy(QString path,location loc)
{
    int index = 0;
    uint32_t x = loc.x;
    uint32_t y = loc.y;

    for(int i=0;i<TESTNUM;i++)
    {
        if(x == db_loc[i].tubes_loc.x && y == db_loc[i].tubes_loc.y)
        {
            index = i;
        }
    }
    return index;
}


Timer::Timer(QObject *parent) : QObject(parent)
{

}

void Timer::TimerStart(int tim)
{
    timer = new QTimer();
    timer->setInterval(tim);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start();
}

void Timer::onTimeout()
{
//    qDebug() << "Timeout";
    timer->stop();
    delete timer;
}
