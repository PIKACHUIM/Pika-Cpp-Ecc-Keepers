#include "UIPF.HPP"
#include "HEAD.CPP"
#include "./LIBS/MD5E.CPP"
#include "./LIBS/ENCY.CPP"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#define MD5E Md5Encode
#define ENCY EncryptDecrypt
int main(int argc, char *argv[])
{
     MD5E MD5E_TEST;
    cout<<MD5E_TEST.Encode("123")<<endl;
    system("pause");
      QTAP QTTR_MAIN(argc, argv);
      UIPF UIPF_MAIN;
           UIPF_MAIN.show();
    return QTTR_MAIN.exec();
}
