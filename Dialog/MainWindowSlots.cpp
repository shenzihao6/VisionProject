#include "View/MainWindow.h"

void MainWindow::onFileNew(){

}

void MainWindow::onConfigureSetting(){

}


QAction* MainWindow::findMenuBarAction(QString text)
{
    QAction* ret = NULL;
    const QObjectList& list = menuBar()->children();

    for(int i=0; i<list.count(); i++)
    {
        QMenu* menu = dynamic_cast<QMenu*>(list[i]);

        if( menu != NULL )
        {
            QList<QAction*> actions = menu->actions();

            for(int j=0; j<actions.count(); j++)
            {
                if( actions[j]->text().startsWith(text) )
                {
                    ret = actions[j];
                    break;
                }
            }
        }
    }

    return ret;
}

QAction* MainWindow::findToolBarAction(QString text)
{
    QAction* ret = NULL;
    QList<QAction*> actions = toolBar()->actions();

    for(int j=0; j<actions.count(); j++)
    {
        if( actions[j]->toolTip().startsWith(text) )
        {
            ret = actions[j];
            break;
        }
    }

    return ret;
}

QToolBar* MainWindow::toolBar()
{
    QToolBar* ret = NULL;
    const QObjectList& list = children();

    for(int i=0; i<list.count(); i++)
    {
        QToolBar* tb = dynamic_cast<QToolBar*>(list[i]);

        if( tb != NULL )
        {
            ret = tb;
            break;
        }
    }

    return ret;
}
