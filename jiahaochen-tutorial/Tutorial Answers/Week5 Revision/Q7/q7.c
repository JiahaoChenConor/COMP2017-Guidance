#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node {
	node* next;
	node* prev;
	void* v;
	size_t sz;
};

node* list_init(void* e, size_t sz) {
	node* n = malloc(sizeof(node));
	n->v = malloc(sz);
	// need copy the correct size from address e
	memcpy(n->v, e, sz);
	n->sz = sz;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void list_add(node* h, void* e, size_t sz) {
	if(h != NULL) {
		node* c = h;
		while(c->next != NULL) {
			c = c->next;
		}
		c->next = list_init(e, sz);
		c->next->prev = c;
	}
}

void list_delete(node** h, node* n) {
	if(h != NULL) {
		if(*h != NULL) {
			node* p = NULL;
			node* c = *h;
			while(c != n && c != NULL) {
				p = c;
				c = c->next;
			}
			if(c != NULL) {
				if(p != NULL) {
					p->next = c->next;
					if(c->next != NULL) {
						c->next->prev = p;
					}
					free(c);
				} else {
					//node is the head, need to remove it
					node* t = (*h)->next;
					free(*h);
					*h = t;
					(*h)->prev = NULL;
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
		t = h->next;
		free(h->v);
		free(h);
		h = t;
	}
}

