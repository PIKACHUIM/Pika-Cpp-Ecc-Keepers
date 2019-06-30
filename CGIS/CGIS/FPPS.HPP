#pragma once
#ifndef READ_HPP
#define READ_HPP
#include"HEAD.CPP"
#include<stdio.h>
/*---READ类
 * 负责底层文件调用，读写
 */
class READ
{
public:
     int LENS;
     int DATA[1024][   6];
  char*  NAME[1024];
  string DIRN;
  string FILC;
  string FILN;
     int NUMS;
     int DATL;
         READ(){}
         READ(string,string,string,int,int);
    void SETP(string,string,string,int,int);
    void WRIT();
};
READ::READ(string READ_LEVE,string READ_TYPE,string READ_NAME,int READ_NUMS,int READ_LENS)
{
    SETP(READ_LEVE,READ_TYPE,READ_NAME,READ_NUMS,READ_LENS);
}
void READ::SETP(string READ_LEVE,string READ_TYPE,string READ_NAME,int READ_NUMS,int READ_LENS)
{
               DIRN =READ_LEVE;
               FILC =READ_TYPE;
               FILN =READ_NAME;
               NUMS =READ_NUMS;
               DATL =READ_LENS;
               FILE* READ_TEMP;
             errno_t READ_ERRO;
              string READ_PATH;
    if(READ_NUMS<=9) READ_PATH ="../"+READ_LEVE+"/"+READ_TYPE+"_"+READ_NAME+"_"+"0"+std::to_string(READ_NUMS)+".INI";
    else             READ_PATH ="../"+READ_LEVE+"/"+READ_TYPE+"_"+READ_NAME+"_"+    std::to_string(READ_NUMS)+".INI";
         const char* READ_OPEN = READ_PATH.c_str();
                     READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "r");
                 int READ_LOOP = 0;
            fscanf_s(READ_TEMP,"%d",&READ_LOOP); //读取
                LENS=READ_LOOP;
             for(int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++)
             {
            fscanf(READ_TEMP,"%d",&DATA[READ_LOOP][0]);
               fseek(READ_TEMP, 0, SEEK_CUR);
            fscanf(READ_TEMP,"%s", NAME[READ_LOOP]);
               fseek(READ_TEMP, 0, SEEK_CUR);
               cout<<DATA[READ_LOOP][0]<<"~"<<NAME[READ_LOOP];
             }

              fclose(READ_TEMP);
}
void READ::WRIT()
{
            string  READ_PATH;
            FILE*   READ_TEMP;
            errno_t READ_ERRO;
        if(NUMS<=9) READ_PATH ="../"+DIRN+"/"+FILC+"_"+FILN+"_"+"0"+std::to_string(NUMS)+".INI";
        else        READ_PATH ="../"+DIRN+"/"+FILC+"_"+FILN+"_"+    std::to_string(NUMS)+".INI";
        const char* READ_OPEN = READ_PATH.c_str();
                    READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "w+");
          fprintf_s(READ_TEMP,"%d\n",LENS);
            for(int TEMP_LOOP=1;TEMP_LOOP<=LENS;TEMP_LOOP++)
            {
                fprintf_s(READ_TEMP,"%d ",DATA[TEMP_LOOP][0]);
            for(int TEMP_ALXR=1;TEMP_ALXR<=DATL;TEMP_ALXR++)
                fprintf_s(READ_TEMP,"%d ",DATA[TEMP_LOOP][TEMP_ALXR]);
                fprintf_s(READ_TEMP,"\n");
            }
            fclose(READ_TEMP);
}
#endif // READ_HPP
