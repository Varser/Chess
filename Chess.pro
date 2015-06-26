#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T00:30:50
#
#-------------------------------------------------

QT       += core gui
QT       += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    welcome_page_widget.cpp \
    startgame_page_widget.cpp \
    loadgame_page_widget.cpp \
    emptychessboard_page_widget.cpp \
    player.cpp \
    chessboard.cpp \
    Pieces/bishop.cpp \
    Pieces/king.cpp \
    Pieces/queen.cpp \
    Pieces/knight.cpp \
    Pieces/pawn.cpp \
    Pieces/rook.cpp \
    logger.cpp

HEADERS  += mainwindow.h \
    welcome_page_widget.h \
    startgame_page_widget.h \
    loadgame_page_widget.h \
    emptychessboard_page_widget.h \
    player.h \
    chessboard.h \
    piece.h \
    Pieces/bishop.h \
    Pieces/king.h \
    Pieces/queen.h \
    Pieces/knight.h \
    Pieces/pawn.h \
    Pieces/rook.h \
    logger.h

FORMS    += mainwindow.ui

RESOURCES += \
    chessresources.qrc
