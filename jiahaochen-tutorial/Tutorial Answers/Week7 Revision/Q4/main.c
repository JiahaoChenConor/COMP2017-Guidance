#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "stack.h"
#define DEFAULT_TEST 10

int main(int argc, char** argv) {
	int n = DEFAULT_TEST;
	if(argc > 1) {
		n = strtol(argv[1], NULL, 10);
	}

	// init stack
	stack* s = stack_alloc();
	
	for(int i = 0; i < n; i++) {
		#if DEBUG
			printf("Pushing %d\n", i);
		#endif
		// pushing 1-9
		push(s, i);
	}
	
	#if DEBUG
			printf("Pushing NULL\n");
	#endif
	push(s, NULL);
	
	for(int i = 0; i < n; i++) {
		// poping 9-1
		s_result res = pop(s);
		if(!res.failed) {
			#if DEBUG
				printf("Value: %d\n", res.val);
			#endif
		} else {
			fprintf(stderr, "No element returned\n");
		}
	}
	
	stack_free(s);
}
