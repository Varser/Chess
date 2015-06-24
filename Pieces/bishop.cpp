#include "bishop.h"

const QString k_witePieceFilePath = ":/Images/bishot_white.svg";
const QString k_blackPieceFilePath = ":/Images/bishot_black.svg";

Bishop::Bishop(Color position, QWidget *parent) :
    QSvgWidget((position == White)?k_witePieceFilePath:k_blackPieceFilePath, parent)
{
}

void Bishop::SetPosition(Coords)
{

}

