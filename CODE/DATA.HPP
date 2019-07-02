#ifndef   DATA_HPP
#define   DATA_HPP
#include "RSAE.HPP"

class DATA
{
public:
       int  LENS;                         //数据长度
       READ TTPP;                         //读写模块
       RSAE FNEW_TEMP;                    //加密解密
       int  FIDS[4096];                   //文件编号
std::string BASE[4096];                   //文件名称
            DATA()= default;;             //默认构造
       void LOAD();                       //载入数据
       void WRIT();                       //写入数据
       void FDEL(int);                    //删除文件
std::string NGET(int);                    //获取名称
        int FNEW(std::string,std::string);//新增文件
        int FGET(int        ,std::string);//导出文件
};
#endif // DATA_HPP
