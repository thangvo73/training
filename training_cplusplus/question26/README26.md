- ***raw pointer***: When allocating memory dynamically, we use raw pointers, so we have to manage memory manually. When we no longer use the memory, we have to delete it to avoid errors caused to the memory.
- ***smart pointer***: When allocating memory dynamically, we use smart pointers, so the memory management will work automatically. It will be automatically deleted when not in use, avoiding errors caused to the memory.

For example use raw pointer:
```cpp
int main(){
	int *ptr = new int(2);
	cout << ptr << endl;
	delete ptr; // release memory
	return 0;
}
```
In the above program we need to free up memory before the program ends with the delete statement

Now let's learn about smart pointer:
1. **unique_ptr**
- Characteristics: Only one smart pointer owns and manages the memory area.
- Cannot be copied: Can only be moved.

For example:
```cpp
int main() {
    unique_ptr<int> ptr(new int(10));
    unique_ptr<int> ptr1 = ptr; // this command is error
    cout << *ptr1 << endl;
    return 0;
}
```
```cpp
int main() {
    unique_ptr<int> ptr(new int(10));
    unique_ptr<int> ptr1 = move(ptr);
    cout << *ptr1 << endl;
    return 0;
}
```
In the above program, an error occurs because the memory area is owned by only one pointer. We are only allowed to move the pointer as in the program below.

2. ***shared_ptr***
- Features: Multiple smart pointers can own and manage memory.
- Reference counting: Memory is freed when there are no more smart pointers pointing to it.

For example:
```cpp
int main() {
    shared_ptr<int> ptr(new int(10));
    shared_ptr<int> ptr1 = ptr;
    cout << *ptr1 << endl;
	cout << ptr.use_count() << endl;
    return 0;
}
```
Result run program:
```
10
2
```
The above program has 2 pointers that share the same memory area.

3. ***weak_ptr***
- Characteristics: Does not own memory but only provides safe access to memory managed by std::shared_ptr.
- Does not affect reference counting: Avoid circular references.

For example:
```cpp
int main() {
    shared_ptr<int> ptr(new int(10));
    weak_ptr<int> ptr1 = ptr;
	if (auto ptr2 = ptr1.lock()){
		cout << *ptr2 << endl;
	} else {
		cout << "the memory is released!" << endl;
	}
	cout << ptr.use_count() << endl;
    return 0;
}
```
Result run program:
```
10
1
```

```cpp
int main() {
    shared_ptr<int> ptr(new int(10));
    weak_ptr<int> ptr1 = ptr;
	ptr.reset(); // release memory
	if (auto ptr2 = ptr1.lock()){
		cout << *ptr2 << endl;
	} else {
		cout << "the memory is released!" << endl;
	}
	cout << ptr.use_count() << endl;
    return 0;
}
```
Result run program:
```
the memory is released!
0
```
We use the lock() method in weak_ptr to check whether the memory area that weak_ptr points to still exists or not. Look at the results of the two programs above to see the meaning of weak_ptr
