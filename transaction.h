#ifndef transaction_header
#define transaction_header
#include <string>
#include "saleRep.h"
#include <utility>
enum TransactionType {
    SALE,
    VALUEADDED,
    CREDIT,
    CANCEL,
    PROMO,
    DISCOUNT,
    INTERTERRITORY
};
class Transaction{
    private:
        string id;
        int amount;
        TransactionType type;
        string saleRepId;
        SaleRep* saleRep;
    public:
        Transaction(string id,string salerepId,string amount, string type);
        TransactionType getType();
        string getSaleRepId();
        SaleRep* getSaleRep();
        void setSaleRep(SaleRep* saleRep);
        pair<int,int> getAmount();
};

#endif