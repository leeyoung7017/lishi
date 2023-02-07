#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serialport = new serial();
    SerialPort= new QSerialPort();
    protocol = new Protocol();
    ui->OpenClose->setEnabled(false);

    connect(serialport,SIGNAL(send()),this,SLOT(receive()));
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_SerialBotton_clicked()
{
    serialport->show();
    ui->OpenClose->setEnabled(false);
}

void MainWindow::on_protocol_clicked()
{
    QByteArray data;
    uint8_t motor = ui->motor->currentIndex();
    uint8_t dir = ui->dir->currentIndex();
    uint16_t step = ui->step->text().toUInt();
    data = protocol->Protocol_Config(motor,dir,step);

    SerialPort->write(data);

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
