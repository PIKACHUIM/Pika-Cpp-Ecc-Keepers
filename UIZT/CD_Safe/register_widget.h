#ifndef REGISTER_WIDGET_H
#define REGISTER_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QDir>
#include <QFileDialog>
#include <QString>
#include <QTextCursor>
#include <file_widget.h>

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

private slots:
    void on_search_released();

    void on_confirm_released();

    void on_recode_input_editingFinished();

    void on_name_input_editingFinished();

    void on_code_input_editingFinished();

    void on_confirm_close_released();

private:
    Ui::Register_Widget *ui;
    File_Widget *w_file = new File_Widget;
    QString directory;
};

#endif // REGISTER_WIDGET_H
