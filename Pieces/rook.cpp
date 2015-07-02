#include "rook.h"

#include "player.h"

const QString k_witePieceFilePath = ":/Images/rook_white.svg";
const QString k_blackPieceFilePath = ":/Images/rook_black.svg";

Rook::Rook(Color position, QWidget *parent) :
    Piece((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
    this->m_color = position;
    this->setGeometry(0, 0, g_k_PieceSize.width(), g_k_PieceSize.height());
    this->setFixedSize(g_k_PieceSize);
}

bool Rook::MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player> friends, QPointer<Player>& enemies, bool CheckForCheck/* = true*/)
{
    if (CheckForCheck)
    {
        if (enemies->MaySomebodyGoHere(friends->GetKing(), friends))
            return false;
    }
    if ((position.x() == prev_position.x()) && (position.y() == prev_position.y()))
        return false;

    if (!((prev_position.x() == position.x()) ||
                       (prev_position.y() == position.y())))
        return false;
    QPointer<Piece> piece;
    QPointer<Piece> pieceForDelete;
    switch ((prev_position.x() == position.x()))
    {
    case true:
        for (int y = position.y(); y != prev_position.y(); (position.y() < prev_position.y())?++y:--y)
        {
            if ((position != Coordinates(position.x(), y)) || CheckForCheck)
            {
                if (!(friends->GetAnotherPiece(Coordinates(position.x(), y), this).isNull()))
                    return false;
            }
            piece = enemies->GetPiece(Coordinates(position.x(), y));
            if (!piece.isNull())
            {
                if (y == position.y())
                    pieceForDelete = piece;
                else
                    return false;
            }
        }
        break;
    case false:
        for (int x = position.x(); x != prev_position.x(); (position.x() < prev_position.x())?++x:--x)
        {
            if ((position != Coordinates(x, position.y())) || CheckForCheck)
            {
                if (!(friends->GetAnotherPiece(Coordinates(x, position.y()), this).isNull()))
                    return false;
            }
            piece = enemies->GetPiece(Coordinates(x, position.y()));
            if (!piece.isNull())
            {
                if (x == position.x())
                    pieceForDelete = piece;
                else
                    return false;
            }
        }
        break;
    }
    if (!pieceForDelete.isNull() && CheckForCheck)
        enemies->RemovePiece(piece);
    return true;
}
