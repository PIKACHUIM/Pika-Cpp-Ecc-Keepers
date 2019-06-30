#ifndef WIND_CPP
#define WIND_CPP
#include "WIND.HPP"
#include "ui_GUI_MAIN.h"

GUI_MAIN::GUI_MAIN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI_MAIN)
{
    ui->setupUi(this);
}

GUI_MAIN::~GUI_MAIN()
{
    delete ui;
}

void GUI_MAIN::on_pushButton_clicked()
{
    exit(0);
}
#endif
