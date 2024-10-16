//https://code.woboq.org/linux/linux/lib/string.c.html

#include <stdio.h>

void memcpy(void* dest, const void* src, size_t len) {
    char *temp = dest;
    const char *s = src;

    while (len--){
        *temp++ = *s++;
    }
}


// dest: 5, 6, 3, ....
// src: 4, 5, 6, ...

// dest: 4, 2, 3
// src: 4, 5, 4

//layout in the memory: 4, 5, 6, 3
void * my_memmove(void* dest, const void* src, unsigned int n)
{
    char *pDest = (char *)dest;
    const char *pSrc =( const char*)src;
    //allocate memory for tmp array
    char *tmp  = (char *)malloc(sizeof(char ) * n);
    if(NULL == tmp)
    {
        return NULL;
    }
    else
    {
        unsigned int i = 0;
        // copy src to tmp array
        for(i =0; i < n ; ++i)
        {
            *(tmp + i) = *(pSrc + i);
        }
        //copy tmp to dest
        for(i =0 ; i < n ; ++i)
        {
            *(pDest + i) = *(tmp + i);
        }
        free(tmp); //free allocated memory
    }
    return dest;
}

int main () {
    memcpy(dest, src, 10);
    // <- dest points to the starting point of the new copy of src
    // src to stay wherever it was <- starting point of the original src


}
