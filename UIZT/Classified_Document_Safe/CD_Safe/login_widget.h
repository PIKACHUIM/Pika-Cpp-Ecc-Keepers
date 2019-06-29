#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <register_widget.h>

namespace Ui {
class Login_Widget;
}

class Login_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Login_Widget(QWidget *parent = nullptr);
    ~Login_Widget();
    QToolButton back;

protected:
    void paintEvent(QPaintEvent *);

private slots:

    void on_toolButton_2_released();

private:
    Ui::Login_Widget *ui;
    Register_Widget *w_register = new Register_Widget;
};

#endif // LOGIN_WIDGET_H
