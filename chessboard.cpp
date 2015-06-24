#include "chessboard.h"

#include <QString>
#include <cassert>


const QString k_backgroundFilePath = ":/Images/Chess_Board.svg";

extern const QSize g_k_windowSize;

ChessBoard::ChessBoard(QWidget *parent) :
    QSvgWidget(k_backgroundFilePath, parent)
{

}

void ChessBoard::InitPlayers()
{
    m_whitePlayer = new Player(this);
    m_blackPlayer = new Player(this);
    m_whitePlayer->Init(White);
    m_blackPlayer->Init(Black);
}

QPair<QPointer<Player>, QPointer<Player> > ChessBoard::GetPlayers()
{
    assert(m_whitePlayer);
    assert(m_blackPlayer);
    return QPair<QPointer<Player>, QPointer<Player> >(m_whitePlayer, m_blackPlayer);
}

