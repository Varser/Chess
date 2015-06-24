#include "knight.h"

const QString k_witePieceFilePath = ":/Images/knight_white.svg";
const QString k_blackPieceFilePath = ":/Images/knight_black.svg";

Knight::Knight(Color position, QWidget *parent) :
    QSvgWidget((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
}

void Knight::SetPosition(Coords)
{

}
