#ifndef DATA_HPP
#define DATA_HPP
#include "HEAD.CPP"
#include "READ.CPP"
#include "RSAE.CPP"
#include <stdio.h>
#include <stdlib.h>
class DATA
{
public:
       int LENS;
       int FIDS[4096];
    string BASE[4096];
    DATA();
      void LOAD()//载入文件
    {
                         FILE* READ_TEMP;
                       errno_t READ_ERRO;
                        string READ_PATH;
                        char   READ_STRS[256];
                               READ_PATH ="./CONF/DAT_BASE_00.INI";
                   const char* READ_OPEN = READ_PATH.c_str();
                               READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "r");
cout<<"--------------[DATA] 0x"<<(void*)READ_TEMP<<" FILEDAT_LOAD--------------"<<endl;
                        fscanf(READ_TEMP,"%d",   &LENS);                        //读取序列
                      for(int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++)
                      {
                          fscanf(READ_TEMP,"%d %s",&FIDS[READ_LOOP],READ_STRS); //读取数据
                          BASE[READ_LOOP]=READ_STRS;
                          printf("LOAD: 0x%08X    ",FIDS[READ_LOOP]);
                          cout<<BASE[READ_LOOP]<<endl;
                      }
                      fclose(READ_TEMP);
cout<<"----------------------------------------------------------"<<endl;
    }
    string NGET(int GNUM)//获取文件名
    {
        printf("NAME: 0x%08X    ",FIDS[GNUM]);
        cout<<BASE[GNUM]<<endl;
        return BASE[GNUM];
    }
    int    FNEW(string FNEW_NAME,string FNEW_PATH)//新增文件
    {
        LENS++;
        BASE[LENS]=FNEW_NAME;
        FIDS[LENS]=FIDS[LENS-1]+1;
        //文件操作------------------------------------
        char*  FNEW_OPEN=(char*)FNEW_PATH.c_str();
        string FNEW_WRPT=".//DATA//"+to_string(FIDS[LENS]);
        string FNEW_READ=FIFT(FNEW_OPEN);
               FNEW_OPEN=(char*)FNEW_WRPT.c_str();
                         FIFR(FNEW_OPEN,FNEW_READ);
        return LENS;
    }
    void   FDEL(int FDEL_FIDS)
    {
        if(FDEL_FIDS>LENS)
        {
            printf("FAIL: 0x00000000    ");
            cout<<"ERROR_FILE_NOT_EXIST"<<endl;
            return;
        }
        printf("FDEL: 0x%08X    ",FIDS[FDEL_FIDS]);
        cout<<BASE[FDEL_FIDS]<<endl;
        for(int FDEL_LOOP=FDEL_FIDS;FDEL_LOOP<LENS;FDEL_LOOP++)
        {
            BASE[FDEL_LOOP]=BASE[FDEL_LOOP+1];
            FIDS[FDEL_LOOP]=FIDS[FDEL_LOOP+1];
        }
        //文件操作
        LENS--;
    }
    void   WRIT()
    {
        FILE* READ_TEMP;
      errno_t READ_ERRO;
       string READ_PATH;
       char*  READ_STRS;
              READ_PATH ="./CONF/DAT_BASE_00.INI";
  const char* READ_OPEN = READ_PATH.c_str();
              READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "w");
cout<<"--------------[DATA] 0x"<<(void*)READ_TEMP<<" FILEDAT_SAVE--------------"<<endl;
       fprintf(READ_TEMP,"%d\n",LENS);                          //写入序列
     for(int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++)
     {
         READ_STRS=(char*)BASE[READ_LOOP].c_str();
         fprintf(READ_TEMP,"%d %s\n",FIDS[READ_LOOP],READ_STRS); //读取数据
         printf("SAVE: 0x%08X    ",FIDS[READ_LOOP]);
         cout<<BASE[READ_LOOP]<<endl;
     }
     fclose(READ_TEMP);
cout<<"----------------------------------------------------------"<<endl;
    }

};
#endif // DATA_HPP
