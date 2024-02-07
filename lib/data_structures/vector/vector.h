#ifndef EDUCATIONPROJECT_VECTOR_H
#define EDUCATIONPROJECT_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


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


//возвращает истина, если вектор пустой
bool vectorIsEmpty(vector *v);


//возвращает истина, если вектор полный
bool vectorIsFull(vector *v);


// возвращает i-ый элемент вектора v.
int vectorGetValue(vector *v, size_t i);


// добавляет элемент x в конец вектора v.
void vectorPushBack(vector *v, int x);


//удаляет последний элемент из вектора.
void vectorPopBack(vector *v);


//возвращает указатель на index-ый элемент вектора.
int* vectorAt(vector *v, size_t index);


//возвращает указатель на последний элемент вектора.
int* vectorBack(vector *v);


//возвращает указатель на нулевой элемент вектора.
int* vectorFront(vector *v);








//освобождает память, выделенную вектору.
void vectorDelete(vector *v);







#endif //EDUCATIONPROJECT_VECTOR_H
