#include "chessboard.h"

#include <QString>
#include <cassert>


const QString k_backgroundFilePath = ":/Images/Chess_Board.svg";

extern const QSize g_k_chessBoardSize(800, 800);

ChessBoard::ChessBoard(QWidget *parent) :
    QSvgWidget(k_backgroundFilePath, parent)
{
    this->setGeometry(0, 0, g_k_chessBoardSize.width(), g_k_chessBoardSize.height());
    this->setFixedSize(g_k_chessBoardSize);
}

void ChessBoard::InitPlayers()
{
    m_whitePlayer = new Player(this);
    m_whitePlayer->setGeometry(0, 0, g_k_chessBoardSize.width(), g_k_chessBoardSize.height());
    m_blackPlayer = new Player(this);
    m_blackPlayer->setGeometry(0, 0, g_k_chessBoardSize.width(), g_k_chessBoardSize.height());
    m_whitePlayer->Init(White);
    m_blackPlayer->Init(Black);
}

void ChessBoard::StartGame()
{
    this->setMouseTracking(true);
}

QPair<QPointer<Player>, QPointer<Player> > ChessBoard::GetPlayers()
{
    assert(m_whitePlayer);
    assert(m_blackPlayer);
    return QPair<QPointer<Player>, QPointer<Player> >(m_whitePlayer, m_blackPlayer);
}

void ChessBoard::mousePressEvent(QMouseEvent * event)
{
    QPoint position = event->pos();
    QPointer<Player> player = GetActivePlayer();
    m_piece = player->GetPiece(Coords(position));
    if (m_piece.isNull())
        return;
    m_savedCoords = position;
}

void ChessBoard::mouseReleaseEvent(QMouseEvent * event)
{
    QPoint position = event->pos();
    if (m_piece.isNull())
        return;
    if ((position.x() != m_savedCoords.x()) &&
            (position.y() != m_savedCoords.y()) &&
            m_piece->MayIGoHere(Coords(position).AbstractCoords(),
                                Coords(m_savedCoords).AbstractCoords(),
                                (GetActivePlayer() == m_whitePlayer)?m_whitePlayer:m_blackPlayer,
                                (GetActivePlayer() == m_whitePlayer)?m_blackPlayer:m_whitePlayer))
    {
        m_piece->SetPosition(Coords(position));
        ChangeActivePlayer();
    }
    else
        m_piece->SetPosition(Coords(m_savedCoords));
    m_piece.clear();
}

void ChessBoard::mouseMoveEvent(QMouseEvent * event)
{
    QPoint position = event->pos();
    if (m_piece.isNull())
        return;
    m_piece->SetPosition(Coords(position));
}

QPointer<Player> ChessBoard::GetActivePlayer()
{
    if (m_whitePlayer->isActivePlayer())
        return m_whitePlayer;
    else if (m_blackPlayer->isActivePlayer())
        return m_blackPlayer;
    return QPointer<Player>();
}

void ChessBoard::ChangeActivePlayer()
{
    m_whitePlayer->SetActivePlayer(!m_whitePlayer->isActivePlayer());
    m_blackPlayer->SetActivePlayer(!m_blackPlayer->isActivePlayer());
}

