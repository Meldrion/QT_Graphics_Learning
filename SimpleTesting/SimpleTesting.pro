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
    tileitem.cpp \
    scene/abstractscenelayer.cpp \
    scene/tilelayer.cpp \
    scene/scenebackgroundwhitelayer.cpp \
    scene/mousecursorlayer.cpp \
    scene/mousecursor.cpp \
    scene/tilerenderer.cpp \
    scene/tiledata.cpp

HEADERS  += mainwindow.h \
    scenecanvas.h \
    tileset.h \
    scenerenderer.h \
    tileitem.h \
    scene/abstractscenelayer.h \
    scene/tilelayer.h \
    scene/scenebackgroundwhitelayer.h \
    scene/mousecursorlayer.h \
    scene/mousecursor.h \
    scene/tilerenderer.h \
    scene/tiledata.h

FORMS    += mainwindow.ui
