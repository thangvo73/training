***4.***

After having the default executable file a.out, I use the command: `size a.out`

***14.***

After I researched, the answer to the question of whether a constructor can be virtual is as follows:
    C++ uses virtual tables to support calling virtual functions. And the constructor is called first when declaring an object so when a constructor of a class is executed there is no virtual table in the memory yet, means no virtual pointer defined yet. So, the constructor should always be non-virtual.

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


***rebase***: The rebase command is used to move commits from the current branch (understandably moving back and forth on the branch) and then combine them with commits from other branches to create a linear history of commits on the current branch.

***rebase***: The rebase command is used to move commits from the current branch, commits that are not on another branch and then combine them with commits from another branch to create a linear history of commits on the current branch.

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