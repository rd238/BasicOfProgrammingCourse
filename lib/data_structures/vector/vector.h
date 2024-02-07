#ifndef EDUCATIONPROJECT_VECTOR_H
#define EDUCATIONPROJECT_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct vector {
    int *data; // Указатель на элементы вектора
    size_t size; // Размер вектора
    size_t capacity; // Вместимость вектора
} vector;


//возвращает структуру-дескриптор вектор из n значений
vector vectorCreate(size_t n);


//изменяет количество памяти, выделенное под хранение элементов вектора
void vectorReserve(vector *v, size_t newCapacity);


//удаляет элементы из контейнера, но не освобождает выделенную память.
void vectorClear(vector *v);


//освобождает память, выделенную под неиспользуемые элементы.
void vectorShrinkToFit(vector *v);


//освобождает память, выделенную вектору.
void vectorDelete(vector *v);



#endif //EDUCATIONPROJECT_VECTOR_H
