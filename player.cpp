#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{

}

void Player::Init(Color pos)
{
    switch (pos)
    {
    case White:
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
//        m_pieces.push_back(Rook(White, this));
        break;
    case Black:
        break;
    }
}

bool Player::UnderCheck(Coords)
{
//    assert(!m_pieces.empty());
    return false;
}

