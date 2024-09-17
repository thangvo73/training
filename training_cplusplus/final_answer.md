***4.***

After having the default executable file a.out, I use the command: `size a.out`

***14.***

After I researched, the answer to the question of whether a constructor can be virtual is as follows:
    C++ uses virtual tables to support calling virtual functions. And the constructor is called first when declaring an object so when a constructor of a class is executed there is no virtual table in the memory yet, means no virtual pointer defined yet. So, the constructor should always be non-virtual.

***Additional:*** Let's analyze the case of calling virtual functions in constructors.

For example:
```cpp
class FatherClass {
public:
    FatherClass() {
        std::cout << "This is Father class!" << std::endl;
        display();
    }
    virtual void display() {
        std::cout << "This is Virtual method!" << std::endl;
    }
};

class SubClass : public FatherClass {
    int x = 10;
public:
    SubClass() { std::cout << "This is Child class!" << std::endl; }
    void display() override { std::cout << "Value of x: " << x << std::endl; }
};

int main() {
    FatherClass* classOne = new SubClass();
    classOne->display();
    delete classOne;

    return 0;
}
```
Looking at this code, the display() method is declared as virtual in the FatherClass. Based on the usual understanding, when the program calls the display() method, we would expect that the overridden display() method in the SubClass would be invoked. Therefore, when running the program, the display() method in the SubClass should be called twice. However, let’s examine the actual result of the program:
```
This is Father class!
This is Virtual method!
This is Child class!
Value of x: 10
```
The result shows that the display() method of the FatherClass is called once instead of the display() method in the SubClass. So what is the reason here?
When an object is created, the constructor of the parent class is the first process, at which point the components of the subclass have not yet been formed and do not exist. Therefore, the display() method called within the constructor is determined to be the display() method of the FatherClass. That’s why the program produces the result as shown.

**Conclusion:** We can still call virtual functions inside the constructor, but if we don't fully understand how it works, doing so can lead to errors, unexpected behavior, or results that are not as intended by the programmer. In general, due to the potential risks, calling virtual functions inside the constructor is not recommended.

***15.***

**Additional**: Runtime Overriding

For example:
```cpp
class FatherClass {
public:
    virtual void display() { cout << "this is parent class!" << endl; }
};

class SubClass : public FatherClass {
public:
    void display() override { cout << "this is child class!" << endl; }
};

int main() {
    FatherClass* classTwo = new SubClass();
    classTwo->display();
    return 0;
}
```
Result run program:
```
this is child class!
```

***26.***

Sorry if I didn't really understand what you meant. But I have previously updated the example for using std::make_shared to create a shared pointer as shown below.

1. **unique_ptr**
- Characteristics: Only one smart pointer owns and manages the memory area.
- Cannot be copied: Can only be moved.

For example:
```cpp
int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::unique_ptr<int> ptr1 = ptr; // this command is error
    std::cout << *ptr1 << std::endl;
    return 0;
}
```
In the above program, an error occurs because the memory area is owned by only one pointer. So we are only allowed to move the pointer as in the program below:

```cpp
int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::unique_ptr<int> ptr1 = std::move(ptr);
    std::cout << *ptr1 << std::endl;
    return 0;
}
```
Result run program:
```
10
```

2. ***shared_ptr***
- Features: Multiple smart pointers can own and manage memory.
- Reference counting: Memory is freed when there are no more smart pointers pointing to it.

For example:
```cpp
int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    std::shared_ptr<int> ptr1 = ptr;
    std::cout << *ptr1 << std::endl;
    std::cout << ptr.use_count() << std::endl;
    return 0;
}
```
Result run program:
```
10
2
```
The above program has 2 pointers that share the same memory area.

3. ***weak_ptr***
- Characteristics: Does not own memory but only provides safe access to memory managed by std::shared_ptr.
- Does not affect reference counting: Avoid circular references.

For example:
```cpp
int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    std::weak_ptr<int> ptr1 = ptr;
    if (auto ptr2 = ptr1.lock()) {
        std::cout << *ptr2 << std::endl;
    } else {
        std::cout << "the memory is released!" << std::endl;
    }
    std::cout << ptr.use_count() << std::endl;
    return 0;
}
```
Result run program:
```
10
1
```

```cpp
int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    std::weak_ptr<int> ptr1 = ptr;
    ptr.reset();
    if (auto ptr2 = ptr1.lock()) {
        std::cout << *ptr2 << std::endl;
    } else {
        std::cout << "the memory is released!" << std::endl;
    }
    std::cout << ptr.use_count() << std::endl;
    return 0;
}
```
Result run program:
```
the memory is released!
0
```
We use the lock() method in weak_ptr to check whether the memory area that weak_ptr points to still exists or not. Look at the results of the two programs above to see the meaning of weak_ptr


***rebase***: The rebase command is used to move commits from the current branch (understandably moving back and forth on the branch) and then combine them with commits from other branches to create a linear history of commits on the current branch.

***rebase***: The rebase command is used to move commits from the current branch, commits that are not on another branch and then combine them with commits from another branch to create a linear history of commits on the current branch.

***rebase***: The rebase command is used to change the base of the current branch to the latest commit on another branch and then continue the changes on the current branch from there. It provides a clear and simple commit history for the current branch.

`git rebase <branch name>`

For example:
```
  (branch main) ---A1--A2
                    \
  (branch B)         B1--B2
```
After perform `git checkout B` and `git rebase main`
```
  (branch main) ---A1--A2
                        \
  (branch B)             B1'--B2'
```
- In this example, the base of branch B is commit A1. When performing `git rebase main`, the new base of branch B is the latest commit of main branch, which is A2.
- I am referring to B1 and B2 as commit IDs (not commit messages). Therefore, after rebasing, B1' and B2' are new commit IDs, but the content remains unchanged.




For example:
```
  (branch main) ---A1--A2
                    \
  (branch B)         B1--B2
```
After perform `git checkout B` and `git rebase main`
```
  (branch main) ---A1--A2
                        \
  (branch B)             B1--B2
```

If perform `git checkout main` and `git rebase B`:
```
  (branch main) ---A1--A2
                    \
  (branch B)         B1--B2
```
Result:
```
  (branch main) ---A1--B1--B2--A2
                    \
  (branch B)         B1--B2
```
**Note**: The commit history of branch B is ---A1--B1--B2 not just B1--B2. So when standing on branch main and doing `git rebase B`, the result of commit history on branch main will be: ---A1--B1--B2--A2