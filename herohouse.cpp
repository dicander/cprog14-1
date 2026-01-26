#include <iostream>
#include <string>
#include <utility> // Required for std::move

using namespace std;

struct house;

struct hero {
    string name;
    house* home;

    hero(const string& name, house* home)
        : name(name), home(home) {}

    virtual ~hero() {
    }
};

struct house {
    string name;
    hero* resident;

    // Constructor
    house(const string& house_name, const string& hero_name)
        : name(house_name), resident(new hero(hero_name, this)) {
    }

    // 1. Destructor
    virtual ~house(){
        delete resident;
    }

    // 2. Copy Constructor
    house(const house& other) 
        : name(other.name) {
        // Deep copy: Create a new hero for the new house
        resident = new hero(other.resident->name, this);
    }

    // 3. Copy Assignment Operator
    house& operator=(const house& other) {
        if (this == &other) return *this; // Self-assignment check

        delete resident; // Clean up existing resource
        
        name = other.name;
        // Deep copy
        resident = new hero(other.resident->name, this);

        return *this;
    }

    // 4. Move Constructor
    house(house&& other) noexcept 
        : name(std::move(other.name)), resident(other.resident) {
        
        // Nullify the source pointer so the destructor doesn't kill the hero
        other.resident = nullptr;

        // CRITICAL: Update the hero's back-pointer.
        // The hero has moved to a new house address ('this'), 
        // so we must tell the hero where they live now.
        if (resident) {
            resident->home = this;
        }
    }

    // 5. Move Assignment Operator
    house& operator=(house&& other) noexcept {
        if (this == &other) return *this; // Self-assignment check

        delete resident; // Clean up our current resident

        // Steal resources
        name = std::move(other.name);
        resident = other.resident;
        
        // Nullify the source
        other.resident = nullptr;

        // Update the hero's back-pointer to the new house address
        if (resident) {
            resident->home = this;
        }

        return *this;
    }
};

int main(){
    house h1("Villa Villerkulla", "Pippi");
    
    // Test Move Constructor
    house h2 = std::move(h1); 

    if (h2.resident) {
        cout << "Moved: " << h2.resident->name << " lives in " << h2.name << endl;
    }

    // h1 is now in a valid but unspecified state (resident is nullptr)
    if (h1.resident == nullptr) {
        cout << "Original house is now empty (moved from)." << endl;
    }
    
    return 0;
}