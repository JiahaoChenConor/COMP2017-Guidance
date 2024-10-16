#include <stdio.h>
#include "LinkedList.h"

int main(){
   struct node* head = list_init(1);
   printf("%d\n", head->v);
   list_free(head);
   return 0;
}
