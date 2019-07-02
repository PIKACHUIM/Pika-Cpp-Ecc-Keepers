#ifndef MODIFY_WIDGET_CPP
#define MODIFY_WIDGET_CPP

#include "modify_widget.h"
#include "ui_modify_widget.h"

Modify_Widget::Modify_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modify_Widget)
{
    ui->setupUi(this);  //ui界面初始化
    ui->path->hide();
    ui->dircomboBox->hide();
    ui->search->hide();
    this->setWindowTitle(QStringLiteral("修改密码"));   //界面名称
    ui->name_input->clear();
    ui->code_input->clear();
    ui->recode_input->clear();
    ui->warning->hide();
    ui->decode_label->hide();
    ui->picture->clear();

    back.setParent(this);   //返回按钮
    back.move(0,500);
    back.resize(100,100);
    back.setStyleSheet(
                "QToolButton{"
                "border-image: url(:/start_button.png);"
                "}");
    back.show();


    //初始提示图片
    QPixmap *judge_pixmap = new QPixmap(":/judge.png");   //验证成功picture
    judge_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
    ui->picture->setScaledContents(true);
    ui->picture->setPixmap(*judge_pixmap);

    ui->info->clear();
    QPixmap *judge_caption = new QPixmap(":/judgeline.png");  //验证成功caption
    judge_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
    ui->info->setScaledContents(true);
    ui->info->setPixmap(*judge_caption);

    delete judge_pixmap;
    delete judge_caption;
}

Modify_Widget::~Modify_Widget()
{
    delete ui;
}

void Modify_Widget::paintEvent(QPaintEvent *)   //背景图片
{
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/login.png") );
}



void Modify_Widget::on_name_input_editingFinished() //原密码输入lineEdit验证框
{
    if(!ui->name_input->text().isEmpty()
            // !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        MD5E MD5T;
        if (MD5T.MD5P(ui->code_input->text().toStdString()))    //原若密码不正确
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_origin_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if (ui->code_input->text() != ui->recode_input->text())    //两次密码输入不一致
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if(ui->code_input->text() == ui->recode_input->text())
        {
            QString str_decode = "567890";
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

            //ui->confirm_close->setDisabled(false);  //按钮显示
            //ui->warning->show();
            ui->decode_label->clear();
            ui->decode_label->setText(str_decode);
            //ui->decode_label->show();

            std::string qstr = ui->recode_input->text().toStdString();   //将密码输入数据库
            MD5E MD5T;
            MD5T.MD5Q(qstr);

            delete true_pixmap;
            delete true_caption;

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

            delete false_pixmap;
            delete false_caption;

            return;
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

        delete false_pixmap;
        delete false_caption;

        return;
    }
}

void Modify_Widget::on_code_input_editingFinished() //密码输入lineEdit验证框
{
    if(!ui->name_input->text().isEmpty()
            // !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        MD5E MD5T;
        if (MD5T.MD5P(ui->code_input->text().toStdString()))    //原若密码不正确
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_origin_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if (ui->code_input->text() != ui->recode_input->text())    //两次密码输入不一致
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if(ui->code_input->text() == ui->recode_input->text())
        {
            QString str_decode = "567890";
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

            //ui->confirm_close->setDisabled(false);  //按钮显示
            //ui->warning->show();
            ui->decode_label->clear();
            ui->decode_label->setText(str_decode);
            //ui->decode_label->show();

            std::string qstr = ui->recode_input->text().toStdString();   //将密码输入数据库
            MD5E MD5T;
            MD5T.MD5Q(qstr);

            delete true_pixmap;
            delete true_caption;

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

            delete false_pixmap;
            delete false_caption;

            return;
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

        delete false_pixmap;
        delete false_caption;

        return;
    }
}

void Modify_Widget::on_recode_input_editingFinished()   //再次密码输入lineEdit验证框
{
    if(!ui->name_input->text().isEmpty()
            // !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        MD5E MD5T;
        if (MD5T.MD5P(ui->code_input->text().toStdString()))    //原若密码不正确
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_origin_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if (ui->code_input->text() != ui->recode_input->text())    //两次密码输入不一致
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if(ui->code_input->text() == ui->recode_input->text())
        {
            QString str_decode = "567890";
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

            //ui->confirm_close->setDisabled(false);  //按钮显示
            //ui->warning->show();
            ui->decode_label->clear();
            ui->decode_label->setText(str_decode);
            //ui->decode_label->show();

            std::string qstr = ui->recode_input->text().toStdString();   //将密码输入数据库
            MD5E MD5T;
            MD5T.MD5Q(qstr);

            delete true_pixmap;
            delete true_caption;

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

            delete false_pixmap;
            delete false_caption;

            return;
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

        delete false_pixmap;
        delete false_caption;

        return;
    }
}

void Modify_Widget::on_confirm_close_released() //确认按钮
{
    if(!ui->name_input->text().isEmpty()
            // !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        MD5E MD5T;
        if (MD5T.MD5P(ui->code_input->text().toStdString()))    //输入原码不正确
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_origin_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if (ui->code_input->text() != ui->recode_input->text())    //两次密码输入不一致
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_code.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            delete false_pixmap;
            delete false_caption;

            return;
        }
        else if(ui->code_input->text() == ui->recode_input->text())
        {
            QString str_decode = "567890";
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

            //ui->confirm_close->setDisabled(false);  //按钮显示
            //ui->warning->show();
            ui->decode_label->clear();
            ui->decode_label->setText(str_decode);
            //ui->decode_label->show();

            std::string qstr = ui->recode_input->text().toStdString();   //将密码输入数据库
            MD5E MD5T;
            MD5T.MD5Q(qstr);

            delete true_pixmap;
            delete true_caption;

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

            delete false_pixmap;
            delete false_caption;

            return;
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

        delete false_pixmap;
        delete false_caption;

        return;
    }
    ui->warning->hide();
    ui->decode_label->hide();
}

#endif
