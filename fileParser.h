#ifndef file_parser_header
#define file_parser_header
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
using namespace std;
class FileParser{
    private:
        string fileName;
        fstream fileStream;
        stringstream lineStream;
        bool ifBinary;
    public:
        FileParser(std::string fileName, bool ifBinary=false);
        FileParser& operator>>(string &aString);
        bool eof();
        void close();
};

#endif