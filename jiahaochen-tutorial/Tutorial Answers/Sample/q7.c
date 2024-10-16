#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node { 
    struct node *next;
    struct node *prev;
    int* value;
};

// takes pointer to pointer to value and performs operations on value
void add_value(struct node** valuep, int* v){
    //printf("addnull %d v %d"
    
    // create the root, malloc 8 bytes for the root address
    if(valuep == NULL){
        struct node **v = (struct node**) malloc(sizeof(**v)); 
        valuep = v;
        // set the root address into NULL, so the program can execute the next
        *(valuep) = NULL;
    }
    // malloc space for root 
    if( (*valuep) == NULL ){
        //printf("valuep null %d",*v); // set new value
        struct node *val = (struct node*) malloc(sizeof (struct node)); 
        *valuep = val;
        val -> next = NULL; 
        val -> prev = NULL; 
        val -> value = v;
    } else if( (*valuep) -> next == NULL){
        //printf("valuep next null %d v %d\n",*(*valuep)->value,*v);
        struct node *val = (struct node *) malloc(sizeof (struct node)); 
        (*valuep)->next = val;
        val -> next = NULL;
        val -> prev = *valuep;
        val -> value = v;
        //printf("valuep %d v %d\n",*(*valuep)->value, *v); //printf("val %d v %d\n",*val->value , *v); //ent -> values = value;
        //add_value(ent, value);
    } else {
        add_value( &(*valuep)->next, v);
    }
} 

struct node* delete_value(struct node** valuep, int* v){
    if (valuep == NULL){
        // 2) the doubly linked list is NULL,
        return NULL;
    }
    struct node* removed_node = NULL;
    int* remove_val = NULL;
    struct node* cur = *valuep;
    while(cur != NULL){
        if (*(cur->value) == *v){
            remove_val = v;
            removed_node = cur;
            break;
        }
    }
    
    // 1) there is no such element with the value v
    // 3) the value v is NULL.
    if (!removed_node || !remove_val){
        return NULL;
    }

    else{
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    return cur;
}

int main(){
    
}
