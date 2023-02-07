/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：初始化类
 * ***************************************/
#include "mainobject.h"
#include "mainwindow.h"
#include "splashscreen.h"


MainObject::MainObject(QObject *parent) :
    QObject(parent)
{
}

MainObject::~MainObject()
{
    delete m_mainWindow;
}

void MainObject::setInit()
{
    SplashScreen::getInstance()->setStagePercent(0,tr("初始化应用程序 ..."));
    m_mainWindow = new MainWindow(nullptr);
    m_mainWindow->setWindowTitle(tr("细胞样本自动染色仪"));
    m_mainWindow->setWindowIcon(QIcon(":/pic/lishi.ico"));
    SplashScreen::getInstance()->setStart(m_mainWindow, tr("QCoolPage"), QString(":/pic/lishi.png"));
    SplashScreen::getInstance()->setStagePercent(40, tr("初始化主界面 ..."));
    SplashScreen::getInstance()->setStagePercent(80, tr("加载界面 ..."));
    SplashScreen::getInstance()->setStagePercent(100, tr("加载完毕！"));
    SplashScreen::getInstance()->setFinish();

//    m_mainWindow->showNormal();
//    m_mainWindow->showFullScreen();
    QSize size = QGuiApplication::primaryScreen()->size();
    m_mainWindow->move((size.width() - m_mainWindow->width()) / 2, (size.height() - m_mainWindow->height()) / 2);
    m_mainWindow->show();
}


