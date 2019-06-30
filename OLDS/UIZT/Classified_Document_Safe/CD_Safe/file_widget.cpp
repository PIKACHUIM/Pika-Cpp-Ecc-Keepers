#include "file_widget.h"
#include "ui_file_widget.h"

File_Widget::File_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::File_Widget)
{
    ui->setupUi(this);
}

File_Widget::~File_Widget()
{
    delete ui;
}

void File_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/file_background.png") );
}
