#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QMessageBox>
#include "serial.h"
#include "protocol.h"
#include "ini.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Serial_Init(void);

private slots:
    void on_SerialBotton_clicked();
    void receive(void);

    void on_protocol_clicked();

    void on_OpenClose_clicked();


    void SerialReceive();

private:
    Ui::MainWindow *ui;
    serial *serialport;
    QSerialPort *SerialPort;
    Protocol *protocol;
};

#endif // MAINWINDOW_H
