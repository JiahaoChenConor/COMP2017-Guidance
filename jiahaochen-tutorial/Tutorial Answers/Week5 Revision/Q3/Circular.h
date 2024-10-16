#ifndef CIRCULAR_H
#define CIRCULAR_H

// define before structure if we want use the new name
typedef struct node node;

struct node {
	int data;
	node* prev;
	node* next;
};


node* list_init(int value);


node* list_add(struct node* head, int value);


void list_delete(struct node** head, struct node* n);


node* list_next(const struct node* n);


void list_free(struct node* head);

#endif
