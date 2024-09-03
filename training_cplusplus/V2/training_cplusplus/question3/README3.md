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