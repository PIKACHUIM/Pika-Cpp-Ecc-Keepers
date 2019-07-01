#ifndef DATA_HPP
#define DATA_HPP
#include "HEAD.CPP"
#include "READ.CPP"
#include "RSAE.CPP"
#include <cstdio>
#include <cstdlib>
class DATA
{
public:
       int LENS;
       int FIDS[4096];
    string BASE[4096];
    RSAE   FNEW_TEMP;
    DATA();
      void LOAD()//载入文件
    {
          FNEW_TEMP.LKEY();
                         FILE* READ_TEMP;
                          char READ_STRS[256];
                        string READ_PATH ="./CONF/DAT_BASE_00.INI";
                   const char* READ_OPEN = READ_PATH.c_str();
                       errno_t READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "r");
cout<<"--------------[DATA] 0x"<<(void*)READ_TEMP<<" FILEDAT_LOAD--------------"<<endl;
                       fscanf(READ_TEMP,"%d",   &LENS);                        //读取序列
                      for(int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++)
                      {
                       fscanf(READ_TEMP,"%d %s",&FIDS[READ_LOOP],READ_STRS); //读取数据
                         BASE[READ_LOOP]=READ_STRS;
                     printf("[LOAD]: 0x%08X    ",FIDS[READ_LOOP]);
                   cout<<BASE[READ_LOOP]<<endl;
                      }
                      fclose(READ_TEMP);
cout<<"----------------------------------------------------------"<<endl;
    }
    string NGET(int GNUM){                        //获取文件名称
        printf("[NAME]: 0x%08X    ",FIDS[GNUM]);  //输出信息
        cout<<BASE[GNUM]<<endl;                   //输出文件
        return BASE[GNUM];}                       //返回名称

    int    FNEW(string FNEW_NAME,string FNEW_PATH)//新增文件
    {
        LENS++;
        BASE[LENS]=FNEW_NAME;
        FIDS[LENS]=FIDS[LENS-1]+1;
        //文件操作------------------------------------
        char*  FNEW_OPEN=(char*)FNEW_PATH.c_str();
        string FNEW_WRPT=".//DATA//"+to_string(FIDS[LENS]);
        string FNEW_READ=FIFT(FNEW_OPEN);
        string FNEW_TSTR=FNEW_TEMP.ENCY(FNEW_READ);
    while(CHEC(FNEW_TSTR)==true)
               FNEW_TSTR=FNEW_TEMP.ENCY(FNEW_READ);
               FNEW_OPEN=        (char*)FNEW_WRPT.c_str();
                         FIFR(FNEW_OPEN,FNEW_TSTR);
            printf("[FNEW]: 0x%08X    ",FIDS[LENS]);
        cout<<BASE[LENS]<<endl;
        return LENS;
    }
int    FGET(int FGET_FIDS,string FGET_PATH)
{
        if(FGET_FIDS>LENS)
        {
            printf("[FAIL]: 0x00000000    ");
            cout<<"ERROR_FILE_NOT_EXIST"<<endl;
            return -1;
        }
        //文件操作------------------------------------
            string FNEW_WRPT=".//DATA//"+to_string(FIDS[FGET_FIDS]);//计算路径
            char*  FNEW_OPEN=(char*)FNEW_WRPT.c_str();              //转换路径
            string FNEW_READ=FIFT(FNEW_OPEN);                       //读取数据
            string FNEW_ENCY=FNEW_TEMP.DECY(FNEW_READ);             //执行解密
                   cout<<"[FILE]: "<<FNEW_ENCY<<endl;
                   FNEW_OPEN=(char*)FGET_PATH.c_str();              //转换路径
              FIFR(FNEW_OPEN,FNEW_ENCY);                            //写入文件
                   printf("[FGET]: 0x%08X    ",FIDS[LENS]);
                   cout<<BASE[LENS]<<endl;
                   return LENS;
}
void   FDEL(int FDEL_FIDS)
{
        if(FDEL_FIDS>LENS)
        {
            printf("[FAIL]: 0x00000000    ");
            cout<<"ERROR_FILE_NOT_EXIST"<<endl;
            return;
        }
        printf("[FDEL]: 0x%08X    ",FIDS[FDEL_FIDS]);
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
         printf("[SAVE]: 0x%08X    ",FIDS[READ_LOOP]);
         cout<<BASE[READ_LOOP]<<endl;
     }
     fclose(READ_TEMP);
cout<<"----------------------------------------------------------"<<endl;
}

};
#endif // DATA_HPP
