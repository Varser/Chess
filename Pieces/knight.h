#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public /*Piece, */QSvgWidget
{
    Q_OBJECT
public:
    Knight(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);

signals:

public slots:
};

#endif // KNIGHT_H
