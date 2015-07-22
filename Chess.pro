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
    player.cpp \
    chessboard.cpp \
    Pieces/bishop.cpp \
    Pieces/king.cpp \
    Pieces/queen.cpp \
    Pieces/knight.cpp \
    Pieces/pawn.cpp \
    Pieces/rook.cpp \
    logger.cpp \
    Widgets/emptychessboard_page_widget.cpp \
    Widgets/loadgame_page_widget.cpp \
    Widgets/startgame_page_widget.cpp \
    Widgets/welcome_page_widget.cpp

HEADERS  += mainwindow.h \
    player.h \
    chessboard.h \
    piece.h \
    Pieces/bishop.h \
    Pieces/king.h \
    Pieces/queen.h \
    Pieces/knight.h \
    Pieces/pawn.h \
    Pieces/rook.h \
    logger.h \
    coordsandcolor.h \
    Widgets/emptychessboard_page_widget.h \
    Widgets/loadgame_page_widget.h \
    Widgets/startgame_page_widget.h \
    Widgets/welcome_page_widget.h

FORMS    += mainwindow.ui

RESOURCES += \
    chessresources.qrc
