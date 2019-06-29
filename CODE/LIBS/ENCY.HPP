#ifndef ENCY_HPP
#define ENCY_HPP


#include <string>
#include "RSAE.CPP"
#include "BNUM.CPP"
class EncryptDecrypt {
public:
    EncryptDecrypt() {}
    ~EncryptDecrypt() {}

    void menu();    // 菜单显示
    bool encrypt();    // 加密
    bool decrypt();    // 解密
    void print();    // 打印RSA相关信息
    void reset();    // 重置RSA相关信息
protected:
    void load(int);    // 根据给定位数加载RSA对象
    bool islegal(const std::string &);// 判断输入字符串是否合法
private:
    RSA rsa;
};


#endif // ENCY_HPP
