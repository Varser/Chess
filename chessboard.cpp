#include "chessboard.h"

#include <QString>
#include <cassert>
#include "logger.h"


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

void ChessBoard::StopGame()
{
    this->setMouseTracking(false);
}

QPair<QPointer<Player>, QPointer<Player> > ChessBoard::GetPlayers()
{
    assert(m_whitePlayer);
    assert(m_blackPlayer);
    return QPair<QPointer<Player>, QPointer<Player> >(m_whitePlayer, m_blackPlayer);
}

void ChessBoard::mousePressEvent(QMouseEvent * event)
{
    Coordinates position(event->pos(), true);
    QPointer<Player> player = GetActivePlayer();
    m_piece = player->GetPiece(position);
    if (m_piece.isNull())
        return;
    m_savedCoords = position;
}

void ChessBoard::mouseReleaseEvent(QMouseEvent * event)
{
    Coordinates position(event->pos(), true);
    if (m_piece.isNull())
        return;
    if (m_piece->MayIGoHere(position,
                                m_savedCoords,
                                (GetActivePlayer() == m_whitePlayer)?m_whitePlayer:m_blackPlayer,
                                (GetActivePlayer() == m_whitePlayer)?m_blackPlayer:m_whitePlayer))
    {
        m_piece->SetPosition(position);
        ChangeActivePlayer();
        Logger::Set(std::pair<Coordinates, Coordinates>(m_savedCoords, position));
        m_whitePlayer->IncrementMove();
        m_blackPlayer->IncrementMove();
    }
    else
        m_piece->SetPosition(m_savedCoords);
    m_piece.clear();
    if ((m_whitePlayer->isLoose()) || (m_blackPlayer->isLoose()))
        StopGame();
}

void ChessBoard::mouseMoveEvent(QMouseEvent * event)
{
    Coordinates position(event->pos(), true);
    if (m_piece.isNull())
        return;
    m_piece->SetPosition(position);
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

void ChessBoard::SetStepWithKillIfNeed(std::pair<Coordinates, Coordinates> step)
{
    QPointer<Player> player = GetActivePlayer();
    m_piece = player->GetPiece(step.first);
    if (m_piece.isNull())
        return;
    if (m_piece->MayIGoHere(step.second,
                                step.first,
                                (GetActivePlayer() == m_whitePlayer)?m_whitePlayer:m_blackPlayer,
                                (GetActivePlayer() == m_whitePlayer)?m_blackPlayer:m_whitePlayer))
    {
        m_piece->SetPosition(step.second);
        ChangeActivePlayer();
        m_whitePlayer->IncrementMove();
        m_blackPlayer->IncrementMove();
    }
    m_piece.clear();
}

void ChessBoard::SetStepWithRestoreIfNeed(std::pair<Coordinates, Coordinates> step)
{
    QPointer<Player> player = GetActivePlayer();
    m_piece = player->GetPiece(step.first);
    if (m_piece.isNull())
        return;

    m_piece->SetPosition(step.second);
    ChangeActivePlayer();
    m_piece.clear();
    GetActivePlayer()->Restore(step.first, Logger::GetMoveNumber());
    m_whitePlayer->DecrementMove();
    m_blackPlayer->DecrementMove();

}

void ChessBoard::Prev()
{
    std::pair<Coordinates, Coordinates> step = Logger::Prev();
    if (step == std::pair<Coordinates, Coordinates>())
        return;
    std::pair<Coordinates, Coordinates> reverce_step = std::pair<Coordinates, Coordinates>(step.second, step.first);
    ChangeActivePlayer();
    SetStepWithRestoreIfNeed(reverce_step);
    ChangeActivePlayer();
}

void ChessBoard::Next()
{
    std::pair<Coordinates, Coordinates> step = Logger::Next();
    if (step == std::pair<Coordinates, Coordinates>())
        return;
    SetStepWithKillIfNeed(step);
}

void ChessBoard::Save()
{
    Logger::SaveLog();
}

void ChessBoard::Load()
{
    Logger::LoadLog();
}
