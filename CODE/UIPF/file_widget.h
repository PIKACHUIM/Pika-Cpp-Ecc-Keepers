#ifndef FILE_WIDGET_H
#define FILE_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QDir>
#include <QFileDialog>
#include <./UIPF/add_delete.h>
#include <./UIPF/modify_widget.h>
#include <QCoreApplication>

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

    void on_delete_button_released();

    void on_file_skim_released();

//    void on_file_output_released();

private:
    Ui::File_Widget *ui;
    QString directory;
    Add_Delete *wad = new Add_Delete;
    Modify_Widget *w_modify = new Modify_Widget;
};

#endif // FILE_WIDGET_H
