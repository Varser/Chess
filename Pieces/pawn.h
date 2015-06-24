#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public /*Piece, */QSvgWidget
{
    Q_OBJECT
public:
    Pawn(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);

signals:

public slots:
};

#endif // PAWN_H
