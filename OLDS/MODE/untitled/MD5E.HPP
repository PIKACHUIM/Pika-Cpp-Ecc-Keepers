#ifndef MD5E_HPP
#define MD5E_HPP
#include "HEAD.CPP"
class MD5E
{
	public:
		MD5E(){};
   	   ~MD5E(){};
	    string MD5E_TEXT;
	    string MD5E_ENCY;
	    string MD5E_EN16;
 unsigned char MD5E_ESTR[33]= {0};
		  char MD5E_BUFF[65]= {0};
		  char MD5E_TEMP[ 3]= {0};
  bool MD5P(string MD5E_INPU)
{
  	 string MD5E_PDMA=MD5C(MD5E_INPU);
  	 string MD5E_PDMB;
  	 char*  MD5E_PDMT;
  	 FILE*  MD5E_FILE;
      char* MD5E_OPEN = "./CONF/PASS";
            MD5E_FILE=fopen(MD5E_OPEN, "r");
   fscanf(MD5E_FILE,"%s",&MD5E_PDMT); //读取
      //fgets(MD5E_PDMT,32,MD5E_FILE);
            MD5E_PDMB=(string)MD5E_PDMT;
     fclose(MD5E_FILE);
   return MD5E_PDMA.compare(MD5E_PDMB);
   
}
/*void MD5Q(string MD5E_INPU)
{
  	 string MD5E_PDMA=MD5C(MD5E_INPU);
  	 FILE*  MD5E_FILE;
 char* MD5E_OPEN = "./CONF/PASS";
   MD5E_FILE=fopen(MD5E_OPEN, "w");
   fprintf(MD5E_FILE,"%s",&MD5E_PDMA); //写入 
    fclose(MD5E_FILE);
}*/
string MD5C(){return MD5C(MD5E_TEXT);}
string MD5C(string MD5E_INPU)
{
	   	MD5E_TEXT=MD5E_INPU;
	   	MD5((const unsigned char *)
		MD5E_TEXT.c_str(),
		MD5E_TEXT.length(), 
		MD5E_ESTR); 
		MD5E_ENCY = std::string((const char *)MD5E_ESTR);
		for (int MD5E_LOOP = 0; MD5E_LOOP < 32; MD5E_LOOP++)  
    	{  
        	sprintf(MD5E_TEMP, "%02x", 
			        MD5E_ESTR[MD5E_LOOP]);  
        	 strcat(MD5E_BUFF, 
			        MD5E_TEMP);  
    	}  
   		MD5E_BUFF[32] = '\0';                               //从0x32截断 
    	MD5E_EN16 = std::string(MD5E_BUFF);  
    	cout<< MD5E_EN16<<endl;
		return MD5E_EN16;
}
};
#endif
