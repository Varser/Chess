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
    void StartGame();
    void StopGame();
    void SetStepWithKillIfNeed(std::pair<Coordinates, Coordinates> step);
    void SetStepWithRestoreIfNeed(std::pair<Coordinates, Coordinates> step);

private:
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

private:
    QPointer<Player> GetActivePlayer();
    void ChangeActivePlayer();

private:
    QPointer<Player>    m_whitePlayer,
                        m_blackPlayer;
    QPointer<Piece> m_piece;
    Coordinates m_savedCoords;
    bool m_track;
public slots:
    void Prev();
    void Next();
    void Save();
    void Load();

};

#endif // CHESSBOARD_H
