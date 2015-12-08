#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T18:18:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleTesting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scenecanvas.cpp \
    tileset.cpp \
    scenerenderer.cpp \
    currentscenecanvas.cpp \
    tileitem.cpp

HEADERS  += mainwindow.h \
    scenecanvas.h \
    tileset.h \
    scenerenderer.h \
    currentscenecanvas.h \
    tileitem.h

FORMS    += mainwindow.ui
