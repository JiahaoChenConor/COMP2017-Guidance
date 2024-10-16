// example

/*
    2's complement
*/
printf("%d %u\n", -1, (unsigned) -1);


//
// Exercise 2 - Casting and promotions
//

//
// Part 1
//

// int to char
char x = 1;

// int to long long
long long y = 1;

// char to int
int z = x;

// double to float
float a = 0.1;

// char* to const char*
const char* ptr = &x;

//
// Part 2
//

// -1 (int) to unsigned
int x = 1U - 1;

// 'a' (char) to int
int y = 'a' - 1;

// 'a' (char) to int to unsigned
unsigned y = 'a' < 1;

// 1 (int) to float
float z = 0.1 + 0.2f + 1;

//
// Part 3
//

// Make sure you complete the C integer quiz to check
// your understanding of casting and promotions.

//
// Part 4
//

// Refer to: http://c-faq.com/ansi/constmismatch.html
