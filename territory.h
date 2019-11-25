#ifndef territory_header
#define territory_header
#include <string>
#include <iostream>
using namespace std;
class Territory{
    protected:
        string id;
        int amount;
    public:
        Territory(string id);
        static Territory* createTerritory(string id, string type);
        string getId();
        virtual void resolve(int amount)=0;
        int getAmount();
        friend ostream& operator<<(ostream& out, Territory& territory);  
};

class PremiumTerritory: public Territory{
    public:
        PremiumTerritory(string id);
        void resolve(int amount);
};
class NormalTerritory: public Territory{
    public:
        NormalTerritory(string id);
        void resolve(int amount);
};
#endif