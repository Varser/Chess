#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : /*public QSvgWidget,*/ public Piece
{
//    Q_OBJECT
public:
    Rook(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords pos);
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);

//signals:

//public slots:
};

#endif // ROOK_H
