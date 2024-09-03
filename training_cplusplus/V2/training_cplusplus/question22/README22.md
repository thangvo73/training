***template***: is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types.

For example:
```cpp
template <typename T> T max(T a, T b){
	return a > b ? a : b;
}

int main(){
	max<int>(2, 4);
	max<float>(2.5, 4.5);
}
```
At compile time, the above code corresponds to:
```cpp
int main(){
	int max(int a, int b){
		return a > b ? a : b;
	}
	float max(float a, float b){
		return a > b ? a : b;
	}
}
```
From here we can visualize what templates are like in C++. The above example is a **function template**, let’s learn more through some of the following examples:

**Class Template**
```cpp
template <typename X, typename Y = float> class classTemplate {
private:
	X a;
	Y b;
public:
	classTemplate(X a, Y b){
		this->a = a;
		this->b = b;
	}
	void display(){
		cout << "value of a = " << a << endl;
		cout << "value of b = " << b << endl;
	}
};

int main(){
	classTemplate<int> classOne(3, 4.5);
	classOne.display();
	return 0;
}
```
Result run program:
```
value of a = 3
value of b = 4.5
```
In the above example, we create a template class with many arguments. In which, we specify a specific value for a template argument.From here, we can understand that when using a template, we can use many arguments and can specify a value for the template argument.

```cpp
int main(){
	classTemplate classOne(3, 4.5);
	classOne.display();
	return 0;
}
```
In this code, there is a slight change in the statement declaring the classOne object. That is, we do not pass the data type to the template argument, but the program still runs and prints the result as above. It shows that the template can automatically recognize the data type for the template argument.