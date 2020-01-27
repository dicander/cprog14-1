#include <iostream>
#include <vector>

using namespace std;

void f(const vector<int>& v) { // BAD PRACTICE!!! Use iterators instead!
    for(auto it = v.begin(); it!=v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}


int main() {
    vector<int> v{1, 2, 3, 4, 5};
    f(v);
    return 0;
}
