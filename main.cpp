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
    FileParser TI(territoryIFile);
    FileParser SI(salerepIOFile);
    FileParser RI(transactionIFile);
    FileParser TO(territoryOFile,false,true);
    TransactionSystem managementSystem;
    while (!TI.eof()){
        string id, type;
        TI >> id >> type;
        managementSystem+= Territory::createTerritory(id,type);
    }
    TI.close();
    while (!SI.eof()){
        string id, terId, amount;
        SI>> id >> terId >> amount;
        managementSystem+= new SaleRep(id,terId,amount);
    }
    while (!RI.eof()){
        string id, salerepId, type, amount;
        RI>> id >> salerepId >> type >> amount;
        managementSystem.resolving(new Transaction(id,salerepId,type,amount));
    }
    RI.close();
    for (SaleRep* saleRep:managementSystem.getSaleReps()){
        cout<<saleRep->getId() <<"," << saleRep->getAmount() << endl;
    }
    TI.close();
}