#ifndef READ_CPP
#define READ_CPP
#include"HEAD.CPP"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int READ_SIZE(char* SIZE_NAME)        //READ_SIZE
{
         ifstream SIZE_IFST(SIZE_NAME);
    ostringstream SIZE_OSST;
             char SZIE_CHER;
            while(SIZE_OSST
                &&SIZE_IFST.
              get(SZIE_CHER))
                  SIZE_OSST.
              put(SZIE_CHER);
           return SIZE_OSST.str().size();
}
bool CHEC(string str)
{
    int SIZE = str.size()-1;//判断次数要减1
    stringstream buf;
    buf << str;
    int sign=0;             //判断标志
    char ch;
    buf.get(ch);
    while(SIZE){
        sign = 0;
        if(ch == 26){
           sign = 2;    //后一个字符为“A”
           break;}
        if(sign == 0)buf.get(ch);
        SIZE = SIZE-1;}
    if(sign == 2)return true;        //含有1A则返回true
    else         return false;
}
string FIFT(char * filename)
{
    ifstream ifile(filename);
    //将文件读入到ostringstream对象buf中
    ostringstream buf;
    int SIZE = READ_SIZE(filename);
    char ch;
    ifile.get(ch);
    while(SIZE)
    {
        buf.put(ch);
        ifile.get(ch);
        SIZE = SIZE - 1;
    }
    return buf.str();

}
void FIFR(char *filename,string str)
{
    ofstream ofile(filename);
    stringstream buf;
    if(ofile.fail())
    {
        cout<<"打开文件"<<filename<<"失败!"<<endl;
        exit(1);
    }
    int SIZE=str.size();
    buf << str;
    char ch;
    ch = buf.get();
    while(SIZE)
    {
        ofile.put(ch);
        ch = buf.get();
        SIZE = SIZE - 1;
    }
}
#endif
