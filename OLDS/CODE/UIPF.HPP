#ifndef UIPF_HPP
#define UIPF_HPP

#include <QMainWindow>

namespace Ui {
class UIPF;
}

class UIPF : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIPF(QWidget *parent = nullptr);
    ~UIPF();

private:
    Ui::UIPF *ui;
};

#endif // UIPF_HPP
