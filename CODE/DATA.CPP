#ifndef DATA_CPP
#define DATA_CPP
#include "DATA.HPP"


void DATA::LOAD()//------------------载入文件-------------------------------------
{
            FNEW_TEMP.LKEY();                              //载入公钥
      FILE* READ_TEMP;                                     //创建文件指针
       char READ_STRS[256];                                //创建字符缓冲
std::string READ_PATH ="./CONF/DAT_BASE_00.INI";           //设置信息路径
const char* READ_OPEN = READ_PATH.c_str();                 //转换路径
   fopen_s(&READ_TEMP,  READ_OPEN, "r");                   //打开文件
     fscanf(READ_TEMP,"%d",   &LENS);                      //读取序列
   for( int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++){      //循环读取
     fscanf(READ_TEMP,"%d %s",&FIDS[READ_LOOP],READ_STRS); //读取数据
       BASE[READ_LOOP]=READ_STRS;}                         //保存在类
     fclose(READ_TEMP);
}
STG  DATA::NGET(int GNUM)//----------获取名称-------------------------------------
{
  std::cout<<BASE[GNUM]<<std::endl;//输出文件
      return BASE[GNUM];           //返回名称
}
int  DATA::FNEW(std::string FNEW_NAME,std::string FNEW_PATH)//新增文件------------
{
                 LENS++;                                    //序列自增
                 FNEW_TEMP.LKEY();                          //载入密钥
      BASE[LENS]=FNEW_NAME;                                 //获取名称
      FIDS[LENS]=(LENS>1)?(FIDS[LENS-1]+1):(1);             //设置编号
          char*  FNEW_OPEN=(char*)FNEW_PATH.c_str();        //
     std::string FNEW_WRPT=".//DATA//"+                     //
  std::to_string(FIDS[LENS]);                               //
     std::string FNEW_READ=TTPP.FIFT(FNEW_OPEN);            //
     std::string FNEW_TSTR=FNEW_TEMP.ENCY(FNEW_READ);       //
 while(TTPP.CHEC(FNEW_TSTR)==true)                          //
                 FNEW_TSTR=       FNEW_TEMP.ENCY(FNEW_READ);//
                 FNEW_OPEN=(char*)FNEW_WRPT.c_str();        //
       TTPP.FIFR(FNEW_OPEN,FNEW_TSTR);                      //
          return LENS;
}

int  DATA::FGET(int FGET_FIDS,std::string FGET_PATH)//导出文件--------------------
{
                  FNEW_TEMP.LKEY();
                  std::cout<<"~~~";
      std::string FNEW_WRPT=".//DATA//"+std::to_string(FIDS[FGET_FIDS]);//计算路径
           char*  FNEW_OPEN=(char*)FNEW_WRPT.c_str();                   //转换路径
      std::string FNEW_READ=TTPP.FIFT(FNEW_OPEN);                       //读取数据
      std::string FNEW_ENCY=FNEW_TEMP.DECY(FNEW_READ);                  //执行解密
                  FNEW_OPEN=(char*)FGET_PATH.c_str();                   //转换路径
        TTPP.FIFR(FNEW_OPEN,FNEW_ENCY);                                 //写入文件
           return LENS;
}
void DATA::FDEL(int FDEL_FIDS)//删除文件-------------------------------------------
{
  for(int  FDEL_LOOP  = FDEL_FIDS;                          //
           FDEL_LOOP<LENS;                                  //
           FDEL_LOOP++){                                    //
      BASE[FDEL_LOOP] = BASE[FDEL_LOOP+1];                  //
      FIDS[FDEL_LOOP] = FIDS[FDEL_LOOP+1];}                 //
      LENS--;
}
void DATA::WRIT()//-------------保存数据-------------------------------------------
{
      FILE* READ_TEMP;                                      //文件指针
    errno_t READ_ERRO;                                      //收集错误
        STG READ_PATH;                                      //文件路径
      char* READ_STRS;                                      //文件名称
            READ_PATH = "./CONF/DAT_BASE_00.INI";           //设置路径
const char* READ_OPEN = READ_PATH.c_str();                  //转换路径
            READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "w"); //
    fprintf(READ_TEMP,"%d\n",LENS);                         //写入序列
    for(int READ_LOOP = 1;READ_LOOP<=LENS;READ_LOOP++){     //写入数据
            READ_STRS = (char*) BASE[READ_LOOP].c_str();    //获取名称
    fprintf(READ_TEMP,"%d %s\n",FIDS[READ_LOOP],READ_STRS); //写入数据
    }
     fclose(READ_TEMP);
}
#endif
