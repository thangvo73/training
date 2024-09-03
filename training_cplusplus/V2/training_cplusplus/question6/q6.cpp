#include <iostream>
using namespace std;

int main() {
    int normal = 1; // normal variable
    int *pointer = &normal; // pointer variable
    int &reference = normal; // reference variable
    cout << "normal value: " << normal << endl;
    cout << "pointer value: " << pointer << endl;
    cout << "value of variable at pointer address: " << *pointer << endl;
    cout << "reference value: " << reference << endl;

    reference = 2;
    cout << "normal value: " << normal << endl;
    cout << "reference value: " << reference << endl;

    normal = 4;
    cout << "normal value: " << normal << endl;
    cout << "reference value: " << reference << endl;
    return 0;
}

