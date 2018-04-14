#include "mainwindow.h"
#include <QProgressBar>
#include <QApplication>
#include <windows.h>
#include <QDesktopWidget>

/*
 * 1) http://www.learncpp.com/cpp-tutorial/112-basic-inheritance-in-c/
 * 2) https://www.google.de/search?q=c%2B%2B+constant+correctnes&ie=utf-8&oe=utf-8&client=firefox-b&gfe_rd=cr&dcr=0&ei=ommzWtvtMtCGgAbP-bWYDw
 */

int main(int argc, char *argv[])
{
    //GraphicsView
    //GraphicsScene

    QApplication a(argc, argv);
    QDesktopWidget desktopWidget;
    MainWindow window;

    window.setFixedSize(desktopWidget.width()*0.7, desktopWidget.height()*0.7);
    window.show();
    return a.exec();
}
