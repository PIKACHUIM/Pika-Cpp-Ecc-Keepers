#ifndef RSAE_CPP
#define RSAE_CPP
#include"RSAE.HPP"
#include"READ.CPP"
void   RSAE::GKEY(string strKey[2])
{
    size_t GKEY_PRIL;    //私钥长度
    size_t pub_len;      //公钥长度
    char *pri_key = NULL;
    char *pub_key = NULL;
    RSA *keypair = RSA_generate_key(KEY_LENGTH, RSA_3, NULL, NULL);
    BIO *pri = BIO_new(BIO_s_mem());
    BIO *pub = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(pri, keypair, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_RSAPublicKey(pub, keypair);
    GKEY_PRIL = BIO_pending(pri);
    pub_len = BIO_pending(pub);
    pri_key = (char *)malloc(GKEY_PRIL + 1);
    pub_key = (char *)malloc(pub_len + 1);
    BIO_read(pri, pri_key, GKEY_PRIL);
    BIO_read(pub, pub_key, pub_len);
    pri_key[GKEY_PRIL] = '\0';
    pub_key[pub_len] = '\0';
    RSAK[0]=pub_key;
    RSAK[1]=pri_key;
    strKey[0] = pub_key;
    strKey[1] = pri_key;
    FILE *pubFile = fopen(PUB_KEY_FILE, "w");
    if (pubFile == NULL)assert(false);
    fputs(pub_key, pubFile);
    fclose(pubFile);
    FILE *priFile = fopen(PRI_KEY_FILE, "w");
    if (priFile == NULL)assert(false);
    fputs(pri_key, priFile);
    fclose(priFile);
    RSA_free(keypair);
    BIO_free_all(pub);
    BIO_free_all(pri);
    free(pri_key);
    free(pub_key);
}
void   RSAE::LKEY()
{
    RSAK[0]=FIFT((char*)"PUBK.PEM");
    RSAK[1]=FIFT((char*)"PRIK.PEM");
    //cout<<RSAK[0]<<endl;
    //cout<<RSAK[1]<<endl;
}
void   RSAE::SKEY(string IRSA[2])
{
    RSAK[0] = IRSA[0];
    RSAK[1] = IRSA[1];
}
void   RSAE::PKEY(string IRSA[2])
{
    IRSA[0] = RSAK[0];
    IRSA[1] = RSAK[1];
}
string RSAE::ENCY(const  string &ENCY_CLTX)
{
          string strRet;
          LKEY();
    const string ENCY_PPBK=RSAK[0];
    RSA *ENCY_TRSA = NULL;
    BIO *ENCY_BRSA = BIO_new_mem_buf((unsigned char *)ENCY_PPBK.c_str(), -1);
         ENCY_TRSA = PEM_read_bio_RSAPublicKey(ENCY_BRSA,
                                              &ENCY_TRSA, NULL, NULL);
         int ENCY_LENS = RSA_size(ENCY_TRSA);
        char*ENCY_ENTX = (char *)malloc(ENCY_LENS + 1);
      memset(ENCY_ENTX, 0, ENCY_LENS + 1);
        int  ENCY_RETS = RSA_public_encrypt(ENCY_CLTX.length(), (const unsigned char*)ENCY_CLTX.c_str(), (unsigned char*)ENCY_ENTX, ENCY_TRSA, RSA_PKCS1_PADDING);
        if  (ENCY_RETS >= 0)strRet = string(ENCY_ENTX, ENCY_RETS);
        free(ENCY_ENTX);
BIO_free_all(ENCY_BRSA);
    RSA_free(ENCY_TRSA);
    return strRet;
}
string RSAE::DECY(const  string& DECY_CIPH)
{
      string DECY_SRET;
       LKEY();
const string DECY_PRIK=RSAK[1];
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
       DECY_SRET = string(DECY_TEXT,
                          DECY_RETS);
                     free(DECY_TEXT);
             BIO_free_all(DECY_BRSA);
                 RSA_free(DECY_TRSA);
                   return DECY_SRET;
}
#endif
