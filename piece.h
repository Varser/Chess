#ifndef PIECE_H
#define PIECE_H

#include <QSvgWidget>
#include <QString>

#include <cassert>

class Player;

extern const QSize g_k_PieceSize;

class Coords
{
public:
//    Coords(){}
    Coords(int _x, int _y) : x(_x), y(_y){}
    Coords(QPoint realCoords) : x(realCoords.x()/g_k_PieceSize.width() + 1), y((8*g_k_PieceSize.height() - realCoords.y())/g_k_PieceSize.height() + 1){}
    inline QPoint RealCoords()
    {
        assert(x > 0);
        assert(y > 0);
        return QPoint(g_k_PieceSize.width()*(x - 1), 7*g_k_PieceSize.height() - g_k_PieceSize.height()*(y - 1));
    }
    inline QPoint AbstractCoords()
    {
        assert(x > 0);
        assert(y > 0);
        return QPoint(x, y);
    }

private:
    qint8 x, y;
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
    Piece(QString str, QWidget * wgt = 0) : QSvgWidget(str, wgt){}
    virtual void SetPosition(Coords) = 0;
    virtual bool MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies) = 0;
    inline bool IsItMyPosition(Coords coord)
    {
       return ((m_position.x() ==  coord.AbstractCoords().x()) && (m_position.y() ==  coord.AbstractCoords().y()));
    }

protected:
    QPoint m_position;
    Color m_color;

signals:

public slots:
};

#endif // PIECE_H
