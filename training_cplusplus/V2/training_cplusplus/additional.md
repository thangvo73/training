***3. ...***

Difference between global variable and static global variable

For example: The two code snippets below are placed in two cpp program files
```cpp
int global_var = 2;
static int static_global_var = 2;
```
```cpp
extern int global_var;
// extern static int static_global_var;
static int static_global_var = 1;

int main() {
    cout << "value of global variable: " << global_var << endl;
    cout << "value of static global variable: " << static_global_var << endl;
}
```
Result run program:
```
value of global variable: 2
value of static global variable: 1
```
- global variable: Global variables are declared and can be used in other program files with the extern keyword. The result when running the program shows that and specifically, the global_var variable has the value 2.
- static global variable: Unlike global variables, static global variables cannot be used from other program files. If we intentionally use the extern keyword, the program will report an error.

    In the above example, both program files declare a variable with the same name static_global_var. However, the program does not report an error because static global variables are only valid in the program file in which they are declared. The result of running the program shows that.

***4. ...***

Let's see how the memory segment size changes when storing variables.

Program without global variables:

```cpp
// int init_global_var = 1;
// int uninit_global_var;

int main() {
    int local_var = 0;
    return 0;
}
```
Memory segment size:
```
text    data     bss     dec     hex filename
1816     640       8    2464     9a0 a.out
```
The program has global variables with declared values ​​and undeclared values:
```cpp
int init_global_var = 1;
int uninit_global_var;

int main() {
    int local_var = 0;
    return 0;
}
```
Memory segment size:
```
text    data     bss     dec     hex filename
1816     644      12    2472     9a8 a.out
```
Looking at the results above, we see that the size of the data segment and .bss has increased by 4 bytes to store the int variable.

***5. ...***

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

***6. ...***

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

***8. ...***

Perhaps we can understand this by analyzing the following example:
```cpp
int &returnThree(int &a){
    return a;
}

int main() {
    int x = 2;

    returnThree(x) = 3; // change value of x by 3 use reference function
    cout << "return reference, value = " << x << endl;
    return 0;
}
```
Result run program:
```
return reference, value = 3
```
When calling the function returnThree(x) it means we are referring to the variable x, at this time we understand that the function returnThree() acts as a reference variable of the variable x. So by calling the function and assigning a value as above, we are at the same time directly changing the variable x and the assigned value is 3.

```cpp
int &returnThree(int &a){
    return a;
}

int main() {
    int x = 2;

    int &y = returnThree(x); 
    y = 4;
    cout << "return reference, value = " << x << endl;
    return 0;
}
```
Result run program:
```
return reference, value = 4
```
We can also initialize the reference variable y to refer to the variable x through the returnThree(x) function as above. Then any changes to the variable y will simultaneously change the variable x directly and the result is like the above program.

***9. ...***

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

***10. ...***

**Explain why the size of the struct can be large the sum of its members**
In struct data type, the way of organizing memory structure follows a structure called Struct Alignment. Let's understand how to allocate memory through the following example:
```cpp
struct Data{
    char a;
    int b;
    float c;
};

int main() {
    Data data;
    cout << "size of data: " << sizeof(data) << endl;
    return 0;
}
```
Result run program:
```
size of data: 12
```
Here's how Struct Alignment works with the above struct:
```
Address 0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07  0x08  0x09  0x0A  0x0B
        |a|                     |         b          |  |         c          |
```
- Variables will be stored at the starting location which is a memory cell with an address value that is a multiple of the size of that variable. Therefore, variable b of type int is not stored at address 0x01
- The total memory size of a struct type is always a multiple of the member variable which is the largest size. Let's look at the following example to understand this feature better:
```cpp
struct Data{
    char a;
    int b;
    float c;
    char d;
};

int main() {
    Data data;
    cout << "size of data: " << sizeof(data) << endl;
    return 0;
}
```
Result run program:
```
size of data: 16
```
We see that the result in this example is 16 and not 13. Because the largest size of the member variable is 4, the total size of the struct is 16.
Here's how Struct Alignment works with the above struct:
```
Address 0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07  0x08  0x09  0x0A  0x0B  0x0C  0x0D  0x0E  0x0F
        |a|                     |         b          |  |         c          |  |d|
```
Let's try some more examples to see this more clearly.

***14. ...***

***Adittional***: About virtual constructor and virtual destructor
First, let's understand that, the virtual mechanism works only when we have a base class pointer to a derived class object.
Next, in C++, constructor cannot be virtual. So let us analyze virtual destructor.

For example:
```cpp
class FatherClass {
public:
	FatherClass(){
		cout << "Call constructor of parent class!" << endl;
	}
	~FatherClass(){
		cout << "Call destructor of parent class!" << endl;
	}
};

class SubClass : public FatherClass {
public:
	SubClass(){
		cout << "Call constructor of child class!" << endl;
	}
	~SubClass(){
		cout << "Call destructor of child class!" << endl;
	}
};

int main() {
	FatherClass *classOne = new SubClass();
	delete classOne;
	return 0;
}
```
In this example, we declare a pointer of the parent class to point to the object of the child class. The result of the above program when the destructor of the parent class is not a virtual destructor is as follows:
```
Call constructor of parent class!
Call constructor of child class!
Call destructor of parent class!
```
We see that the child class's destructor is not called. So now the virtual destructor of the parent class will solve this problem. The result of the above program when the parent class's destructor is a virtual destructor is as follows:
```cpp
class FatherClass {
public:
	FatherClass(){
		cout << "Call constructor of parent class!" << endl;
	}
	~FatherClass(){
		cout << "Call destructor of parent class!" << endl;
	}
};

class SubClass : public FatherClass {
public:
	SubClass(){
		cout << "Call constructor of child class!" << endl;
	}
	~SubClass(){
		cout << "Call destructor of child class!" << endl;
	}
};

int main() {
	FatherClass *classOne = new SubClass();
	delete classOne;
	return 0;
}
```
```
Call constructor of parent class!
Call constructor of child class!
Call destructor of child class!
Call destructor of parent class!
```
Looking at this result, we see that the order of calling constructors and destructors when operating in virtual mode is still the same as the previous analysis.

***15. ...***

- ***Method overloading***: is the existence of multiple methods with the same name in the same class, with different parameter data types or different number of parameters.
- ***Method overriding***: It refers to creating a new implementation for an existing method in the parent class (which can extend or replace the definition of the method in the parent class). This newly created method is placed in the child class and has the same name and parameters as the method in the parent class. Method overriding can be used with the virtual keyword to support dynamic polymorphism.

For example:
```cpp
class FatherClass {
public:
	int sum(int a, int b){
		return a + b;
	}

	double sum(double a, double b){
		return a + b;
	}

	int sum(int a, int b, int c){
		return a + b + c;
	}
	void display(){
		cout << "this is parent class!" << endl;
	}
};

class SubClass : public FatherClass {
public:
	void display(){
		cout << "this is child class!" << endl;
	} 
};

int main() {
	SubClass classTwo;

	cout << "result of sum: " << classTwo.sum(2,3) << endl;
	cout << "result of sum: " << classTwo.sum(2.5, 3.6) << endl;
	classTwo.display();
	return 0;
}
```
Result run program:
```
result of sum: 5
result of sum: 6.1
this is child class!
```
- In the above program, we overload the add() method and override the display() method.
- Because the display() method is overridden, when calling the display() method through an object instantiated from the child class, the display() method in the child class is called.

***19. ...***

- ***virtual function***: is a member function in a class declared with the keyword virtual. It can also be overridden like other member functions.
- ***runtime polymorphism***: is the ability of C++ to call virtual functions through a pointer or reference to a base class, but actually call overridden functions in a derived class at runtime. This allows a function of a derived class to be called through a pointer or reference to a base class, increasing the flexibility and extensibility of the program.

For example:
```cpp
class FatherClass {
public:
    void display() { cout << "this is father class!" << endl; }
};

class SubClass : public FatherClass {
public:
    void display() { cout << "this is sub class!" << endl; }
};

int main() {
    FatherClass* myclass = new SubClass();
    myclass->display();
    return 0;
}
```
Result run program:
```
this is father class!
```
In the above example, the pointer myclass points to the object of the SubClass class but the method called is not in that object but the method in the FatherClass class. To call the method in the subclass, we need to add the keyword virtual to the method in the parent class to use the runtime polymorphism.

For example:
```cpp
class FatherClass {
public:
    virtual void display() { cout << "this is father class!" << endl; }
};

class SubClass : public FatherClass {
public:
    void display() override { cout << "this is sub class!" << endl; }
};

int main() {
    FatherClass* myclass = new SubClass();
    myclass->display();
    return 0;
}
```
Result run program:
```
this is sub class!
```
When using a virtual function in a parent class, the purpose is to clearly indicate to the compiler that the method that needs to be called will be determined at runtime (at runtime, the compiler can determine which class the pointer is pointing to => from there it can call the corresponding methods).

***27. ...***

**Create Static Library in C++**

In staticLib directory:
```
	Header File: include/myMath.h
	Source File: src/myMath.cpp
```
At staticLib directory, run below commands:
```
	g++ -c src/myMath.cpp -Iinclude -o myMath.o
		// This command compiles the source code into an object file (machine code) but does not link it into an executable file using
		// the -c option.
		// src/myMath.cpp: is the source file
		// -Iinclude: the compiler will look for header files in the include directory
		// myMath.o: is the generated object file

	ar rcs myMath.a myMath.o
		// ar (GNU Archiver) is a tool to generate static libraries from compiled object files
		// rcs : are options of ar
		// myMath.a : is the generated static library
```

In question27 directory:
```
	Source File: q27.cpp
	staticLib directory
```
At question27 directory, run below commands:
```
	g++ q27.cpp -IstaticLib/include -L. -l:staticLib/myMath.a -o myprogram
		// This command compiles the source file (q27.cpp) into an executable file, which uses the static library myMath.a
		// -IstaticLib/include : is the directory path where the compiler will look for header files
		// -L. : specifies the directory where the linker will look for library files, the "." indicates that it should start from the
		// directory where the command is run
		// -l:staticLib/myMath.a : is the path to the library myMath.a
		// myprogram : is the executable file created
	./myprogram
```
Result run myprogram:
```
value of sum: 5
```

**Create Dynamic Library in C++**

In dynamicLib directory:
```
	Header File: include/myMath.h
	Source File: src/myMath.cpp
```
At dynamicLib directory, run below commands:
```
	g++ -fpic -shared src/myMath.cpp -Iinclude -o myMath.lib
		// -fpic : is an option for the compiler to generate position independent code, which means that the code will be available at
		// any memory address when loaded during execution.
		// -shared : is an option for the compiler to generate a shared library instead of a regular executable
		// myMath.lib : is a dynamic library file generated
```
In question27 directory:
```
	Source File: q27.cpp
	dynamicLib directory
```
At question27 directory, run below commands:
```
	g++ q27.cpp -o myprogram -IdynamicLib/include -l:dynamicLib/myMath.lib -L.
	./myprogram
```
Result run myprogram:
```
value of sum: 5
```