#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVector>

#include"piece.h"

class Coords;

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    void Init(Color);
    bool UnderCheck(Coords);

private:
//    QVector<Piece> m_pieces;

signals:

public slots:
};

#endif // PLAYER_H
