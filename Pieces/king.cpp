#include "king.h"

#include "player.h"

const QString k_witePieceFilePath = ":/Images/king_white.svg";
const QString k_blackPieceFilePath = ":/Images/king_black.svg";

King::King(Color position, QWidget *parent) :
    Piece((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)

{
    this->m_color = position;
    this->setGeometry(0, 0, g_k_PieceSize.width(), g_k_PieceSize.height());
    this->setFixedSize(g_k_PieceSize);
}

bool King::MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player> friends, QPointer<Player>& enemies, bool CheckForCheck/* = true*/)
{
    if (CheckForCheck)
    {
        if (enemies->MaySomebodyGoHere(friends->GetKing(), friends))
            return false;
    }
    if ((position.x() == prev_position.x()) && (position.y() == prev_position.y()))
        return false;

    int dx = position.x() - prev_position.x();
    int dy = position.y() - prev_position.y();
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    if (!((dx < 2) &&
            (dy < 2)))
        return false;
    if (CheckForCheck)
    {
        if (!(friends->GetAnotherPiece(position, this).isNull()))
            return false;
    }
    QPointer<Piece> piece = enemies->GetPiece(position);
    if (!piece.isNull())
    {
        enemies->RemovePiece(piece);
        return true;
    }
    return true;
}
