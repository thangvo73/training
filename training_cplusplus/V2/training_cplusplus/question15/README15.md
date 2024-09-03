- ***Method overloading***: is the existence of multiple methods with the same name in the same class, with different parameter data types or different number of parameters.
- ***Method overriding***: It refers to creating a new implementation for an existing method in the parent class (which can extend or replace the definition of the method in the parent class). This newly created method is placed in the child class and has the same name and parameters as the method in the parent class. Method overriding can be used with the virtual keyword to support dynamic polymorphism.

For example:
```cpp
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
```
Result run program:
```
result of sum: 5
result of sum: 6.1
this is child class!
```
- In the above program, we overload the add() method and override the display() method.
- Because the display() method is overridden, when calling the display() method through an object instantiated from the child class, the display() method in the child class is called.

