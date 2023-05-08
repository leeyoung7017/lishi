#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <processthreadsapi.h>
#include <QDebug>
#include <QMetaType>


file *csv;
sqlite *sql;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->SerialBotton->setVisible(false);
    ui->ScanSlideBotton->setVisible(false);
    ui->ScanTubeBotton->setVisible(false);

    serialport = new serial();
    scanslideport = new serial();
    scantubeport = new serial();

    List_Init();

    QMessageLogger().debug() << "mainwindow current thread ID :" <<QThread::currentThreadId();

    SerialThreadInit();

    DataThreadInit();   //创建子线程，在子线程中 完成数据库或CSV文件的操作

    TimThreadInit();    //创建子线程，在子线程中 使用定时器功能   吹气，滴水等等

    emit timStart(1000);


    protocol = new Protocol();


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


void MainWindow::SerialThreadInit()
{
    QThread *sub_serial = new QThread;
    serialthread = new SerialThread;
    serialthread->moveToThread(sub_serial);
    sub_serial->start(QThread::NormalPriority);

    QThread *sub_slide = new QThread;
    scanslidethread = new ScanSlideThread;
    scanslidethread->moveToThread(sub_slide);
    sub_slide->start(QThread::NormalPriority);

    QThread *sub_tube = new QThread;
    scantubethread = new ScanTubeThread;
    scantubethread->moveToThread(sub_tube);
    sub_tube->start(QThread::NormalPriority);

    qRegisterMetaType<location>("location");

    //将串口绑定
    connect(serialthread,SIGNAL(send(QByteArray, location)),this,SLOT(SerialReceive(QByteArray, location)));
    connect(scanslidethread,SIGNAL(send(QString)),this,SLOT(ScanSlideSerialReceive(QString)));
    connect(scantubethread,SIGNAL(send()),this,SLOT(ScanTubeSerialReceive()));

    connect(scantubethread,SIGNAL(tubexystore(int)),this,SLOT(sendTubesxyStore(int)));    //按照字符串对应试管坐标
    connect(this,SIGNAL(sendSerial(QByteArray)),serialthread,SLOT(SerialSend(QByteArray)));
    connect(this,SIGNAL(sendScanSlide(QByteArray)),scanslidethread,SLOT(ScanSlideSerialSend(QByteArray)));
    connect(this,SIGNAL(sendScanTube(QByteArray)),scantubethread,SLOT(ScanTubeSerialSend(QByteArray)));
}

//数据库与csv文件转移线程
void MainWindow::DataThreadInit()
{
    QThread *thread_info = new QThread();   //线程创建
    infoThread *infothread = new infoThread;    //线程功能实现类
    infothread->moveToThread(thread_info);  //将对象转移到子线程中运行
    thread_info->start(QThread::NormalPriority);    //线程开启
    connect(this, SIGNAL(infoinit()),infothread, SLOT(infoInit()));     //信息初始化指令绑定  信息文件数据库初始化(实现了 信息导入全局结构体中)
    connect(this, SIGNAL(infostore(QString)),infothread, SLOT(infoStore(QString))); //信息保存指令绑定  信息存储(信息的全局结构体存储)
    connect(infothread,SIGNAL(motornameinit()),this, SLOT(MotorNameInit())); //电机名初始化指令绑定   电机文件数据库初始化(实现了 电机名导入全局结构体与界面中)
    connect(this,SIGNAL(motorstore()), infothread, SLOT(motorStore())); //电机名保存指令绑定     电机名存储(将 电机名全局结构体存储)
    connect(this,SIGNAL(tubexystore(int)),infothread,SLOT(TubesxyStore(int)));    //按照字符串对应试管坐标

    emit infoinit();//发送信息初始化指令
}

//定时器转移线程
void MainWindow::TimThreadInit()
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
    motor_list.append(ui->motor20);
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

void MainWindow::ConnnectInit()
{

}

//电机控制接收反馈______________测试需要完成流程
void MainWindow::SerialReceive(QByteArray data, location loc)
{

    file->logWrite(READ,data,ui->log);

    //打印显示位置
    if(data.at(3) == 0x00)
    {
        ui->lcdNumber->display(QString::number(loc.x));
        ui->lcdNumber_2->display(QString::number(loc.y));
        ui->lcdNumber_3->display(QString::number(loc.z));
    }
}


//扫码枪玻片扫描
void MainWindow::on_SlideButton_clicked()
{
    QByteArray data;
    data = scan->Scan_Decode_Start();
    sendScanSlide(data);
    ui->stateslide->setText("扫码中...");
}
//扫码枪试管扫描
void MainWindow::on_TubeBotton_clicked()
{
    QByteArray data;
    data = scan->Scan_Decode_Start();
    sendScanTube(data);
    ui->statetube->setText("扫码中...");
}


//玻片接收条形码数据________________测试需要完善
void MainWindow::ScanSlideSerialReceive(QString str_slide)
{

    ui->stateslide->setText("扫码完成");



    if(str_slide.at(str_slide.size()-1)=="\n")
    {
        str_slide = str_slide.left(str_slide.size()-1);
    }
    if(str_slide.at(str_slide.size()-1)=="\r")
    {
        str_slide = str_slide.left(str_slide.size()-1);
    }
    infostore(str_slide);  //发送信息保存指令
}
//试管接收条形码数据
void MainWindow::ScanTubeSerialReceive()
{
    ui->statetube->setText("扫码完成");
//    if(str_tube.at(str_tube.size()-1)=="\n")
//    {
//        str_tube = str_tube.left(str_tube.size()-1);
//    }

//    if(str_tube.at(str_tube.size()-1)=="\r")
//    {
//        str_tube = str_tube.left(str_tube.size()-1);
//    }
//    infostore(str_tube);  //发送信息保存指令
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
            motor |= 1<<(i-1);//电机号位控制
            num_motor++;
            step = step_list[i]->text().toInt();
//            speed[num_motor] = speed_list[i]->text().toUInt();
            loc_str = func_list[i]->text();
        }
    }
    if(num_motor==0)
    {
        QMessageBox::warning(this, tr("警告"),  tr("未选中任何电机"), QMessageBox::Yes | QMessageBox::Cancel,  QMessageBox::Cancel);
        return;
    }
    if(ui->motor1->isChecked() && ui->motor6->isChecked())//判断是哪个电机，1、6电机
    {
        data = protocol->Protocol_Config(CMD_MOTORY,motor,step);
        motor_g = motor;
        step_g = step;
    }
    else if(ui->motor2->isChecked() && ui->motor3->isChecked() && ui->motor4->isChecked() && ui->motor5->isChecked() && ui->motor7->isChecked() && ui->motor8->isChecked())
    {
        data = protocol->Protocol_Config(CMD_MOTORXZ,motor,step);
        motor_g = motor;
        step_g = step;
    }
    else if(ui->motor9->isChecked())//移液电机
    {
        if(step<0) //方向为0
        {
            step = -step;
            data = protocol->Protocol_Config(CMD_YY,0,step);
        }
        else//方向为1
        {
            data = protocol->Protocol_Config(CMD_YY,1,step);
        }
    }
    else if(ui->motor10->isChecked())//喷淋电机
    {
        if(step<0) //方向为0
        {
            step = -step;
            data = protocol->Protocol_Config(CMD_PL,0,step);
        }
        else//方向为1
        {
            data = protocol->Protocol_Config(CMD_PL,1,step);
        }
    }
    else if(ui->motor11->isChecked())//吹气电机
    {
        data = protocol->Protocol_Config(CMD_CQ,motor,step);
    }


//    motor_g = motor;
//    step_g = step;
//    SerialPort->write(data);
    sendSerial(data);
    file->logWrite(WRITE,data,ui->log);
    data.clear();    

}
void MainWindow::on_run_clicked()
{
    QByteArray data;
    if(ui->run->text() == "停止")
    {
//        data = protocol->Protocol_Stop();
        data = protocol->Protocol_Config(CMD_CONTINUE,motor_g,step_g);  //停止指令
        ui->run->setText("继续");
    }
    else
    {
//        data = protocol->Protocol_Continue();

        data = protocol->Protocol_Config(CMD_STOP,motor_g,step_g);  //继续指令
        ui->run->setText("停止");
    }

//    SerialPort->write(data);
    sendSerial(data);
    file->logWrite(WRITE,data,ui->log);
    data.clear();
}
void MainWindow::on_reset_clicked()
{
    QByteArray data;
//    data = protocol->Protocol_Reset();
    data = protocol->Protocol_Config(CMD_RESET,0,0);  //继续指令
//    SerialPort->write(data);
    sendSerial(data);
    file->logWrite(WRITE,data,ui->log);
    data.clear();
}

//串口配置窗口
void MainWindow::on_fpga_triggered()
{
    serialport->show();//打开子界面，重新选择串口
    connect(serialport,SIGNAL(send()),serialthread,SLOT(SerialOpen()));
}
void MainWindow::on_slide_triggered()
{
    scanslideport->show();//打开子界面，重新选择串口
    connect(scanslideport,SIGNAL(send()),scanslidethread,SLOT(ScanSlideOpen()));
}
void MainWindow::on_tube_triggered()
{
    scantubeport->show();//打开子界面，重新选择串口
    connect(scantubeport,SIGNAL(send()),scantubethread,SLOT(ScanTubeOpen()));
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


void MainWindow::on_save_clicked()
{
    // 弹出文件对话框让用户选择文件保存路径
    QString filePath = LOGPATH;

    // 打开文件并将 QTextEdit 控件的内容写入文件
    QFile file(LOGPATH);
    QString str = ui->log->toPlainText();
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << str << endl;
        file.close();
    }
}

void MainWindow::sendTubesxyStore(int ID)
{
    emit tubexystore(ID);//将坐标进行保存
}
