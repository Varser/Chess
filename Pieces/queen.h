#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : /*public QSvgWidget,*/ public Piece
{
//    Q_OBJECT
public:
    Queen(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies);

//signals:

//public slots:
};

#endif // QUEEN_H
