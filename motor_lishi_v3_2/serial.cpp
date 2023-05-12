#include "gv.h"
#include "serial.h"
#include "ui_serial.h"
#include <QThread>

serial::serial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serial)
{
    ui->setupUi(this);
    SerialInfo();
}

serial::~serial()
{
    delete ui;
}

void serial::SerialInfo(void)
{
    QStringList m_serialPortName;
    uint8_t i=0;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        ui->Com->addItem(info.portName());
        i++;
    }
//    if(i>1) ui->Com->setItemText(0,m_serialPortName.at(0));

}


void serial::on_buttonBox_accepted()
{

    switch(ui->Baud->currentIndex())
    {
        case 0:
            serialstruct.baud = QSerialPort::Baud115200;
            break;
        case 1:
            serialstruct.baud = QSerialPort::Baud9600;
            break;
        default:
            break;
    }

    switch(ui->Data->currentIndex())
    {
        case 0:
            serialstruct.data = QSerialPort::Data8;
            break;
        case 1:
            serialstruct.data = QSerialPort::Data7;
            break;
        case 2:
            serialstruct.data = QSerialPort::Data6;
            break;
        case 3:
            serialstruct.data = QSerialPort::Data5;
            break;
        default:
            break;
    }

    switch(ui->Stop->currentIndex())
    {
        case 0:
            serialstruct.stop = QSerialPort::OneStop;
            break;
        case 1:
            serialstruct.stop = QSerialPort::OneAndHalfStop;
            break;
        case 2:
            serialstruct.stop = QSerialPort::TwoStop;
            break;
        default:
            break;
    }
    switch(ui->Parity->currentIndex())
    {
        case 0:
            serialstruct.parity = QSerialPort::NoParity;
            break;
        case 1:
            serialstruct.parity = QSerialPort::OddParity;
            break;
        case 2:
            serialstruct.parity = QSerialPort::EvenParity;
            break;
        default:
            break;
    }

    serialstruct.com = ui->Com->currentText();
    emit send();
}

