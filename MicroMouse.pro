#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T23:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MicroMouse
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maze.cpp \
    mouse.cpp \
    game.cpp \
    point.cpp

HEADERS  += mainwindow.h \
    maze.h \
    mouse.h \
    game.h \
    point.h \
    cell.h

FORMS    += mainwindow.ui
