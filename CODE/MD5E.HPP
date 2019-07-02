#ifndef   MD5E_HPP
#define   MD5E_HPP
#include "READ.CPP"
class MD5E
{
	public:
        MD5E(){}                       //构造函数
       ~MD5E(){}                       //析构函数
        READ TTPP;                     //读取模块
        std::string MD5E_TEXT;         //原始文本
        std::string MD5E_ENCY;         //摘要字符
        std::string MD5E_EN16;         //摘要文本
 unsigned char MD5E_ESTR[33]= {0};     //中间数据
          char MD5E_BUFF[65]= {0};     //缓冲文件
          char MD5E_TEMP[ 3]= {0};     //临时转存
    bool MD5P(std::string);            //验证密码
    void MD5Q(std::string);            //写入密码
  std::string MD5C();                  //获取摘要
  std::string MD5C(std::string);       //获取摘要
};
#endif
