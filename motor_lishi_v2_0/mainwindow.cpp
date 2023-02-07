#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    List_Init();
    serialport = new serial();
    SerialPort= new QSerialPort();
    protocol = new Protocol();
    ui->OpenClose->setEnabled(false);

    connect(serialport,SIGNAL(send()),this,SLOT(receive()));
    for(int i=0;i<20;i++)
    {
        connect(step_list[i],SIGNAL(editingFinished()),this,SLOT(SliderChanged()));
        connect(slider_list[i],SIGNAL(sliderMoved(int)),this,SLOT(LineEditChanged()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

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

    dir_list.append(ui->dir0);
    dir_list.append(ui->dir1);
    dir_list.append(ui->dir2);
    dir_list.append(ui->dir3);
    dir_list.append(ui->dir4);
    dir_list.append(ui->dir5);
    dir_list.append(ui->dir6);
    dir_list.append(ui->dir7);
    dir_list.append(ui->dir8);
    dir_list.append(ui->dir9);
    dir_list.append(ui->dir10);
    dir_list.append(ui->dir11);
    dir_list.append(ui->dir12);
    dir_list.append(ui->dir13);
    dir_list.append(ui->dir14);
    dir_list.append(ui->dir15);
    dir_list.append(ui->dir16);
    dir_list.append(ui->dir17);
    dir_list.append(ui->dir18);
    dir_list.append(ui->dir19);

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

    slider_list.append(ui->step0);
    slider_list.append(ui->step1);
    slider_list.append(ui->step2);
    slider_list.append(ui->step3);
    slider_list.append(ui->step4);
    slider_list.append(ui->step5);
    slider_list.append(ui->step6);
    slider_list.append(ui->step7);
    slider_list.append(ui->step8);
    slider_list.append(ui->step9);
    slider_list.append(ui->step10);
    slider_list.append(ui->step11);
    slider_list.append(ui->step12);
    slider_list.append(ui->step13);
    slider_list.append(ui->step14);
    slider_list.append(ui->step15);
    slider_list.append(ui->step16);
    slider_list.append(ui->step17);
    slider_list.append(ui->step18);
    slider_list.append(ui->step19);


    //csv文件读取
    QStringList name = file_op(FILE);

    for(int i=0;i<20;i++)
    {
        motor_list[i]->setText(name.at(i));
        motor_list[i]->installEventFilter(this);//复选框安装事件过滤器
        slider_list[i]->setMaximum(65536);
    }
}

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
             for(int i=0;i<20;i++)
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

void MainWindow::Serial_Init(void)
{
    SerialPort->setPortName(serialport->serialstruct.com);
    SerialPort->setBaudRate(serialport->serialstruct.baud);
    SerialPort->setDataBits(serialport->serialstruct.data);
    SerialPort->setParity(serialport->serialstruct.parity);
    SerialPort->setStopBits(serialport->serialstruct.stop);
    ui->OpenClose->setEnabled(true);
}

void MainWindow::receive(void)
{
    Serial_Init();
}


//步数的数据修改
void MainWindow::LineEditChanged()
{
    qDebug() << "LineEditChanged";
    QSlider *slider = qobject_cast<QSlider *>(sender());  //发送信号者的对象
    for(int i=0;i<20;i++)
    {
        if(slider == slider_list[i])
        {
            step_list[i]->setText(QString::number(slider->value()-417));
        }
    }
}

//步数滑动修改
void MainWindow::SliderChanged()
{
     qDebug() << "SliderChanged";
    QLineEdit *lineedit = qobject_cast<QLineEdit *>(sender());
    for(int i=0;i<20;i++)
    {
        if(lineedit == step_list[i])
        {
            //设置进度条的进度
            slider_list[i]->setValue(lineedit->text().toUInt());
        }
    }
}

void MainWindow::on_SerialBotton_clicked()
{
    serialport->show();
    ui->OpenClose->setEnabled(false);
}

void MainWindow::on_protocol_clicked()
{
    int num_motor = 0;
    QByteArray data;
    QByteArray dir;
    uint16_t step[20];
    QByteArray motor;
    uint16_t speed[20];


    //获取选中电机数
    for(int i=0;i<20;i++)
    {
        if(motor_list[i]->isChecked())
        {
            motor.append(i+1);
            dir.append(dir_list[i]->currentIndex());
            speed[num_motor] = speed_list[i]->text().toUInt();
            step[num_motor++] = step_list[i]->text().toUInt();
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
        data = protocol->Protocol_Config(0x00,motor[i],dir[i],step[i],speed[i],0);
        SerialPort->write(data);
        data.clear();
    }
    data = protocol->Protocol_Config(0x00,motor[num_motor-1],dir[num_motor-1],step[num_motor-1],speed[num_motor-1],0xff);
    SerialPort->write(data);
    data.clear();

}

void MainWindow::on_OpenClose_clicked()
{
    if(ui->OpenClose->text() == "串口打开")
    {
        SerialPort->open(QIODevice::ReadWrite);
        ui->OpenClose->setText("串口关闭");
        connect(SerialPort,SIGNAL(readyRead()),this,SLOT(SerialReceive()));
    }
    else {
        SerialPort->close();
        ui->OpenClose->setText("串口打开");
    }
}

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
    }
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
