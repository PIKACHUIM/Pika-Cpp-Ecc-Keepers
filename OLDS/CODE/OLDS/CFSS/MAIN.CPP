#include "UIPF.CPP"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIPF w;
    w.show();

    return a.exec();
}
