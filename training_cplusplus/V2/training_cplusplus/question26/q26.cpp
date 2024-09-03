#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> ptr(new int(10));
    weak_ptr<int> ptr1 = ptr;
	ptr.reset();
	if (auto ptr2 = ptr1.lock()){
		cout << *ptr2 << endl;
	} else {
		cout << "the memory is released!" << endl;
	}
	cout << ptr.use_count() << endl;
    return 0;
}