#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : /*public QSvgWidget,*/ public Piece
{
//    Q_OBJECT
public:
    Knight(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);

//signals:

//public slots:
};

#endif // KNIGHT_H
