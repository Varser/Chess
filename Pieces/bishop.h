#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Color position, QWidget *parent = 0);
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);
};

#endif // BISHOP_H
