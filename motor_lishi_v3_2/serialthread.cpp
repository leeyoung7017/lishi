#include "serialthread.h"
#include <QSerialPortInfo>

enum Except{ss,ssss};

//串口初始化并打开
static void Serial_Init(QSerialPort *serialport)
{
    serialport->setPortName(serialstruct.com);
    serialport->setBaudRate(serialstruct.baud);
    serialport->setDataBits(serialstruct.data);
    serialport->setParity(serialstruct.parity);
    serialport->setStopBits(serialstruct.stop);
    serialport->setFlowControl(QSerialPort::NoFlowControl);
}

SerialThread::SerialThread(QObject *parent) : QObject(parent)
{
//    QThread *sub = new QThread;
    SerialPort = new QSerialPort();
    QMessageLogger().debug() << "SerialPort current thread ID :" <<QThread::currentThreadId();
    connect(SerialPort,SIGNAL(readyRead()),this,SLOT(SerialReceive()));//串口打开，并绑定接收槽函数
}

void SerialThread::SerialClose()
{
    SerialPort->close();
}

void SerialThread::SerialOpen()
{
    QMessageLogger().debug() << "SerialPort current thread ID :" <<QThread::currentThreadId();
    if(SerialPort->isOpen())
        SerialPort->close();
    Serial_Init(SerialPort);
    if(!SerialPort->open(QIODevice::ReadWrite))
    {
        QMessageLogger().debug() << "serial open failed";
//        QMessageBox::critical(nullptr, "警告", "该串口已打开", QMessageBox::Yes|QMessageBox::No);
    }
}

void SerialThread::SerialReceive()
{
    QMessageBox Mbox;
    QByteArray data = nullptr;
    data = SerialPort->readAll();

    //       file->logWrite(READ,data,ui->log);
       if(data.size() < 2) return;
   if((uint8_t)(data.at(0))==0x55 && (uint8_t)data.at(1)==0xAA)
   {
       switch((uint8_t)data.at(2))
       {
           case FB_OK0:
               if((uint8_t)data.at(3)==FB_OK1)
               {
                   flag_run = 1;
                   QMessageLogger().debug() << "flag_run =" << flag_run;
               }
               break;
           case FB_RESET0:
               if((uint8_t)data.at(3) == (FB_RESET1))
               {
                   flag_reset= 1;
                   QMessageLogger().debug() << "flag_reset =" << flag_reset;
               }
               break;
           case FB_CRC0:
               if((uint8_t)data.at(3) == FB_CRC1)
               {
                   flag_crc = 1;
                   QMessageLogger().debug() << "thread flag_crc =" << flag_crc;
               }

               break;
           default:
               break;
       }

       data.append(flag_run | flag_crc << 2 | flag_reset << 1);
       if(flag_run)
       {
//            if()//判断是否为x,y,z轴的运动电机
           if(loc_str == "x")  loc.x = step;
           else if(loc_str == "y") loc.y = step;
           else if(loc_str == "z") loc.z = step;

//            if()//判断是否为试管运动电机
           if(loc_str == "tube")   loc.tube = step;

           flag_run = 0;
       }
       if(flag_stop)
       {
           flag_stop = 0;
       }
       if(flag_continue)
       {
           flag_continue = 0;
       }
       if(flag_reset)
       {
           //完成复位
           loc.x = 0;  loc.y = 0;  loc.z = 0;
           flag_reset = 0;
           qDebug() << "flag_reset";
       }
   }
   send(data,loc);


}

void SerialThread::SerialSend(QByteArray data)
{
    SerialPort->write(data);
}

ScanTubeThread::ScanTubeThread(QObject *parent) : QObject(parent)
{
//    QThread *sub = new QThread;
    ScanTubePort = new QSerialPort();
    QMessageLogger().debug() << "ScanTubePort current thread ID :" <<QThread::currentThreadId();
    connect(ScanTubePort,SIGNAL(readyRead()),this,SLOT(ScanTubeSerialReceive()));//串口打开，并绑定接收槽函数

}

void ScanTubeThread::ScanTubeClose()
{
    ScanTubePort->close();
}

void ScanTubeThread::ScanTubeOpen()
{
    QMessageLogger().debug() << "ScanTubePort current thread ID :" <<QThread::currentThreadId();
    if(ScanTubePort->isOpen())
        ScanTubePort->close();
    Serial_Init(ScanTubePort);
    if(!ScanTubePort->open(QIODevice::ReadWrite))
    {
        QMessageLogger().debug() << "Tube serial open failed";
//        QMessageBox::critical(nullptr, "警告", "该串口已打开", QMessageBox::Yes|QMessageBox::No);
    }
    ScanTubePort->setBaudRate(QSerialPort::Baud115200);
}

void ScanTubeThread::ScanTubeSerialReceive()
{
    QByteArray data;
    data = scan->Scan_Decode_End();
    ScanTubePort->write(data);
    QString str_tube = ScanTubePort->readAll();
    if(str_tube.size()<2) return;
    flag_scan_tube = 1;
    //将数据记录在map中
    tubes_map[str_tube] = tube_loc[tubes_times];

    tubes_times++;
    if(tubes_times%8==0)
    {
        qDebug() << "tubes have already scaned";//一批试管完成

    }
    if(tubes_times == 8)
    {
        qDebug() << "ALL tubes have already scaned";//所有试管完成

        //开始向结构体数据库传递数据
        for(int i=0;i<8;i++)
        {
            QString str = db_loc[i].slide_info;
            if(tubes_map.contains(str+"\r\n"))
            {
                db_loc[i].tubes_loc.x = tubes_map.value(str+"\r\n").x;//试管坐标
                db_loc[i].tubes_loc.y = tubes_map.value(str+"\r\n").y;//试管坐标
                tubexystore(i);
            }

        }
        tubes_times = 0;
    }
    send();
}

void ScanTubeThread::ScanTubeSerialSend(QByteArray data)
{
    ScanTubePort->write(data);
}



ScanSlideThread::ScanSlideThread(QObject *parent) : QObject(parent)
{
//    QThread *sub = new QThread;
    ScanSlidePort = new QSerialPort();
//    QMessageLogger().debug() << "ScanSlidePort current thread ID :" <<QThread::currentThreadId();
    connect(ScanSlidePort,SIGNAL(readyRead()),this,SLOT(ScanSlideSerialReceive()));//串口打开，并绑定接收槽函数
}

void ScanSlideThread::ScanSlideClose()
{
    ScanSlidePort->close();
}

void ScanSlideThread::ScanSlideOpen()
{
    QMessageLogger().debug() << "ScanSlidePort current thread ID :" <<QThread::currentThreadId();
    if(ScanSlidePort->isOpen())
        ScanSlidePort->close();
//    serialstruct.baud = QSerialPort::Baud9600;
    Serial_Init(ScanSlidePort);
    if(!ScanSlidePort->open(QIODevice::ReadWrite))
    {
        QMessageLogger().debug() << "slide serial open failed";
//        QMessageBox::critical(nullptr, "警告", "该串口已打开", QMessageBox::Yes|QMessageBox::No);
    }

    ScanSlidePort->setBaudRate(QSerialPort::Baud115200);
}

void ScanSlideThread::ScanSlideSerialReceive()
{
    QByteArray data;
    data = scan->Scan_Decode_End();
    ScanSlidePort->write(data);
    QString str_slide = ScanSlidePort->readAll();
    if(str_slide.size() < 2) return;
    flag_scan_slide = 1;
    send(str_slide);
}

void ScanSlideThread::ScanSlideSerialSend(QByteArray data)
{
    ScanSlidePort->write(data);
}

