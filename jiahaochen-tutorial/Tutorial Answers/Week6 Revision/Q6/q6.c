#include<stdio.h>
#include<stdlib.h>
#define LINE_LEN 99

typedef int (*calli)(int, int);

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
	return a * b;
}

int divi(int a, int b){
	return a / b;
}


int exectue(int a, int b, calli fp){
	// return fp(a, b);
    return (*fp)(a, b);
}


int main(){
	char line[LINE_LEN];
	FILE* f;
	if ((f = fopen("instructions.txt", "r")) == NULL){
		return -1;
	}
	
	calli fn = NULL;
	int res = 0;
	int start = 1;

	char ins[4];
	char num1[4];
	char num2[4];

	while (fgets(line, LINE_LEN, f)){
		sscanf(line, "%s %s %s", ins, num1, num2);

		if (ins[0] == 'A'){
			fn = &add;
		}else if (ins[0] == 'S'){
			fn = &sub;
		}else if (ins[0] == 'M'){
			fn = &mul;
		}else if (ins[0] == 'D'){
			fn = &divi;
		}


		if (start){
			res = exectue(atoi(num1), atoi(num2), fn);
			start = 0;
		}else{
			if (num1[0] == '%'){
				res = exectue(res, atoi(num2), fn);
			}else if (num2[0] == '%'){
				res = exectue(atoi(num1), res, fn);
			}else{
				res = exectue(atoi(num1), atoi(num2), fn);
			}
		}
	}
	printf("%d\n", res);

	fclose(f);
	




		



    return 0;
}
