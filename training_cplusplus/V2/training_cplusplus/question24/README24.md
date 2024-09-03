**24. The difference between C-style string and std::string**
- The std::string string is implemented in a class of the STL standard library.
- The original C-style string from the C language.

***1. std::string***
Để sử dụng chuỗi std::string cần phải #include thư viện string thuộc namespace std
```cpp
#include <string>
using namespace std;

string mystring("hi");
```
String can be viewed as a data type and we can initialize and assign values ​​to string variables like normal variables
```cpp
string mystring1("hello");
string mystring2{"hello world"};
string mystring3 = "this is string!";
```
Enter a string of characters:
```cpp
int main(){
	cout << "Enter your full name: ";
	string strName;
	cin >> strName;
	cout << "Your name is " << strName << endl;
	return 0;
}
```
Result run program:
```
Enter your full name: vo quang thang
Your name is vo
```
The above program output shows that if std::cin is used to input a string with spaces, it will ignore the characters after when it encounters a space, so we need to use std::getline(). For example:
```cpp
int main(){
	cout << "Enter your full name: ";
	string strName;
	getline(cin, strName);
	cout << "Your name is " << strName << endl;
	return 0;
}
```
Result run program:
```
Enter your full name: vo quang thang
Your name is vo quang thang
```
When using std::string, it is possible to concatenate strings using the "+" or "+=" operators
For example:
```cpp
int main(){
	string a("vo");
	string b("quang");
	string c = a + b;    
	cout << c << endl;
	a += " quang";
	cout << a << endl;

	return 0;
}
```
Result run program:
```
voquang
vo quang
```
You can use the two methods length() and size() to get the length of a string. For example:
```cpp
int main(){
	string mystring("Hello World!");
	cout << mystring << " has " << mystring.length() << " characters\n";
	cout << mystring << " has " << mystring.size() << " characters\n";

	return 0;
}
```
Result run program:
```
Hello World! has 12 characters
Hello World! has 12 characters
```
