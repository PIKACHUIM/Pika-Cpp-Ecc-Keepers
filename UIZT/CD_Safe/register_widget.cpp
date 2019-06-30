#include "register_widget.h"
#include "ui_register_widget.h"

Register_Widget::Register_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register_Widget)
{
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

    ui->confirm->hide();

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

}

Register_Widget::~Register_Widget()
{
    delete ui;
}

void Register_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/login.png") );
}

void Register_Widget::on_search_released()
{
    directory=QDir::toNativeSeparators
            (QFileDialog::getExistingDirectory(this, "save path", "/"));

    if(!directory.isEmpty())
    {
        if(ui->dircomboBox->findText(directory) == -1)
        {
            ui->dircomboBox->addItem(directory);
        }
        ui->dircomboBox->setCurrentIndex(ui->dircomboBox->findText(directory));
    }

//    qDebug() << "DirPath=" << directory;
//    directory += "/";
}

void Register_Widget::on_confirm_released()
{
    this->hide();
    w_file->show();
}

void Register_Widget::on_recode_input_editingFinished()
{
    if(!ui->name_input->text().isEmpty()
            && !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        QString str = "root";
        if (ui->name_input->text() == str)
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_name.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            ui->confirm->hide();
        }
        else if (ui->code_input->text() != ui->recode_input->text())
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

            ui->confirm->hide();
        }
        else if(ui->code_input->text() == ui->recode_input->text())
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

            ui->confirm->show();  //按钮显示
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

            ui->confirm->hide();
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

        ui->confirm->hide();
    }
}

void Register_Widget::on_name_input_editingFinished()
{
    if(!ui->name_input->text().isEmpty()
            && !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        QString str = "root";
        if (ui->name_input->text() == str)
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_name.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            ui->confirm->hide();
        }
        else if (ui->code_input->text() != ui->recode_input->text())
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

            ui->confirm->hide();
        }
        else if(ui->code_input->text() == ui->recode_input->text())
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

            ui->confirm->show();  //按钮显示
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

            ui->confirm->hide();
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

        ui->confirm->hide();
    }

}

void Register_Widget::on_code_input_editingFinished()
{
    if(!ui->name_input->text().isEmpty()
            && !ui->dircomboBox->currentText().isEmpty()
            && !ui->recode_input->text().isEmpty()
            && !ui->code_input->text().isEmpty())
    {
        QString str = "root";
        if (ui->name_input->text() == str)
        {
            ui->picture->clear();
            QPixmap *false_pixmap = new QPixmap(":/false.png"); //验证失败caption
            false_pixmap->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->picture->setScaledContents(true);
            ui->picture->setPixmap(*false_pixmap);

            ui->info->clear();
            QPixmap *false_caption = new QPixmap(":/false_name.png");  //验证失败caption
            false_caption->scaled(ui->picture->size(), Qt::KeepAspectRatio);
            ui->info->setScaledContents(true);
            ui->info->setPixmap(*false_caption);

            ui->confirm->hide();
        }
        else if (ui->code_input->text() != ui->recode_input->text())
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

            ui->confirm->hide();
        }
        else if(ui->code_input->text() == ui->recode_input->text())
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

            ui->confirm->show();  //按钮显示
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

            ui->confirm->hide();
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

        ui->confirm->hide();
    }
}
