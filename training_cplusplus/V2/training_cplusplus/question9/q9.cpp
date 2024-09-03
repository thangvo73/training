#include <iostream>
using namespace std;

int main() {
    unsigned int x = 1;
    char *check = (char*)&x;
    if (*check)
        std::cout << "little endian\n";
    else
        std::cout << "big endian\n";

    cout << &x << endl;
    cout << (int*)check << endl;
    cout << (int*)(check+1) << endl;
    cout << (int*)(check+2) << endl;
    cout << (int*)(check+3) << endl;
    return 0;
}