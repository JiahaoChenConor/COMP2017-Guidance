#include<stdio.h>
// #define LINE_LEN (24)

int main()
{
	float kmph = 0;
	float miph = 0;
	float dist = 0;
	// char line[LINE_LEN];
	printf("What is your current km/h: ");
	scanf("%f", &kmph);

	// fgets(line, LINE_LEN, stdin);
	// sscanf(line, "%f", &kmph);

	printf("How many hours are you travelling for: ");
	// fgets(line, LINE_LEN, stdin);
	// sscanf(line, "%f", &dist);
	scanf("%f", &dist);

	// 1 km/h = 0.6213711922 mi/h
	miph = (kmph * 0.6213711922);

	printf("You will cover: %.2f km (%.2f mi)\n", (dist*kmph), (dist*miph));

	printf("While travelling at %.2f km/h (%.2f mph)\n", kmph, miph);

	return(0);
}

