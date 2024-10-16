#include <stdio.h>

int main(){
    char *ptr;               // pointer to char
    char (*ptr_array)[10];  // pointer to array    
  	/*
  		Different with 
  		char* p_array[10];  
  		
      p array, the elemnet in the array is pointers/addresses
  	*/


    char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', '\0'};

    ptr = arr; // cast into char*
    ptr_array = (char (*)[]) arr; // cast into char(*)[]


    printf("%p\n", ptr);

    // + sizeof (elemnet_pointer_points_to) 
    printf("%p\n", ptr + 1);  // element is char so + 1
    printf("%p\n", ptr_array + 1); // element is char[10], so + 10


    printf("%c\n", *ptr);  // get 'a'

    printf("%p\n", *ptr_array); // get an array ? How to access array ? we get address/pointer here ? what the type ???
    printf("%p\n", *ptr_array + 1); // the type seems to be char*


    printf("%c\n", **ptr_array);
    /*  
        Rule 6.3.2.1
        deference a pointer to array
        
        "array of type" is converted to an expression with type "pointer to type" that points to the initial element of the array object...
    */


    char twoD[10][20];
		/*
			We know that the name of the array is a constant pointer that points to the 0th element of the array. 
      In the case of a 2-D array, 0th element is a 1-D array. 
      So the name of the array in case of a 2-D array represents a pointer to the 0th 1-D array. 
		
		*/
  
    // twoD is a pointer points to array[20], type is a pointer to array;     

    // twoD + 0  ==> pointer to first array[20], the type of pointer is (char (*)[]) 
    // twoD + 1  ==> pointer to second array[20], the type of pointer is (char (*)[]) 

    // scanf("%s\n", char* ptr); // type is char* (a pointer to char), not a pointer to array

    // scanf("%s\n", *(twoD + 0)); // when deference a pointer to array, we get the pointer points to the initial elemnet in the array, type is char*
    scanf("%s", *(twoD + 0));
    printf("%s\n", twoD[0]);
}