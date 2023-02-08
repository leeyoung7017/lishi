#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    List_Init();
    serialport = new serial();//串口配置
    scanport = new serial();//扫码枪串口配置
    SerialPort= new QSerialPort();//串口传输

    ScanSerialPort= new QSerialPort();//扫码枪串口传输
    protocol = new Protocol();

    connect(serialport,SIGNAL(send()),this,SLOT(serialreceive()));
    connect(scanport,SIGNAL(send()),this,SLOT(scanreceive()));

//    //同步变化
    for(int i=0;i<MOTORNUM;i++)
    {
        connect(step_list[i],SIGNAL(editingFinished()),this, SLOT(on_step_textChanged()));
//        connect(step_list[i],SIGNAL(editingFinished()),this,SLOT(SliderChanged()));
//        connect(slider_list[i],SIGNAL(sliderMoved(int)),this,SLOT(LineEditChanged()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
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

//    slider_list.append(ui->step0);
//    slider_list.append(ui->step1);
//    slider_list.append(ui->step2);
//    slider_list.append(ui->step3);
//    slider_list.append(ui->step4);
//    slider_list.append(ui->step5);
//    slider_list.append(ui->step6);
//    slider_list.append(ui->step7);
//    slider_list.append(ui->step8);
//    slider_list.append(ui->step9);
//    slider_list.append(ui->step10);
//    slider_list.append(ui->step11);
//    slider_list.append(ui->step12);
//    slider_list.append(ui->step13);
//    slider_list.append(ui->step14);
//    slider_list.append(ui->step15);
//    slider_list.append(ui->step16);
//    slider_list.append(ui->step17);
//    slider_list.append(ui->step18);
//    slider_list.append(ui->step19);


    //csv文件读取
    QStringList name = file_op(FILE);

    for(int i=0;i<MOTORNUM;i++)
    {
        motor_list[i]->setText(name.at(i));
        motor_list[i]->installEventFilter(this);//复选框安装事件过滤器
//        slider_list[i]->setMaximum(65536);
    }
}
//双击事件触发
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QCheckBox *motor = qobject_cast<QCheckBox *>(obj);
    if (event->type() == QEvent::MouseButtonDblClick)//触发双击事件
    {
        bool bOk = false;
        QString sName = QInputDialog::getText(this,
                                              "Motor Name",
                                              "请输入编号",
                                              QLineEdit::Normal,
                                              "",
                                              &bOk
                                              );

         if (bOk && !sName.isEmpty())
         {
             QString name;
             motor->setText(sName);
             motor->setChecked(false);
             for(int i=0;i<MOTORNUM;i++)
             {
                 name += (motor_list.at(i)->text()+',');
             }
             name = name.left(name.size() - 1);/* 取data左边size - 1长度的数据 */
             file_write(FILE,name);
         }

        return true;
    }
    return false;
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
    connect(SerialPort,SIGNAL(readyRead()),this,SLOT(SerialReceive()));
    SerialPort->open(QIODevice::ReadWrite);
}
void MainWindow::scanreceive()
{
    QString str;
    QByteArray data;
    Serial_Init(ScanSerialPort, scanport);
    connect(ScanSerialPort,SIGNAL(readyRead()),this,SLOT(ScanSerialReceive()));
    ScanSerialPort->open(QIODevice::ReadWrite);

    data = protocol->Scan_Protocol(RST);
    ScanSerialPort->write(data);
    data = protocol->Scan_Protocol(SCANMODE_MASTER);
    ScanSerialPort->write(data);
    data = protocol->Scan_Protocol(LIGHTING_AUTO);
    ScanSerialPort->write(data);
    data = protocol->Scan_Protocol(LIGHTING_AUTO);
    ScanSerialPort->write(data);
    data = protocol->Scan_Decode(DECODE_START);
    ScanSerialPort->write(data);

    data = protocol->Scan_Decode(DECODE_END);
    ScanSerialPort->write(data);
}

////步数的数据修改
//void MainWindow::LineEditChanged()
//{
//    qDebug() << "LineEditChanged";
//    QSlider *slider = qobject_cast<QSlider *>(sender());  //发送信号者的对象
//    for(int i=0;i<MOTORNUM;i++)
//    {
//        if(slider == slider_list[i])
//        {
//            step_list[i]->setText(QString::number(slider->value()-417));
//        }
//    }
//}
////步数滑动修改
//void MainWindow::SliderChanged()
//{
//     qDebug() << "SliderChanged";
//    QLineEdit *lineedit = qobject_cast<QLineEdit *>(sender());
//    for(int i=0;i<MOTORNUM;i++)
//    {
//        if(lineedit == step_list[i])
//        {
//            //设置进度条的进度
//            slider_list[i]->setValue(lineedit->text().toUInt());
//        }
//    }
//}

void MainWindow::SerialReceive()
{
    QMessageBox Mbox;
    QByteArray data = nullptr;
    data = SerialPort->readAll();
    if(data.at(0)==0x55 && data.at(1)==(char)0xAA)
    {
        if(!data.at(2) && !data.at(3))
        {
            //输出正确结果
            QMessageBox::information(this, tr("提示"), tr("接收正确"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
        }
        else if(data.at(2)==(char)0xFF && data.at(3)==(char)0xFF)
        {
            //输出错误结果
            QMessageBox::critical(this, tr("提示"), tr("接收错误"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
        }

        else if(data.at(2) == 0x00 && data.at(3) == 0x01)
        {
            //输出正确结果
            QMessageBox::information(this, tr("提示"), tr("电机到达位置"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
        }



        //完成电机运动

        //完成复位
        loc.x = 0;
        loc.y = 0;
        loc.z = 0;

        //接收完成之后记录位置
        if(loc_str == "x")  loc.x = step;
        else if(loc_str == "y") loc.y = step;
        else if(loc_str == "z") loc.z = step;






        //打印显示位置
        ui->lcdNumber->display(QString::number(loc.x));
        ui->lcdNumber_2->display(QString::number(loc.y));
        ui->lcdNumber_3->display(QString::number(loc.z));

    }
}
//接收条形码数据________________测试需要完善
void MainWindow::ScanSerialReceive()
{
    QString str_code = "lishuyang,1302";
    qDebug() << "lishuyang";

    file_write(SCANPATH,str_code);
}

void MainWindow::on_protocol_clicked()
{
    int num_motor = 0;
    QByteArray data;
    QByteArray dir;
    uint32_t motor = 0;
    uint16_t speed[MOTORNUM];


    //获取选中电机数
    for(int i=0;i<MOTORNUM;i++)
    {
        if(motor_list[i]->isChecked())
        {
            motor |= 1<<i;
            num_motor++;
            step = step_list[i]->text().toUInt();
            speed[num_motor] = speed_list[i]->text().toUInt();
            loc_str = func_list[i]->text();
        }
    }
    if(num_motor==0)
    {
        QMessageBox::warning(this, tr("警告"),  tr("未选中任何电机"),
                                           QMessageBox::Yes | QMessageBox::Cancel,  QMessageBox::Cancel);
        return;
    }
    for(int i=0;i<num_motor-1;i++)
    {


    }
    data = protocol->Protocol_Config(0x00,motor,step );
    SerialPort->write(data);
    data.clear();    

}
void MainWindow::on_run_clicked()
{
    QByteArray data;
    if(ui->run->text() == "停止")
    {
        data = protocol->Protocol_Stop();
        ui->run->setText("继续");
    }
    else
    {
        data = protocol->Protocol_Continue();
        ui->run->setText("停止");
    }

    SerialPort->write(data);
    data.clear();
}
void MainWindow::on_reset_clicked()
{
    QByteArray data;
    data = protocol->Protocol_Reset();
    SerialPort->write(data);
    data.clear();
}

void MainWindow::on_SerialBotton_clicked()
{
    SerialPort->close();
    serialport->show();
}
void MainWindow::on_ScanBotton_clicked()
{
    ScanSerialPort->close();
    scanport->show();
}

//将同功能的电机坐标为相同数据
void MainWindow::on_step_textChanged()
{
    uint8_t index = 0;
    QLineEdit *lineedit = qobject_cast<QLineEdit *>(sender());
    for(int i=0;i<MOTORNUM;i++)
    {
        if(step_list[i]==lineedit)
        {
            index = i;
            break;
        }
    }

    for(int i=0;i<MOTORNUM;i++)
    {
        if(index == i) continue;
        if(func_list[i]->text() == func_list[index]->text())
        {
            step_list[i]->setText(step_list[index]->text());
        }
    }

}
