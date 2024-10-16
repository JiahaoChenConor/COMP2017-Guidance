#include <stdio.h>

#define N_BATS 10
#define N_NAME_LEN 101

int main() {

    char fname[N_BATS][N_NAME_LEN];
    char lname[N_BATS][N_NAME_LEN];
    int score[N_BATS];

    int i = 0;

    while (i < N_BATS) {
        printf("Enter name and Score for batter %d: ", i+1);
        // if (scanf("%s %s %d", *(fname + i), *(lname + i), &score[i]) != 3)
        if (scanf("%100s %100s %d", fname[i], lname[i], score + i) != 3) {
            break;
        }
        i++;
    }

    for (int b = 0; b < N_BATS; b++){ 
        if (score[b] > 0){
            printf("%c. %s: %d\n", fname[b][0], lname[b], score[b]); 
        }else {
            printf("%c. %s: Duck\n", fname[b][0], lname[b]);
        }
    }

    return 0;
}
