#include "pawn.h"

#include "player.h"

const QString k_witePieceFilePath = ":/Images/pawn_white.svg";
const QString k_blackPieceFilePath = ":/Images/pawn_black.svg";

Pawn::Pawn(Color position, QWidget *parent) :
    Piece((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
    this->m_color = position;
    this->setGeometry(0, 0, g_k_PieceSize.width(), g_k_PieceSize.height());
    this->setFixedSize(g_k_PieceSize);
}

bool Pawn::MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player> friends, QPointer<Player>& enemies, bool CheckForCheck/* = true*/)
{
    int dx = position.x() - prev_position.x();
    int dy = 0;

    QPointer<Piece> piece;
    switch(m_color)
    {
    case White:
        dy = position.y() - prev_position.y();
        if ((dy == 1) && ((dx == 1) || (dx == -1)))
        {
            piece = enemies->GetPiece(position);
            if (piece.isNull() && CheckForCheck)
                return false;
        }
        else if ((dx != 0) || ((dy != 1) &&
                ((prev_position.y() == 2)?(dy != 2):true)))
                return false;
        break;
    case Black:
        dy = prev_position.y() - position.y();
        if ((dy == 1) && ((dx == 1) || (dx == -1)))
        {
            piece = enemies->GetPiece(position);
            if (piece.isNull() && CheckForCheck)
                return false;
        }
        else if ((dx != 0) || ((dy != 1) &&
                ((prev_position.y() == 7)?(dy != 2):true)))
            return false;
    }

    if (dx == 0)
    {
        for (int y = position.y(); y != prev_position.y(); (position.y() < prev_position.y())?++y:--y)
        {
            if (!friends->GetAnotherPiece(Coordinates(position.x(), y), this).isNull())
            {
                piece.clear();
                return false;
            }
            if (!enemies->GetPiece(Coordinates(position.x(), y)).isNull())
            {
                piece.clear();
                return false;
            }
        }
    }

    if (CheckForCheck)
    {
        if (enemies->MaySomebodyGoHere(friends->GetKing(), friends, piece))
        {
            piece.clear();
            return false;
        }
    }
    if (CheckForCheck  && !piece.isNull())
        enemies->RemovePiece(piece);

    piece.clear();
    return true;
}
