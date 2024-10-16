#include <stdio.h>
int main(void) {
    for (unsigned i = 5; i-- > 0;) {
        printf("%u\n", i);
        if (i) {
            for (int j = 0; j < i; ++j) {
                printf("%d\n", i + j);
            }
        }
    }
}
