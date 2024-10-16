
#include <stdio.h>
int max(int a, int b) {  
    return a > b ? a : b;  
}  

int min(int a, int b) {  
    return a < b ? a : b;  
}  

int (*f)(int, int);  // Declare a function pointer, the pointer points to a function whose return value type is int, and there are two parameter types that are both int

int main()  
{  

    printf("------------------------------ Start\n");  

    f = max;    
    int c = (*f)(1, 2);  
    printf("The max value is %d \n", c);  

    f = min;      
    c = (*f)(1, 2);  
    printf("The min value is %d \n", c);  

    printf("------------------------------ End\n");  
    getchar();  
    return 0;  
} 
