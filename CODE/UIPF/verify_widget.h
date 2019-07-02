#ifndef VERIFY_WIDGET_H
#define VERIFY_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QDir>
#include <QFileDialog>
#include <QString>
#include <QCoreApplication>
#include <./UIPF/file_widget.h>
namespace Ui {
class Verify_Widget;
}

class Verify_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Verify_Widget(QWidget *parent = nullptr);
    ~Verify_Widget();
    QToolButton back;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_code_input_editingFinished();

    void on_enter_released();

private:
    Ui::Verify_Widget *ui;
    File_Widget *w_file = new File_Widget;
};

#endif // VERIFY_WIDGET_H
