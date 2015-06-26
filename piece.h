#ifndef PIECE_H
#define PIECE_H

#include <QSvgWidget>
#include <QString>

class Player;

extern const QSize g_k_PieceSize;

class Coordinates
{
public:
    Coordinates() : m_x(1), m_y(1){}

    Coordinates(int _x, int _y, bool real = false)
    {
        if (!real)
        {
            m_x = _x;
            m_y = _y;
        }
        else
        {
            m_x = _x/g_k_PieceSize.width() + 1;
            m_y = (8*g_k_PieceSize.height() - _y)/g_k_PieceSize.height() + 1;
        }
        if (m_x < 1)
            m_x = 1;
        if (m_x > 8)
            m_x = 8;
        if (m_y < 1)
            m_y = 1;
        if (m_y > 8)
            m_y = 8;
    }

    Coordinates(const QPoint& realCoords, bool real = false)
    {
        if (!real)
        {
            m_x = realCoords.x();
            m_y = realCoords.y();
        }
        else
        {
            m_x = realCoords.x()/g_k_PieceSize.width() + 1;
            m_y = (8*g_k_PieceSize.height() - realCoords.y())/g_k_PieceSize.height() + 1;
        }
        if (m_x < 1)
            m_x = 1;
        if (m_x > 8)
            m_x = 8;
        if (m_y < 1)
            m_y = 1;
        if (m_y > 8)
            m_y = 8;
    }

    inline QPoint RealCoordinates() const
    {
        return QPoint(g_k_PieceSize.width()*(m_x - 1), 7*g_k_PieceSize.height() - g_k_PieceSize.height()*(m_y - 1));
    }

    inline QPoint AbstractCoordinates() const
    {
        return QPoint(m_x, m_y);
    }

    inline int x() const
    {
        return m_x;
    }

    inline int y() const
    {
        return m_y;
    }

    inline int rx() const
    {
        return g_k_PieceSize.width()*(m_x - 1);
    }

    inline int ry() const
    {
        return 7*g_k_PieceSize.height() - g_k_PieceSize.height()*(m_y - 1);
    }

private:
    qint8 m_x, m_y;
};

enum Color
{
    White,
    Black
};

class Piece : public QSvgWidget
{
    Q_OBJECT
public:
    Piece(const QString& str, QWidget * wgt = 0) : QSvgWidget(str, wgt){}
    virtual bool MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player>& friends, QPointer<Player>& enemies) = 0;
    inline bool IsItMyPosition(Coordinates coordinates) const
    {
       return ((m_coordinates.x() ==  coordinates.AbstractCoordinates().x()) && (m_coordinates.y() ==  coordinates.AbstractCoordinates().y()));
    }

    inline void SetPosition(Coordinates coordinates)
    {
        this->m_coordinates = coordinates.AbstractCoordinates();
        this->move(coordinates.RealCoordinates());
    }

protected:
    Coordinates m_coordinates;
    Color m_color;

signals:

public slots:
};

#endif // PIECE_H
