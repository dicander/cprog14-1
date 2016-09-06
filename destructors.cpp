#include <iostream>

struct base {
	virtual ~base() {std::cout << "base destructor" << std::endl;}
};

struct derived:public base {
	~derived() {std::cout << "derived destructor" << std::endl;}
};


int main() {
	derived d;
}
