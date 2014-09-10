#include <iostream>
#include <string>

using namespace std;

struct house;
struct hero;

struct hero{
    string name;
    house* home;
    hero(const string& name, house* home){
        this->name = name;
        this->home = home;
    }
};


struct house{
    string name;
    hero* resident;
    house(const string& house_name, const string& hero_name){
        this->name = house_name;
        this->resident = new hero(hero_name, this);
    }
    virtual ~house(){
        delete this->resident;
    }
};


int main(){
    house h("Villa Villerkulla", "Pippi");
    cout << h.resident->name << " bor i " << h.name << "." << endl;
    
}
