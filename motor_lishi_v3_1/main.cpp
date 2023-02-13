#include "mainwindow.h"
#include <QApplication>
#include "screen/mainobject.h"
#include "gv.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//启动界面
//    MainObject mainObject;
//    mainObject.setInit();

    MainWindow m;
    m.show();

//    sqlite sql;

//    informationInit(FILE);


    return a.exec();
}
