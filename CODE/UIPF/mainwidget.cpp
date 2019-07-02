#ifndef MAINWIDGET_CPP
#define MAINWIDGET_CPP

#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("文件保险箱"));  //页面标题

    connect(&w_login->back, &QToolButton::released, this,   //LoginWidget返回按钮实现
            [=](){
                w_login->close();
                this->show();
                }
            );
}

void MainWidget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/safe.png") );
}


MainWidget::~MainWidget()
{
    delete ui;
    delete w_login;
}

void MainWidget::on_toolButton_released()   //进入按钮
{
    this->hide();
    w_login->show();
}

#endif
