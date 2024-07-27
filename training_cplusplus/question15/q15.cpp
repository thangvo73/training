#include <iostream>
using namespace std;

class FatherClass {
public:
	int sum(int a, int b){
		return a + b;
	}

	double sum(double a, double b){
		return a + b;
	}

	int sum(int a, int b, int c){
		return a + b + c;
	}
	void display(){
		cout << "this is parent class!" << endl;
	}
};

class SubClass : public FatherClass {
public:
	void display(){
		cout << "this is child class!" << endl;
	} 
};

int main() {
	SubClass classTwo;

	cout << "result of sum: " << classTwo.sum(2,3) << endl;
	cout << "result of sum: " << classTwo.sum(2.5, 3.6) << endl;
	classTwo.display();
	return 0;
}