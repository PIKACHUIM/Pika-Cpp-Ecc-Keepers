#include "register_widget.h"
#include "ui_register_widget.h"

Register_Widget::Register_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register_Widget)
{
    ui->setupUi(this);

    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("保险箱创建"));   //界面名称

    back.setParent(this);   //返回按钮
    back.move(0,500);
    back.resize(100,100);
    back.setStyleSheet(
                "QToolButton{"
                "border-image: url(:/start_button.png);"
                "}");
    back.show();
}

Register_Widget::~Register_Widget()
{
    delete ui;
}

void Register_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/login.png") );
}
