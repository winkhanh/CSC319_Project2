#include "transaction.h"

Transaction::Transaction(string id,string salereipId,string amount,string type){
    this->id=id;
    this->saleRepId=saleRepId;
    this->amount=stoi(amount);
    if (type=="1") this->type=SALE;
    if (type=="2") this->type=VALUEADDED;
    if (type=="3") this->type=CREDIT;
    if (type=="4") this->type=CANCEL;
    if (type=="5") this->type=PROMO;
    if (type=="6") this->type=DISCOUNT;
    if (type=="7") this->type=INTERTERRITORY;
}

TransactionType Transaction::getType(){
    return this->type;
}

string Transaction::getSaleRepId(){
    return this->saleRepId;
}

SaleRep* Transaction::getSaleRep(){
    return this->saleRep;
}

void Transaction::setSaleRep(SaleRep* saleRep){
    this->saleRep=saleRep;
}

int Transaction::getAmount(){
    return this->amount;
}