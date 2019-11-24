#include <string>
#include "fileParser.h"
#include <iostream>
#include <tuple>
int main(int argc, char* argv[]){    
    std::string territoryIFile=argv[1];
    std::string salerepIOFile=argv[2];
    std::string transactionIFile=argv[3];
    std::string territoryOFile=argv[4];
    FileParser TI(territoryIFile);
    std::string a;
    std::string b;
    cout<<"Territory"<<endl;
    while (!TI.eof()){
        TI>>b>>a;
        cout<<b<<" "<<b<<endl;
    }
    TI.close();
    FileParser SI(salerepIOFile);
    string a1,b1,c1;
    cout<<"SALEREP:"<<endl;
    while (!SI.eof()){
        SI>>a1>>b1>>c1;
        cout<<a1<<" "<<b1<<" "<<c1;
        cout<< endl;

    }
}