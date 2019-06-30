#include <QCoreApplication>
#include <iostream>
#include "MD5E.CPP"
#include "HEAD.CPP"
#include "RSAE.CPP"
#include "DATA.CPP"
#include "FPPS.HPP"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DATA TEST;
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
