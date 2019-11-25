#include "transaction.h"
Transaction::Transaction(string id,string saleRepId,string type,string amount){
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

pair<int,int> Transaction::getAmount(){
    switch (this->type){
        case SALE: return make_pair(this->amount,this->amount*1.1);
        case VALUEADDED: return make_pair((this->amount),(this->amount)*1.1);
        case CREDIT: return make_pair(-(this->amount),-(this->amount));
        case CANCEL: return make_pair(-(this->amount),-(this->amount)*1.25);
        case PROMO: return make_pair(-(this->amount),0);
        case DISCOUNT: return make_pair(-(this->amount),-(this->amount)*1/1);
        case INTERTERRITORY: return make_pair(0,(this->amount)*0.75);
        default: return make_pair(0,0);
    }
}