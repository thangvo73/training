#include <iostream>
using namespace std;

int main(){
	string mystring("Hello World!");
	cout << mystring << " has " << mystring.length() << " characters\n";
	cout << mystring << " has " << mystring.size() << " characters\n";

	return 0;
}