#include <iostream>
using namespace std;

class FatherClass {
protected:
	int a = 1;
public:
	virtual void display (){
		cout << "this is father class: " << "a = " << a << endl;
	}
};

class SubClass : public FatherClass {
private:
	int b = 2;
public:
	void display (){
		cout << "this is sub class: " << "a = " << a << ", b = " << b << endl;
	}
};

int main() {
	SubClass classOne;
	FatherClass *classTwo = &classOne;
	classTwo->display();
	return 0;
}