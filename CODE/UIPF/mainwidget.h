#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QCoreApplication>
#include <./UIPF/login_widget.h>
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_toolButton_released();

private:
    Ui::MainWidget *ui;
    Login_Widget *w_login = new Login_Widget;
};

#endif // MAINWIDGET_H
