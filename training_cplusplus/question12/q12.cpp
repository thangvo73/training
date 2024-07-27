#include <iostream>
using namespace std;

class FatherClass {
private:
	int a = 0;
protected:
	int b = 1;
public:
	int c = 2;

	void displayOne(){
		cout << "value of a: " << a << endl;
	}
};

class SubClass : public FatherClass {
public:
	void displayTwo(){
		cout << "value of b: " << b << endl;
	}
};

int main() {
	SubClass classOne;
	classOne.displayOne();
	classOne.displayTwo();
	cout << "value of c: " << classOne.c << endl;
	return 0;
}