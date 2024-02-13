#include "vector_void.h"


vector_void vectorVoidCreate(size_t n, size_t baseTypeSize){
    void *a = malloc(n * baseTypeSize);
    if(a == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }else{
        return (vector_void){a,0,n, baseTypeSize};
    }
}


void vectorVoidReserve(vector_void *v, size_t newCapacity){
    if(newCapacity == 0){
        free(v->data);
        v->data = NULL;
    }
    void *a = realloc(v->data, newCapacity * v->baseTypeSize);
    if(a != NULL){
        if(v->size >= newCapacity)
            v->size = newCapacity;
        free(v->data);
        v->capacity = newCapacity;
        v->data = a;
    }else{
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}



void vectorVoidShrinkToFit(vector_void *v){
    vectorVoidReserve(v, v->size);
}


void vectorVoidClear(vector_void *v){
    v->size = 0;
}


bool vectorVoidIsEmpty(vector_void *v){
    return 0 == v->size;
}


bool vectorVoidIsFull(vector_void *v){
    return v->size == v->capacity;
}


void vectorVoidGetValue(vector_void *v, size_t index, void *destination){
    if(index < v->size){
        char *sourse = (char *)(v->data + index * v->baseTypeSize);
        memcpy(destination,sourse, v->baseTypeSize);
    }else{
        fprintf(stderr, "%zu index > size vector", index);
        exit(1);
    }
}


void vectorVoidSetValue(vector_void *v, size_t index, void *source){
    if(index >= v->size){
        fprintf(stderr, "%zu index not in vector", index);
        exit(1);
    }
    char *des = (char *)(v->data + index * v->baseTypeSize);
    memcpy(des, source, v->baseTypeSize);
}


void vectorVoidPopBack(vector_void *v){
    if(v->size > 0){
        v->size--;
        vectorVoidShrinkToFit(v); // добавлена строка
    }else{
        fprintf(stderr, "vector is empty");
        exit(1);
    }
}


void vectorVoidPushBack(vector_void *v, void *x){
    if(v->size >= v->capacity){
        v->capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        v->data = realloc(v->data, v->capacity * v->baseTypeSize);
    }
    char *index = (char *)v->data + v->size++ * v->baseTypeSize;
    memcpy(index, x, v->baseTypeSize);
}


void vectorVoidDelete(vector_void *v){
    free(v->data);
}