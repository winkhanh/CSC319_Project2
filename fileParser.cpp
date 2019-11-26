#include "fileParser.h"
using namespace std;

//Constructor 
FileParser::FileParser(string fileName){
    this->fileName=fileName;
}

TextFileParser::TextFileParser(string fileName,bool required) : FileParser(fileName){
    fileStream.open(fileName,(required)?(fstream::out):(fstream::in | fstream::out));
}
BinaryFileParser::BinaryFileParser(string fileName) : FileParser(fileName){
    fileStream.open(fileName,fstream::binary | fstream::in | fstream::out);
    this->buffer=vector<unsigned char>((istreambuf_iterator<char>(fileStream)),istreambuf_iterator<char>());    
}

// operator >>
TextFileParser& TextFileParser::operator>>(string& aString){
    char c;
    aString="";
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
    return *this;
}
BinaryFileParser& BinaryFileParser::operator>>(string& aString){
    return *this;
}

//operator <<
TextFileParser& TextFileParser::operator<<(SaleRep& aSaleRep){
    fileStream<<aSaleRep;
    return *this;
}

TextFileParser& TextFileParser::operator<<(Territory& aTerritory){
    fileStream << aTerritory;
    return *this;
}
BinaryFileParser& BinaryFileParser::operator<<(SaleRep& aSaleRep){
    return *this;
}

//common function
bool FileParser::eof(){
    return fileStream.eof();
}
void FileParser::close(){
    fileStream.close();
}