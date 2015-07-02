#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook(Color position, QWidget *parent = 0);
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player> friends, QPointer<Player>& enemies, bool CheckForCheck = true);
};

#endif // ROOK_H
