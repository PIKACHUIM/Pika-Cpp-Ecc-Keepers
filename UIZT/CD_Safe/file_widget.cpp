#include "file_widget.h"
#include "ui_file_widget.h"

File_Widget::File_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::File_Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("文件查看"));   //界面名称

/*    back.setParent(this);   //返回按钮
    back.move(0,500);
    back.resize(100,100);
    back.setStyleSheet(
                "QToolButton{"
                "border-image: url(:/start_button.png);"
                "}");
    back.show();*/
}

File_Widget::~File_Widget()
{
    delete ui;
}

void File_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/File_background.png") );
}

void File_Widget::on_back_released()
{
    this->close();
}
