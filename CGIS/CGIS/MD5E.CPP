#ifndef MD5E_CPP
#define MD5E_CPP
#include"MD5E.HPP"
#include"READ.CPP"
bool MD5E::MD5P(string MD5E_INPU)
{
    string MD5E_PDMA=MD5C((const string)MD5E_INPU);
    string MD5E_PDMB=FIFT((char* )".//CONF//PASS");
     cout<<MD5E_PDMB<<endl;
    return MD5E_PDMA.compare(MD5E_PDMB);
}
void MD5E::MD5Q(string MD5E_INPU)
{
   string MD5E_PDMA=MD5C(MD5E_INPU);

}
string MD5E::MD5C(){return MD5C(MD5E_TEXT);}
string MD5E::MD5C(string MD5E_INPU)
{
      MD5E_TEXT=MD5E_INPU;
      MD5((const unsigned char *)
      MD5E_TEXT.c_str(),
      MD5E_TEXT.length(),
      MD5E_ESTR);
      MD5E_ENCY = string((const char *)MD5E_ESTR);
      for (int MD5E_LOOP = 0; MD5E_LOOP < 32; MD5E_LOOP++){
          sprintf(MD5E_TEMP, "%02x",
                  MD5E_ESTR[MD5E_LOOP]);
           strcat(MD5E_BUFF,
                  MD5E_TEMP);}
      MD5E_BUFF[32] = '\0';                               //从0x32截断
      MD5E_EN16 = string(MD5E_BUFF);
       cout<<MD5E_EN16.c_str()<<endl;
      return MD5E_EN16;
}
#endif
