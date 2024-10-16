#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node* next;
}NODE;


void* init();

int add_node(int val, int position, void* helper);

int delete_node(int val, void *helper);

int search_node(int val, void* helper);

int delete_all(void* helper);

