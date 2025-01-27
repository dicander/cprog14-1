#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int a = 1;
    //++a;
    //const_pointers.cpp:18:7: error: increment of read-only variable ‘a’    
    const int * b = new int(2);
    b++; //Compiles, but points where?
    b--; //Compiles and ensures that b does not crash
    // *b=3;
    // const_pointers.cpp:23:7: error: assignment of read-only location ‘* b’
    //int* cant_be_evil = b;
    //const_pointers.cpp:25:25: error: invalid conversion from ‘const int*’ to ‘int*’
    int* cast_away(const_cast<int*>(b));
    *cast_away = 13;
    cout << " *b = " << *b << endl;
    int* const pointer_arithmetic_considered_harmful = new int(3);
    *pointer_arithmetic_considered_harmful = 42; //WORKS GREAT!
    //++pointer_arithmetic_considered_harmful;
    //const_pointers.cpp:32:7: error: increment of read-only variable ‘pointer_arithmetic_considered_harmful’
    delete b;
    //delete cast_away;
    delete pointer_arithmetic_considered_harmful;
}
