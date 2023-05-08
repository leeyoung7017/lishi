#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QSerialPort>
#include <QThread>
#include "gv.h"
#include <QMessageBox>
#include <QDebug>

class SerialThread : public QObject
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);
    QSerialPort *SerialPort;
public slots:
    void SerialOpen();
    void SerialReceive();
    void SerialSend(QByteArray data);
signals:
    void send(QByteArray data, location loc);
};




class ScanTubeThread: public QObject
{
    Q_OBJECT
public:
    explicit ScanTubeThread(QObject *parent = nullptr);
    QSerialPort *ScanTubePort;
public slots:
    void ScanTubeOpen();
    void ScanTubeSerialReceive();
    void ScanTubeSerialSend(QByteArray data);
signals:
    void send();
    void tubexystore(int ID);
};

class ScanSlideThread: public QObject
{
    Q_OBJECT
public:
    explicit ScanSlideThread(QObject *parent = nullptr);
    QSerialPort *ScanSlidePort;
public slots:
    void ScanSlideOpen();
    void ScanSlideSerialReceive();
    void ScanSlideSerialSend(QByteArray data);
signals:
    void send(QString str);
};

#endif // SERIALTHREAD_H
