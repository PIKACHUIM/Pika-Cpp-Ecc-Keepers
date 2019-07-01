#include "verify_widget.h"
#include "ui_verify_widget.h"

Verify_Widget::Verify_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Verify_Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("验证"));   //界面名称

    back.setParent(this);   //返回按钮
    back.move(10,410);
    back.resize(60,60);
    back.setStyleSheet(
                "QToolButton{"
                "border-image: url(:/start_button.png);"
                "}");
    back.show();

    ui->enter->hide();
    ui->code_input->clear();

    ui->picture->clear();
    QPixmap *judge_pixmap = new QPixmap(":/judge.png");   //验证成功picture
    judge_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
    ui->picture->setScaledContents(true);
    ui->picture->setPixmap(*judge_pixmap);

    ui->info->clear();
    QPixmap *judge_caption = new QPixmap(":/judgeline.png");  //验证成功caption
    judge_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
    ui->info->setScaledContents(true);
    ui->info->setPixmap(*judge_caption);

//    ui->enter->show();  //按钮显示

}

Verify_Widget::~Verify_Widget()
{
    delete ui;
}

void Verify_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/verify_background.png") );
}

void Verify_Widget::on_code_input_editingFinished()
{
    if(!ui->name_input->text().isEmpty()
            &&!ui->code_input->text().isEmpty())
    {
        QString str = "123456";

        if(ui->code_input->text() == str)
        {
            ui->picture->clear();
            QPixmap *true_pixmap = new QPixmap(":/true.png");   //验证成功picture
            true_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*true_pixmap);

            ui->info->clear();
            QPixmap *true_caption = new QPixmap(":/trueline.png");  //验证成功caption
            true_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*true_caption);

            ui->enter->show();  //按钮显示
        }

        else
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/falseline.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            ui->enter->hide();
        }
    }
    else
    {
        ui->picture->clear();
        QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
        false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
        ui->picture->setScaledContents(true);
        ui->picture->setPixmap(*false_pixmap);

        ui->info->clear();
        QPixmap *false_caption = new QPixmap(":/false_null.png");  //验证失败caption
        false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
        ui->info->setScaledContents(true);
        ui->info->setPixmap(*false_caption);

        ui->enter->hide();
    }
}

void Verify_Widget::on_enter_released()
{
    this->hide();
    w_file->show();
}
