#include <stdlib.h>
#include <stdio.h>


// fgets(buffer, BUF_LEN, stdin);
        // int ret = sscanf(buffer, "%s %d %s", customers[i].name, &customers[i].age, customers[i].object);
            // if (ret != 3){
        //     printf("Invalid input\n\n");
        //     break;
        // }


        /*
            our buffer
            +----------------------+
            | name1 | 20 | object1 |     macth the format "%s %d %s" from buffer
            +----------------------+ 
        */
        
    

        /*
            Why we don't recommend scanf ?

            check test2.input

            + scanf store the values in buffer   
                +------------------------------+   
                | name1 | 20 | object1 | name2 | 
                +------------------------------+  

              then get "%s %d %s" from buffer
                +------------------------------+   
                | name2 | 
                +------------------------------+  

            + store the values
                +------------------------------+   
                | name2 | 19 | object2 |
                +------------------------------+ 
            


            What happens for sscanf:
            + our own buffer
                after fgets
                +------------------------------+   
                | name1 | 20 | object1 | name2 | 
                +------------------------------+  

                after sscanf
                +------------------------------+   
                | name1 | 20 | object1 | name2 | 
                +------------------------------+ 

                after fgets
                +------------------------------+   
                | 19 | object2 (maybe object2 is very long ....) |.  can not format with "%s %d %s"
                +------------------------------+ 

        */
#define CUST_LEN (3)
// #define BUF_LEN (300)

typedef struct customer {
    char name[100];
    char object[100];
    int age;
}customer;

int main() {

    customer customers[CUST_LEN];
    // char buffer[BUF_LEN];
    int i = 0;

    while(i < CUST_LEN) {
        
        printf("Welcome to ShopaMocha\n");
        printf("Could you please tell me your name, age and what you are looking for?\n");
        

        int ret = scanf("%s %d %s", customers[i].name, &customers[i].age, customers[i].object);
        if (ret != 3){
            printf("Invalid input\n\n");
            break;
        }


        printf("\nHrmm, I think you should talk to a ShopaMocha assistant to find \"%s\"\n", 
            customers[i].object);
        printf("Have a good day!\n\n");

        i++;
        
    }

    for(int j = 0; j < i; j++) {
        printf("Customer %d, Name: %s, Age: %d, Looking for: %s\n", 
            j, 
            customers[j].name,
            customers[j].age,
            customers[j].object);
    }

}
