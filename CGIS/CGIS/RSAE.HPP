#ifndef RSAE_HPP
#define RSAE_HPP
#include"HEAD.CPP"
#define KEY_LENGTH    1024         // 密钥长度
#define PUB_KEY_FILE "PUBK.PEM"    // 公钥路径
#define PRI_KEY_FILE "PRIK.PEM"    // 私钥路径
#define RSA_S RSA_FLAGS_SECURIT    // 加密标识
#define RSA_P RSA_PKCS1_PADDING    // 填充方式
class RSAE
{
    public:
          void LKEY();          //载入密钥，从文件读取公私钥
          void GKEY(string[2]); //创建密钥，本地文件会被覆盖
          void PKEY(string[2]); //读取密钥，存放在字符串数组
          void SKEY(string[2]); //写入密钥，从传入字符串写入
        string ENCY(const string&);//加密
        string DECY(const string&);//解密
   private:
        string RSAK[2];         //主密密钥
};
#endif
