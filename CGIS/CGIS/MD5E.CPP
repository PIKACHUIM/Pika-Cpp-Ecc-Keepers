#ifndef   MD5E_CPP
#define   MD5E_CPP
#include "MD5E.HPP"
#include "read.CPP"
#define PASS_PATH ".//CONF//DAT_PASS_00.INI"
bool MD5E::MD5P(string MD5E_INPU)
{
    MD5E TEMP;
    string MD5E_PDMA=TEMP.MD5C((const string)MD5E_INPU);
    string MD5E_PDMB=FIFT     ((char* )      PASS_PATH);
    cout<<"--------------[PASS] 0x"<<(void*)&TEMP<<" PASSWDR_AUTH--------------"<<endl;
     cout<<"*** ORG_PASSWDRO_MD5: "<<MD5E_PDMB<<"***"<<endl;
     cout<<"*** IPU_PASSWDRO_MD5: "<<MD5E_PDMA<<"***"<<endl;
     if(MD5E_PDMA.compare(MD5E_PDMB)==0)
          cout<<"#######################AUTH_SUCCESS#######################"<<endl;
     else cout<<"#######################AUTH_FAILURE#######################"<<endl;
     cout<<"----------------------------------------------------------"<<endl;
     return MD5E_PDMA.compare(MD5E_PDMB);
}
void MD5E::MD5Q(string MD5E_INPR)
{
     MD5E TEMP;
   string MD5E_PDMC;
          MD5E_PDMC=TEMP.MD5C((const string) MD5E_INPR);
                    FIFR((char* )PASS_PATH,  MD5E_PDMC);
    cout<<"--------------[PASS] 0x"<<(void*)&TEMP<<" PASSWDR_CHAG--------------"<<endl;
    cout<<"*** NEW_PASSWDRO_MD5: "<<MD5E_PDMC<<"***"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
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
      memset(&MD5E_TEXT,sizeof (MD5E_TEXT),0);
       return MD5E_EN16;
}
#endif
