#include <iostream>
using namespace std;

void display(int arr[], int sz){
	for (int i=0; i<sz; i++){
		cout << " " << arr[i];
	}
	cout << endl;
}

int main(){
	int arr1[10];
	int arr2[6] = {2,5,3,7};
	int arr3[] = {1,2,3,4,5};

	display(arr1, sizeof(arr1)/sizeof(arr1[0]));
	display(arr2, sizeof(arr2)/sizeof(arr2[0]));
	display(arr3, sizeof(arr3)/sizeof(arr3[0]));
	return 0;
}