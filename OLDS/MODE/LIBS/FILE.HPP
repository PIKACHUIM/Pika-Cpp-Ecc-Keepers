#ifndef FILE_HPP
#define FILE_HPP

#include<iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Cfile
{
    Cfile() {};
    fstream f;
    string str;

        void readFileIntoString(char * filename)
        {
            ifstream ifile(filename);
            ostringstream buf;
            char ch;
            while (buf&&ifile.get(ch))
                buf.put(ch);
            cout<<buf.str()<<endl;
        }

        void writeFile(char * filename)
        {
            cin >> str;
            f.open(filename, ios::in | ios::out | ios::binary);
            if (f.fail())
            {
                cout << "OPEN_FAIL" << endl;
                exit(1);
            }
            f.write((char*)&str, sizeof(str));
            f.close();
        }

        void readString()
        {
            cin >> str;
            f << str;
        }

};

#endif // FILE_HPP
