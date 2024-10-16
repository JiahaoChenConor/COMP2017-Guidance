#include <stdio.h>

#define N_BATSMEN (3)

struct batsman {
    char first_name[20];
    char last_name[20];
    int score;
};

int output_scores(struct batsman* batsmans, const char* filename);


int main(int argc, char* argv[]) {
	if (argc <= 1){
		return 0;
	}


	struct batsman batsmans[N_BATSMEN];

	int i = 0;

	while(i < N_BATSMEN) {
		printf("Enter Name and Score for batter %d: ", i+1);

		// &((batsmans + i) -> first_name[0])
		int ret = scanf("%s %s %d", (batsmans + i) -> first_name, 
									(batsmans + i) -> last_name, 
									&((batsmans + i) -> score));
		if (ret != 3){
			continue;
		}

		i++;
	}
	
	output_scores(batsmans, argv[1]);

	return 0;
}


int output_scores(struct batsman* batsmans, const char* filename){
	FILE* f = fopen(filename, "w+");
	if (NULL == f){
		return -1;
	}

	for (int i = 0 ; i < N_BATSMEN; i++){
		if(((batsmans + i) -> score) > 0) {
			fprintf(f, "%s; %s; %d\n", (batsmans + i) -> first_name,
                                    (batsmans + i) -> last_name,
                                    (batsmans + i) -> score);
		} else {
			fprintf(f, "%s; %s; Duck\n", (batsmans + i) -> first_name,
                                    (batsmans + i) ->  last_name);
		}
	}
	fclose(f);
	return 1;
}

