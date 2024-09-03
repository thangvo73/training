#include <iostream>
using namespace std;

class Math {
private:
	int a;
	int b;
public:
	Math(int a, int b){
		this->a = a;
		this->b = b;
	}
	friend int max(Math data);
};

int max(Math data) {
	return data.a > data.b ? data.a : data.b;
}

int main() {
	Math math(2,3);
	cout << max(math) << endl;
	return 0;
}