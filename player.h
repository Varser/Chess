#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVector>
#include <QPointer>
#include <QStack>

#include"piece.h"


class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    void Init(Color);
    bool isActivePlayer();
    void SetActivePlayer(bool enable);
    QPointer<Piece> GetPiece(Coordinates coordinates);
    QPointer<Piece> GetAnotherPiece(Coordinates coordinates, QPointer<Piece> excluded);
    void RemovePiece(QPointer<Piece> piece);
    bool isLoose();
    void Restore(Coordinates coordinates, size_t move);
    bool MaySomebodyGoHere(Coordinates coordinates, QPointer<Player> emenies);
    inline void DecrementMove() {--m_move;}
    inline void IncrementMove() {++m_move;}
    Coordinates GetKing();

private:
    QVector<QPointer<Piece> > m_pieces;
    QStack<std::pair<QPointer<Piece> , size_t> > m_killedPieces;
    QPointer<Piece> m_king;
    bool m_active;
    size_t m_move;

signals:

public slots:
};

#endif // PLAYER_H
