#include "saleRep.h"

SaleRep::SaleRep(string id,string territoryId,string amount){
    this->id=id;
    this->territoryId=territoryId;
    this->amount= stoi(amount);
}

string SaleRep::getTerritoryId(){
    return this->territoryId;
}

Territory* SaleRep::getTerritory(){
    return this->territory;
}

void SaleRep::setTerritory(Territory* territory){
    this->territory=territory;
}

void SaleRep::resolve(int amount){
    this->amount+=amount;
}

string SaleRep::getId(){
    return this->id;
}

int SaleRep::getAmount(){
    return this->amount;
}