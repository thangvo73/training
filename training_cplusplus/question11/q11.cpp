#include <iostream>
using namespace std;

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