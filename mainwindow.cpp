#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "welcome_page_widget.h"
#include "startgame_page_widget.h"
#include "loadgame_page_widget.h"
#include "emptychessboard_page_widget.h"

#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->InitWelcomePage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_currentWidget;
}

void MainWindow::InitWelcomePage()
{
    if (!m_currentWidget.isNull())
    {
        m_currentWidget->close();
        m_currentWidget.clear();
    }
    m_currentWidget = new Welcome_page_widget(this);
    setCentralWidget(m_currentWidget);
    QPushButton* button = static_cast<Welcome_page_widget*>(m_currentWidget.data())->m_startButton;
    this->connect(button, SIGNAL(clicked()), this, SLOT(InitStartGamePage()));
    button = static_cast<Welcome_page_widget*>(m_currentWidget.data())->m_loadButton;
    this->connect(button, SIGNAL(clicked()), this, SLOT(InitLoagGamePage()));
    button = static_cast<Welcome_page_widget*>(m_currentWidget.data())->m_emptyChessBoardButton;
    this->connect(button, SIGNAL(clicked()), this, SLOT(InitEmptyChessBoardPage()));
    m_currentWidget->show();
}

void MainWindow::InitStartGamePage()
{
    if (!m_currentWidget.isNull())
    {
        m_currentWidget->close();
        m_currentWidget.clear();
    }
    m_currentWidget = new StartGame_page_widget(this);
    setCentralWidget(m_currentWidget);
    m_currentWidget->show();
}

void MainWindow::InitLoagGamePage()
{
    if (!m_currentWidget.isNull())
    {
        m_currentWidget->close();
        m_currentWidget.clear();
    }
    m_currentWidget = new LoadGame_page_widget(this);
    setCentralWidget(m_currentWidget);
    m_currentWidget->show();
}

void MainWindow::InitEmptyChessBoardPage()
{
    if (!m_currentWidget.isNull())
    {
        m_currentWidget->close();
        m_currentWidget.clear();
    }
    m_currentWidget = new EmptyChessBoard_page_widget(this);
    setCentralWidget(m_currentWidget);
    m_currentWidget->show();
}

