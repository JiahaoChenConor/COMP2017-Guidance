#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#define DEFAULT_SIZE (4)

typedef struct dyn_array{
    int* array;
    int size;
    int capacity;
}dyn_array;


struct dyn_array* dyn_array_init();

void dyn_array_add(struct dyn_array* dyn, int value);

void dyn_array_delete(struct dyn_array* dyn, int index);

int dyn_array_get(struct dyn_array* dyn, int index);

void dyn_array_free(dyn_array* dyn);

#endif
