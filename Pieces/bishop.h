#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public /*Piece, */QSvgWidget
{
    Q_OBJECT
public:
    Bishop(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);

signals:

public slots:
};

#endif // BISHOP_H
