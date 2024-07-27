#include <iostream>
using namespace std;

class Math {
public:
	int min (int a, int b){
		return a < b ? a : b;
	}
	virtual int max(int a, int b) = 0;
};

class MAX : public Math{
public:
	int max(int a, int b){
		return a > b ? a : b;
	}
};

int main() {
	Math* math = new MAX();
	cout << "max value: " << math->max(2,4) << endl;
	return 0;
}