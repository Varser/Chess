#include "queen.h"

#include "player.h"

const QString k_witePieceFilePath = ":/Images/queen_white.svg";
const QString k_blackPieceFilePath = ":/Images/queen_black.svg";

Queen::Queen(Color position, QWidget *parent) :
    Piece((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
    this->m_color = position;
    this->setGeometry(0, 0, g_k_PieceSize.width(), g_k_PieceSize.height());
    this->setFixedSize(g_k_PieceSize);
}

bool Queen::MayIGoHere(Coordinates position, Coordinates prev_position, QPointer<Player>& friends, QPointer<Player>& enemies)
{
    if ((position.x() == prev_position.x()) && (position.y() == prev_position.y()))
        return false;

    if ((prev_position.x() != position.x()) &&
                        (prev_position.y() != position.y()) &&
                        (prev_position.y() - prev_position.x() != position.y() - position.x()) &&
                        (prev_position.y() + prev_position.x() != position.y() + position.x()))
        return false;
    QPointer<Piece> pieceForDelete;
    if ((prev_position.x() != position.x()) && (prev_position.y() != position.y()))
    {
        for (int x = position.x(), y = position.y(); x != prev_position.x(), y != prev_position.y(); (position.x() < prev_position.x())?++x:--x, (position.y() < prev_position.y())?++y:--y)
        {
            if (!(friends->GetAnotherPiece(Coordinates(x, y), this).isNull()))
                return false;
            QPointer<Piece> piece = enemies->GetPiece(Coordinates(x, y));
            if (!piece.isNull())
            {
                if ((x == position.x()) && (y == position.y()))
                    pieceForDelete = piece;
                else
                    return false;
            }
        }
    }
    else
    {
        QPointer<Piece> piece;
        switch ((prev_position.x() == position.x()))
        {
        case true:
            for (int y = position.y(); y != prev_position.y(); (position.y() < prev_position.y())?++y:--y)
            {
                if (!(friends->GetAnotherPiece(Coordinates(position.x(), y), this).isNull()))
                    return false;
                piece = enemies->GetAnotherPiece(Coordinates(position.x(), y), this);
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
                if (!(friends->GetAnotherPiece(Coordinates(x, position.y()), this).isNull()))
                    return false;
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
    }
    if (!pieceForDelete.isNull())
        enemies->RemovePiece(pieceForDelete);
    return true;
}
