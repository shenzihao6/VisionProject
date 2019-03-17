#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QKeySequence>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    bool construct();
    bool initMenuBar();
    bool initToolBar();
    bool intStatusBar();
    /*菜单的种类*/
    bool initFileMenu(QMenuBar* mb);
    bool initConfigureMenu(QMenuBar* mb);

    bool makeAction(QAction*& action, QWidget* parent, QString text, int key);
    bool makeAction(QAction*& action, QWidget* parent, QString tip, QString icon);

    QAction* findMenuBarAction(QString text);
    QAction* findToolBarAction(QString text);

    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator= (const MainWindow&);

private slots:
    void onFileNew();
    void onConfigureSetting();

public:
    static MainWindow* NewInstance();
    QToolBar* toolBar();
    ~MainWindow();
};

#endif // MAINWINDOWUI_H
