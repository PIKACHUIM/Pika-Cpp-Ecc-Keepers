#ifndef MODIFY_WIDGET_H
#define MODIFY_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QDir>
#include <QFileDialog>
#include <QTextCursor>
#include <QCoreApplication>
#include "MD5E.HPP"
namespace Ui {
class Modify_Widget;
}

class Modify_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Modify_Widget(QWidget *parent = nullptr);
    ~Modify_Widget();
    QToolButton back;

protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_name_input_editingFinished();

    void on_code_input_editingFinished();

    void on_recode_input_editingFinished();

    void on_confirm_close_released();

private:
    Ui::Modify_Widget *ui;
    QString directory;
};

#endif // MODIFY_WIDGET_H
