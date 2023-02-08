#ifndef SERIAL_H
#define SERIAL_H

#include <QDialog>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>

namespace Ui {
class serial;
}

class serial : public QDialog
{
    Q_OBJECT

public:
    explicit serial(QWidget *parent = nullptr);
    ~serial();
    void SerialInfo();


    typedef struct{
        QString com;
        QSerialPort::BaudRate baud;
        QSerialPort::DataBits data;
        QSerialPort::StopBits stop;
        QSerialPort::Parity parity;
    }SerialStruct;

    SerialStruct serialstruct;

signals :
    void send();
private slots:
    void on_buttonBox_accepted();
private:
    Ui::serial *ui;
};

#endif // SERIAL_H
