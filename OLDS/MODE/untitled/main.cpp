#include "HEAD.CPP" 
#include "MD5E.CPP" 
#include "RSAE.CPP" 
int main(int argc, char** argv) {
	MD5E MD5S;
	string test="1";
	//MD5S.MD5Q(test);
	//test="148";
	cout<<endl<<MD5S.MD5P(test);
	/*
	RSAE TEST;
	std::cout << "=== rsa加解密 ===" << std::endl;  
    std::string key[2];  
    TEST.GKEY(key);  
    std::cout << "公钥: " << std::endl;  
    std::cout << key[0] << std::endl;  
    std::cout << "私钥： " << std::endl;  
    std::cout << key[1] << std::endl; 
    */
	return 0;
}

