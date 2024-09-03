***Array***
- Definition: An array is a data structure consisting of a series of elements of the same data type, stored in consecutive memory locations.
- Element access: Random access through array index
- Size: The size of the array is fixed after initialization, we cannot change the number of elements in the array
- Memory: Memory is allocated consecutively for the elements of the array, so the memory organization structure is easy to understand.

For example:
```cpp
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
```
Result run program:
```
 0 0 0 0 0 0 0 0 0 0
 2 5 3 7 0 0
 1 2 3 4 5
 ```
- Initialize array arr1 with a size of 10 elements, the default value of the elements is 0.
- Initialize array arr2 with a size of 6 elements, of which 2 elements have not been initialized, the default value is 0.
- Initialize array arr3 automatically determines the size of 5.

***vector***
- Definition: Vector is a data structure in the C++ standard library (STL), similar to a dynamic array, allowing flexible resizing.
- Element access: Random access through indexes is similar to accessing array elements.
- Size: The size of a vector can change dynamically, elements can be added or removed flexibly.
- Memory: Memory is allocated contiguously but may need to be reallocated and data copied when the vector expands.

For example:
```cpp
void display(vector<int> vt){
	for (int i=0; i<vt.size(); i++){
		cout << " " << vt[i];
	}
	cout << endl;
}

int main(){
	vector<int> vector1;
	vector<int> vector2(5);
	vector<int> vector3 = {1,2,3,4,5,6};

	display(vector1); // result is empty
	display(vector2);
	display(vector3);
	return 0;
}
```
Result run program:
```

 0 0 0 0 0
 1 2 3 4 5 6
```
- Initialize vector vector1 as an empty vector, then we can add or delete elements.
- Initialize vector vector2 with an initial size of 5 elements, the default value of the elements is 0. Then we can add or delete elements.
- Initialize vector vector3 with a self-defined initial size of 6. Then we can add or delete elements.
