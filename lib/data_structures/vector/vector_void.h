#ifndef EDUCATIONPROJECT_VECTOR_VOID_H
#define EDUCATIONPROJECT_VECTOR_VOID_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


typedef struct vector_void {
    void *data; // Указатель на элементы вектора
    size_t size; // Размер вектора
    size_t capacity; // Вместимость вектора
    size_t baseTypeSize; // Размер базового типа
} vector_void;





#endif //EDUCATIONPROJECT_VECTOR_VOID_H
