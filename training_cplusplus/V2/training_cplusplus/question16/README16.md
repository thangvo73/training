- ***member function***: is a function declared in a class, it can be defined inside or outside the class. Access to member function must be through the instantiated object.
- ***static member function***: is a function declared in a class with the static keyword, it can be defined inside or outside the class. Can be accessed directly through the class.
- ***friend function***: Not a member function in a class, it is declared in a class with the friend keyword and can be defined inside or outside the class. Private properties or methods can be accessed from outside through the friend function.

For example of member function:
```cpp
class Math {
public:
	int max(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {
	Math math;
	cout << math.max(2, 3) << endl;
	return 0;
}
```
Result run program:
```
3
```
For example of static member function:
```cpp
class Math {
public:
	static int max(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {
	cout << Math::max(2, 3) << endl;
	return 0;
}
```
Result run program:
```
3
```
For example of friend function:
```cpp
class Math {
private:
	int a;
	int b;
public:
	Math(int a, int b){
		this->a = a;
		this->b = b;
	}
	friend int max(Math data);
};

int max(Math data) {
	return data.a > data.b ? data.a : data.b;
}

int main() {
	Math math(2,3);
	cout << max(math) << endl;
	return 0;
}
```
Result run program:
```
3
```