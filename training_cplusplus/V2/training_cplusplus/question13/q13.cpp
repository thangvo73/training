#include <iostream>
using namespace std;

class FatherClass {
private:
	int a = 0;
public:
	void displayOne(){
		cout << "value of a: " << a << endl;
	}
};

class SubClass : public FatherClass {

};

int main() {
	SubClass classOne;
	classOne.displayOne();
	return 0;
}