#include "View/MainWindow.h"
#include <QApplication>
#include <QSplashScreen>
#include "DataStructure/MSysInfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* w = MainWindow::NewInstance();

    int ret = -1;

    if( w != NULL ){
        QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap("./Images/splash.jpg"));
        splash->show();

        Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

        splash->showMessage(QObject::tr("Setting up the main window..."), topRight, Qt::white);
        splash->showMessage(QObject::tr("Loading data..."), topRight, Qt::white);

        MSysInfo::Instance()->Init();

        splash->showMessage(QObject::tr("Establishing connections..."), topRight, Qt::white);

        MSysInfo::Instance()->Open();

        w->show();

        ret = a.exec();
    }

    return ret;
}
