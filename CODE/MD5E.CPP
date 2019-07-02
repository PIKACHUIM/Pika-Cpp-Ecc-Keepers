#ifndef   MD5E_CPP
#define   MD5E_CPP
#include "MD5E.HPP"

bool MD5E::MD5P(std::string MD5E_INPU)//-----------验证密码-----------------------------
{
                MD5E TEMP;                                        //防止冲突
    std::string MD5E_PDMA=TEMP.MD5C((const std::string)MD5E_INPU);//获取摘要
    std::string MD5E_PDMB=TTPP.FIFT     ((char* )      PASS_PATH);//读取文件
         return MD5E_PDMA.compare(MD5E_PDMB);                     //判断密码
}
void MD5E::MD5Q(std::string MD5E_INPR)//-----------修改密码-----------------------------
{
               MD5E TEMP;
   std::string MD5E_PDMC;
               MD5E_PDMC=TEMP.MD5C((const std::string) MD5E_INPR);
               TTPP.FIFR((char* )PASS_PATH,  MD5E_PDMC);
}
std::string MD5E::MD5C(){return MD5C(MD5E_TEXT);}//从内部获取摘要------------------------
std::string MD5E::MD5C(std::string MD5E_INPU)    //从外部获取摘要------------------------
{
      MD5E_TEXT=MD5E_INPU;
      MD5((const unsigned char *)
      MD5E_TEXT.c_str(),
      MD5E_TEXT.length(),
      MD5E_ESTR);
      MD5E_ENCY = std::string((const char *)MD5E_ESTR);
         for (int MD5E_LOOP = 0;
                  MD5E_LOOP < 32;
                  MD5E_LOOP++){
          sprintf(MD5E_TEMP, "%02x",
                  MD5E_ESTR[MD5E_LOOP]);
           strcat(MD5E_BUFF,
                  MD5E_TEMP);}
                  MD5E_BUFF[32] = '\0';                               //从0x32截断
                  MD5E_EN16 = std::string(MD5E_BUFF);
          memset(&MD5E_TEXT,sizeof (MD5E_TEXT),0);
           return MD5E_EN16;
}
#endif
