#ifndef sale_rep_header
#define sale_rep_header
#include <string>
#include <iostream>
#include "territory.h"
class SaleRep{
    private:
        string id;
        int amount;
        string territoryId;
        Territory* territory;
    public:
        SaleRep(string id, string territoryId,string amount);
        string getTerritoryId();
        Territory* getTerritory();
        void setTerritory(Territory* territory);
        void resolve(int amount);
        string getId();
        int getAmount();
        friend ostream& operator<< (ostream& out,SaleRep& saleRep);
};

#endif