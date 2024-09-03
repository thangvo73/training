- ***Public***: specifies the widest access scope, within the class, within the subclass and outside the class
- ***Protected***: specifies the most limited access scope than Public, only within the class and subclass
- ***Private***: specifies the most limited access scope, only within the class
For example:
```cpp
class FatherClass {
private:
	int a = 0; // private variable 
protected:
	int b = 1; // protected variable
public:
	int c = 2; // public variable

	void displayOne(){
		cout << "value of a: " << a << endl;
	}
};

class SubClass : public FatherClass {
public:
	void displayTwo(){
		cout << "value of b: " << b << endl;
	}
};

int main() {
	SubClass classOne;
	classOne.displayOne();
	classOne.displayTwo();
	cout << "value of c: " << classOne.c << endl;
	return 0;
}
```
Result run program:
```
value of a: 0
value of b: 1
value of c: 2
```
Looking at the above program:
- variable a can only be used inside the parent class and can only be accessed through the public method of the class, specifically the displayOne() method here.
- variable b can be used inside the parent class and child class, if accessed beyond this scope, it must be through the public method, specifically the displayTwo() method here.
- variable c can be used in the parent class, child class and accessed directly from outside the class through the instantiated object
