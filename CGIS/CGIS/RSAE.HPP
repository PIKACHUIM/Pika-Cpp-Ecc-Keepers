#ifndef RSAE_HPP
#define RSAE_HPP
#include"HEAD.CPP"
#define KEY_LENGTH    1024         // 密钥长度  
#define PUB_KEY_FILE "PUBK.PEM"    // 公钥路径  
#define PRI_KEY_FILE "PRIK.PEM"    // 私钥路径  
class RSAE
{
	public:
        string RSAK[2];
          void LKEY();
          void GKEY(std::string[2]);
          void PKEY(std::string[2]);
          void SKEY(std::string[2]);
        string ENCY(const std::string&);
        string DECY(const std::string&);
};
#endif
