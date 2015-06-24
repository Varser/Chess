#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QSvgWidget>
#include<QPointer>
#include<QPair>

#include "player.h"

class ChessBoard : public QSvgWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = 0);
    void InitPlayers();
    QPair<QPointer<Player>, QPointer<Player> > GetPlayers();

private:
    QPointer<Player>    m_whitePlayer,
                        m_blackPlayer;
signals:

public slots:
};

#endif // CHESSBOARD_H
