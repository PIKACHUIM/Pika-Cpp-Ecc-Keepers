#ifndef DESA_HPP
#define DESA_HPP

#include <string>

#define DESA_BPCL_LENS 8
#define DESA_KSZI_LENS 8
#define DESA_SKEY_LENS 16
#define DESA_SBBK_LENS 48
#define DESA_EXKY_SIZE 48
#define DESA_PC2R_LENS 48
#define DESA_PC1R_LENS 56
#define DESA_BSTR_LENS 64

class DESA
{
public:
    DESA();
   ~DESA();
    std::string Encrypt(const std::string& plain, const std::string& key);
    std::string Decrypt(const std::string& cipher, const std::string& key);
private:
    //生成16个子秘钥
    bool CreateSubKey(const std::string& key, char subKey[DESA_SKEY_LENS][DESA_SBBK_LENS]);
    bool EncryptBlock(std::string& block, char subKey[DESA_SKEY_LENS][DESA_SBBK_LENS]);//加密8字节数据块
    bool DecryptBlock(std::string& block, char subKey[DESA_SKEY_LENS][DESA_SBBK_LENS]);//解密8字节数据块
    //----------------------------------转换工具-----------------------------------------------
    bool PC1_Transform(const std::string& bitStr, std::string& PC1BitStr);
    bool PC2_Transform(const std::string& PC1BitStr, char subKey[DESA_SBBK_LENS]);
    bool IP_Transform(std::string& bitStr);
    bool Expand_Transform(const std::string& halfBitStr, std::string& eBitStr);
    bool SBox_Transform(const std::string& eBitStr, std::string& halfBitStr);
    bool Permute_Transform(std::string& halfBitStr);
    bool IP_1_Transform(std::string& bitStr);
    //------------------------------------基础工具------------------------------------------------
    bool Char8ToBit64(const std::string& str, std::string& bitStr);
    bool Bit64ToChar8(const std::string& bitStr, std::string& str);
    bool XOR(std::string& strFirst, std::string& strSecond, size_t num);
    bool LeftCycle(std::string& str, size_t beginSection, size_t endSection, size_t step);
    //------------------------------------生成秘钥需要的表------------------------------------------
    static char PC1_Table[DESA_PC1R_LENS];          //置换选择表
    static char Move_Table[DESA_SKEY_LENS];         //左循距离表
    static char PC2_Table[DESA_PC2R_LENS];          //置换选择表
    //----------------------------------加密或解密需要的表------------------------------------------
    static char IP_Table[DESA_BSTR_LENS];           //置换位置
    static char Expand_Table[DESA_EXKY_SIZE];       //重复扩展
    static char Permute_Table[DESA_BSTR_LENS / 2];  //单置换表
    static char IP_1_Table[DESA_BSTR_LENS];         //反置换表
    static char SBox_Table[DESA_KSZI_LENS][4][16];  //单置换盒
};



#endif // DESA_HPP
