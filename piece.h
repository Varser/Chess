#ifndef PIECE_H
#define PIECE_H

#include <QSvgWidget>
#include <QString>

#include "coordsandcolor.h"

class Player;

class Piece : public QSvgWidget
{
    Q_OBJECT
public:
    Piece(const QString& str, QWidget * wgt = 0) : QSvgWidget(str, wgt){}
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player> friends, QPointer<Player>& enemies, bool CheckForCheck = true) = 0;
    inline bool IsItMyPosition(Coordinates coordinates) const
    {
       return m_coordinates ==  coordinates;
    }

    inline void SetPosition(Coordinates coordinates)
    {
        this->m_coordinates = coordinates.AbstractCoordinates();
        this->move(coordinates.RealCoordinates());
    }

    inline Coordinates GetMyCoordinates()
    {
        return this->m_coordinates;
    }

protected:
    Coordinates m_coordinates;
    Color m_color;
};

#endif // PIECE_H
