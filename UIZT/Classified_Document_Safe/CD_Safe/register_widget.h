#ifndef REGISTER_WIDGET_H
#define REGISTER_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>

namespace Ui {
class Register_Widget;
}

class Register_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Register_Widget(QWidget *parent = nullptr);
    ~Register_Widget();
    QToolButton back;

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Register_Widget *ui;
};

#endif // REGISTER_WIDGET_H
