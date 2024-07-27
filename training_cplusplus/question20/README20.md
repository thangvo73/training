***object slicing***: when a derived class object is assigned to a base class object in C++, the derived class object’s extra attributes are sliced off (not considered) to generate the base class object; and this whole process is termed object slicing. In simple words, when extra components of a derived class are sliced or not used and the priority is given to the base class’s object this is termed object slicing.

For example:
```cpp
class FatherClass {
protected:
	int a = 1;
public:
	virtual void display (){
		cout << "this is father class: " << "a = " << a << endl;
	}
};

class SubClass : public FatherClass {
private:
	int b = 2;
public:
	void display (){
		cout << "this is sub class: " << "a = " << a << ", b = " << b << endl;
	}
};

int main() {
	SubClass classOne;
	FatherClass classTwo = classOne; // object slicing
	classTwo.display();
	return 0;
}
```
Result run program:
```
this is father class: a = 1
```
In the above example, the object of the SubClass class (classOne) is assigned to the object of the FatherClass class (classTwo). Therefore, only the properties and methods of the Father class in the classOne object are accessed.

For example:
```cpp
class FatherClass {
protected:
	int a = 1;
public:
	virtual void display (){
		cout << "this is father class: " << "a = " << a << endl;
	}
};

class SubClass : public FatherClass {
private:
	int b = 2;
public:
	void display (){
		cout << "this is sub class: " << "a = " << a << ", b = " << b << endl;
	}
};

int main() {
	SubClass classOne;
	FatherClass *classTwo = &classOne;
	classTwo->display();
	return 0;
}
```
Result run program:
```
this is sub class: a = 1, b = 2
```
When using the pointer of an object of the class FatherClass to point to an object of the class SubClass, the object slicing phenomenon is overcome.