
/*

    You can look at this file using the xxd program.

    Integers are stored on little endian order that is,
    least significant bits of the integers are stored first.

    The least significant byte (the "little end") of the data 
    is placed at the byte with the lowest address
    
    >> INPUT: hello 12348
    Eg.
        00000060 (96 address) :  3c is one byte(8 bits 0000 0000 = hex 00) 
        hello
        104 101 108 108 111
        68  65  6c  6c  6f          big endian

        12348
        30 3c
        But it is 3c30 at memory    litte endian


        00000000: 6865 6c6c 6f00 0000 0000 0000 0000 0000  hello...........
        00000010: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000020: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000030: ffb5 f000 0000 0000 c500 0000 0000 0000  ................
        00000040: 9f73 692c ff7f 0000 171d a174 547f 0000  .si,.......tT...
        00000050: 0000 0000 0000 0000 0000 c300 0100 0000  ................
        00000060: 0000 0000 3c30 0000 6865 6c6c 6f00 0000  ....<0..hello...

    Note that the compiler has added padding into the
    struct to align the structs to four bytes in memory.
*/
#include <stdio.h>

#define SIZE 1
/*
    100 + 4 = 104 / 4 (divisible)

*/
typedef struct pokemon {
	char name[100];
	unsigned level;
} pokemon;

int main(void) {

	pokemon pokemons[SIZE];

	for (size_t i = 0; i < SIZE; i++) {
		if (scanf("%99s %u",
				pokemons[i].name,
				&pokemons[i].level) != 2) {
			fprintf(stderr, "unable to read input\n");
			return 1;
		}
	}

	printf("sizeof(size_t) = %zu\n", sizeof(size_t));
	printf("sizeof(unsigned) = %zu\n", sizeof(unsigned));
	printf("sizeof(char[100]) = %zu\n", sizeof(char[100]));

	printf("sizeof(pokemon) = %zu\n", sizeof(pokemon));
	printf("sizeof(pokemons) = %zu\n", sizeof(pokemons));

	// Attempt to save to file
	FILE* file = fopen("pokemon.dat", "w");
	if (file == NULL) {
		perror("unable to open file for writing");
		return 1;
	}



	fwrite(pokemons, sizeof(pokemon), SIZE, file);
	fclose(file);

	return 0;
}

