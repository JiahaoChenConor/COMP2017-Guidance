#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	node* next;
	int v;
};

node* list_init(int v) {
	node* n = malloc(sizeof(node));
	// check return value of malloc is not null
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

	main(){
		node* head;
		// create a new LinkedList

		list_delete(head, head);
		// "head" will be change
	}

	void list_delete(node* h, node* n){
		node* new_head = h -> next;
		h = new_head // doesn't work.
	}
*/

void list_delete(node** h, node* n) {
	if(h != NULL) {
		if(*h != NULL) {
			node* prev = NULL;
			// current node = header
			node* cur = *h;
			// find the node which will be deleted
			while(cur != n && cur != NULL) {
				prev = cur;
				cur = cur -> next;
			}
			if (cur != NULL) {
				// Two case if exists n
				// 1. The node to be deteled is not the head 
				/*
					node_0 ---->  node_1 ----> node_2 ----> node3
									pre		  deleted
												cur
				*/
				if(prev != NULL) {
					prev->next = cur->next;
					free(cur);
					
				} else {
					
					// if prev is null, it means cur is head
					//node is the head, need to remove it
					/*
									node_0 ---->  node_1 ----> node_2 ----> node3
							prev	deleted
									cur
					*/
					node* new_head = (*h)->next;
					free(*h);
					// after deleting the head, we need to update the head
					*h = new_head;
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


void print_list(node* h){
	while (h != NULL){
		printf("Node %d ; ", h->v);
		h = h->next;
	}
	printf("\n");
}

int main(){
	struct node* head = list_init(0);
	// print_list(head);


	list_add(head, 1);
	list_add(head, 2);
	list_add(head, 3);
	list_add(head, 4);
	// print_list(head);

	struct node* node1 = list_next(head);
	list_delete(&head, node1);
	// print_list(head);

	list_delete(&head, head);
	// print_list(head);


	list_free(head); 

}