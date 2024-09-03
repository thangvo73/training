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