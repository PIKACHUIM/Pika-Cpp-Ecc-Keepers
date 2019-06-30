#ifndef MD5E_HPP
#define MD5E_HPP
#include "HEAD.CPP"
class MD5E
{
	public:
        MD5E(){}
       ~MD5E(){}
	    string MD5E_TEXT;
	    string MD5E_ENCY;
	    string MD5E_EN16;
 unsigned char MD5E_ESTR[33]= {0};
		  char MD5E_BUFF[65]= {0};
		  char MD5E_TEMP[ 3]= {0};
    bool MD5P(string);
    void MD5Q(string);
  string MD5C();
  string MD5C(string);
};
#endif
