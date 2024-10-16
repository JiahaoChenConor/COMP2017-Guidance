 /*
        1. check what changes in different platforms   (64-bit OS    ==> "-m32" for 32-bit OS)
            + sizeof(b) and sizeof(c)  the size for pointer  ==>  8 -> 4  
            + sizeof(f)                the size for long     ==>  8 -> 4
            + sizeof(t)                the size for size_t   ==>  8 -> 4

            +  About the size of "int"
                Back in the day, when processors were 16 bit, an int was 2 bytes. 
                Nowadays, it's most often 4 bytes on a 32-bit as well as 64-bit systems.

            These types are OS dependent!

        2. If we want to use some type that is consistent in size even across platforms ？
            + header <stdint.h>
              This header defines a set of integral type aliases with specific width requirements
                + Like uint8_t ==> fixed 8 bits (1 byte)

            + advantage
                good portability

        3. In 64-bit OS, check sizeof(struct quoll), sizeeof(quokka), sizeof(mammal)
            1. why sizeof(struct quoll) == 21
                + char = 1 byte, uint8_t = 1 byte   ==> largest member 1 byte
                + size of whole structure           ==> divisible by largest member (1 byte)
                + size = 20 + 1
            
                + what if change char ==> int ?
                    struct quoll
                    {
                        int name[20];   // 20 * 4 = 80 bytes ==> 80 bytes
                        uint8_t age;    // 1 byte            ==> no padding before This
                    };

                    + the size of wohle structure should be divisible by int(4)
                    + so the total size need extra 3 bytes padding 


            2. why sizeof(struct quokka) == 24
                + each member is 8 bytes
                + 24/8 = 3

            3. for mammal ==> since they share the memory, choose large one

        4. In 32-bit OS, check sizeof(struct quoll), sizeeof(quokka), sizeof(mammal)
            1. quoll ==> 21 bytes the same
            2. quokka ==> 12 bytes since each address takes up 4 bytes
            3. mammal 
                Union mammal{
                    struct quoll
                    {
                        char name[20];   
                        uint8_t age;    
                    };   ==> looks like 21 bytes, aglin by 1 byte

                    struct quokka
                    {
                        char* name;                
                        struct quokka* quokka_father;
                        struct quokka* quokka_mother;
                    };  ==> largest individual member 4 bytes

                    alignment by 4  
                }
                ==> so 24 bytes

            
    */


#include <stdio.h>
#include <stdint.h>


int main(){
   
 
    int a;
    printf("int a: %zu\n", sizeof(a));

    int* b = &a;
    printf("int* b: %zu\n", sizeof(b));

    int* c = NULL;
    printf("int* c: %zu\n", sizeof(c));

    unsigned d;
    printf("unsigned d: %zu\n", sizeof(d));

    short e;
    printf("short e: %zu\n", sizeof(e));
    
    long f;
    printf("long f: %zu\n", sizeof(f));

    size_t g;
    printf("size_t g: %zu\n", sizeof(g));

    long long h;
    printf("long long h: %zu\n", sizeof(h));

    uint8_t i;
    printf("uint8_t i: %zu\n", sizeof(i));

    uint32_t j;
    printf("uint32_t j: %zu\n", sizeof(j));


    struct quoll
    {
        char name[20];   
        uint8_t age;    // 1 byte 
    };



    struct quokka
    {
        char* name;
        struct quokka* quokka_father;
        struct quokka* quokka_mother;
    };


    union mammal
    {
        struct quoll l;
        struct quokka a;
    };

    union mammal m;
    printf("%p %p\n", &m.l, &m.a);
    
    printf("mammal: %zu, quokka: %zu, quoll: %zu\n", sizeof(union mammal), sizeof(struct quokka), sizeof(struct quoll));
    // printf("quoll*: %zu, quokka*: %zu\n", sizeof(struct quoll* ), sizeof(struct quokka*));


    // printf("uint8_t: %zu, uint32_t: %zu\n", sizeof(i), sizeof(j));
}

