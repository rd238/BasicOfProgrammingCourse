#ifndef EDUCATIONPROJECT_ARRAY_H
#define EDUCATIONPROJECT_ARRAY_H

#include <stddef.h>

// ввод массива data размера n
void inputArray(int *a, size_t n);

// вывод массива data размера n
void outputArray(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch(const int *a, const size_t n, int x);


// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - -1
int binarySearch(int *a, size_t n, int x);


// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает right
int binarySearchMoreOrEqual(int *a, size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert(int *a, size_t *n, size_t pos, int value);


// добавление элемента value в конец массива data размера n
void append(int *a, size_t *n, int value);


// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder(int *a, size_t *n, size_t pos);


// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsaveOrder(int *a, size_t *n, size_t pos);




// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all(const int* a, size_t n, int (*predicate) (int));


// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any(const int *a, size_t n, int (*predicate) (int));


// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach(const int * source, int * dest, size_t n, const int (*predicate) ( int));


// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf(const int * a, size_t n, int (*predicate) (int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf(int * a, size_t * n, int (*deletePredicate) (int));


#endif //EDUCATIONPROJECT_ARRAY_H
