#ifndef FILE_WIDGET_H
#define FILE_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>

namespace Ui {
class File_Widget;
}

class File_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit File_Widget(QWidget *parent = nullptr);
    ~File_Widget();
//    QToolButton back;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_back_released();

private:
    Ui::File_Widget *ui;
};

#endif // FILE_WIDGET_H
