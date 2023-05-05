#include "mainwindow.h"
#include <QApplication>
#include "screen/mainobject.h"
#include "gv.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//启动界面
    MainObject mainObject;
    mainObject.setInit();

//    uint8_t data123 = 10;
//    printf("data = %x\n" , data123);
//    printf("~data= %x\n" , data123);

//    MainWindow m;
//    m.show();

//    QByteArray data;
//    data.append(0x52);
//    data.append(0x53);
//    data.append(0x54);
//    data.append(0x55);
//    file *file = new class file();
//    file->logInit();
//    file->logWrite(data);

//    sqlite sql;

//    informationInit(FILE);


    return a.exec();
}
