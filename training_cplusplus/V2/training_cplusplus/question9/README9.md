***little endian*** and ***big endian*** refers to the order in which bytes are arranged in memory
- ***little endian***: Stores the least significant byte (the “little end”) first. This means that the first byte (at the lowest memory address) is the smallest, which makes the most sense to people who read right to left
- ***big endian***: Stores the most significant byte (the “big end”) first. This means that the first byte (at the lowest memory address) is the largest, which makes the most sense to people who read left to right

For instance, a 32-bit integer 0x12345678 would be stored in memory as follows:
```
In little endian:
Address:    0x00  0x01  0x02  0x03
Value:      0x78  0x56  0x34  0x12
```
```
In big endian:
Address:    0x00  0x01  0x02  0x03
value:      0x12  0x34  0x56  0x78
```
See the below example to check if the system is little endian or big endian:
```cpp
int main() {
    unsigned int x = 1;
    char *check = (char*)&x;
    if (*check)
        std::cout << "little endian\n";
    else
        std::cout << "big endian\n";
    return 0;
}
```
Result run program:
```
little endian
```
The results show that the system works in little endian

Show the byte address of the int variable:
```cpp
int main() {
    unsigned int x = 1;
    char *check = (char*)&x;
    cout << &x << endl;
    cout << (int*)check << endl;
    cout << (int*)(check+1) << endl;
    cout << (int*)(check+2) << endl;
    cout << (int*)(check+3) << endl;
    return 0;
}
```
Result run program
```
0x7fffa2b7bbfc
0x7fffa2b7bbfc
0x7fffa2b7bbfd
0x7fffa2b7bbfe
0x7fffa2b7bbff
```
The above result shows us the address of each byte used to store variable x with data type int