//Completed 11/27/2019
//Project2-CSC319
//Team 2:
//Dominic Le
//Minh Le
//Quan Le
#include <string>
#include <iostream>
#include <tuple>
#include "fileParser.h"
#include "transactionSystem.h"
#include "transaction.h"
#include "territory.h"
#include "saleRep.h"
int main(int argc, char* argv[]){    
    std::string territoryIFile=argv[1];
    std::string salerepIOFile=argv[2];
    std::string transactionIFile=argv[3];
    std::string territoryOFile=argv[4];
    TextFileParser TI(territoryIFile);
    BinaryFileParser SIO(salerepIOFile);
    TextFileParser RI(transactionIFile);
    TextFileParser TO(territoryOFile,true);
    TransactionSystem managementSystem;
    //Read file Territory
    while (!TI.eof()){
        string id, type;
        TI >> id >> type;
        managementSystem+= Territory::createTerritory(id,type);
    }
    TI.close();
    //Read file SaleRep
    while (!SIO.eof()){
        string id, terId, amount;
        SIO>> id >> terId >> amount;
        managementSystem+= new SaleRep(id,terId,amount);
    }
    //Read file Transaction
    while (!RI.eof()){
        string id, salerepId, type, amount;
        RI>> id >> salerepId >> type >> amount;
        managementSystem.resolving(new Transaction(id,salerepId,type,amount));
    }
    RI.close();
    //Write to File Output
    for (Territory* territory:managementSystem.getTerritories()){
        TO << *territory;
    }
    TO.close();
    //Write to console and Edit file SaleRep
    for (SaleRep* saleRep:managementSystem.getSaleReps()){
        cout<< (*saleRep);
        SIO << *saleRep;
    }
    SIO.close();
}