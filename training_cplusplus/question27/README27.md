- ***Static library***: when compiling a program, machine code is generated and will call the linker. Here the code of the static library is copied and combined with the program code to form complete executable code for the program.
	
	Features:
	- Static linking: Code from a static library is copied directly into the executable during compilation-time linking.
	- Executable file size: The executable will be larger because it contains the library code.
	- Performance: Usually a bit faster because no additional libraries need to be loaded at runtime.

- ***Dynamic library***: when compiling a program, machine code is generated and will call the linker. Here the linker does some arrangements so that the entire library code does not need to be copied into the machine code but will be provided when the program is run.
	
	Features:
	- Dynamic linking: Code from the dynamic library is linked at runtime.
	- Executable file size: The executable is smaller because it does not contain the dynamic library code, only the references to it.
	- Performance: Can be a bit slower because the library needs to be loaded at runtime.


Create Static Library in C++
```
**staticLib directory**
	Header File: include/myMath.h
	Source File: src/myMath.cpp

	Run below commands:
	g++ -c src/myMath.cpp -Iinclude -o myMath.o
	ar rcs myMath.a myMath.o

**question27 directory**
	Source File: q27.cpp
	staticLib directory

	Run below commands:
	g++ q27.cpp -IstaticLib/include -L. -l:staticLib/myMath.a -o myprogram
	./myprogram
```
Result run myprogram:
```
value of sum: 5
```

Create Dynamic Library in C++
```
**dynamicLib directory**
	Header File: include/myMath.h
	Source File: src/myMath.cpp

	Run below commands:
	g++ -fpic -shared src/myMath.cpp -Iinclude -o myMath.lib

**question27 directory**
	Source File: q27.cpp
	dynamicLib directory
	
	Run below commands:
	g++ q27.cpp -o myprogram -IdynamicLib/include -l:dynamicLib/myMath.lib -L.
	./myprogram
```
Result run myprogram:
```
value of sum: 5
```