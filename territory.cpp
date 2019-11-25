#include "territory.h"
//Function to create a territory
Territory* Territory::createTerritory(string id, string type){
    if (type=="PREMIUM")
        return new PremiumTerritory(id);
    if (type=="NORMAL")
        return new NormalTerritory(id);
    return NULL;
}

//Constructors
Territory::Territory(string id){
    this->id=id;
    this->amount=0;
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

//getId function

string Territory::getId(){
    return this->id;
}

ostream& operator<<(ostream& out, Territory& territory ){
    out << territory.getId() << ",";
    out.fill('0');
    out.width(7);
    out << territory.getAmount()<<endl;
    out.clear();
    return out;
}