#include "add_delete.h"
#include "ui_add_delete.h"

Add_Delete::Add_Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Delete)
{
    ui->setupUi(this);
    ui->listButton->setChecked(true);
    ui->upButton->setChecked(true);
    //列表部件采用排序.默认采用AAA-ZZZ排序.
    ui->listWidget->setSortingEnabled(true);
    //往列表部件中加入项组.一共3个.
    //ui->listWidget->addItems(QStringList()<<QString::fromLocal8Bit("北京")<<QString::fromLocal8Bit("上海")<<QString::fromLocal8Bit("杭州"));
    //设置标题为"QListWidget".
    this->setWindowTitle(QString::fromLocal8Bit("QListWidget"));
    //对于前面的三个项设置图标.可根据实际情况使用.
    //ui->listWidget->item(0)->setIcon(QIcon("create_button.png"));
    //设置项的选择情况.
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    //连接信号与槽.
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addItemSlot()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(delItemSlot()));
    connect(ui->delAllButton, SIGNAL(clicked()), this, SLOT(delAllItemSlot()));
    //QLineEdit的信号:void returnPressed()的意思是:当焦点在lineEdit内时，敲击enter键，发出信号.
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(addItemSlot()));
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
}

Add_Delete::~Add_Delete()
{
    delete ui;
}

void Add_Delete::paintEvent(QPaintEvent *){ //背景图片
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/File_background.png") );
}

void Add_Delete::addItemSlot()
{
    //通过LineEdit输入加入保险箱
    QListWidgetItem *ite = new QListWidgetItem;
    //从lineEdit行编辑框中获取输入的文字.
    QString iteText = ui->lineEdit->text();
    //一定要检查是否空，否则也会输入进去!!!
    if (!iteText.isEmpty())
    {
        //然后设置项的文本.
        ite->setText(iteText);
        //最后把这个项加入到列表部件中去.
        ui->listWidget->addItem(ite);
        //清空行编辑器，坐下善后工作.
        ui->lineEdit->clear();
    }
//    QListWidgetItem *item = ui->listWidget_input->selectedItems();


    //list中直接选中加入保险箱
    QList<QListWidgetItem*> wlist = ui->listWidget_input->selectedItems();

     if(wlist.size() == 0)
      return;

     QListWidgetItem* sel = wlist[0];
     if (sel)
     {
        int rownum = ui->listWidget_input->row(sel);
//        QListWidgetItem *item = ui->listWidget_input->item(rownum);
//        ui->listWidget->addItem(item);
        QString file = list.at(rownum).fileName();
        ui->listWidget->addItem(file); //添加文件名

     }
}
void Add_Delete::delItemSlot()
{
    //直接使用QListWidget部件的删除函数，通过currentItem()成员函数来获取当前的选择项.
    //ui->listWidget->removeItemWidget(ui->listWidget->currentItem());

    QList<QListWidgetItem*> wlist = ui->listWidget->selectedItems();

     if(wlist.size() == 0)
      return;

     QListWidgetItem* sel = wlist[0];
     if (sel)
     {
        int rownum = ui->listWidget->row(sel);
        ui->listWidget->takeItem(rownum);
     }
}
void Add_Delete::delAllItemSlot()
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
    ui->listWidget->clear();
}
void Add_Delete::changeListWidgetViewModeSlot()
{
    //判断对于列表显示模式的选择情况.如果选择了列表模式，则设置列表模式.
    if (ui->listButton->isChecked())
    {
        ui->listWidget->setViewMode(QListView::ListMode);
    }
    //否则选择图标模式.
    else
    {
        ui->listWidget->setViewMode(QListView::IconMode);
    }
}
void Add_Delete::changeSortModeSlot()
{
    //判断循环模式的选择情况.
    if (ui->upButton->isChecked())
    {
        ui->listWidget->sortItems(Qt::AscendingOrder);
    }
    else
    {
        ui->listWidget->sortItems(Qt::DescendingOrder);
    }
}

void Add_Delete::on_file_choose_released()
{
    ui->listWidget_input->clear();

    path = QDir::toNativeSeparators(QFileDialog::
                   getExistingDirectory(this, tr("view file"), QDir::currentPath()));
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
