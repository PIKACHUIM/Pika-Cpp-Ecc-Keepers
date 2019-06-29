#include"HEAD.CPP"
#include "./UIPF/WIND.CPP"
#include "./LIBS/DESA.HPP"
#include "./LIBS/MD5E.CPP"
int main(int argc, char *argv[])
{
    MD5E md5;
    cout<<md5.Encode("123")<<endl;
    system("pause");
    //QApplication a(argc, argv);
    //GUI_MAIN w;
    //w.show();

    //return a.exec();
}
