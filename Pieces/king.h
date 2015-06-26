#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King(Color position, QWidget *parent = 0);
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);
};

#endif // KING_H
