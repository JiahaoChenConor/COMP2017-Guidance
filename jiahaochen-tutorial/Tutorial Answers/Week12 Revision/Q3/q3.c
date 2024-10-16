//
// Question 3 - Strict aliasing, restrict and optimisations
//

/*
    Strict aliasing is an assumption, made by the C (or C++) compiler, 
    that dereferencing pointers to objects of different types will never refer to the same memory location 
    (i.e. alias each other.)"


*/

//
// Part 1
//

// Make sure to read through the stories on strict aliasing.





//
// Part 2
//

// No. 
// using a union to type pun is fine.
// Alternative you could use memcpy.
//
// Refer to: https://en.wikipedia.org/wiki/Type_punning






//
// Part 3
//
// Yes. The same memory is accessed through a uint32_t* and a int*

float pi = 3.14159;
uint32_t piAsRawData = *(uint32_t*)&pi; // get pointer, cast , then dereference





//
// Part 4
//

// No. Memcpy is the alternative way to type pun without violating strict aliasing.
// since memcpy is declared using restrict pointers, implying that they will not interleave.
float x = 123.4f;
x = 2;
uint32_t y = 123;
memcpy(&x, &y, sizeof(uint32_t));







//
// Part 5
//

// The compiler cannot optimise cpy2 to memcpy because the memory addresses can interleave,
// and memcpy is declared using restrict pointers, implying that they will not interleave.




// 2. different behaviour
char s[] = "123456";
cpy2(s + 1, s, 4);
// Then the contents of s will be "111116"
// memmove => ihe two strings may overlap; the copy is always done in a non-
   //  destructive manner. => check the man 3 
// memmove => 112346 the "2345" is replaced with "1234"
