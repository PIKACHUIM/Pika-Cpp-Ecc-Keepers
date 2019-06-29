#ifndef WIND_HPP
#define WIND_HPP

#include <QMainWindow>

namespace Ui {
class GUI_MAIN;
}

class GUI_MAIN : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI_MAIN(QWidget *parent = nullptr);
    ~GUI_MAIN();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GUI_MAIN *ui;
};

#endif
