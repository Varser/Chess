#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn(Color position, QWidget *parent = 0);
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);
};

#endif // PAWN_H
