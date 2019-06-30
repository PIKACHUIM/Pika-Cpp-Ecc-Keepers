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
    TEST.LOAD();
    TEST.NGET(2);
    //TEST.FDEL(2);
    TEST.FNEW("PIKAPIKA","TEST.txt");
    TEST.WRIT();



    cout<<"--------------[EXIT] 0x"<<(void*)argv<<" PROGRAM_EXIT--------------"<<endl;
    return a.exec();
}





/*MD5E TEST;
string t="AAAA";
cout<<TEST.MD5P("AAAA");
string TXT = "PIKAPIKA";
string ENC;
string DEC;
cout << "----------RSA----------" << endl;
string key[2];
RSAE TEMP;
TEMP.LKEY();
cout << key[0] << endl;
cout << key[1] << endl;
ENC = TEMP.ENCY(TXT);
cout << ENC << endl;
DEC = TEMP.DECY(ENC);
cout << DEC << endl;
TXT = "1234";
ENC = TEMP.ENCY(TXT);
cout << ENC << endl;
DEC = TEMP.DECY(ENC);
cout << DEC << endl;
//DATA TEST;
//TEST.LOAD();
READ TTMP("CONF","DAT","BASE",00,02);
cout<<"[SUCC]READ_PROFILE"<<endl;
cout<<TTMP.NAME[1]<<endl;
*/
