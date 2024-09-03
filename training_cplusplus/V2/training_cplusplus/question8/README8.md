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
