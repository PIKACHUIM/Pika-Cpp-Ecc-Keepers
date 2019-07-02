#ifndef   READ_CPP
#define   READ_CPP
#include "HEAD.CPP"

class READ
{
public:
    int READ_SIZE(char* FILE_NAME)                 //READ_SIZE，读文件大小
    {
        std::ifstream      SIZE_IFST(FILE_NAME);
        std::ostringstream SIZE_OSST;
                      char SIZE_CHAR;
        while(SIZE_OSST && SIZE_IFST.get(SIZE_CHAR))
              SIZE_OSST.put(SIZE_CHAR);
       return SIZE_OSST.str().size();
    }
bool CHEC(std::string CHEC_STRS)                //检测字符串中是否含有“1A”字符串结束符
    {
              int CHEC_SIZE = CHEC_STRS.size()-1;//判断次数比字符串长度少1
std::stringstream CHEC_BUFF;
                  CHEC_BUFF << CHEC_STRS;
              int CHEC_FLAG = 0;                 //判断标志
             char CHEC_CHAR;
                  CHEC_BUFF.get(CHEC_CHAR);
      while(CHEC_SIZE){
            CHEC_FLAG = 0;
         if(CHEC_CHAR == 26){CHEC_FLAG = 1;break;}       //若检测到“1A”字符串结束符,则将sign置1
         if(CHEC_FLAG == 0)  CHEC_BUFF.get(CHEC_CHAR);
            CHEC_SIZE = CHEC_SIZE-1;}
        if(CHEC_FLAG == 1) return  true;                 //含有1A则返回true
        else               return false;                 //否则返回false
    }
inline std::string FIFT(char* FIFT_NAME)                 //读文件成字符串，并返回
    {
        FILE *     FIFT_INFL = fopen((const char*)FIFT_NAME,"rb");
        char       FIFT_BUFF[2];
        char *     FIFT_TEMP = new char[1048576];
        long long  FIFT_LENS = 0;
       while(fread(FIFT_BUFF,sizeof(char),1,FIFT_INFL) != 0)
        {
         FIFT_TEMP[FIFT_LENS] = FIFT_BUFF[0];
         FIFT_LENS++;
        }
       std::string FIFT_STRS(FIFT_TEMP,FIFT_LENS);
            return FIFT_STRS;
    }
    void FIFR(char* FIFGR_PATH,std::string FIFR_STRB)    //将字符串写入文件
    {
        std::ofstream      FIFR_OFST(FIFGR_PATH);
        std::stringstream  FIFR_SSTM;
          int FIFR_SIZE =  FIFR_STRB.size();
              FIFR_SSTM << FIFR_STRB;
         char FIFR_CHAR =  FIFR_SSTM.get();
        while(FIFR_SIZE){
              FIFR_OFST.put(FIFR_CHAR);
              FIFR_CHAR =   FIFR_SSTM.get();                               //以字符为单位依次写入
              FIFR_SIZE =   FIFR_SIZE - 1;}
    }

};
#endif
