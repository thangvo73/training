Let's see how the memory segment size changes when storing variables.

Program without global variables:

```cpp
// int init_global_var = 1;
// int uninit_global_var;

int main() {
    int local_var = 0;
    return 0;
}
```
Memory segment size:
```
text    data     bss     dec     hex filename
1816     640       8    2464     9a0 a.out
```
The program has global variables with declared values ​​and undeclared values:
```cpp
int init_global_var = 1;
int uninit_global_var;

int main() {
    int local_var = 0;
    return 0;
}
```
Memory segment size:
```
text    data     bss     dec     hex filename
1816     644      12    2472     9a8 a.out
```
Looking at the results above, we see that the size of the data segment and .bss has increased by 4 bytes to store the int variable.

