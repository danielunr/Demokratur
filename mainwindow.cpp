#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QProgressBar>
#include <iostream>
#include <windows.h>
#include <QCoreApplication>
#include <QPushButton>
#include <QIcon>
#include <QToolButton>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QSpinBox>
#include <QTextEdit>
#include <QEvent>
#include <QString>

#include <math.h>
#include <time.h>
#include <string>
#include <sstream>
#include <cmath>

#include "mainwindow.h"
#include "util.h"

#include "villager.h"
#include "talk.h"

#include "field.h"

//#include <thread>
#include "thread.h"

#include <QtDebug>

/*
The QPixmap class is an off-screen image representation that can be used as a paint device.

The QImage class provides a hardware-independent image representation that allows direct access to the pixel data, and can be used as a paint device.
*/

using namespace std;

field* root;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //TODO check default constructor
    view = new QGraphicsView(this);
    view->setFixedSize(10000, 10000);
    const QRectF rect = QRectF(0, 0, view->width(), view->height());
    view->fitInView(rect, Qt::KeepAspectRatio);
    view->setSceneRect(rect);
    scene = new QGraphicsScene(this);
    //1.)
    populateMenue();
    //initializeList();

    view->setScene(scene);
    connect(initButton, SIGNAL(released()), this, SLOT (populateScene()));
    connect(playerButton, SIGNAL(released()), this, SLOT (spawnPlayer()));
    connect(objectButton, SIGNAL(released()), this, SLOT (spawnObject()));
}

void MainWindow::refresh(field* root){
    //GET ONLY!
    int size = spinbox->value();
    field* rootTmp = root;
    int padding = 70;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            QPixmap pixmap = rootTmp->getQPixmap();
            QMessageLogger(__FILE__, __LINE__, 0).debug() << "root first field" << root->getQcolor();
            pixmap.fill(rootTmp->getQcolor());
            item = new QGraphicsPixmapItem(pixmap);
            QMessageLogger(__FILE__, __LINE__, 0).debug() << "QLocation " << i*padding << " : " << j*padding;
            root->setQLocation(position(i*padding, j*padding));
            QMessageLogger(__FILE__, __LINE__, 0).debug() << "Position " << root->getQLocation().getX() << " : " << root->getQLocation().getY();
            //TODO change this
            root->setPosition(position(j,i));

            item->setPos(root->getQLocation().getX(), root->getQLocation().getY());
            scene->addItem(item);
            rootTmp = rootTmp->rNeighbour;
        }
    }
}

void MainWindow::populateScene()
{
    //enable player button
    playerButton->setEnabled(true);
    int size = spinbox->value();
    QMessageLogger(__FILE__, __LINE__, 0).debug() << "test" << size;
    scene->clear();
    root = nullptr;
    // Populate scene
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            object o = object();
            //TODO refactor!!
            root = root->einfuegen(root, o);            
        }
    }
    MainWindow::refresh(root);
}

void MainWindow::setupFieldOrder() {
    int size = spinbox->value();
    const int x_const = 0;
    const int y_const = 0;
    int x_max = size -1;
    int y_max = size -1;
    field* thisElement = root;
    field* otherElementRightOf = nullptr;
    field* otherElementLeftOf = nullptr;
    field* otherElementBelow = nullptr;
    field* otherElementAbove = nullptr;
    int y = y_const;
    for (y; y <= y_max; y++) {
        int x = x_const;
        for(x; x <= x_max; x++) {
            //thisElement = field::findElementById(root, util::calcPos(x, y, x_max+1));
            thisElement = field::findElementByPos(thisElement, position(x,y));
            otherElementRightOf = field::findElementByPos(thisElement, position(x-1,y));
            otherElementLeftOf = field::findElementByPos(thisElement, position(x+1,y));
            otherElementBelow = field::findElementByPos(thisElement, position(x,y+1));
            otherElementAbove = field::findElementByPos(thisElement, position(x,y-1));
            /*special cases - wrap around*/
            if (x == 0 || x == x_max || y == 0 || y == y_max) {
                if (x == 0) {
                    otherElementRightOf = field::findElementByPos(thisElement, position(x_max,y));
                }
                if (x == x_max) {
                    otherElementLeftOf = field::findElementByPos(thisElement, position(x_const,y));
                }
                if (y == 0) {
                    otherElementBelow = field::findElementByPos(thisElement, position(x,y_max));
                }
                if (y == y_max) {
                    otherElementAbove = field::findElementByPos(thisElement, position(x,y_const));
                }
            }

            thisElement->rightOf = otherElementRightOf;
            thisElement->leftOf = otherElementLeftOf;
            thisElement->above = otherElementAbove;
            thisElement->below = otherElementBelow;
        }
    }
}

void MainWindow::instantiatePayer(){
    //TODO refactor (field -> object -> color)
     field* spawnField = nullptr;
    spawnField = field::findElementByPos(root, position(0,0));
    spawnField->setQColor(QColor(Qt::red));
    MainWindow::refresh(root);
}

void MainWindow::spawnPlayer()
{
    MainWindow::instantiatePayer();
    /*thread::Thread t;
    t.start();*/
}

/*void MainWindow::spawnObject()
{
    //TODO random class extend object
}*/

void MainWindow::populateMenue()
{
    spinbox = new QSpinBox(this);
    spinbox->setGeometry(QRect(850,30,80,30));
    spinbox->setMinimum(1);
    spinbox->setMaximum(10);
    scene->addWidget(spinbox);

    initButton = new QPushButton(this);
    initButton->setText("Spielfeld initialisieren");
    initButton->setGeometry(QRect(820,60,110,30));
    scene->addWidget(initButton);

    playerButton = new QPushButton(this);
    playerButton->setText("Spawn Player");
    playerButton->setEnabled(false);
    playerButton->setGeometry(QRect(820,100,80,30));
    scene->addWidget(playerButton);

    objectButton = new QPushButton(this);
    objectButton->setText("Spawn Object");
    objectButton->setEnabled(false);
    objectButton->setGeometry(QRect(820,140,80,30));
    scene->addWidget(objectButton);
}

MainWindow::~MainWindow()
{
    delete scene;
}
