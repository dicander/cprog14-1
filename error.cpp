#include<iostream>

using namespace std;

void leak() {
    int* v = new int[1000];
    //cout << v[1000];
}

int main() {
    leak();
}
