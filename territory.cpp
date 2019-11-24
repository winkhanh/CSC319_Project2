#include "territory.h"
//Function to create a territory
Territory* Territory::createTerritory(string id, string type){
    if (type=="PREMIUM")
        return new PremiumTerritory(id);
    if (type=="NORMAL")
        return new NormalTerritory(id);
}

//Constructors
Territory::Territory(string id){
    this->id=id;
}
PremiumTerritory::PremiumTerritory(string id):Territory(id){};
NormalTerritory::NormalTerritory(string id):Territory(id){};

//getAmount func
int Territory::getAmount(){
    return this->amount;
}

//resolve Functions
void PremiumTerritory::resolve(int amount){
    if (amount<0)
        this->amount-=amount;
    else
        this->amount+=amount*1.5;
    
}
void NormalTerritory::resolve(int amount){
    this->amount+=amount;
}

