#include "queen.h"

const QString k_witePieceFilePath = ":/Images/queen_white.svg";
const QString k_blackPieceFilePath = ":/Images/queen_black.svg";

Queen::Queen(Color position, QWidget *parent) :
    QSvgWidget((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
}

void Queen::SetPosition(Coords)
{

}
