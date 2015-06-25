#ifndef STARTGAME_PAGE_WIDGET_H
#define STARTGAME_PAGE_WIDGET_H

#include <QWidget>

#include"chessboard.h"

class StartGame_page_widget : public QWidget
{
    Q_OBJECT
public:
    explicit StartGame_page_widget(QWidget *parent = 0);

private:
    ChessBoard m_chessBoard;
    QWidget m_menu;
signals:

public slots:
};

#endif // STARTGAME_PAGE_WIDGET_H
