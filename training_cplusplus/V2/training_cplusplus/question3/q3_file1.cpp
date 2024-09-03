#include <iostream>
using namespace std;

extern int global_var;
// extern static int static_global_var;
static int static_global_var = 1;

int main() {
    cout << "value of global variable: " << global_var << endl;
    cout << "value of static global variable: " << static_global_var << endl;
}