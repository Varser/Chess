#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPointer>

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
    void InitLoagGamePage();
    void InitEmptyChessBoardPage();

private:
    QPointer<QWidget> m_currentWidget;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
