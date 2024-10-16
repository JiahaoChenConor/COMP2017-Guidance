#include <stdio.h>
#include <dlfcn.h>
typedef struct node node;

struct node {
	node* next;
	int v;
};

int main(){

   // open the dynamic library
   void* handler = dlopen("liblinkedlist.so",RTLD_LAZY);
    if(dlerror() != NULL){
        printf("%s",dlerror());
    }


    // get the function list_init from lib
   node* (*init)(int)=dlsym(handler,"list_init");
    if(dlerror()!=NULL){
        printf("%s",dlerror());
    }

	void (*free_my_list)(node*) = dlsym(handler, "list_free");
   if(dlerror()!=NULL){
        printf("%s",dlerror());
    }

   // use the function
   struct node* head = init(1);
   printf("%d\n", head->v);
   free_my_list(head);
   return 0;

   // close dynamic lib
   dlclose(handler);
   return 0;

}