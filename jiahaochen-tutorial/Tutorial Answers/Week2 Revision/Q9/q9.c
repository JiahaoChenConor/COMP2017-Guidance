#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* a, size_t length) {

	for(int i = 0; i < length / 2; i++) { //In-place reverse Symmetrically
    /*
      odd
        a b c
        cba => nothing to do with the middle chararcter


      even
       a b c d
       d c b a
    */
    
		char temp = a[i];
		a[i] = a[length - i - 1];
		a[length - i - 1] = temp;
	}
}

int main() {
	char word[100];

  while(fgets(word, 101, stdin)) {
      word[strlen(word)-1] = '\0'; //Replaces \n with \0
      reverse(word, strlen(word)); //You can assume 100
      printf("%s\n", word);
  }

}
