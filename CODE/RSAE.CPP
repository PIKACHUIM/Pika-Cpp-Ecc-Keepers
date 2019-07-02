#ifndef  RSAE_CPP
#define  RSAE_CPP
#include"RSAE.HPP"

void   RSAE::GKEY(std::string strKey[2])//--------------------------生成密钥---------------
{
    size_t GKEY_PRIL;    //私钥长度
    size_t GKEY_PUBL;    //公钥长度
     char* GKEY_PRIK = NULL;
     char* GKEY_PUBK = NULL;
      RSA* GKEY_KRPY = RSA_generate_key(KEY_LENGTH, RSA_3, NULL, NULL);
      BIO* GKEY_PRIB = BIO_new(BIO_s_mem());
      BIO* GKEY_PUBB = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(GKEY_PRIB, GKEY_KRPY, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_RSAPublicKey (GKEY_PUBB, GKEY_KRPY);
                GKEY_PRIL = BIO_pending(GKEY_PRIB);
                GKEY_PUBL = BIO_pending(GKEY_PUBB);
                GKEY_PRIK = (char *)malloc(GKEY_PRIL + 1);
                GKEY_PUBK = (char *)malloc(GKEY_PUBL + 1);
       BIO_read(GKEY_PRIB, GKEY_PRIK, GKEY_PRIL);
       BIO_read(GKEY_PUBB, GKEY_PUBK, GKEY_PUBL);
                GKEY_PRIK[GKEY_PRIL] = '\0';
                GKEY_PUBK[GKEY_PUBL] = '\0';
        RSAK[0]=GKEY_PUBK;
        RSAK[1]=GKEY_PRIK;
    strKey[0] = GKEY_PUBK;
    strKey[1] = GKEY_PRIK;
          FILE *GKEY_PUBF = fopen(PUB_KEY_FILE, "w");
            if (GKEY_PUBF == NULL)assert(false);
          fputs(GKEY_PUBK, GKEY_PUBF);
         fclose(GKEY_PUBF);
          FILE *GKEY_PRIF = fopen(PRI_KEY_FILE, "w");
            if (GKEY_PRIF == NULL)assert(false);
          fputs(GKEY_PRIK, GKEY_PRIF);
         fclose(GKEY_PRIF);
       RSA_free(GKEY_KRPY);
   BIO_free_all(GKEY_PUBB);
   BIO_free_all(GKEY_PRIB);
           free(GKEY_PRIK);
           free(GKEY_PUBK);
}
void   RSAE::LKEY()                     //--------------------------载入密钥---------------
{
    RSAK[0]=TTPP.FIFT((char*)"PUBK.PEM");
    RSAK[1]=TTPP.FIFT((char*)"PRIK.PEM");
}
void   RSAE::SKEY(std::string IRSA[2])  //--------------------------修改密钥---------------
{
    RSAK[0] = IRSA[0];
    RSAK[1] = IRSA[1];
}
void   RSAE::PKEY(std::string IRSA[2])  //--------------------------获取密钥---------------
{
    IRSA[0] = RSAK[0];
    IRSA[1] = RSAK[1];
}
std::string RSAE::ENCY(const  std::string &ENCY_CLTX)  //-----------数据加密---------------
{
          std::string strRet;
          LKEY();
    const std::string ENCY_PPBK=RSAK[0];
    RSA *ENCY_TRSA = NULL;
    BIO *ENCY_BRSA = BIO_new_mem_buf((unsigned char *)ENCY_PPBK.c_str(), -1);
         ENCY_TRSA = PEM_read_bio_RSAPublicKey(ENCY_BRSA,
                                              &ENCY_TRSA, NULL, NULL);
         int ENCY_LENS = RSA_size(ENCY_TRSA);
        char*ENCY_ENTX = (char *)malloc(ENCY_LENS + 1);
      memset(ENCY_ENTX, 0, ENCY_LENS + 1);
        int  ENCY_RETS = RSA_public_encrypt(ENCY_CLTX.length(), (const unsigned char*)ENCY_CLTX.c_str(), (unsigned char*)ENCY_ENTX, ENCY_TRSA, RSA_PKCS1_PADDING);
        if  (ENCY_RETS >= 0)strRet = std::string(ENCY_ENTX, ENCY_RETS);
        free(ENCY_ENTX);
BIO_free_all(ENCY_BRSA);
    RSA_free(ENCY_TRSA);
    return strRet;
}
std::string RSAE::DECY(const  std::string& DECY_CIPH)  //-----------数据解密---------------
{
      std::string DECY_SRET;
       LKEY();
const std::string DECY_PRIK=RSAK[1];
  RSA *DECY_TRSA = RSA_new();
  BIO *DECY_BRSA;
       DECY_BRSA = BIO_new_mem_buf((unsigned char*)DECY_PRIK.c_str(), -1);
       DECY_TRSA = PEM_read_bio_RSAPrivateKey(DECY_BRSA,&DECY_TRSA, nullptr, nullptr);
   int DECY_LENS =      RSA_size(DECY_TRSA);
 char* DECY_TEXT = (char*)malloc(DECY_LENS + 1);
memset(DECY_TEXT,0,
       DECY_LENS+1);
   int DECY_RETS = RSA_private_decrypt(
                          DECY_CIPH.length(), (const unsigned char*)
                          DECY_CIPH.c_str(), (unsigned char*)
                          DECY_TEXT,
                          DECY_TRSA, RSA_PKCS1_PADDING);
   if (DECY_RETS >= 0)
       DECY_SRET = std::string(DECY_TEXT,
                          DECY_RETS);
                     free(DECY_TEXT);
             BIO_free_all(DECY_BRSA);
                 RSA_free(DECY_TRSA);
                   return DECY_SRET;
}
#endif
