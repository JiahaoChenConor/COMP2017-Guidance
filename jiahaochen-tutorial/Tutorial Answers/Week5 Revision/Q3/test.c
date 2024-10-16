#include<stdio.h>
#include <stdlib.h>
#include "Circular.h"

/*


    gcc -fsanitize=address -Wall -Werror -std=gnu11 test.c Circular.c


*/
int main(){
    /* 
        test init 
    */
    node* head = list_init(1);
    printf("head value should be 1: %d\n", head->data);
    printf("head prev value should be itself 1: %d\n", head->prev->data);
    printf("head next value should be itself 1: %d\n", head->next->data);
    list_free(head);

    /* 
        test add
    */
    node* head2 = list_init(1);
    list_add(head2, 2);
    list_add(head2, 3);
    list_add(head2, 4);

    // go clockwise
    node* clockwise_head = head2;
    for (int i = 0; i < 5; i++){
        printf("%d ", clockwise_head->data);
        clockwise_head = clockwise_head->next;
    }

    printf("\n");

    // go conuterclockwise
    node* counter_head = head2;
    for (int i = 0; i < 5; i++){
        printf("%d ", counter_head->data);
        counter_head = counter_head->prev;
    }

    printf("\n");
    list_free(head2);


    /*
        Test list_delete
    */

    node* head3 = list_init(1);
    node* new1 = list_add(head3, 2);
    list_add(head3, 3);
    list_add(head3, 4);


    node* not_exist = malloc(sizeof(node));
    not_exist ->data = 100;
    list_delete(&head3, not_exist);
    free(not_exist);


    list_delete(&head3, new1);
    node* cw = head3;
    for (int i = 0; i < 5; i++){
        printf("%d ", cw->data);
        cw = cw->next;
    }
     printf("\n");

    node* ccw = head3;
    for (int i = 0; i < 5; i++){
        printf("%d ", ccw->data);
        ccw = ccw->prev;
    }
     printf("\n");

    list_delete(&head3, head3);
    node* cw2 = head3;
    for (int i = 0; i < 5; i++){
        printf("%d ", cw2->data);
        cw2 = cw2->next;
    }
     printf("\n");


    node* ccw2 = head3;
    
    for (int i = 0; i < 5; i++){
        printf("%d ", ccw2->data);
        ccw2 = ccw2->prev;
    }
    
    
    list_free(head3);
    
}
