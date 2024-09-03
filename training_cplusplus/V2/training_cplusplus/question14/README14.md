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

***Adittional***: About virtual constructor and virtual destructor
First, let's understand that, the virtual mechanism works only when we have a base class pointer to a derived class object.
Next, in C++, constructor cannot be virtual. So let us analyze virtual destructor.

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
	FatherClass *classOne = new SubClass();
	delete classOne;
	return 0;
}
```
In this example, we declare a pointer of the parent class to point to the object of the child class. The result of the above program when the destructor of the parent class is not a virtual destructor is as follows:
```
Call constructor of parent class!
Call constructor of child class!
Call destructor of parent class!
```
We see that the child class's destructor is not called. So now the virtual destructor of the parent class will solve this problem. The result of the above program when the parent class's destructor is a virtual destructor is as follows:
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
	FatherClass *classOne = new SubClass();
	delete classOne;
	return 0;
}
```
```
Call constructor of parent class!
Call constructor of child class!
Call destructor of child class!
Call destructor of parent class!
```
Looking at this result, we see that the order of calling constructors and destructors when operating in virtual mode is still the same as the previous analysis.


