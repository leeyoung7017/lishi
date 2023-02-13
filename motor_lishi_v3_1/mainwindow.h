#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QMessageBox>
#include <QList>
#include <QComboBox>
#include <QLineEdit>
#include <QInputDialog>
#include <QDebug>
#include "serial.h"
#include "protocol.h"
#include "ini.h"
#include "file.h"
#include "sqlite.h"
#include "scancodegun.h"
#include "mythread.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Serial_Init(QSerialPort *serialport, serial *serial);
    void List_Init(void);
    bool eventFilter(QObject *obj, QEvent *event);

    void changeMotorName(QCheckBox *motor, QString sName);
    void DataThread();
    void TimThread();
private slots:
    void MotorNameInit();
    void on_SerialBotton_clicked();
    void serialreceive(void);
    void scanreceive(void);

    void on_protocol_clicked();


    void SerialReceive();
    void ScanSerialReceive();

    void on_run_clicked();

    void on_reset_clicked();



    void on_ScanBotton_clicked();

    void step_textChanged();

private:
    Ui::MainWindow *ui;
    serial *serialport;
    serial *scanport;
    QSerialPort *SerialPort;
    QSerialPort *ScanSerialPort;
    Protocol *protocol;

    QString loc_str;//发送的坐标所平行轴
    uint32_t step;//坐标

    QList<QCheckBox *> motor_list;
    QList<QComboBox *> dir_list;
    QList<QLineEdit *> step_list;
    QList<QLineEdit *> speed_list;
    QList<QLineEdit *> func_list;
    QList<QSlider *> slider_list;


    ScanCodeGun *scan;

signals:
    void infoinit();
    void infostore(QString str);
    void motorinit();
    void motorstore();
    void timStart(int ms);

};

#endif // MAINWINDOW_H
