#include <iostream>
using namespace std;

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