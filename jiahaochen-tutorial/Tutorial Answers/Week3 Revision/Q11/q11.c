
// C program for the above approach
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Two things to random 
    1. types  : numbers/letters/sepcial symbols  => use rand to choose one type
    2. the digit is numbers / the letter in letters / the symbol in symbol => use rand to choose one

*/
// Function to randomly generates password
// of length N
void randomPasswordGeneration(int N)
{
    // Initialize counter
    int i = 0;
  
    int randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
    /*
        The C library function void srand(unsigned int seed) 
        seeds the random number generator used by the function rand.

        seed − 
        This is an integer value to be used as seed by the pseudo-random number generator algorithm.
    */
  
    // Array of numbers
    char numbers[] = "0123456789";
  
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    // Array of all the special symbols
    char symbols[] = "!@#$^&*?";
  
    // Stores the random password
    char password[N];
  
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
        randomizer = rand() % 4;   // choose one type

        if (randomizer == 0) {
            password[i] = numbers[rand() % 10];  
            printf("%c", password[i]);
        }
        else if (randomizer == 1) {
            password[i] = symbols[rand() % 8];
            printf("%c", password[i]);
        }
        else if (randomizer == 2) {
            password[i] = LETTER[rand() % 26];
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            printf("%c", password[i]);
        }
    }
}
  
// Driver Code
int main(int argc, char* argv[])
{
    // Length of the password to
    // be generated
    
  
    // Function Call or *(argv + 1)
    randomPasswordGeneration(atoi(argv[1]));
  
    return 0;
}
