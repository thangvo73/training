#include <iostream>
using namespace std;

int main() {
    unsigned int x = 1;
    char *check = (char*)&x;
    if (*check)
        std::cout << "little endian\n";
    else
        std::cout << "big endian\n";
    return 0;
}