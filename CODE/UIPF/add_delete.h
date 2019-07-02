#ifndef ADD_DELETE_H
#define ADD_DELETE_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QPainter>
#include <QtCore>
#include <QtDebug>
#include <QToolButton>
#include <QCoreApplication>
#include "DATA.HPP"

namespace Ui {
class Add_Delete;
}

class Add_Delete : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Delete(QWidget *parent = nullptr);
    ~Add_Delete();
    QToolButton back;
    DATA TBOX;
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void addItemSlot();
    void delItemSlot();
    void delAllItemSlot();
    void changeListWidgetViewModeSlot();
    void changeSortModeSlot();

    void on_file_choose_released();

    void on_outputButton_released();

private:
    Ui::Add_Delete *ui;
    QFileInfoList list;
    QString path;
};

#endif // ADD_DELETE_H
