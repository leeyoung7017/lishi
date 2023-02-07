#include "mainwindow.h"
#include <QApplication>
#include "screen/mainobject.h"
#include "ini.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    passwd_changed("0");

    MainObject mainObject;
    mainObject.setInit();
//    LOADQSS(GlobalSpace::STYLE_QSS_FILE_PATH);

    return a.exec();
}
