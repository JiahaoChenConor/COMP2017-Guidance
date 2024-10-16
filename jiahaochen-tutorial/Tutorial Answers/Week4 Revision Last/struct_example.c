#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
    char *name;
    int age;
};

void set_name_to_albert(struct person* p){
    // (*p).name = "Albert";
    char albert[30] = "Albert";
    p->name = albert;
}


void bad_function(){
    char something[30] = "This is something I have";
    printf("%s\n", something);
}

int main(){
    struct person jeff = { .name = "Jeff", .age = 21};
    //struct person jeff = {  "Jeff",  21};
    set_name_to_albert(&jeff);
    bad_function();
    printf("%s %d\n", jeff.name, jeff.age);
    
    return 0;


}

/*

main() :0x1000
    -> set_name_to_albert(&jeff) 0x2000. stack memory will be reused
        30 bytes for albert at 0x2000
        9 bytes for p 0x2000 + 30 = 0x201E

        :: p->name points to albert -> 0x2000
    
    :: finished set_name_to_albert()
    :: back at main()


    -> bad_function() 0x2000
        30 bytes for something at 0x2000. when calling another function again, this stack memory is reused again

    // side effect, p->name points to 'something', to avoid this.
    1) char name[30] in struct
    2) example 2

*/
