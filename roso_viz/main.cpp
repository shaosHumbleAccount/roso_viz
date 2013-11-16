#include <QtGui/QApplication>
#include "mainwindow.h"
#include "util/logger.h"
#include "udpserver.h"
#include "Setting/settingcenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingCenter::singleton();//init settingCenter

    MainWindow w;
    w.show();

    //udpServer.start();

    return a.exec();
}
