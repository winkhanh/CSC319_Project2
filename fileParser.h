#ifndef file_parser_header
#define file_parser_header
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <iterator>
#include "territory.h"
#include "saleRep.h"
using namespace std;
class FileParser{
    protected:
        string fileName;
        fstream fileStream;
    public:
        FileParser(string fileName);
        virtual FileParser& operator>>(string &aString)=0;
        virtual FileParser& operator<<(SaleRep& aSaleRep)=0;
        bool eof();
        void close();
};

class TextFileParser: public FileParser{
    private:
        stringstream lineStream;
    public:
        TextFileParser(string fileName,bool required=false);
        TextFileParser& operator>>(string &aString);
        TextFileParser& operator<<(SaleRep& aSaleRep);
        TextFileParser& operator<<(Territory& aTerritory);
};

class BinaryFileParser: public FileParser{
    private:
        vector <unsigned char> buffer;
        int readPos;
    public:
        BinaryFileParser(string fileName);
        BinaryFileParser& operator>>(string &aString);
        BinaryFileParser& operator<<(SaleRep& aSaleRep);
        bool eof();
        void flush();
};

#endif