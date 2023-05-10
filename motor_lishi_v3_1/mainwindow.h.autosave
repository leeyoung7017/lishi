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
#include "serialthread.h"
#include "dialog.h"

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
    void TimThreadInit();


    void ConnnectInit();
    void DataThreadInit();
    void SerialThreadInit();

private slots:
    void MotorNameInit();
    void on_protocol_clicked();

    void sendTubesxyStore(int ID);

    void SerialReceive(QByteArray data, location loc);
    void ScanSlideSerialReceive(QString str_slide);
    void ScanTubeSerialReceive();

    void on_run_clicked();

    void on_reset_clicked();



    void step_textChanged();

    void on_SlideButton_clicked();

    void on_TubeBotton_clicked();


    void on_fpga_triggered();

    void on_slide_triggered();

    void on_tube_triggered();

    void on_save_clicked();

    void on_action_triggered();

    void sendProtocoltoSerial(QByteArray data);

private:
    Ui::MainWindow *ui;
    serial *serialport;
    serial *scanslideport;
    serial *scantubeport;
    Protocol *protocol;
    file *file;

    QList<QCheckBox *> motor_list;
    QList<QComboBox *> dir_list;
    QList<QLineEdit *> step_list;
    QList<QLineEdit *> speed_list;
    QList<QLineEdit *> func_list;
    QList<QSlider *> slider_list;


    ScanCodeGun *scan;

    SerialThread *serialthread;
    ScanSlideThread *scanslidethread;
    ScanTubeThread *scantubethread;

    Dialog *dialog;

signals:
    void infoinit();
    void infostore(QString str);
    void motorinit();
    void motorstore();
    void timStart(int ms);
    void tubexystore(int ID);

    void sendScanSlide(QByteArray data);
    void sendScanTube(QByteArray data);
    void sendSerial(QByteArray data);
    void sendToDialog();

};

#endif // MAINWINDOW_H
