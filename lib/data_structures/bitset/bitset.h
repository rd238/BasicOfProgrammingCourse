#ifndef EDUCATIONPROJECT_BITSET_H
#define EDUCATIONPROJECT_BITSET_H

#include <stdint.h>
#include <stdbool.h>


typedef struct bitset {
    uint32_t value; // множество
    uint32_t maxValue; // Максимальный элемент
} bitset;

// возвращает пустое множество c универсумом 0, 1,..., maxValue
bitset bitsetCreate(unsigned maxValue);


// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitsetIn(bitset set, unsigned int value);


// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitsetIsEqual(bitset set1, bitset set2);


// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitsetIsSubset(bitset subset, bitset set);


// добавляет элемент value в множество set
void bitsetInsert(bitset *set, unsigned int value);


// удаляет элемент value из множества set
void bitsetDeleteElement(bitset *set, unsigned int value);


// возвращает объединение множеств set1 и set2
bitset bitsetUnion(bitset set1, bitset set2);


// возвращает пересечение множеств set1 и set2
bitset bitsetIntersection(bitset set1, bitset set2);


// возвращает разность множеств set1 и set2
bitset bitsetDifference(bitset set1, bitset set2);


// возвращает симметрическую разность множеств set1 и set2
bitset bitsetSymmerticDifference(bitset set1, bitset set2);


// возвращает дополнение до универсума множества set
bitset bitsetComplement(bitset set);


// вывод множества set
void bitsetPrint(bitset set);


#endif //EDUCATIONPROJECT_BITSET_H















