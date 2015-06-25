#ifndef KING_H
#define KING_H

#include "piece.h"

class King : /*public QSvgWidget,*/ public Piece
{
//    Q_OBJECT
public:
    King(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);

//signals:

//public slots:
};

#endif // KING_H
