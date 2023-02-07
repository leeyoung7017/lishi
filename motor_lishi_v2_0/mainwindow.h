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

namespace Ui {
class MainWindow;
}

#define FILE "F:\\Project\\motor_lishi\\motor_lishi_v2_0\\files\\QCheckBox.csv"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Serial_Init(void);
    void List_Init(void);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_SerialBotton_clicked();
    void receive(void);

    void on_protocol_clicked();

    void on_OpenClose_clicked();


    void SerialReceive();

    void on_run_clicked();

    void on_reset_clicked();

    void SliderChanged();
    void LineEditChanged();

private:
    Ui::MainWindow *ui;
    serial *serialport;
    QSerialPort *SerialPort;
    Protocol *protocol;

    QList<QCheckBox *> motor_list;
    QList<QComboBox *> dir_list;
    QList<QLineEdit *> step_list;
    QList<QLineEdit *> speed_list;
    QList<QSlider *> slider_list;


};

#endif // MAINWINDOW_H
