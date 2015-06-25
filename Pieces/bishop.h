#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : /*public QSvgWidget,*/ public Piece
{
//    Q_OBJECT
public:
    Bishop(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);

//signals:

//public slots:
};

#endif // BISHOP_H
