#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    QByteArray Protocol_Config(uint8_t motornum, uint8_t dir, uint16_t step);
signals:

public slots:

private:

};

#endif // PROTOCOL_H
