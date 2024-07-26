- ***struct***: The structure is a user-defined data type, it are used to combine different types of data types. The memory of a struct is greater than or equal to the sum of the sizes of its variables.
- ***union***: Similarly to the structure, the union can contain different types of data types. It be used where the amount of memory used is a key factor. The memory of a union is equal to the size of the largest data type. So it is important to understand that variables share the same memory cells.

For example:
```cpp
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
    DataOne dataOne; // create a struct
    dataOne.a = 98;
    dataOne.b = 'A';
    dataOne.c = 25.5;
    cout << "Struct:" << endl;
    cout << dataOne.a << endl;
    cout << dataOne.b << endl; 
    cout << dataOne.c << endl; 

    DataTwo dataTwo;
    dataTwo.a = 98;
    cout << "Union:" << endl;
    cout << dataTwo.a << endl;
    cout << dataTwo.b << endl; 
    cout << dataTwo.c << endl; 
    return 0;
}
```
Result run program:
```
Struct:
a = 98
b = A
c = 25.5

Union:
a = 98
b = b
c = 1.37327e-43
```
- With struct the values ​​are printed exactly as the initial values, showing that the variables do not share the same memory cells
- With union we have not initialized values ​​for variables b and c but the printed result has the above values. That's right, those values ​​are not random but have a rule. Let's understand it as follows:
```
Address         0x00  0x01  0x02  0x03
Variable a        98     0     0     0
Variable b        98
Variable c        98     0     0     0
```
The int and float data types have a size of 4 bytes, the char data type has a size of 1 byte
- When calling variable b with a char data type, we are accessing the value at memory cell 0x00 with a value of 98, corresponding to the char type as the character 'b'
- When calling variable c with a float data type, we are accessing the value at 4 memory cells, the value of 4 memory cells with float type will have the value as above