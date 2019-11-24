#ifndef file_parser_header
#define file_parser_header
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <utility>
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
        FileParser& operator<<(string aString);
        FileParser& operator<<(pair <string,int> aFormattedString);
        bool eof();
        void close();
};

#endif