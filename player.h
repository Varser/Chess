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
    bool isActivePlayer();
    void SetActivePlayer(bool enable);
    QPointer<Piece> GetPiece(Coordinates coordinates);
    QPointer<Piece> GetAnotherPiece(Coordinates coordinates, QPointer<Piece> excluded);
    void RemovePiece(QPointer<Piece> piece);
    inline bool isLoose() const {return m_pieces.size();}

private:
    QVector<QPointer<Piece> > m_pieces;
    QPointer<Piece> m_king;
    bool m_active;

signals:

public slots:
};

#endif // PLAYER_H
