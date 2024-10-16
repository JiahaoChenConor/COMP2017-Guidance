#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct person create_person(const char* name, int age){
    struct person p;
    strcpy(p.name, name);
    p.age = age;
    return p;
}

int main(){
    struct person jeff = {"jeff", 21};
    jeff = (struct person) {"albert", 23}; // casting to avoid incorrect type of element

    bad_function();
    printf
}
