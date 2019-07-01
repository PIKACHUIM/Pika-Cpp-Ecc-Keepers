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

    connect(&wad->back, &QToolButton::released, this,   //RegiserWidget返回按钮实现
            [=](){
                wad->close();
                this->show();
                }
            );

    ui->title->hide();
    ui->title_label->hide();
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



//    qDebug() << "DirPath=" << directory;
//    directory += "/";
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
    QFileInfoList list = dir.entryInfoList();   //得到过滤猴的文件和目录

    for(int i=0; i<list.length(); i++)
    {
        QString file = list.at(i).fileName();
        ui->text->insertPlainText(file + "\n"); //添加文件名
    }
}
