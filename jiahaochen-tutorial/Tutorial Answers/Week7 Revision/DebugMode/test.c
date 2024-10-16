#ifdef EBUG
#define DEBUG(m) \
	printf("debug: %s at line %d in file %s\n", (m), __LINE__, __FILE__);
#else
#define DEBUG(m)
#endif

#include <stdio.h>

int main(){
    char arr[10] = {'a', 'b', '\0'};
    DEBUG(arr)
    int c = 2;
}