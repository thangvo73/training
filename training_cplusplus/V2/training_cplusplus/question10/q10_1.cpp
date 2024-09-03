#include <iostream>
using namespace std;

struct Data{
    char a;
    int b;
    float c;
    char d;
};

int main() {
    Data data;
    cout << "size of data: " << sizeof(data) << endl;
    return 0;
}