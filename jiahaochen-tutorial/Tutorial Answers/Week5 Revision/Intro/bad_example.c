#include <stdio.h>

int* createArray(int size){
	int arr[size];
	return arr;
}

int main(){
	int s = 10;
	int* arr = createArray(s);
	for (int i = 0; i < s; i++){
		arr[i] = i;
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int* createArray(int size){
	int* arr = (int*) malloc(sizeof(int) * 10);
	return arr;
}

int main(){
	int s = 10;
	int * arr = createArray(s);
  
	for (int i = 0; i < s; i++){
		arr[i] = i;
	}
  
  free(arr);

  arr = NULL;
  
	return 0;
}