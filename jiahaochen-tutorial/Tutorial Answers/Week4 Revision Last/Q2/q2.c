#include <stdio.h>

enum TYPE { FIRE, WATER, FLYING, ROCK, ELECTRIC };
struct pokemon {
	const char* name; 
	enum TYPE type;  
};

// add some padding at the end

int main(void) {
    //
	// Part 1
	//


	// Will not compile. Needs a typedef or the struct keyword before the declaration.
	pokemon pa = { "Pikachu", ELECTRIC };


    //  compile with warning and error. char* can not convert into integer
    struct pokemon pb = { ELECTRIC,  "Pikachu"};

	// Will compile. Sets attributes in the order they are defined.
	struct pokemon pc = { "Pikachu", ELECTRIC };

	// Will compile. Designator initalization syntax.  order does not matter
	struct pokemon pd = { .name = "Pikachu" , .type = ELECTRIC};

	// Will compile. Sets first attribute to zero and the rest default to zero.   pointer == 0 (means null)
	struct pokemon pe = { 0 };
    if (pe.name == NULL && pe.type == 0){
        printf("name is null and type is default\n");
    }

	//
	// Part 2
	//

	// The size of the struct will be >= sizeof(char *) + sizeof(enum TYPE)
	// depending on whether the compiler will add any padding to the struct.
	size_t s = sizeof(struct pokemon);
	printf("%d", s);
	// An enum is only guaranteed to be large enough to hold int values. 
	
	//
	// Part 3
	//

	struct pokemon pf = { "Pikachu", ELECTRIC };
	struct pokemon* pg = &pf;

	// Sets the values of the pikachu struct to { "Raichu", ELECTRIC }
	pg->name = "Raichu";
	pg->type = ELECTRIC;
}

