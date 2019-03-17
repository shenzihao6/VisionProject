#include "MainWindow.h"

MainWindow::MainWindow(){

}

MainWindow* MainWindow::NewInstance(){
    MainWindow* ret = new MainWindow();

    if( (ret == NULL) || !ret->construct() ){
        delete ret;
        ret = NULL;
    }

    return ret;
}

bool MainWindow::construct(){
    bool ret = true;

    ret = ret && initMenuBar();
    ret = ret && initToolBar();

    return ret;
}

bool MainWindow::initMenuBar(){
    bool ret = true;
    QMenuBar* mb = menuBar();

    ret = ret && initFileMenu(mb);
    ret = ret && initConfigureMenu(mb);

    return ret;
}

bool MainWindow::initToolBar()
{
    bool ret = true;

    return ret;
}

bool MainWindow::initFileMenu(QMenuBar *mb){
    QMenu* menu = new QMenu("File(&F)", mb);
    bool ret = (menu != NULL);

    if( ret ){
        QAction* action = NULL;

        ret = ret && makeAction(action, menu, "new(&N)", Qt::CTRL + Qt::Key_N);

        if( ret ){
            connect(action, SIGNAL(triggered(bool)), this, SLOT(onFileNew()));
            menu->addAction(action);
        }
    }

    if( ret ){
        mb->addMenu(menu);
    }
    else{
        delete menu;
    }

    return ret;
}

bool MainWindow::initConfigureMenu(QMenuBar *mb){
    QMenu* menu = new QMenu("Configure(&C)", mb);
    bool ret = (menu != NULL);

    if( ret ){
        QAction* action = NULL;

        ret = ret && makeAction(action, menu, "Settings(&S)", Qt::CTRL + Qt::Key_S);

        if( ret ){
            connect(action, SIGNAL(triggered()), this, SLOT(onConfigureSetting()));
            menu->addAction(action);
        }
    }

    if( ret ){
        mb->addMenu(menu);
    }
    else{
        delete menu;
    }

    return ret;
}


bool MainWindow::makeAction(QAction*& action, QWidget* parent, QString text, int key){
    bool ret = true;

    action = new QAction(text, parent);

    if( action != NULL ){
        action->setShortcut(QKeySequence(key));
    }
    else{
        ret = false;
    }

    return ret;
}

bool MainWindow::makeAction(QAction*& action, QWidget* parent, QString tip, QString icon){
    bool ret = true;

    action = new QAction("", parent);

    if( action != NULL ){
        action->setToolTip(tip);
        action->setIcon(QIcon(icon));
    }
    else{
        ret = false;
    }

    return ret;
}

MainWindow::~MainWindow(){

}
