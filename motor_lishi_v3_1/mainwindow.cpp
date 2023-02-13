#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <processthreadsapi.h>


file *csv;
sqlite *sql;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    List_Init();

    DataThread();   //创建子线程，在子线程中 完成数据库或CSV文件的操作

    TimThread();    //创建子线程，在子线程中 使用定时器功能

    emit timStart(1000);

    scan = new ScanCodeGun();//扫码枪
    serialport = new serial();//串口配置
    scanport = new serial();//扫码枪串口配置
    SerialPort= new QSerialPort();//串口传输

    ScanSerialPort= new QSerialPort();//扫码枪串口传输
    protocol = new Protocol();




    qDebug() << "当前 ID号：" << GetCurrentThreadId();

    //实现将子界面的数据传递到主界面中
    connect(serialport,SIGNAL(send()),this,SLOT(serialreceive()));
    connect(scanport,SIGNAL(send()),this,SLOT(scanreceive()));
    for(int i=0;i<MOTORNUM;i++)
    {
        //将同轴作用的电机进行步数统一
        connect(step_list[i],SIGNAL(editingFinished()),this, SLOT(step_textChanged()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DataThread()
{
    QThread *thread_info = new QThread();   //线程创建
    infoThread *infothread = new infoThread;    //线程功能实现类
    infothread->moveToThread(thread_info);  //将对象转移到子线程中运行
    thread_info->start(QThread::NormalPriority);    //线程开启
    connect(this, SIGNAL(infoinit()),infothread, SLOT(infoInit()));     //信息初始化指令绑定  信息文件数据库初始化(实现了 信息导入全局结构体中)
    connect(this, SIGNAL(infostore(QString)),infothread, SLOT(infoStore(QString))); //信息保存指令绑定  信息存储(信息的全局结构体存储)
    connect(infothread,SIGNAL(motornameinit()),this, SLOT(MotorNameInit())); //电机名初始化指令绑定   电机文件数据库初始化(实现了 电机名导入全局结构体与界面中)
    connect(this,SIGNAL(motorstore()), infothread, SLOT(motorStore())); //电机名保存指令绑定     电机名存储(将 电机名全局结构体存储)

    emit infoinit();//发送信息初始化指令
}

void MainWindow::TimThread()
{
    QThread *thread_tim = new QThread();    //线程创建
    Timer *tim = new Timer;             //线程功能实现类   定时器功能
    tim->moveToThread(thread_tim);      //将对象转移到子线程中
    thread_tim->start(QThread::NormalPriority);     //线程开启
    connect(this,SIGNAL(timStart(int)),tim, SLOT(TimerStart(int)));     //定时器开启绑定
}

//将界面控件分类批量进行打包
void MainWindow::List_Init(void)
{
    motor_list.append(ui->motor0);
    motor_list.append(ui->motor1);
    motor_list.append(ui->motor2);
    motor_list.append(ui->motor3);
    motor_list.append(ui->motor4);
    motor_list.append(ui->motor5);
    motor_list.append(ui->motor6);
    motor_list.append(ui->motor7);
    motor_list.append(ui->motor8);
    motor_list.append(ui->motor9);
    motor_list.append(ui->motor10);
    motor_list.append(ui->motor11);
    motor_list.append(ui->motor12);
    motor_list.append(ui->motor13);
    motor_list.append(ui->motor14);
    motor_list.append(ui->motor15);
    motor_list.append(ui->motor16);
    motor_list.append(ui->motor17);
    motor_list.append(ui->motor18);
    motor_list.append(ui->motor19);



    step_list.append(ui->lineEdit0);
    step_list.append(ui->lineEdit1);
    step_list.append(ui->lineEdit2);
    step_list.append(ui->lineEdit3);
    step_list.append(ui->lineEdit4);
    step_list.append(ui->lineEdit5);
    step_list.append(ui->lineEdit6);
    step_list.append(ui->lineEdit7);
    step_list.append(ui->lineEdit8);
    step_list.append(ui->lineEdit9);
    step_list.append(ui->lineEdit10);
    step_list.append(ui->lineEdit11);
    step_list.append(ui->lineEdit12);
    step_list.append(ui->lineEdit13);
    step_list.append(ui->lineEdit14);
    step_list.append(ui->lineEdit15);
    step_list.append(ui->lineEdit16);
    step_list.append(ui->lineEdit17);
    step_list.append(ui->lineEdit18);
    step_list.append(ui->lineEdit19);


    speed_list.append(ui->speed_0);
    speed_list.append(ui->speed_1);
    speed_list.append(ui->speed_2);
    speed_list.append(ui->speed_3);
    speed_list.append(ui->speed_4);
    speed_list.append(ui->speed_5);
    speed_list.append(ui->speed_6);
    speed_list.append(ui->speed_7);
    speed_list.append(ui->speed_8);
    speed_list.append(ui->speed_9);
    speed_list.append(ui->speed_10);
    speed_list.append(ui->speed_11);
    speed_list.append(ui->speed_12);
    speed_list.append(ui->speed_13);
    speed_list.append(ui->speed_14);
    speed_list.append(ui->speed_15);
    speed_list.append(ui->speed_16);
    speed_list.append(ui->speed_17);
    speed_list.append(ui->speed_18);
    speed_list.append(ui->speed_19);

    func_list.append(ui->func0);
    func_list.append(ui->func1);
    func_list.append(ui->func2);
    func_list.append(ui->func3);
    func_list.append(ui->func4);
    func_list.append(ui->func5);
    func_list.append(ui->func6);
    func_list.append(ui->func7);
    func_list.append(ui->func8);
    func_list.append(ui->func9);
    func_list.append(ui->func10);
    func_list.append(ui->func11);
    func_list.append(ui->func12);
    func_list.append(ui->func13);
    func_list.append(ui->func14);
    func_list.append(ui->func15);
    func_list.append(ui->func16);
    func_list.append(ui->func17);
    func_list.append(ui->func18);
    func_list.append(ui->func19);


}


//串口初始化并打开
void MainWindow::Serial_Init(QSerialPort *serialport, serial *serial)
{
    serialport->setPortName(serial->serialstruct.com);
    serialport->setBaudRate(serial->serialstruct.baud);
    serialport->setDataBits(serial->serialstruct.data);
    serialport->setParity(serial->serialstruct.parity);
    serialport->setStopBits(serial->serialstruct.stop);
}

void MainWindow::serialreceive(void)
{
    Serial_Init(SerialPort, serialport);
    connect(SerialPort,SIGNAL(readyRead()),this,SLOT(SerialReceive()));//串口打开，并绑定接收槽函数
    SerialPort->open(QIODevice::ReadWrite);
}

//电机控制接收反馈______________测试需要完成流程
void MainWindow::SerialReceive()
{
    QMessageBox Mbox;
    QByteArray data = nullptr;
    data = SerialPort->readAll();
    if(data.at(0)==0x55 && data.at(1)==(char)0xAA)
    {
        switch(data.at(2))
        {
            case 0x00:
                if(data.at(3)==0x00)
                    flag_run = 1;
                else if(data.at(3) == (char)(0xff))
                    QMessageBox::critical(this, tr("提示"), tr("运动指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                break;
            case 0x01:
                if(data.at(3)==0x00)
                    flag_stop = 1;
                else if(data.at(3) == (char)(0xff))
                    QMessageBox::critical(this, tr("提示"), tr("停止指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                break;
            case 0x02:
                if(data.at(3)==0x00)
                    flag_continue = 1;
                else if(data.at(3) == (char)(0xff))
                    QMessageBox::critical(this, tr("提示"), tr("继续运动指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                break;
            case 0x03:
                if(data.at(3)==0x00)
                    flag_reset = 1;
                else if(data.at(3) == (char)(0xff))
                    QMessageBox::critical(this, tr("提示"), tr("复位指令接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
                break;
            default:
                break;
        }

        if(flag_run)
        {
            //接收完成之后记录位置
            if(loc_str == "x")  loc.x = step;
            else if(loc_str == "y") loc.y = step;
            else if(loc_str == "z") loc.z = step;
            //进行流程的封装


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


        //打印显示位置
        if(data.at(3) == 0x00)
        {
            ui->lcdNumber->display(QString::number(loc.x));
            ui->lcdNumber_2->display(QString::number(loc.y));
            ui->lcdNumber_3->display(QString::number(loc.z));
        }


    }
}

//扫码枪串口初始化配置________________测试需要完善
void MainWindow::scanreceive()
{
    QString str;
    QByteArray data;
    Serial_Init(ScanSerialPort, scanport);
    connect(ScanSerialPort,SIGNAL(readyRead()),this,SLOT(ScanSerialReceive()));
    ScanSerialPort->open(QIODevice::ReadWrite);


    data = scan->Scan_Protocol(RST);
    ScanSerialPort->write(data);
    data = scan->Scan_Protocol(SCANMODE_MASTER);
    ScanSerialPort->write(data);
    data = scan->Scan_Protocol(LIGHTING_AUTO);
    ScanSerialPort->write(data);
    data = scan->Scan_Protocol(LIGHTING_AUTO);
    ScanSerialPort->write(data);
    data = scan->Scan_Decode_Start();
    ScanSerialPort->write(data);

    data = scan->Scan_Decode_End();
    ScanSerialPort->write(data);
}

//接收条形码数据________________测试需要完善
void MainWindow::ScanSerialReceive()
{
    QString str_code = "lishuyang,1302";
    QString str_tube;// = ScanSerialPort->readAll();
    QString str_slide = ScanSerialPort->readAll();
    flag_scan_tube = 0;
    flag_scan_slide = 1;

    emit infostore(str_slide);  //发送信息保存指令
}

//发送协议
void MainWindow::on_protocol_clicked()
{
    int num_motor = 0;
    QByteArray data;
    QByteArray dir;
    uint32_t motor = 0;
//    uint16_t speed[MOTORNUM];//暂时先不需要速度


    //获取选中电机数
    for(int i=0;i<MOTORNUM;i++)
    {
        if(motor_list[i]->isChecked())  //获取选中的数据
        {
            motor |= 1<<i;
            num_motor++;
            step = step_list[i]->text().toUInt();
//            speed[num_motor] = speed_list[i]->text().toUInt();
            loc_str = func_list[i]->text();
        }
    }
    if(num_motor==0)
    {
        QMessageBox::warning(this, tr("警告"),  tr("未选中任何电机"), QMessageBox::Yes | QMessageBox::Cancel,  QMessageBox::Cancel);
        return;
    }
    data = protocol->Protocol_Config(0x00,motor,step);
    motor_g = motor;
    step_g = step;
    SerialPort->write(data);
    data.clear();    

}
void MainWindow::on_run_clicked()
{
    QByteArray data;
    if(ui->run->text() == "停止")
    {
//        data = protocol->Protocol_Stop();
        data = protocol->Protocol_Config(0x01,motor_g,step_g);  //停止指令
        ui->run->setText("继续");
    }
    else
    {
//        data = protocol->Protocol_Continue();

        data = protocol->Protocol_Config(0x02,motor_g,step_g);  //继续指令
        ui->run->setText("停止");
    }

    SerialPort->write(data);
    data.clear();
}
void MainWindow::on_reset_clicked()
{
    QByteArray data;
//    data = protocol->Protocol_Reset();
    data = protocol->Protocol_Config(0x03,0,0);  //继续指令
    SerialPort->write(data);
    data.clear();
}

void MainWindow::on_SerialBotton_clicked()
{
    SerialPort->close();//关闭之前打开的串口
    serialport->show();//打开子界面，重新选择串口
}
void MainWindow::on_ScanBotton_clicked()
{
    ScanSerialPort->close();//关闭之前打开的串口
    scanport->show();//打开子界面，重新选择串口
}

//将同功能的电机坐标为相同数据
void MainWindow::step_textChanged()
{
    uint8_t index = 0;
    QLineEdit *lineedit = qobject_cast<QLineEdit *>(sender());
    for(int i=0;i<MOTORNUM;i++)     //获取已修改内容的文本框
    {
        if(step_list[i]==lineedit)
        {
            index = i;
            break;
        }
    }

    for(int i=0;i<MOTORNUM;i++)     //将同功能电机的文本框内容保持一致
    {
        if(index == i) continue;
        if(func_list[i]->text() == func_list[index]->text())
        {
            step_list[i]->setText(step_list[index]->text());
        }
    }

}

//初始化Motor name
void MainWindow::MotorNameInit()
{
    for(int i=0;i<MOTORNUM;i++)
    {
        motor_list[i]->setText(MotorName[i]);
        motor_list[i]->installEventFilter(this);//复选框安装事件过滤器
    }
}

//修改motor name
void MainWindow::changeMotorName(QCheckBox *motor, QString sName)
{
    motor->setText(sName);
    motor->setChecked(false);
    for(int i=0;i<MOTORNUM;i++)
    {
        if(motor == motor_list[i])
        {
            MotorName[i] = sName;
        }
    }
    emit motorstore();  //电机名保存指令
}

//双击事件触发修改点击名称
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QCheckBox *motor = qobject_cast<QCheckBox *>(obj);
    if (event->type() == QEvent::MouseButtonDblClick)//触发双击事件
    {
        bool bOk = false;
        QString sName = QInputDialog::getText(this, "Motor Name", "请输入编号", QLineEdit::Normal, "", &bOk);
        if (bOk && !sName.isEmpty())    changeMotorName(motor,sName);
        return true;
    }
    return false;
}

