#include <iostream>
using namespace std;

template <typename X, typename Y = float> class classTemplate {
private:
	X a;
	Y b;
public:
	classTemplate(X a, Y b){
		this->a = a;
		this->b = b;
	}
	void display(){
		cout << "value of a = " << a << endl;
		cout << "value of b = " << b << endl;
	}
};

int main(){
	classTemplate<int> classOne(3, 4.5);
	classOne.display();
	return 0;
}