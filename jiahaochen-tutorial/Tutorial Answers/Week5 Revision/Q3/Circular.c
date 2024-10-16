#include <stdlib.h>
#include "Circular.h"

node* list_init(int value){
    node* head = malloc(sizeof(node));

    head->data = value;
    head->prev = head;
    head->next = head;
    return head;
}

/*
                                        cur 
    head <---> node1 <---> node2 <---> node3   new_node
    ^                                   ^
    \                                   /
     \_________________________________/                               



    cur->next = new_node;

                                       cur 
    head <---> node1 <---> node2 <---> node3 --> new_node
                                         ^
                                        /
        \______________________________/                               


    new_node->prev = cur;

                                       cur 
    head <---> node1 <---> node2 <---> node3 <--> new_node
                                         ^
                                        /
        \______________________________/    



    new_node->next = head;
    head->prev = new_node;

                                       cur 
    head <---> node1 <---> node2 <---> node3 <--> new_node
      ^                                             ^
       \                                           /
        \_________________________________________/   

*/

node* list_add(struct node* head, int value){
    if (head == NULL){
        return NULL;
    }

    // find the last node.
    node* cur = head;
    while(cur->next != head){
        cur = cur->next;
    }

    // init the new node
    node* new_node = malloc(sizeof(node));
    new_node->data = value;

    // three things need to change. 1. original last node. 2.new node 3. head
    cur->next = new_node;

    new_node->prev = cur;
    new_node->next = head;

    head->prev = new_node;

    return new_node;

}

/*

                prev        cur                
    head <---> node1 <---> node2 <---> node3   
    ^                                   ^
    \                                   /
     \_________________________________/   

*/
void list_delete(struct node** head, struct node* n){
    if (head == NULL || *head == NULL || n == NULL){
        return;
    }

    int loop = 0; // avoid infinite loop
    
    node* cur = *head;
    // find node  
    while (cur != n){
        if (cur == *head){
            loop++;
            if (loop == 2){
                return;
            }
        }
        cur = cur->next;
    }

    // link the prev and next
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;


    // if the deleted one is head, change head
    if (cur == *head){
        *head = cur->next;
    }

    free(cur);

    

}



void list_free(struct node* head){
    if (head == NULL){
        return;
    }
	// disconnect the last one with the first one
	node* temp = head;
	while (temp->next != head){
		temp = temp->next;
	}
	temp->next = NULL;

	// free as normal linked list
	node* record = NULL;
	while (head != NULL){
		// record the next node
		record = head ->next;
		// free the cur
		free(head);
		head = record;
	}

}
