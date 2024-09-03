#include <iostream>
using namespace std;

class Math {
public:
	int max(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {
	Math math;
	cout << math.max(2, 3) << endl;
	return 0;
}