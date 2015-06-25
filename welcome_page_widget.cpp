#include "welcome_page_widget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QPushButton>

Welcome_page_widget::Welcome_page_widget(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout * layout = new QVBoxLayout(this);
    QPushButton * button;

    //Add Start Game Button
    button = new QPushButton("Start Game", this);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(InitStartGamePage()));
    layout->addWidget(button);

    //Add Start Load Button
    button = new QPushButton("Load Game", this);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(InitLoadGamePage()));
    layout->addWidget(button);

    //Add Empty Chess Board Button
    button = new QPushButton("Empty Chess Board", this);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(InitEmptyChessBoardPage()));
    layout->addWidget(button);

    //Add Exit Game Button
    button = new QPushButton("Exit Game", this);
    this->connect(button, SIGNAL(clicked()), this->parent(), SLOT(close()));
    layout->addWidget(button);
}

