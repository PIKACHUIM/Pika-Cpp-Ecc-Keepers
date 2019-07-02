#ifndef FILE_WIDGET_CPP
#define FILE_WIDGET_CPP

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

    connect(&wad->back, &QToolButton::released, this,   //Add_Delete back button
            [=](){
                wad->close();
                this->show();
                }
            );

    connect(&w_modify->back, &QToolButton::released, this,   //ModifyWidget back button
            [=](){
                w_modify->close();
                this->show();
                }
            );


    ui->title->hide();
    ui->title_label->hide();
    ui->choose->hide();
    ui->choose_label->hide();
    ui->file_choose->hide();
    ui->text->clear();
    ui->file_output->hide();
}

File_Widget::~File_Widget()
{
    delete ui;
    delete wad;
    delete w_modify;
}

void File_Widget::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/File_background.png") );
}

void File_Widget::on_back_released()
{
    this->close();
}

void File_Widget::on_add_button_released()
{
    this->hide();
    wad->show();
}

/*void File_Widget::on_toolButton_released()
{
    directory=QDir::toNativeSeparators
            (QFileDialog::getExistingDirectory(this, "save path", "/"));

    if(!directory.isEmpty())
    {
        if(ui->choose->findText(directory) == -1)
        {
            ui->choose->addItem(directory);
        }
        ui->choose->setCurrentIndex(ui->choose->findText(directory));
    }
}*/

void File_Widget::on_file_choose_released()
{
    ui->text->clear();
    QString path = QDir::toNativeSeparators(QFileDialog::
                   getExistingDirectory(this, tr("view file"), QDir::currentPath()));
//    ui->title->setText(path);
    if(!path.isEmpty())
    {
        if(ui->choose->findText(path) == -1)
        {
            ui->choose->addItem(path);
        }
        ui->choose->setCurrentIndex(ui->choose->findText(path));
        ui->title->setText(path);
    }
    QDir dir(path);
    dir.setFilter(QDir::Files|QDir::Dirs);  //过滤非文件和非目录
    QFileInfoList list = dir.entryInfoList();   //得到过滤好的文件和目录
    for(int i=0; i<list.length(); i++)
    {
        QString file = list.at(i).fileName();
        ui->text->insertPlainText(file + "\n"); //添加文件名
    }
}

void File_Widget::on_delete_button_released()   //修改密码按钮
{
    this->hide();
    w_modify->show();
}

void File_Widget::on_file_skim_released()   //查看文件列表
{
    ui->text->clear();
    DATA TEMP;
    TEMP.LOAD();
    for(int i=1;i<=TEMP.LENS;i++)
    {
        QString file = QString::fromStdString(TEMP.NGET(i));
        ui->text->insertPlainText(file + "\n"); //添加文件名
    }
    TEMP.WRIT();
}

/*void File_Widget::on_file_output_released()     //全体导出
{
    QString path = QDir::toNativeSeparators(QFileDialog::
                   getExistingDirectory(this, tr("view file"), QDir::currentPath()));
    DATA TEMP;
    TEMP.LOAD();
    for(int i=1;i<=TEMP.LENS;i++)
    {
        QString file = QString::fromStdString(TEMP.NGET(i));
        QString input_path = path + "\\" + file;
        TEMP.FGET(i, input_path.toStdString());
    }
    TEMP.WRIT();

}*/

#endif
