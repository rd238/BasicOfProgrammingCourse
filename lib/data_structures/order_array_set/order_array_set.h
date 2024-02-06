#ifndef EDUCATIONPROJECT_ORDER_ARRAY_SET_H
#define EDUCATIONPROJECT_ORDER_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "../../algorithms/array/array.h"


typedef struct order_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} order_array_set;


// возвращает пустое множество, в которое можно вставить capacity элементов
order_array_set orderArraySetCreate(size_t capacity);


// возвращает множество, состоящее из элементов массива a размера size
order_array_set orderArraySetCreateFromArray(const int *a, size_t size);


// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
int orderArraySetIn(order_array_set *set, int value);


// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool orderArraySetIsEqual(order_array_set set1, order_array_set set2);


// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool orderArraySetIsSubset(order_array_set subset, order_array_set set);


// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void orderArraySetIsAbleAppend(order_array_set *set);


// добавляет элемент value в множество set
void orderArraySetInsert(order_array_set *set, int value);


// удаляет элемент value из множества set
void orderArraySetDeleteElement(order_array_set *set, int value);


// возвращает объединение множеств set1 и set2
order_array_set orderArraySetUnion(order_array_set set1, order_array_set set2);


// возвращает пересечение множеств set1 и set2
order_array_set orderArraySetIntersection(order_array_set set1, order_array_set set2);


// возвращает разность множеств set1 и set2
order_array_set orderArraySetDifference(order_array_set set1, order_array_set set2);


// возвращает симметрическую разность множеств set1 и set2
order_array_set orderArraySetSymmetricDifference(order_array_set set1, order_array_set set2);


// возвращает дополнение до универсума universumSet множества set
order_array_set orderArraySetComplement(order_array_set set, order_array_set universum_set);


// вывод множества set
void orderArraySetPrint(order_array_set set);


// освобождает память, занимаемую множеством set
void orderArraySetDelete(order_array_set set);


#endif //EDUCATIONPROJECT_ORDER_ARRAY_SET_H
