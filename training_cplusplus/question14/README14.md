- ***Constructor***: The constructor of the parent class is called first, then the child class
- ***Destructor***: The destructor of the child class is called first, then the parent class

For example:
```cpp
class FatherClass {
public:
	FatherClass(){
		cout << "Call constructor of parent class!" << endl;
	}
	~FatherClass(){
		cout << "Call destructor of parent class!" << endl;
	}
};

class SubClass : public FatherClass {
public:
	SubClass(){
		cout << "Call constructor of child class!" << endl;
	}
	~SubClass(){
		cout << "Call destructor of child class!" << endl;
	}
};

int main() {
	SubClass classOne;
	return 0;
}
```
Result run program:
```
Call constructor of parent class!
Call constructor of child class!

Call destructor of child class!
Call destructor of parent class!
```
The result of running the program is correct when the parent class's constructor is called first and when the program ends, the child class's destructor is called first.