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
    void StopGame();
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void ChangeActivePlayer();
    void SetActivePlayerPieceCoordinates(Coordinates current, Coordinates prev);

private:
    QPointer<Player> GetActivePlayer();

private:
    QPointer<Player>    m_whitePlayer,
                        m_blackPlayer;

private:
    QPointer<Piece> m_piece;
    Coordinates m_savedCoords;
signals:

public slots:
};

#endif // CHESSBOARD_H
