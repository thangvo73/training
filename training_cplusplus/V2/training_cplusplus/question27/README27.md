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


**Create Static Library in C++**

In staticLib directory:
```
	Header File: include/myMath.h
	Source File: src/myMath.cpp
```
At staticLib directory, run below commands:
```
	g++ -c src/myMath.cpp -Iinclude -o myMath.o
		// This command compiles the source code into an object file (machine code) but does not link it into an executable file using
		// the -c option.
		// src/myMath.cpp: is the source file
		// -Iinclude: the compiler will look for header files in the include directory
		// myMath.o: is the generated object file

	ar rcs myMath.a myMath.o
		// ar (GNU Archiver) is a tool to generate static libraries from compiled object files
		// rcs : are options of ar
		// myMath.a : is the generated static library
```

In question27 directory:
```
	Source File: q27.cpp
	staticLib directory
```
At question27 directory, run below commands:
```
	g++ q27.cpp -IstaticLib/include -L. -l:staticLib/myMath.a -o myprogram
		// This command compiles the source file (q27.cpp) into an executable file, which uses the static library myMath.a
		// -IstaticLib/include : is the directory path where the compiler will look for header files
		// -L. : specifies the directory where the linker will look for library files, the "." indicates that it should start from the
		// directory where the command is run
		// -l:staticLib/myMath.a : is the path to the library myMath.a
		// myprogram : is the executable file created
	./myprogram
```
Result run myprogram:
```
value of sum: 5
```

**Create Dynamic Library in C++**

In dynamicLib directory:
```
	Header File: include/myMath.h
	Source File: src/myMath.cpp
```
At dynamicLib directory, run below commands:
```
	g++ -fpic -shared src/myMath.cpp -Iinclude -o myMath.lib
		// -fpic : is an option for the compiler to generate position independent code, which means that the code will be available at
		// any memory address when loaded during execution.
		// -shared : is an option for the compiler to generate a shared library instead of a regular executable
		// myMath.lib : is a dynamic library file generated
```
In question27 directory:
```
	Source File: q27.cpp
	dynamicLib directory
```
At question27 directory, run below commands:
```
	g++ q27.cpp -o myprogram -IdynamicLib/include -l:dynamicLib/myMath.lib -L.
	./myprogram
```
Result run myprogram:
```
value of sum: 5
```