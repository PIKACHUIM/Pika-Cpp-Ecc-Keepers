#ifndef ADD_DELETE_CPP
#define ADD_DELETE_CPP

#include "add_delete.h"
#include "ui_add_delete.h"

Add_Delete::Add_Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Delete)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("修改文件"));
    ui->listButton->setChecked(true);
    ui->upButton->setChecked(true);

    ui->listWidget->setSortingEnabled(true);    //列表部件排序，默认A-Z排序.

    //ui->listWidget->addItems(QStringList()<<QString::fromLocal8Bit("pika.txt");   //往列表部件中加入项组
    //ui->listWidget->item(0)->setIcon(QIcon("create_button.png")); //对于前面的项设置图标

    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //设置项的选择情况.

    //连接信号与槽.
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addItemSlot()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(delItemSlot()));
    connect(ui->delAllButton, SIGNAL(clicked()), this, SLOT(delAllItemSlot()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(addItemSlot()));  //在lineEdit内，敲击回车，发出信号.
    connect(ui->listButton, SIGNAL(clicked()), this, SLOT(changeListWidgetViewModeSlot()));
    connect(ui->iconButton, SIGNAL(clicked()), this, SLOT(changeListWidgetViewModeSlot()));
    connect(ui->upButton, SIGNAL(clicked()), this, SLOT(changeSortModeSlot()));
    connect(ui->downButton, SIGNAL(clicked()), this, SLOT(changeSortModeSlot()));

    back.setParent(this);   //返回按钮
    back.move(0,500);
    back.resize(100,100);
    back.setStyleSheet(
                "QToolButton{"
                "border-image: url(:/start_button.png);"
                "}");
    back.show();

    DATA TEMP;  //列表初始化
    TEMP.LOAD();
    for(int i=1;i<=TEMP.LENS;i++)
    {
        QString file = QString::fromStdString(TEMP.NGET(i));
        ui->listWidget->addItem(file); //添加文件名
    }
}

Add_Delete::~Add_Delete()
{
    delete ui;
}

void Add_Delete::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/File_background.png") );
}

void Add_Delete::addItemSlot()  //加入
{
    //通过LineEdit输入加入保险箱
    QListWidgetItem *ite = new QListWidgetItem;
    QString iteText = ui->lineEdit->text(); //从lineEdit行编辑框中获取输入的文字.
    if (!iteText.isEmpty()) //检查是否为空
    {
        ite->setText(iteText);  //设置项文本.
        ui->listWidget->addItem(ite);   //把这个项加入到列表部件中去
        ui->lineEdit->clear();  //清空行编辑器
    }


    //list中直接选中加入保险箱
    QList<QListWidgetItem*> wlist = ui->listWidget_input->selectedItems();  //现有选中项
    if(wlist.size() == 0)
    {
        return;
    }

    QListWidgetItem* sel = wlist[0];
    if (sel)
    {
        int rownum = ui->listWidget_input->row(sel);    //选中的文件行序号
        QString file = list.at(rownum).fileName();
        ui->listWidget->addItem(file);  //添加文件名

        DATA TEMP;
        TEMP.LOAD();
        QString input_path = path + "\\" + file;    //路径修改
        ui->lineEdit->setText(file);
        TEMP.FNEW(file.toStdString(), input_path.toStdString());    //加入文件
        TEMP.WRIT();
     }
     delete ite;
}

void Add_Delete::delItemSlot()  //删除选择目标
{
    //直接使用QListWidget部件的删除函数，通过currentItem()成员函数来获取当前的选择项.
    //ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
    QList<QListWidgetItem*> wlist = ui->listWidget->selectedItems();
    if(wlist.size() == 0)
    {
        return;
    }

    QListWidgetItem* sel = wlist[0];
    if (sel)
    {
        int rownum = ui->listWidget->row(sel);
        DATA TEMP;
        TEMP.LOAD();

        for(int i=1;i<=TEMP.LENS;i++)
        {
            QString file = QString::fromStdString(TEMP.NGET(i));
            if(ui->listWidget->item(rownum)->text() == QString::fromStdString(TEMP.NGET(i)))
            {
                TEMP.FDEL(i);
                TEMP.WRIT();
                break;
            }
        }
        ui->listWidget->takeItem(rownum);
    }
    delete sel;
}


void Add_Delete::delAllItemSlot()   //清空保险箱
{
    //通过循环一个个删除QListWidget内的项.
    /*int count = ui->listWidget->count();
    for (int i = count - 1; i >= 0; --i)
    {
        QListWidgetItem* ite = ui->listWidget->takeItem(i);
        if (ite)
            delete ite;
    }*/

    //直接清空
    DATA TEMP;
    TEMP.LOAD();
    for(int i=1;i<=TEMP.LENS;i++)
    {
        TEMP.FDEL(i);
    }
    TEMP.WRIT();
    ui->listWidget->clear();
}



void Add_Delete::changeListWidgetViewModeSlot() //改变排列模式
{
    if (ui->listButton->isChecked())    //如果选择了列表模式，则设置列表模式.
    {
        ui->listWidget->setViewMode(QListView::ListMode);
    }
    else    //否则选择图标模式
    {
        ui->listWidget->setViewMode(QListView::IconMode);
    }
}


void Add_Delete::changeSortModeSlot()   //排序模式
{

    if (ui->upButton->isChecked())  //判断循环模式的选择情况
    {
        ui->listWidget->sortItems(Qt::AscendingOrder);
    }
    else
    {
        ui->listWidget->sortItems(Qt::DescendingOrder);
    }
}

void Add_Delete::on_file_choose_released()  //选择路径
{
    ui->listWidget_input->clear();
    path = QDir::toNativeSeparators(QFileDialog::
                   getExistingDirectory(this, tr("view file"), QDir::currentPath()));   //选择文件夹路径

//    ui->title->setText(path);
/*    if(!path.isEmpty())
    {
        if(ui->choose->findText(path) == -1)
        {
            ui->choose->addItem(path);
        }
        ui->choose->setCurrentIndex(ui->choose->findText(path));
    }*/

    QDir dir(path);
    dir.setFilter(QDir::Files|QDir::Dirs);  //过滤非文件和非目录
    list = dir.entryInfoList();   //得到过滤好的文件和目录

    for(int i=0; i<list.length(); i++)
    {
        QString file = list.at(i).fileName();
        ui->listWidget_input->addItem(file); //添加文件名
    }
}

void Add_Delete::on_outputButton_released() //导出选中文件
{
    QList<QListWidgetItem*> wlist = ui->listWidget->selectedItems();
    if(wlist.size() == 0)
    {
        return;
    }

    QListWidgetItem* sel = wlist[0];
    if (sel)
    {
        int rownum = ui->listWidget->row(sel);
        DATA TEMP;
        TEMP.LOAD();

        for(int i=1;i<=TEMP.LENS;i++)
        {
            QString file = QString::fromStdString(TEMP.NGET(i));
            if(ui->listWidget->item(rownum)->text() == QString::fromStdString(TEMP.NGET(i)))
            {
                QString path = QDir::toNativeSeparators(QFileDialog::
                               getExistingDirectory(this, tr("view file"), QDir::currentPath()));
                QString input_path = path + "\\" + file;
                TEMP.FGET(i, input_path.toStdString());
                //TEMP.FDEL(i);
                TEMP.WRIT();
                break;
            }
        }
        //ui->listWidget->takeItem(rownum);
    }
}
#endif // ADD_DELETE_CPP
