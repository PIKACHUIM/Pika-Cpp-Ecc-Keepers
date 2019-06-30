#include "login_widget.h"
#include "ui_login_widget.h"

Login_Widget::Login_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("登录验证"));   //界面名称

    back.setParent(this);   //返回按钮
    back.move(580,500);
    back.resize(100,100);
    back.setStyleSheet(
                "QToolButton{"
                "border-image: url(:/start_button.png);"
                "}");
    back.show();

    connect(&w_register->back, &QToolButton::released, this,   //RegiserWidget返回按钮实现
            [=](){
                w_register->close();
                this->show();
                }
            );

    connect(&w_verify->back, &QToolButton::released, this,   //FileWidget返回按钮实现
            [=](){
                w_verify->close();
                this->show();
                }
            );
}

Login_Widget::~Login_Widget()
{
    delete ui;
}

void Login_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/choose2.png") );
}


void Login_Widget::on_toolButton_2_released()   //创建保险箱
{
    //this->hide();
    w_register->show();
}

void Login_Widget::on_toolButton_released() //打开保险箱
{
    //this->hide();
    w_verify->show();
}
