#include <iostream>
using namespace std;

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
