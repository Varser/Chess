#include "bishop.h"

#include "player.h"

extern const QSize g_k_PieceSize(100, 100);

const QString k_witePieceFilePath = ":/Images/bishop_white.svg";
const QString k_blackPieceFilePath = ":/Images/bishop_black.svg";

Bishop::Bishop(Color position, QWidget *parent) :
    Piece((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
    this->m_color = position;
    this->setGeometry(0, 0, g_k_PieceSize.width(), g_k_PieceSize.height());
    this->setFixedSize(g_k_PieceSize);
}

void Bishop::SetPosition(Coords pos)
{
    this->m_position = pos.AbstractCoords();
    this->move(pos.RealCoords());
}

bool Bishop::MayIGoHere(QPoint position, QPoint prev_position, QPointer<Player>& friends, QPointer<Player>& enemies)
{
    if ((position.x() == prev_position.x()) && (position.y() == prev_position.y()))
        return false;
    if ((prev_position.y() - prev_position.x() != position.y() - position.x()) &&
            (prev_position.y() + prev_position.x() != position.y() + position.x()))
        return false;
    QPointer<Piece> pieceForDelete;
    for (int x = position.x(), y = position.y(); x != prev_position.x(), y != prev_position.y(); (position.x() < prev_position.x())?++x:--x, (position.y() < prev_position.y())?++y:--y)
    {
        if (!(friends->GetAnotherPiece(Coords(x, y), this).isNull()))
            return false;
        QPointer<Piece> piece = enemies->GetPiece(Coords(x, y));
        if (!piece.isNull())
        {
            if ((x == position.x()) && (y == position.y()))
                pieceForDelete = piece;
            else
                return false;
        }
    }
    if (!pieceForDelete.isNull())
        enemies->RemovePiece(pieceForDelete);
    return true;
}

