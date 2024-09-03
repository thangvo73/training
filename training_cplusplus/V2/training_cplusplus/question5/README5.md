- ***array***: An array is essentially a constant pointer pointing to the address of the first element. The size of an array is fixed, determined at the time of declaration. Because of its nature as a constant pointer, the address of an array is fixed.
- ***pointer***: A pointer is a variable that stores a memory address, so the address that the pointer points to can change. The dynamic memory area that the pointer points to has a size that can change.
For example: 
```cpp
int *ptr = new int[10];
delete []ptr;
ptr = new int[20];
delete []ptr;
```
The above code shows that the memory area that the pointer points to can change.

**One-dimensional arrays and pointers**

For example:
```cpp
int main() {
    int a = 1;
    int *ptr = &a; // ptr point to address of a variable
    int arr[5] = {1,2,3,4,5};

    cout << "value of a: " << *ptr << endl;
    cout << "arr:";
    for (int i=0; i<5; i++){
        cout << " " << arr[i];
    }
    cout << endl;

    ptr = arr; // ptr point to address of arr array
    cout << "arr:";
    for (int i=0; i<5; i++){
        cout << " " << *(ptr + i);
    }
}
```
Result run program:
```
value of a: 1
arr: 1 2 3 4 5
arr: 1 2 3 4 5
```
- It can be seen in the above program that the pointer variable points to different addresses.  ptr pointer can point to the address of the variable a and then point to the address of the array. 
- We can also access the elements of the array through the array index and using the pointer.

***Additional***: show the address of the original variable and it's address through a pointer
```cpp
ptr = arr;
cout << "Address of array: " << arr << endl;
cout << "Address of array: " << ptr << endl;
```
Result run program:
```
Address of array: 0x7ffe91c5cb30
Address of array: 0x7ffe91c5cb30
```

**Two-dimensional arrays and pointers**: A two-dimensional array can be viewed as an array of one-dimensional arrays.

For example:
```cpp
int main() {
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*ptr2D)[3] = arr2D; // The pointer ptr2D points to an array of 3 elements.

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << endl;
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "*(*(ptr2D + " << i << ") + " << j << ") = " << *(*(ptr2D + i) + j) << endl;
        }
    }

    return 0;
}
```
Result run program:
```
arr2D[0][0] = 1
arr2D[0][1] = 2
arr2D[0][2] = 3
arr2D[1][0] = 4
arr2D[1][1] = 5
arr2D[1][2] = 6

*(*(ptr2D + 0) + 0) = 1
*(*(ptr2D + 0) + 1) = 2
*(*(ptr2D + 0) + 2) = 3
*(*(ptr2D + 1) + 0) = 4
*(*(ptr2D + 1) + 1) = 5
*(*(ptr2D + 1) + 2) = 6
```
The above program demonstrates the relationship between two-dimensional arrays and pointers. We can access array elements through array indices and pointers.

***Additional***:  try this as an another approach
```cpp
int main() {
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int **ptrptr = new int*[2];
    for (int i=0; i<2; i++){
        ptrptr[i] = new int[3];
    }

    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            ptrptr[i][j] = arr2D[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "ptrptr[" << i << "][" << j << "] = " << *(*(ptrptr + i) + j) << endl;
        }
    }

    for (int i=0; i<2; i++){
        delete[] ptrptr[i];
    }
    delete[] ptrptr;

    return 0;
}
```
Result run program:
```
ptrptr[0][0] = 1
ptrptr[0][1] = 2
ptrptr[0][2] = 3
ptrptr[1][0] = 4
ptrptr[1][1] = 5
ptrptr[1][2] = 6
```
When using dynamic memory allocation as above, we need to pay attention to memory release.

***Additional***: There are 3 types of arrays:
- Static Array: Arrays have fixed sizes and are divided into two types for clearer understanding: global static arrays and local static arrays.
+ Global static array: stored in memory segments like global variables. Scope and operation are the same as a global variable.
+ Local static array: like a local variable, a local array is allocated memory on the stack, memory is allocated when the function is called and automatically released when the function ends. Scope and operation are the same as a local variable.
- Dynamic Array: Arrays are dynamically allocated on Heap memory, whose size can change during program execution and memory management must be managed manually by the programmer. Therefore, when using dynamic arrays, we need to pay attention to memory leaks.


