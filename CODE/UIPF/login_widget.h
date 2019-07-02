#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <./UIPF/register_widget.h>
#include <./UIPF/verify_widget.h>
#include <QCoreApplication>

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

    void on_toolButton_released();

private:
    Ui::Login_Widget *ui;
    Register_Widget *w_register = new Register_Widget;
    File_Widget *w_file = new File_Widget;
    Verify_Widget *w_verify = new Verify_Widget;
};

#endif // LOGIN_WIDGET_H
