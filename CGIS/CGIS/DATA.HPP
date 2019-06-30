#ifndef DATA_HPP
#define DATA_HPP
#include "HEAD.CPP"
#include "READ.CPP"
#include <stdio.h>
#include <stdlib.h>
class DATA
{
public:
       int LENS;
       int FIDS[4096];
    char*  BASE[4096];
    DATA();
      void LOAD()//载入文件
    {
                         FILE* READ_TEMP;
                       errno_t READ_ERRO;
                        string READ_PATH;
                               READ_PATH ="./CONF/DATA";
                   const char* READ_OPEN = READ_PATH.c_str();
                               READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "r");
                      fscanf_s(READ_TEMP,"%d",&LENS); //读取
                      cout<<LENS;
    }
    string NGET(int GNUM)//获取文件名
    {
        return BASE[GNUM];
    }

};
#endif // DATA_HPP
