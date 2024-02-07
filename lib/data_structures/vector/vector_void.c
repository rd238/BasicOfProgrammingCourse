#include "vector_void.h"


vector_void vectorVoidCreate(size_t n, size_t baseTypeSize){
    void *a = malloc(n * baseTypeSize);
    if(a == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }else{
        return (vector_void){a,0,n,baseTypeSize};
    }
}


void vectorVoidReserve(vector_void *v, size_t newCapacity){
    if(newCapacity != v->capacity){
        if(newCapacity == 0) {
            v->data = NULL;
            v->size = 0;
            v->capacity = 0;
        }else {
            void *a = realloc(v->data, newCapacity * v->baseTypeSize);
            if(a != NULL){
                if(v->size >= newCapacity){
                    free(v->data);
                    v->size = newCapacity;
                    v->capacity = newCapacity;
                    v->data = a;
                }else{
                    free(v->data);
                    v->capacity = newCapacity;
                    v->data = a;
                }
            }else{
                fprintf(stderr, "bad alloc");
                exit(1);
            }
        }
    }
}


void vectorVoidShrinkToFit(vector_void *v){
    vectorVoidReserve(v, v->size);
}


void vectorVoidClear(vector_void *v){
    v->size = 0;
}


void vectorVoidDelete(vector_void *v){
    free(v->data);
}