#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T00:30:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    welcome_page_widget.cpp \
    startgame_page_widget.cpp \
    loadgame_page_widget.cpp \
    emptychessboard_page_widget.cpp

HEADERS  += mainwindow.h \
    welcome_page_widget.h \
    startgame_page_widget.h \
    loadgame_page_widget.h \
    emptychessboard_page_widget.h

FORMS    += mainwindow.ui
