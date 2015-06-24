#include "rook.h"

const QString k_witePieceFilePath = ":/Images/rook_white.svg";
const QString k_blackPieceFilePath = ":/Images/rook_black.svg";

Rook::Rook(Color position, QWidget *parent) :
    QSvgWidget((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
}

void Rook::SetPosition(Coords)
{

}
