#include <iostream>
using namespace std;

int main() {
   int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
//     int (*ptr2D)[3] = arr2D; 

//     for (int i = 0; i < 2; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << endl;
//         }
//     }

//     for (int i = 0; i < 2; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             cout << "*(*(ptr2D + " << i << ") + " << j << ") = " << *(*(ptr2D + i) + j) << endl;
//         }
//     }

    int **ptrptr = new int*[2];
    for (int i=0; i<2; i++){
        ptrptr[i] = new int[3];
    }

    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            ptrptr[i][j] = arr2D[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "ptrptr[" << i << "][" << j << "] = " << *(*(ptrptr + i) + j) << endl;
        }
    }

    for (int i=0; i<2; i++){
        delete[] ptrptr[i];
    }
    delete[] ptrptr;
    return 0;
}