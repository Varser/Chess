#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPointer>

extern const QSize g_k_windowSize;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void InitWelcomePage();
    void InitStartGamePage();
    void InitLoadGamePage();
    void InitEmptyChessBoardPage();

private:
    QPointer<QWidget> m_currentWidget;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
