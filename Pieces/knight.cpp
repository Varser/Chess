#include "knight.h"

#include "player.h"

const QString k_witePieceFilePath = ":/Images/knight_white.svg";
const QString k_blackPieceFilePath = ":/Images/knight_black.svg";

Knight::Knight(Color position, QWidget *parent) :
    Piece((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
    this->m_color = position;
    this->setGeometry(0, 0, g_k_PieceSize.width(), g_k_PieceSize.height());
    this->setFixedSize(g_k_PieceSize);
}

void Knight::SetPosition(Coords pos)
{
    this->m_position = pos.AbstractCoords();
    this->move(pos.RealCoords());
}

bool Knight::MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies)
{
    int dx = position.x() - prev_position.x();
    int dy = position.y() - prev_position.y();
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    if (!(((dx == 2) && (dy == 1)) ||
            ((dx == 1) && (dy == 2))))
        return false;
    if (!friends->GetAnotherPiece(Coords(position.x(), position.y()), this).isNull())
        return false;
    QPointer<Piece> piece = enemies->GetPiece(Coords(position.x(), position.y()));
    if (!piece.isNull())
    {
        enemies->RemovePiece(piece);
        return true;
    }
    return true;
}
