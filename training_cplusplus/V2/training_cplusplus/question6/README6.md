For example:
```cpp
int main() {
    int normal = 1; // normal variable
    int *pointer = &normal; // pointer variable
    int &reference = normal; // reference variable
    cout << "normal value: " << normal << endl;
    cout << "pointer value: " << pointer << endl;
    cout << "value of variable at pointer address: " << *pointer << endl; // access the value at the memory address pointed to by the pointer variable
    cout << "reference value: " << reference << endl;

    reference = 2;
    cout << "normal value: " << normal << endl;
    cout << "reference value: " << reference << endl;

    normal = 4;
    cout << "normal value: " << normal << endl;
    cout << "reference value: " << reference << endl;
    return 0;
}
```
Result run program:
```
normal value: 1
pointer value: 0x7fff8d46dfb4
value of variable at pointer address: 1 // value of normal variable
reference value: 1
normal value: 2
reference value: 2
normal value: 4
reference value: 4
```
We access the value at the address pointed to by the pointer variable through the * character.