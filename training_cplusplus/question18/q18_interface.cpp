#include <iostream>
using namespace std;

class Math {
public:
	virtual int min(int a, int b) = 0;
	virtual int max(int a, int b) = 0;
};

class MaxMin : public Math{
public:
	int max(int a, int b){
		return a > b ? a : b;
	}
	int min(int a, int b){
		return a < b ? a : b;
	}
};

int main() {
	Math* mathMaxMin = new MaxMin();
	cout << "max value: " << mathMaxMin->max(2,4) << endl;
	cout << "min value: " << mathMaxMin->min(2,4) << endl;
	return 0;
}