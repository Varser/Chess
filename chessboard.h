#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QSvgWidget>
#include <QPointer>
#include <QPair>
#include <QMouseEvent>

#include "player.h"

extern const QSize g_k_chessBoardSize;

class ChessBoard : public QSvgWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = 0);
    void InitPlayers();
    QPair<QPointer<Player>, QPointer<Player> > GetPlayers();
    void StartGame();
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

private:
    QPointer<Player> GetActivePlayer();
    void ChangeActivePlayer();

private:
    QPointer<Player>    m_whitePlayer,
                        m_blackPlayer;

private:
    QPointer<Piece> m_piece;
    QPoint m_savedCoords;
signals:

public slots:
};

#endif // CHESSBOARD_H
