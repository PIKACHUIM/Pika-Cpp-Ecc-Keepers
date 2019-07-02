#ifndef HEAD_CPP
#define HEAD_CPP
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <QCoreApplication>
#include <QApplication>
#include "OSSL/md5.h"
#include "OSSL/pem.h"
#include "OSSL/rsa.h"
#define STG std::string
#define KEY_LENGTH 1024         // 密钥长度
#define PRI_KEY_FILE "PRIK.PEM" // 私钥路径
#define PUB_KEY_FILE "PUBK.PEM" // 公钥路径
#define RSA_P RSA_PKCS1_PADDING // 填充方式
#define RSA_S RSA_FLAGS_SECURIT // 加密标识
#define PASS_PATH ".//CONF//DAT_PASS_00.INI"
#pragma comment(lib, "E:\\CPP-BCSZ\\PIKA-CFSS\\CGIS\\CGIS\\OLIB\\libcrypto32MD.lib")
class      Add_Delete;
class    Login_Widget;
class Register_Widget;
class     File_Widget;
class   Modify_Widget;
class   Verify_Widget;
class      MainWidget;

#endif
