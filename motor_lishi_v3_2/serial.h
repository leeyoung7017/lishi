#ifndef SERIAL_H
#define SERIAL_H

#include <QDialog>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>
#include <QTimer>
#include "gv.h"

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
signals :
    void send();
    void closed();
private slots:

    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::serial *ui;
    QSerialPort *SerialPort;
    QSerialPort *ScanSlideSerialPort;
    QSerialPort *ScanTubeSerialPort;
    QTimer *tim;
};

#endif // SERIAL_H
