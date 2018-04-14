#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QIcon>
#include <QToolButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QRectF>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QSpinBox>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QString>

#include <iostream>

#include "villager.h"
#include "field.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);    
    ~MainWindow();
public slots:
    void populateScene();
    void populateMenue();
    void spawnPlayer();
    void instantiatePayer();
    void refresh(field* anker);
    void setupFieldOrder();

private:
    QSpinBox * spinbox;
    QSpinBox * spinboxPlayer;

    QPushButton *initButton;
    QPushButton *playerButton;
    QPushButton *objectButton;

    QIcon *icon;
    QPixmap *pixmap;
    QLabel *label;
    QImage *image;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit2;
    QPlainTextEdit *plainTextEdit3;
    QString *qString;

};
#endif // MAINWINDOW_H
