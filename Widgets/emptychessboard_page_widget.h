#ifndef EMPTYCHESSBOARD_PAGE_WIDGET_H
#define EMPTYCHESSBOARD_PAGE_WIDGET_H

#include <QWidget>

#include"chessboard.h"

class EmptyChessBoard_page_widget : public QWidget
{
    Q_OBJECT
public:
    explicit EmptyChessBoard_page_widget(QWidget *parent = 0);

private:
    ChessBoard m_chessBoard;
    QWidget m_menu;

signals:

public slots:
};

#endif // EMPTYCHESSBOARD_PAGE_WIDGET_H
