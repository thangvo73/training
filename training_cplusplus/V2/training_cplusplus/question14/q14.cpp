#include <iostream>
using namespace std;

class FatherClass {
public:
	FatherClass(){
		cout << "Call constructor of parent class!" << endl;
	}
	virtual ~FatherClass(){
		cout << "Call destructor of parent class!" << endl;
	}
};

class SubClass : public FatherClass {
public:
	SubClass(){
		cout << "Call constructor of child class!" << endl;
	}
	~SubClass(){
		cout << "Call destructor of child class!" << endl;
	}
};

int main() {
	// SubClass classOne;
	FatherClass *classOne = new SubClass();
	delete classOne;
	return 0;
}