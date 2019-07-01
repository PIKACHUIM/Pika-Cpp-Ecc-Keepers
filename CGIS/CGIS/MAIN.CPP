#include <QCoreApplication>
#include <iostream>
#include "MD5E.CPP"
#include "HEAD.CPP"
#include "RSAE.CPP"
#include "DATA.CPP"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //密码初始化
    MD5E MD5T;
    //验证密码
    MD5T.MD5P("PASSWD");
    //修改密码
    string TSTR="PASSWD";
    MD5T.MD5Q(TSTR);

    DATA TEST;
    RSAE TTTP;
    TTTP.LKEY();
    TEST.LOAD();
    //TEST.NGET(2);
    //TEST.FDEL(2);
    //TEST.FNEW("PIKAPIKA","TEST.txt");
    //TEST.FGET(TEST.LENS,(string)"OUTPUT.TXT");
    TEST.WRIT();

    cout<<"--------------[EXIT] 0x"<<(void*)argv<<" PROGRAM_EXIT--------------"<<endl;
    return a.exec();
}
