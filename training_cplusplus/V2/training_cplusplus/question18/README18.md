- ***pure virtual functions***: is a function that belongs to a class but is not defined inside the class, it is declared with the keyword virtual and assigned a value of 0. So it will be defined in subclasses.
- ***abstract base classes***: is a class that contains at least one Pure Virtual Functions. This class cannot instantiate objects directly, but can be inherited by subclasses.
- ***interface classes***: is a class whose member functions are all Pure Virtual Functions. Similar to abstract base classes, this class cannot be instantiated directly, but can be inherited by subclasses.

For example:
```cpp
// Math class is abstract base class
class Math {
public:
	int min (int a, int b){
		return a < b ? a : b;
	}
	virtual int max(int a, int b) = 0;  // this is pure virtual function
};

class MAX : public Math{
public:
	int max(int a, int b){
		return a > b ? a : b;
	}
};

int main() {
	Math* math = new MAX();  // math object can not declared directly 
	cout << "max value: " << math->max(2,4) << endl;
	return 0;
}
```
Result run program:
```
max value: 4
```
In the child class we have to override the pure virtual function of the parent class and define them clearly, specifically in the above example it is the max function.

For example:
```cpp
// Math class is interface classes
class Math {
public:
	virtual int min(int a, int b) = 0; // this is pure virtual function
	virtual int max(int a, int b) = 0; // this is pure virtual function
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
```
Result run program:
```
max value: 4
min value: 2
```
Similar to the above example, in the child class we have to override the pure virtual functions of the parent class and define them explicitly, specifically in the above example the max function and min function.