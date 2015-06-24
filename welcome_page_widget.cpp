#include "welcome_page_widget.h"

#include <QPushButton>

Welcome_page_widget::Welcome_page_widget(QWidget *parent) :
    QWidget(parent),
    m_buttonsLayout(new QVBoxLayout(this)),
    m_startButton(new QPushButton("Start Game", this)),
    m_loadButton(new QPushButton("Load Game", this)),
    m_emptyChessBoardButton(new QPushButton("Empty Chess Board", this)),
    m_exitButton(new QPushButton("Exit Game", this))
{
    m_buttonsLayout->addSpacing(1);
    m_buttonsLayout->addWidget(m_startButton);
    m_buttonsLayout->addSpacing(0.05);
    m_buttonsLayout->addWidget(m_loadButton);
    m_buttonsLayout->addSpacing(0.05);
    m_buttonsLayout->addWidget(m_emptyChessBoardButton);
    m_buttonsLayout->addSpacing(0.05);
    m_buttonsLayout->addWidget(m_exitButton);
    m_buttonsLayout->addSpacing(0.05);
    m_buttonsLayout->addSpacing(1);
    this->connect(m_exitButton, SIGNAL(clicked()), this->parent(), SLOT(close()));
}

Welcome_page_widget::~Welcome_page_widget()
{
    m_startButton.clear();
    m_loadButton.clear();
    m_emptyChessBoardButton.clear();
    m_exitButton.clear();
    m_buttonsLayout.clear();
}

