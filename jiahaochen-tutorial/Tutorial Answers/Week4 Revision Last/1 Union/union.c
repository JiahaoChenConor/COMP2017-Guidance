#include <stdio.h>
union data{
    int n;
    char ch;
    short m;
};
int main(){
    union data a;
    printf("%lu, %lu\n", sizeof(a), sizeof(union data) );
    a.n = 0x40;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.ch = '9';
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
   
    return 0;
}