#include "player.h"
#include "Pieces/rook.h"
#include "Pieces/queen.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/bishop.h"

Player::Player(QWidget *parent) :
    QWidget(parent),
    m_move(0)
{

}

void Player::Init(Color pos)
{
    m_active = (pos == White);

    QPointer<Piece> piece;
    //Setting Rooks
    piece = new Rook(pos, this);
    piece->SetPosition(Coordinates(1, (pos == White)?1:8));
    m_pieces.push_back(piece);

    piece = new Rook(pos, this);
    piece->SetPosition(Coordinates(8, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Knight
    piece = new Knight(pos, this);
    piece->SetPosition(Coordinates(2, (pos == White)?1:8));
    m_pieces.push_back(piece);

    piece = new Knight(pos, this);
    piece->SetPosition(Coordinates(7, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Bishops
    piece = new Bishop(pos, this);
    piece->SetPosition(Coordinates(3, (pos == White)?1:8));
    m_pieces.push_back(piece);

    piece = new Bishop(pos, this);
    piece->SetPosition(Coordinates(6, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Queen
    piece = new Queen(pos, this);
    piece->SetPosition(Coordinates(4, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting King
    m_king = new King(pos, this);
    m_king->SetPosition(Coordinates(5, (pos == White)?1:8));
    m_pieces.push_back(m_king);

    //Setting Pawns.
    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(1, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(2, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(3, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(4, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(5, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(6, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(7, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coordinates(8, (pos == White)?2:7));
    m_pieces.push_back(piece);

}

bool Player::isActivePlayer()
{
    return m_active;
}

void Player::SetActivePlayer(bool enable)
{
    m_active = enable;
}

QPointer<Piece> Player::GetPiece(Coordinates coordinates)
{
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        if (m_pieces[i]->IsItMyPosition(coordinates) && !m_pieces[i]->isHidden())
            return m_pieces[i];
    }
    return QPointer<Piece>();
}

void Player::RemovePiece(QPointer<Piece> piece)
{
    if (piece == m_king)
    {
        for (int i = 0; i < m_pieces.size(); ++i)
        {
            m_pieces[i]->hide();
//            m_pieces[i]->close();
        }
//        m_pieces.clear();
        return;
    }
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        if (m_pieces[i] == piece)
        {
            m_pieces[i]->hide();
            m_killedPieces.push(std::pair<QPointer<Piece>, size_t>(m_pieces[i], m_move));
//            m_pieces[i]->close();
//            m_pieces.remove(i);
            break;
        }
    }
}

QPointer<Piece> Player::GetAnotherPiece(Coordinates coordinates, QPointer<Piece> excluded)
{
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        if (m_pieces[i]->IsItMyPosition(coordinates) && (m_pieces[i] != excluded) && (!m_pieces[i]->isHidden()))
            return m_pieces[i];
    }
    return QPointer<Piece>();
}

void Player::Restore(Coordinates coordinates, size_t move)
{
    if (m_killedPieces.empty())
        return;
    if (m_killedPieces.back().first->IsItMyPosition(coordinates) && (move == m_killedPieces.back().second))
    {
        m_killedPieces.back().first->show();
        m_killedPieces.pop_back();
    }
}

bool Player::isLoose()
{
    for (QVector<QPointer<Piece> >::iterator iter = m_pieces.begin(); iter != m_pieces.end(); ++iter)
    {
        if (!iter->data()->isHidden())
            return false;
    }
    return true;
}

bool Player::MaySomebodyGoHere(Coordinates coordinates, QPointer<Player> enemies)
{
    for (QVector<QPointer<Piece> >::iterator iter = m_pieces.begin(); iter != m_pieces.end(); ++ iter)
    {
        if (iter->data()->MayIGoHere(coordinates, iter->data()->GetMyCoordinates(), static_cast<QPointer<Player> >(this), enemies, false))
            return true;
    }
    return false;
}

Coordinates Player::GetKing()
{
    return m_king->GetMyCoordinates();
}


