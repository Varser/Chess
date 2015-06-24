#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public /*Piece, */QSvgWidget
{
    Q_OBJECT
public:
    Queen(Color position, QWidget *parent = 0);
    virtual void SetPosition(Coords);

signals:

public slots:
};

#endif // QUEEN_H
