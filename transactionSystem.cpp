#include "transactionSystem.h"

TransactionSystem& TransactionSystem::operator+=(Territory* aTerrioty){
    this->mapTerritory[aTerrioty->getId()]=aTerrioty;
    return *this;
}

TransactionSystem& TransactionSystem::operator+=(SaleRep* aSaleRep){
    string territoryId= aSaleRep->getTerritoryId();
    if (this->mapTerritory.find(territoryId)==this->mapTerritory.end())
        {
            //No territory
            cout<< "No territory for this salrep found in the system\n";
            return *this;
        }
    aSaleRep->setTerritory(this->mapTerritory[territoryId]);
    this->mapSaleRep[aSaleRep->getId()]=aSaleRep;
    return *this;
}

vector <SaleRep*> TransactionSystem::getSaleReps(){
    vector <SaleRep*> aList;aList.clear();
    for (auto saleRepit = this->mapSaleRep.begin(); saleRepit != this->mapSaleRep.end();saleRepit++){
        aList.push_back(saleRepit->second);
    };
    sort(aList.begin(),aList.end(),[](SaleRep* x, SaleRep* y)->bool{
        return (x->getAmount() ==y->getAmount())?(x->getId() < y->getId()):(x->getAmount()>y->getAmount());
    });
    return aList;
}

vector <Territory*> TransactionSystem::getTerritories(){
    vector <Territory*> aList;aList.clear();
    for (auto territoryit = this->mapTerritory.begin(); territoryit != this->mapTerritory.end();territoryit++){
        aList.push_back(territoryit->second);
    };
    sort(aList.begin(),aList.end(),[](Territory* x, Territory* y)->bool{
        return (x->getAmount() == y->getAmount())?(x->getId() < y->getId()):(x->getAmount()>y->getAmount());
    });
    return aList;
}

void TransactionSystem::resolving(Transaction* aTransaction){
    if (this->mapSaleRep.find(aTransaction->getSaleRepId())==this->mapSaleRep.end())
    {
        //No salerep
        cout<<aTransaction->getSaleRepId()<< " : no salerep found for this transaction in the system\n";
        return;
    }
    SaleRep* saleRep=this->mapSaleRep[aTransaction->getSaleRepId()];
    Territory* territory=saleRep->getTerritory();
    pair < int, int > amount= aTransaction->getAmount();
    territory->resolve(amount.first);
    saleRep->resolve(amount.second);    
    delete aTransaction;
}

TransactionSystem::~TransactionSystem(){
    for (auto territoryit = this->mapTerritory.begin(); territoryit != this->mapTerritory.end();territoryit++){
        delete territoryit->second;
    }
    for (auto saleRepit = this->mapSaleRep.begin(); saleRepit != this->mapSaleRep.end();saleRepit++){
        delete saleRepit->second;
    }
}