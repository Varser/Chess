#ifndef PIECE_H
#define PIECE_H

#include <QSvgWidget>
#include <QString>

struct Coords
{
    qint8 x, y;
    Coords(int _x, int _y) : x(_x), y(_y){}
};

enum Color
{
    White,
    Black
};

class Piece
{
public:
    virtual void SetPosition(Coords) = 0;
};

#endif // PIECE_H
