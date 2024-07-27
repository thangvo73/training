***Encapsulation***: is a technique that helps hide information inside an object, helping to limit errors when developing a program.
For example:
```cpp
class Student {
public:
	string name;
	int age;
};

int main() {
	Student student;
	cout << student.name << endl;
	return 0;
}
```
In the above code, the properties are in public mode so they can be accessed directly from the outside, specifically here is the main function.

```cpp
class Student {
private:
	string name;
	int age;
public:
	string getName(){
		return name;
	}
	void setName(string name){
		this->name = name;
	}
};

int main() {
	Student student;
	cout << student.getName() << endl;
	return 0;
}
```
In this code, the properties are private so they cannot be accessed directly from other places. They can only be accessed indirectly through setters and getters such as the getName() and setName() methods above. This way, the properties are hidden and communicated through public methods. This helps control properties when accessed from outside.

***Inheritance***: Inheritance in object-oriented programming is inheriting the properties and methods of a class. This means that if class A inherits class B, class A will have the properties and methods of class B.
For example:
```cpp
class Person {
private:
	string name;
	int age;
public:
	string getName(){
		return name;
	}
	void setName(string name){
		this->name = name;
	}
};

class Student : public Person {
private:
	int gpa;
}

int main() {
	Student student;
	cout << student.getName() << endl;
	return 0;
}
```
In the above code, Person() is the parent class and Student() is the child class. In addition to the name and age properties inherited from the parent class, there is also the gpa property and the methods as well.

***Polymorphism***: Polymorphism can be understood as the same object but at different times and spaces, it plays different roles. It can be visualized through the most obvious forms of expression such as method overloading, method overriding...
For example:
```cpp
class Math {
public:
	int add(int a, int b){
		return a + b;
	}
	float add(float a, float b, float c){
		return a + b + c;
	}
};

int main() {
	Math math;
	cout << math.add(2,3) << endl;
	return 0;
}
```
The above code is overloading the add() method with different number of parameters and data types.

***Abstraction***: Abstraction is one of the four characteristics in object-oriented programming, the main goal of abstraction is to hide unnecessary information to focus only on the features of the object.
For example:
```cpp
class Person {
private:
	string name;
	int age;
public:
	Person(string name, int age){
		this->name = name;
		this->age = age;
	}
	virtual void display() = 0;
};

class Student : public Person {
private:
	int gpa;
public:
	Student(string name, int age, int gpa) : Person(name, age){
		this->gpa = gpa;
	}
	void display(){
		cout << "gpa: " << gpa << endl; 
	}
};

int main() {
	Person *person = new Student("A", 24, 8);
	person->display();
	return 0;
}
```
In the above code, the display() method is an abstract method and its main functionality is implemented in the subclass through method overriding.