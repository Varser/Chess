#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public /*Piece, */QSvgWidget
{
    Q_OBJECT
public:
    Rook(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);

signals:

public slots:
};

#endif // ROOK_H
