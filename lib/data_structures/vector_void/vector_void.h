#ifndef EDUCATIONPROJECT_VECTOR_VOID_H
#define EDUCATIONPROJECT_VECTOR_VOID_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>

typedef struct vector_void {
    void *data; // Указатель на элементы вектора
    size_t size; // Размер вектора
    size_t capacity; // Вместимость вектора
    size_t baseTypeSize; // Размер базового типа
} vector_void;


//возвращает структуру-дескриптор вектор из n значений.
vector_void vectorVoidCreate(size_t n, size_t baseTypeSize);


//изменяет количество памяти, выделенное под хранение элементов вектора.
void vectorVoidReserve(vector_void *v, size_t newCapacity);


//освобождает память, выделенную под неиспользуемые элементы.
void vectorVoidShrinkToFit(vector_void *v);


//удаляет элементы из контейнера, но не освобождает выделенную память.
void vectorVoidClear(vector_void *v);


//освобождает память, выделенную вектору.
void vectorVoidDelete(vector_void *v);


//возвращает истина, если вектор пустой
bool vectorVoidIsEmpty(vector_void *v);


//возвращает истина, если вектор полный
bool vectorVoidIsFull(vector_void *v);


//записывает по адресу destination index-ый элемент вектора v.
void vectorVoidGetValue(vector_void *v, size_t index, void *destination);


//записывает на index-ый элемент вектора v значение, расположенное по адресу source;
void vectorVoidSetValue(vector_void *v, size_t index, void *source);


//удаляет последний элемент из вектора.
void vectorVoidPopBack(vector_void *v);


// добавляет элемент x в конец вектора v.
void vectorVoidPushBack(vector_void *v, void *x);


#endif //EDUCATIONPROJECT_VECTOR_VOID_H
