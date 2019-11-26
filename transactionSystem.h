#ifndef transaction_system_header
#define transaction_system_header
#include "saleRep.h"
#include "territory.h"
#include "transaction.h"
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
class TransactionSystem{
    private:
        map <string, SaleRep* > mapSaleRep;
        map <string, Territory*> mapTerritory;
    public:
        TransactionSystem()=default;
        TransactionSystem& operator+= (SaleRep* aSaleRep);
        TransactionSystem& operator+= (Territory* aTerritory);
        void resolving(Transaction* aTransaction);
        vector < SaleRep* > getSaleReps();
        vector < Territory*> getTerritories();
        ~TransactionSystem();
};

#endif