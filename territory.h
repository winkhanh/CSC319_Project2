#ifndef territory_header
#define territory_header
#include <string>
using namespace std;
class Territory{
    protected:
        int id;
        int amount;
    public:
        Territory(int id);
        static Territory* createTerritory(int id, string type);
        virtual void resolve(int amount)=0;
        int getAmount();
};

class PremiumTerritory: public Territory{
    public:
        PremiumTerritory(int id);
        void resolve(int amount);
};
class NormalTerritory: public Territory{
    public:
        NormalTerritory(int id);
        void resolve(int amount);
};
#endif