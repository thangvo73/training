#include <iostream>
using namespace std;

struct DataOne{
    int a;
    char b;
    float c;
};

union DataTwo{
    int a;
    char b;
    float c;
};

int main() {
    DataOne dataOne;
    dataOne.a = 98;
    dataOne.b = 'A';
    dataOne.c = 25.5;
    cout << "Struct:" << endl;
    cout << "a = " << dataOne.a << endl;
    cout << "b = " << dataOne.b << endl; 
    cout << "c = " << dataOne.c << endl; 

    DataTwo dataTwo;
    dataTwo.a = 98;
    cout << "Union:" << endl;
    cout << "a = " << dataTwo.a << endl;
    cout << "b = " << dataTwo.b << endl; 
    cout << "c = " << dataTwo.c << endl; 
    return 0;
}