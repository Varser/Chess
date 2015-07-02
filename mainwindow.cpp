#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "welcome_page_widget.h"
#include "startgame_page_widget.h"
#include "loadgame_page_widget.h"
#include "emptychessboard_page_widget.h"

#include <QCloseEvent>

const QSize g_k_windowSize(820, 900);

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
}

void MainWindow::InitWelcomePage()
{
    if (!m_currentWidget.isNull())
    {
        delete m_currentWidget.operator->();
        m_currentWidget.clear();
    }
    m_currentWidget = new Welcome_page_widget(this);
    setCentralWidget(m_currentWidget);
    m_currentWidget->show();
}

void MainWindow::InitStartGamePage()
{
    if (!m_currentWidget.isNull())
    {
        delete m_currentWidget.operator->();
        m_currentWidget.clear();
    }
    m_currentWidget = new StartGame_page_widget(this);
    setCentralWidget(m_currentWidget);
    m_currentWidget->show();
}

void MainWindow::InitLoadGamePage()
{
    if (!m_currentWidget.isNull())
    {
        delete m_currentWidget.operator->();
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
        delete m_currentWidget.operator->();
        m_currentWidget.clear();
    }
    m_currentWidget = new EmptyChessBoard_page_widget(this);
    setCentralWidget(m_currentWidget);
    m_currentWidget->show();
}

