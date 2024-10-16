#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node* list_init(int v) {
	node* n = malloc(sizeof(node));
	n->v = v;
	n->next = NULL;
	return n;
}

void list_add(node* h, int value) {
	if(h != NULL) {
		node* c = h;
		// to the last node
		while(c->next != NULL) {
			c = c->next;
		}
		c->next = list_init(value);
	}
}


/*
	node_0 ---->  node_1 ----> node_2 ----> node3
					pre		  deleted
								cur
*/
/*
	Why node** h here ?

	void list_delete(node* h, node* n){
		node* new_head = h -> next;
		h = new_head // doesn't work.
	}
*/

void list_delete(node** h, node* n) {
	if(h != NULL) {
		if(*h != NULL) {
			node* p = NULL;
			// current node = header
			node* c = *h;
			// find previous
			while(c != n && c != NULL) {
				p = c;
				c = c->next;
			}
			if(c != NULL) {
				if(p != NULL) {
					p->next = c->next;
					free(c);
					
				} else {// if prev is null, it means cur is head
					//node is the head, need to remove it
					node* t = (*h)->next;
					free(*h);
					// when deleting the head, we need to update the head
					*h = t;
				}
			}
		}
	}
}

node* list_next(node* n) {
	node* r = NULL;
	if(n) {
		r = n->next;
	}
	return r;
}

void list_free(node* h) {
	node* t = NULL;
	while(h) {
		// record the next first
		t = h->next;
		// delete the current
		free(h);
		h = t;

	}
}

