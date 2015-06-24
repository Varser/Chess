#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public /*Piece, */QSvgWidget
{
    Q_OBJECT
public:
    King(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);

signals:

public slots:
};

#endif // KING_H
