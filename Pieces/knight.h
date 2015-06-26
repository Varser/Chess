#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight(Color position, QWidget *parent = 0);
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);
};

#endif // KNIGHT_H
