//
// Question 3 - Declarations, definitions and linkages
//

//
// Part 1
//

// memory allocated ? yes the default value is 0, => definition
int x;

 // memory allocated ? No, just a reference ==> declaration
extern int y;
/*
	only the information about the variable is sent and no memory allocation is done. 
	The above information tells the compiler that the variable a is declared now 
	while memory for it will be defined later in the same file or in different file.
*/

// memory allocated ? yes ==> definition
static int z;

 // declaration
int add(int a, int b);

 // declaration
extern int multiply(int a, int b);

// definition
int add(int a, int b) {
	return a + b;
}

// declaration
static int subtract(int a, int b);

// definition
static int subtract(int a, int b) {
	return a - b;
}

// definition
int main(void) {
	return 0;
}

//
// Part 2
//

// external linkage
extern int y;

// internal linkage
int add(int a, int b);

// since add is defined later in the current translation unit
// although linkage is internal it is also accessible externally

// external linkage
extern int multiply(int a, int b);

// internal linkage
static int subtract(int a, int b);

// the static keyword means the function must
// be defined in the current translation unit

//
// Part 3
//

// global variables are accessible by default
int x;

// Test
int add(int a, int b);


int main(void);

//
// Part 4
//

/*
	#include <stdio.h>
	extern void print_My();
	int main(){
		print_My();
	}

*/
// If the linker cannot find a function that has external linkage then
// your code will compile successfully to object files [gcc -c xxx], however you will
// get a link error when you attempt to merge the object files together.

//
// Part 5
//

// Advantages of definitions in headers:
// - Useful when the code is small
// - Code is inlined into where it is used
// - Avoids the need to link to an object file

// Advantages of definitions in source files:
// - Neater code base

