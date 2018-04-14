#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T08:29:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demokratur
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    party.cpp \
    talk.cpp \
    villager.cpp \
    contact.cpp \
    field.cpp \
    object.cpp \
    player.cpp \
    magnet.cpp \
    block.cpp \
    position.cpp \
    probability.cpp \
    thread.cpp

HEADERS += \
        mainwindow.h \
    contact.h \
    party.h \
    talk.h \
    villager.h \
    util.h \
    field.h \
    object.h \
    player.h \
    magnet.h \
    block.h \
    position.h \
    probability.h \
    thread.h

FORMS += \
        mainwindow.ui
