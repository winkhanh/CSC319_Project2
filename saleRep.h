#ifndef sale_rep_header
#define sale_rep_header
#include <string>
#include "territory.h"
class SaleRep{
    private:
        string id;
        int amount;
        string territoryId;
        Territory* territory;
    public:
        SaleRep(string id, string teritoryId,string amount);
        string getTerritoryId();
        Territory* getTerritory();
        void setTerritory(Territory* territory);
        void resolve(int amount);
};

#endif