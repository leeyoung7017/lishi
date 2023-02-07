#ifndef INI_H
#define INI_H

#include <QString>
#include <QSettings>
#include <QCryptographicHash>

typedef enum{
    code = true,
    decode = false
}codec;

#define KEY 0x55

void passwd_changed(QString str);   //修改密码
bool passwd_cmp(QString str);  //判断密码
QString passwd_key_codec(QString str, QChar key=KEY);
QString passwd_codec(QString str,bool flag);    //密码加密

#endif // INI_H
