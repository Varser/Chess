#ifndef LOADGAME_PAGE_WIDGET_H
#define LOADGAME_PAGE_WIDGET_H

#include <QWidget>
#include"chessboard.h"

class LoadGame_page_widget : public QWidget
{
    Q_OBJECT
public:
    explicit LoadGame_page_widget(QWidget *parent = 0);

    void StartFromThis();
    void Next();
    void Prev();

private:
    ChessBoard m_chessBoard;
    QWidget m_menu;

signals:

public slots:
};

#endif // LOADGAME_PAGE_WIDGET_H
