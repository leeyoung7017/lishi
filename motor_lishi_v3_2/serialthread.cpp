#include "serialthread.h"

//串口初始化并打开
static void Serial_Init(QSerialPort *serialport)
{
    serialport->setPortName(serialstruct.com);
    serialport->setBaudRate(serialstruct.baud);
    serialport->setDataBits(serialstruct.data);
    serialport->setParity(serialstruct.parity);
    serialport->setStopBits(serialstruct.stop);
}

SerialThread::SerialThread(QObject *parent) : QObject(parent)
{
//    QThread *sub = new QThread;
    SerialPort = new QSerialPort;
}

void SerialThread::SerialOpen()
{
    SerialPort->close();
    Serial_Init(SerialPort);
    connect(SerialPort,SIGNAL(readyRead()),this,SLOT(SerialReceive()));//串口打开，并绑定接收槽函数
    SerialPort->open(QIODevice::ReadWrite);
}

void SerialThread::SerialReceive()
{
    QMessageBox Mbox;
       QByteArray data = nullptr;
       data = SerialPort->readAll();
//       file->logWrite(READ,data,ui->log);
       if(data.at(0)==0x55 && data.at(1)==(char)0xAA)
       {
           switch(data.at(2))
           {
               case FB_OK0:
                   if(data.at(3)==(char)FB_OK1)
                   {
                       QMessageBox::critical(nullptr, tr("提示"), tr("电机运动完成"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                       flag_run = 1;
                   }
                   break;
               case FB_RESET0:
                   if(data.at(3) == (char)(FB_RESET1))
                   {
                       flag_reset= 1;
                       QMessageBox::critical(nullptr, tr("提示"), tr("复位指令完成"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                   }
                   break;
   //            case 0x01:
   //                if(data.at(3)==0x00)
   //                    flag_stop = 1;
   //                else if(data.at(3) == (char)(0xff))
   //                    QMessageBox::critical(nullptr, tr("提示"), tr("停止指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
   //                break;
   //            case 0x02:
   //                if(data.at(3)==0x00)
   //                    flag_continue = 1;
   //                else if(data.at(3) == (char)(0xff))
   //                    QMessageBox::critical(nullptr, tr("提示"), tr("继续运动指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
   //                break;
               case FB_CRC0:
                   if(data.at(3) == (char)FB_CRC1)
                       QMessageBox::critical(nullptr, tr("提示"), tr("校验码指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                   break;
               default:
                   break;
           }

           if(flag_run)
           {
   //            if()//判断是否为x,y,z轴的运动电机
               //接收完成之后记录位置
               if(loc_str == "x")  loc.x = step;
               else if(loc_str == "y") loc.y = step;
               else if(loc_str == "z") loc.z = step;

   //            if()//判断是否为试管运动电机
               if(loc_str == "tube")   loc.tube = step;

               flag_run = 0;
               qDebug() << "flag_run";
           }
           if(flag_stop)
           {
               flag_stop = 0;
               qDebug() << "flag_stop";
           }
           if(flag_continue)
           {
               flag_continue = 0;
               qDebug() << "flag_continue";
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
    ScanTubePort = new QSerialPort;

}

void ScanTubeThread::ScanTubeOpen()
{
    ScanTubePort->close();
    Serial_Init(ScanTubePort);
    connect(ScanTubePort,SIGNAL(readyRead()),this,SLOT(ScanTubeSerialReceive()));//串口打开，并绑定接收槽函数
    ScanTubePort->open(QIODevice::ReadWrite);
}

void ScanTubeThread::ScanTubeSerialReceive()
{
    QByteArray data;
    data = scan->Scan_Decode_End();
    ScanTubePort->write(data);
    QString str_tube = ScanTubePort->readAll();

    flag_scan_tube = 1;
    //将数据记录在map中
    tubes_map[str_tube] = tube_loc[tubes_times];

    tubes_times++;
    if(tubes_times%8==0)
    {
        qDebug() << "tubes have already scaned\n";//一批试管完成

    }
    if(tubes_times == 8)
    {
        qDebug() << "ALL tubes have already scaned\n";//所有试管完成

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
    ScanSlidePort = new QSerialPort;
}

void ScanSlideThread::ScanSlideOpen()
{
    ScanSlidePort->close();
    Serial_Init(ScanSlidePort);
    connect(ScanSlidePort,SIGNAL(readyRead()),this,SLOT(ScanSlideSerialReceive()));//串口打开，并绑定接收槽函数
    ScanSlidePort->open(QIODevice::ReadWrite);
}

void ScanSlideThread::ScanSlideSerialReceive()
{
    QByteArray data;
    data = scan->Scan_Decode_End();
    ScanSlidePort->write(data);
    QString str_slide = ScanSlidePort->readAll();
    flag_scan_slide = 1;
    send(str_slide);
}

void ScanSlideThread::ScanSlideSerialSend(QByteArray data)
{
    ScanSlidePort->write(data);
}

