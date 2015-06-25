#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVector>
#include <QPointer>

#include"piece.h"


class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    void Init(Color);
    bool UnderCheck(Coords);
    bool isActivePlayer();
    void SetActivePlayer(bool enable);
    QPointer<Piece> GetPiece(Coords position);
    QPointer<Piece> GetAnotherPiece(Coords position, QPointer<Piece> excluded);
    void RemovePiece(QPointer<Piece> piece);

private:
    QVector<QPointer<Piece> > m_pieces;
    bool m_active;

signals:

public slots:
};

#endif // PLAYER_H
