#include <iostream>
using namespace std;

int main() {
    int a = 1;
    int *ptr = &a;
    int arr[5] = {1,2,3,4,5};

    cout << "value of a: " << *ptr << endl;
    cout << "arr:";
    for (int i=0; i<5; i++){
        cout << " " << arr[i];
    }
    cout << endl;

    ptr = arr;
    cout << "Address of array: " << arr << endl;
    cout << "Address of array: " << ptr << endl;
    cout << "arr:";
    for (int i=0; i<5; i++){
        cout << " " << *(ptr + i);
    }
}