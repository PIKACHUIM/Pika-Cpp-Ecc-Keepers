#include "mainwidget.h"
#include "add_delete.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    //Add_Delete wad;
    //wad.show();

    return a.exec();
}
