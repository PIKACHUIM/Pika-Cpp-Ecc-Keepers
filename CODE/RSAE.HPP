#ifndef   RSAE_HPP
#define   RSAE_HPP
#include "READ.CPP"
class RSAE
{
    public:
          READ TTPP;
          void LKEY();                       //载入密钥
          void GKEY(std::string[2]);         //创建密钥
          void PKEY(std::string[2]);         //读取密钥
          void SKEY(std::string[2]);         //写入密钥
        std::string ENCY(const std::string&);//加密数据
        std::string DECY(const std::string&);//解密数据
   private:
        std::string RSAK[2];                 //公私密钥
};
#endif
