#include <iostream>
using namespace std;

class Math {
public:
	static int max(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {
	cout << Math::max(2, 3) << endl;
	return 0;
}