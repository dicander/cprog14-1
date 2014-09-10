#include <iostream>
#include <vector>

using namespace std;

class account {
private:
	int balance;
public:
	account(int value):balance(value){}
	int get_balance() const {return this->balance;}
	void set_balance(int new_balance) {
		this->balance = new_balance;
	}
};

int main() {
	account a(42);
	account b(10);
	cout << a.get_balance() << " " << b.get_balance() << endl;
	b.set_balance(13);
	cout << a.get_balance() << " " << b.get_balance() << endl;
}