#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    QByteArray Protocol_Config(uint8_t command, uint8_t motornum, uint8_t dir, uint16_t step, uint16_t speed, uint16_t run);
    QByteArray Protocol_Reset(void);
    QByteArray Protocol_Stop(void);
    QByteArray Protocol_Continue(void);
signals:

public slots:

private:

};

#endif // PROTOCOL_H
