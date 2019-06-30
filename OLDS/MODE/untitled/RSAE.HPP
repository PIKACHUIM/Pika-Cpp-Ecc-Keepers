#ifndef RSAE_HPP
#define RSAE_HPP
#include"HEAD.CPP"
#define KEY_LENGTH    1024         // 密钥长度  
#define PUB_KEY_FILE "PUBK.PEM"    // 公钥路径  
#define PRI_KEY_FILE "PRIK.PEM"    // 私钥路径  
class RSAE
{
	public:
		string strKey[2];
		void GKEY(std::string strKey[2])  
		{
		    // 公私密钥对    
		    size_t pri_len;  
		    size_t pub_len;  
		    char *pri_key = NULL;  
		    char *pub_key = NULL;  
		    // 生成密钥对    
		    RSA *keypair = RSA_generate_key(KEY_LENGTH, RSA_3, NULL, NULL);  
		    BIO *pri = BIO_new(BIO_s_mem());  
		    BIO *pub = BIO_new(BIO_s_mem());  
		    PEM_write_bio_RSAPrivateKey(pri, keypair, NULL, NULL, 0, NULL, NULL);  
		    PEM_write_bio_RSAPublicKey(pub, keypair);  
		    // 获取长度    
		    pri_len = BIO_pending(pri);  
		    pub_len = BIO_pending(pub);  
		    // 密钥对读取到字符串    
		    pri_key = (char *)malloc(pri_len + 1);  
		    pub_key = (char *)malloc(pub_len + 1);  
		    BIO_read(pri, pri_key, pri_len);  
		    BIO_read(pub, pub_key, pub_len);  
		    pri_key[pri_len] = '\0';  
		    pub_key[pub_len] = '\0';  
		    // 存储密钥对    
		    strKey[0] = pub_key;  
		    strKey[1] = pri_key;  
		    // 存储到磁盘（这种方式存储的是begin rsa public key/ begin rsa private key开头的）  
		    FILE *pubFile = fopen(PUB_KEY_FILE, "w");  
		    if (pubFile == NULL)  
		    {  
		        assert(false);  
		        return;  
		    }  
		    fputs(pub_key, pubFile);  
		    fclose(pubFile);  
		  
		    FILE *priFile = fopen(PRI_KEY_FILE, "w");  
		    if (priFile == NULL)  
		    {  
		        assert(false);  
		        return;  
		    }  
		    fputs(pri_key, priFile);  
		    fclose(priFile);  
		    // 内存释放  
		    RSA_free(keypair);  
		    BIO_free_all(pub);  
		    BIO_free_all(pri);  
		    free(pri_key);  
		    free(pub_key);  
}
};
#endif
