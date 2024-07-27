- ***Public inheritance***: in the child class, the access scope of the parent class's properties or methods is kept the same
- ***Protected inheritance***: in the child class, the access scope of the properties or methods changes. Specifically, if it is public in the parent class, it will be protected in the child class, protected and private remain the same
- ***Private inheritance***: in the child class, the access scope of the parent class's properties or methods is changed to private

```
Parent Class {}                             public       protected       private
Child Class : public Parent Class {}        public       protected       private

Parent Class {}                             public       protected       private
Child Class : protected Parent Class {}     protected    protected       private

Parent Class {}                             public       protected       private
Child Class : private Parent Class {}       private      private         private
```
For example:
```cpp
class FatherClass {
private:
	int a = 0;
public:
	void displayOne(){
		cout << "value of a: " << a << endl;
	}
};

class SubClass : protected FatherClass {

};

int main() {
	SubClass classOne;
	classOne.displayOne();  // this command error
	return 0;
}
```
The above program has an error at **classOne.displayOne()** because the class FatherClass is inherited in protected mode. If the class SubClass inherits the class FatherClass in public mode, the program will run correctly.
