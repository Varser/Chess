#include "pawn.h"

const QString k_witePieceFilePath = ":/Images/pawn_white.svg";
const QString k_blackPieceFilePath = ":/Images/pawn_black.svg";

Pawn::Pawn(Color position, QWidget *parent) :
    QSvgWidget((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
}

void Pawn::SetPosition(Coords)
{

}
