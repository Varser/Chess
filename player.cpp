#include "player.h"
#include "Pieces/rook.h"
#include "Pieces/queen.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/bishop.h"

Player::Player(QWidget *parent) : QWidget(parent)
{

}

void Player::Init(Color pos)
{
    m_active = (pos == White);

    QPointer<Piece> piece;
    //Setting Rooks
    piece = new Rook(pos, this);
    piece->SetPosition(Coords(1, (pos == White)?1:8));
    m_pieces.push_back(piece);

    piece = new Rook(pos, this);
    piece->SetPosition(Coords(8, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Knight
    piece = new Knight(pos, this);
    piece->SetPosition(Coords(2, (pos == White)?1:8));
    m_pieces.push_back(piece);

    piece = new Knight(pos, this);
    piece->SetPosition(Coords(7, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Bishops
    piece = new Bishop(pos, this);
    piece->SetPosition(Coords(3, (pos == White)?1:8));
    m_pieces.push_back(piece);

    piece = new Bishop(pos, this);
    piece->SetPosition(Coords(6, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Queen
    piece = new Queen(pos, this);
    piece->SetPosition(Coords(4, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting King
    piece = new King(pos, this);
    piece->SetPosition(Coords(5, (pos == White)?1:8));
    m_pieces.push_back(piece);

    //Setting Pawns.
    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(1, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(2, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(3, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(4, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(5, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(6, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(7, (pos == White)?2:7));
    m_pieces.push_back(piece);

    piece = new Pawn(pos, this);
    piece->SetPosition(Coords(8, (pos == White)?2:7));
    m_pieces.push_back(piece);

}

bool Player::UnderCheck(Coords)
{
    assert(!m_pieces.empty());
    return false;
}

bool Player::isActivePlayer()
{
    return m_active;
}

void Player::SetActivePlayer(bool enable)
{
    m_active = enable;
}

QPointer<Piece> Player::GetPiece(Coords position)
{
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        if (m_pieces[i]->IsItMyPosition(position))
            return m_pieces[i];
    }
    return QPointer<Piece>();
}

void Player::RemovePiece(QPointer<Piece> piece)
{
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        if (m_pieces[i] == piece)
        {
            m_pieces[i]->close();
            m_pieces.remove(i);
            break;
        }
    }
}

QPointer<Piece> Player::GetAnotherPiece(Coords position, QPointer<Piece> excluded)
{
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        if (m_pieces[i]->IsItMyPosition(position) && (m_pieces[i] != excluded))
            return m_pieces[i];
    }
    return QPointer<Piece>();
}


