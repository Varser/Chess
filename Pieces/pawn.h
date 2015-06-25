#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : /*public QSvgWidget,*/ public Piece
{
//    Q_OBJECT
public:
    Pawn(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);

//signals:

//public slots:
};

#endif // PAWN_H
