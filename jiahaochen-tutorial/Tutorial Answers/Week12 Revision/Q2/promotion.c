#include <stdio.h>

#include <stdio.h>
int main(){
  unsigned int a = 1;
  signed int b = -3;
  int c;
  (a + b > 0) ? (c = 1): (c = 0);
  printf("%d\n", c);
  // a + b => unsigned, big/small(overflow)

  /*
    UINT_MAX + 1 == 0
    UINT_MAX + 2 == 1
    UINT_MAX + 3 == 2
  
  */
short t = -1;
 printf("unsigned short -1: %hu\n", t);
 printf("%d", (unsigned short) 1 > -1);
}
