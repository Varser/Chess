#include "king.h"

const QString k_witePieceFilePath = ":/Images/king_white.svg";
const QString k_blackPieceFilePath = ":/Images/king_black.svg";

King::King(Color position, QWidget *parent) :
    QSvgWidget((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)

{
}

void King::SetPosition(Coords)
{

}
