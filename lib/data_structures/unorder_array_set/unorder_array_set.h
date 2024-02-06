#ifndef EDUCATIONPROJECT_UNORDER_ARRAY_SET_H
#define EDUCATIONPROJECT_UNORDER_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"


typedef struct unorder_array_set {
    int *data; //Элементы множества
    size_t size; //Количество элементов в множестве
    size_t capacity; //Макс. колличество элементов в множестве
} unorder_array_set;


// возвращает пустое множество для capacity элементов
unorder_array_set unorderArraySetCreate(size_t capacity);


// возвращает множество, состоящее из элементов массива a размера size.
unorder_array_set unorderArraySetCreateFromArray(int *a, size_t size);


// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set, иначе - -1
size_t unorderArraySetIn(unorder_array_set set, int value);


// возвращает true(1) если множество subset является
// подмножеством set, иначе false(0)
bool unorderArraySetIsSubset(unorder_array_set subset, unorder_array_set set);


// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unorderArraySetIsEqual(unorder_array_set set1, unorder_array_set set2);


// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unorderArraySetIsAbleAppend(unorder_array_set *set);


// добавляет элемент value в множество set
void unorderArraySetInsert(unorder_array_set *set, int value);


// удаляет элемент value из множества set
void unorderArraySetDeleteElement(unorder_array_set *set, int value);


// возвращает объединение множеств set1 и set2.
unorder_array_set unorderArraySetUnion(unorder_array_set set1, unorder_array_set set2);


// возвращает пересечение множеств set1 и set2
unorder_array_set unorderArraySetIntersection(unorder_array_set set1, unorder_array_set set2);


// возвращает разность множеств set1 и set2
unorder_array_set unorderArraySetDifference(unorder_array_set set1, unorder_array_set set2);


// возвращает дополнение до универсума множества set
unorder_array_set unorderArraySetComplement(unorder_array_set set, unorder_array_set universum_set);


// возвращает симметрическую разность множеств set1 и set2
unorder_array_set unorderArraySetSymmetricDifference(unorder_array_set set1, unorder_array_set set2);


// вывод множества set
void unorderArraySetPrint(unorder_array_set set);


// освобождает память, занимаемую множеством set
void unorderArraySetDelete(unorder_array_set set);


#endif //EDUCATIONPROJECT_UNORDER_ARRAY_SET_H