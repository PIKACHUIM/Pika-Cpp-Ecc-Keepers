#ifndef READ_CPP
#define READ_CPP
#include"HEAD.CPP"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class GSTR
{
public:
    GSTR() {}
   fstream FSTM;
    string STRS;
    void RFIS(const char * filename)   //读取文件到字符串
    {
            ifstream ifile(filename);
            ostringstream buf;
            char ch;
            while (buf&&ifile.get(ch))
                buf.put(ch);
            cout<<buf.str()<<endl;
    }
    void WTFL(const char * filename)  //字符串来写入文件
    {
        fstream cf(filename, ios::out | ios::binary);
        cf.close();
        cin >> STRS;
        cf.open(filename, ios::in | ios::out | ios::binary);
        if (cf.fail()){cout << "打开文件失败" << endl;exit(1);}
        cf.write((char*)&STRS, sizeof(STRS));
        cf.close();
    }
    //目标：读取字符串及文件名，将其保存到文件中
    void GASF(string Stringname ,const char * Filename)//问题在于此处并没有使用地址，而是使用了字符串的名字
    {
        fstream cf(Filename, ios::out);//使用txt格式保存并以便输出string
        cf<<Stringname.data();
        cf.close();
    }
};
string FIFT(char * filename)
{
         ifstream READ_IOFF(filename);
    ostringstream READ_BUFF;
     char ch;
     while(READ_BUFF&&
           READ_IOFF.get(ch))
           READ_BUFF.put(ch);
    return READ_BUFF.str();
}
string FIFR(char * filename)
{
         ifstream READ_IOFF(filename);
    ostringstream READ_BUFF;
     char ch;
     while(READ_BUFF&&
           READ_IOFF.get(ch))
           READ_BUFF.put(ch);
    return READ_BUFF.str();
}
#endif
