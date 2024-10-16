#include <stdio.h>  
 

 /*
 
    INLINE:

    If some functions are called frequently, 
    and functions are continuously pushed onto the stack. 
    
        --> a large consumption of stack space 


    ==> so we have `inline`

    Example below:
    dbtest(i) will be replaced by `(a % 2 > 0) ? "odd" : "even"` rather than call the function


    Limit: only some simple functions
    every time invoking inline, computer need to copy the code -> waste memory
    

    STATIC:

    Static functions will be automatically allocated in a storage area 
    that has been used until the application instance is exited, 
    which avoids pushing the stack out of the stack when calling the function, 
    which is much faster


 */
 
inline char* dbtest(int a) 
{  
	return (a % 2 > 0) ? "odd" : "even";  
}   
  
int main()  
{  
	int i = 0;  
	for (i=1; i < 100; i++) 
	{  
		printf("i:%d    odd/even:%s /n", i, dbtest(i));      
	}  
} 