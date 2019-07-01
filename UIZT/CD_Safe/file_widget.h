#ifndef FILE_WIDGET_H
#define FILE_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QDir>
#include <QFileDialog>
#include <add_delete.h>

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

    void on_add_button_released();

//    void on_toolButton_released();

    void on_file_choose_released();

private:
    Ui::File_Widget *ui;
    QString directory;
    Add_Delete *wad = new Add_Delete;
};

#endif // FILE_WIDGET_H
