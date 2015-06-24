#ifndef WELCOME_PAGE_WIDGET_H
#define WELCOME_PAGE_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPointer>

class Welcome_page_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Welcome_page_widget(QWidget *parent = 0);
    ~Welcome_page_widget();

private:
    QPointer<QVBoxLayout> m_buttonsLayout;
    QPointer<QPushButton> m_exitButton;

public:
    QPointer<QPushButton>   m_startButton,
                            m_loadButton,
                            m_emptyChessBoardButton;

signals:

public slots:

};

#endif // WELCOME_PAGE_WIDGET_H
