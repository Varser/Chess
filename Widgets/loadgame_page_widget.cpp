#include "loadgame_page_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include"logger.h"

LoadGame_page_widget::LoadGame_page_widget(QWidget *parent) :
    QWidget(parent),
    m_chessBoard(this),
    m_menu(this)
{
    m_chessBoard.StopGame();
    //Add ChessBoard
    QVBoxLayout * v_layout = new QVBoxLayout(this);
    v_layout->addWidget(&m_chessBoard);

    //Add horisontal layout for buttons
    QHBoxLayout * h_layout = new QHBoxLayout();
    v_layout->addLayout(h_layout);
    QPushButton * button;

    //Add Prev Button
    button= new QPushButton("Prev", this);
    h_layout->addWidget(button);
    this->connect(button, SIGNAL(clicked()), &m_chessBoard, SLOT(Prev()));

    //Add Next Button
    button= new QPushButton("Next", this);
    h_layout->addWidget(button);
    this->connect(button, SIGNAL(clicked()), &m_chessBoard, SLOT(Next()));

    //Add horisontal layout for buttons
    h_layout = new QHBoxLayout();
    v_layout->addLayout(h_layout);

    //Add Main menu Button
    button= new QPushButton("Main Menu", this);
    h_layout->addWidget(button);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(InitWelcomePage()));

    //Add Start Game Button
    button= new QPushButton("Start Game", this);
    h_layout->addWidget(button);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(InitStartGamePage()));

    //Add Empty Chess Board Button
    button= new QPushButton("Empty Chess Board", this);
    h_layout->addWidget(button);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(InitEmptyChessBoardPage()));

    //Add Exit Game Button
    button = new QPushButton("Exit Game", this);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(close()));
    h_layout->addWidget(button);
    m_chessBoard.InitPlayers();
    Logger::LoadLog();
    if (!Logger::isEmpty())
    {
        std::vector<std::pair<Coordinates, Coordinates> > log = Logger::GetLog();
        for (std::vector<std::pair<Coordinates, Coordinates> >::iterator iter = log.begin(); iter != log.end(); ++iter)
        {
            m_chessBoard.SetStepWithKillIfNeed(*iter);
        }
    }
}

