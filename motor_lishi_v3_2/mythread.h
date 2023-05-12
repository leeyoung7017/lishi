#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "file.h"
#include "sqlite.h"


extern file *csv;//csv文件
extern sqlite *sql;//数据库

class infoThread : public QObject
{
    Q_OBJECT
public:
    explicit infoThread(QObject *parent = nullptr);

    int getIndexSildeFromxy(QString path, location loc);
    int getIndexTubeFromxy(QString path, location loc);

public slots:
    void infoInit();
    void infoStore(QString str);
    void motorStore();
    void TubesxyStore(int ID);
signals:
    void motornameinit();
private:
    QString strStore;
};


class Timer: public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

public slots:
    void onTimeout();
    void TimerStart(int tim);
private:
    QTimer *timer;
};

#endif // MYTHREAD_H
