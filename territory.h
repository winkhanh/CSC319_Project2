#ifndef territory_header
#define territory_header
#include <string>
using namespace std;
class Territory{
    protected:
        string id;
        int amount;
    public:
        Territory(string id);
        static Territory* createTerritory(string id, string type);
        virtual void resolve(int amount)=0;
        int getAmount();
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