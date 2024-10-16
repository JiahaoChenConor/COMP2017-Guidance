#include <stdio.h>

int main() {
  // large enough
	char word[99];

  // get 100 bytes from stdin
  while(fgets(word, 99, stdin)) {
      printf("%s\n", word);
  }

  // what if stdin is very long ?
}