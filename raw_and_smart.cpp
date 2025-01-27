#include <iostream>
#include <memory>
using namespace std;


// This program makes a shared_ptr and a raw pointer pont to the
// same object on the heap
int main() {
    int* raw = new int(42);
    shared_ptr<int> smart(raw);
    cout << *raw << endl;
    cout << *smart << endl;
    *raw = 43;
    cout << *raw << endl;
    cout << *smart << endl;
    *smart = 44;
    cout << *raw << endl;
    cout << *smart << endl;
    delete raw;
    cout << *smart << endl;
    return 0;    
}