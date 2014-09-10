#include <iostream>
#include <vector>
using namespace std;
static const int ARRAY_SIZE = 4;

template<typename It>
void print_values(It begin, It end){
	for(auto current = begin; current!= end; ++current){
		cout << *current << " ";	
	}
	cout << endl;
}



void primitive(){
    int a = 1;
    cout << " a = " << a << " &a = " << (&a) << "" << endl;
    int* b = new int(2);
    cout << " b = " << b << " &b = " << (&b) << " *b = " << *b << endl;
    int* c = new int[ARRAY_SIZE]{3,4,5,6};
	print_values(c, &c[ARRAY_SIZE]);
    int d[ARRAY_SIZE]{7,8,9,10}; //int d[ARRAY_SIZE]={7,8,9,10};
    for(int i=0; i<ARRAY_SIZE; ++i){
        cout << d[i] << " ";
    }
    cout << endl; 
    delete b;
    delete[] c;
}

void advanced(){
    std::vector<int> v{11, 12, 13, 14};//
    vector<int> my_vector;
    for(int& current: v){
        cout << current << " ";
    }
    cout << endl;
    print_values(v.begin(), v.end());
    cout << " &v = " << &v << " &v[0] = " << &v[0] << endl;
}

int main(){
    primitive();
    advanced();
}
