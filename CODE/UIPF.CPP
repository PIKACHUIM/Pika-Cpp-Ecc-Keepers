#include "UIPF.HPP"
#include "ui_UIPF.h"

UIPF::UIPF(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIPF)
{
    ui->setupUi(this);
}

UIPF::~UIPF()
{
    delete ui;
}
