#include "fileParser.h"
#include <iostream>
using namespace std;
FileParser::FileParser(std::string fileName,bool ifBinary){
    this->fileName=fileName;
    this->ifBinary=ifBinary;
    
    if (ifBinary)
        fileStream.open(fileName,ios::binary | ios::in | ios::out);
    else
        fileStream.open(fileName);
    
}
FileParser& FileParser::operator>>(std::string &aString){
    char c;
    aString="";
    if (!ifBinary)
    {
        bool ifWord=false;
        if (lineStream.eof() || lineStream.str()==""){
            string line;
            lineStream.clear();
            getline(fileStream,line);
            lineStream.str(line);
        }
        while (lineStream >> c){
            if ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'))
                {aString.insert(aString.end(),c);ifWord=true;}
            else{
                if (ifWord) break;
            }
        }
    }
    else
    {
       //TODO
    }
    return *this;
}
bool FileParser::eof(){
    return fileStream.eof();
}
void FileParser::close(){
    fileStream.close();
}