#ifndef file_parser_header
#define file_parser_header
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <utility>
#include "territory.h"
#include "saleRep.h"
using namespace std;
class FileParser{
    private:
        string fileName;
        fstream fileStream;
        stringstream lineStream;
        bool ifBinary;
    public:
        FileParser(std::string fileName, bool ifBinary=false, bool required=false);
        FileParser& operator>>(string &aString);
        FileParser& operator<<(SaleRep& aSaleRep);
        FileParser& operator<<(Territory& aTerritory);
        bool eof();
        void close();
};

#endif