#ifndef EDUCATIONPROJECT_MATRIX_H
#define EDUCATIONPROJECT_MATRIX_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "../../algorithms/array/array.h"



typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;


//Размещает в динамической памяти матрицу размером nRows на nCols.
//Возвращает матрицу.
matrix matrixGetMem(int nRows, int nCols);


//Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
//Возвращает указатель на нулевую матрицу.
matrix *matrixGetMemArray(int nMatrices, int nRows, int nCols);


//освобождает память, выделенную под хранение матрицы m.
void matrixFreeMem(matrix *m);


//Освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void matrixFreeMemArray(matrix *ms, int nMatrices);


//Ввод матрицы m.
void matrixInput(matrix *m);


//Ввод массива из nMatrices матриц, хранящейся по адресу ms.
void matrixInputArray(matrix *ms, int nMatrices);


//Вывод матрицы m.
void matrixOutput(matrix m);


//Вывод массива из nMatrices матриц, хранящейся по адресу ms.
void matrixOutputArray(matrix *ms, int nMatrices);


//Обмен строк с порядковыми номерами i1 и i2 в матрице m.
void matrixSwapRows(matrix m, int i1, int i2);


//Обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void matrixSwapColumns(matrix m, int j1, int j2);


//Выполняет сортировку вставками строк матрицы m по неубыванию
//значения функции criteria применяемой для строк.
void matrixSelectionSortRowsByRowCriteria(matrix m, int (*criteria)(int*, int));


//Выполняет сортировку выбором столбцов матрицы m по неубыванию
//значения функции criteria применяемой для столбцов.
void matrixSelectionSortColsByColCriteria(matrix m, int (*criteria)(int*, int));


//Возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае.
bool matrixIsSquare(matrix *m);


//Возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool matrixIsEqual(matrix *m1, matrix *m2);


//Возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае.
bool matrixIsE(matrix *m);


//Возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае.
bool matrixIsSymmetric(matrix *m);


//Транспонирует квадратную матрицу m.
void matrixTransposeSquare(matrix *m);


//Транспонирует матрицу m.
void matrixTranspose(matrix *m);


//Возвращает позицию минимального элемента матрицы m.
position matrixGetMinValuePos(matrix m);


//Возвращает позицию максимального элемента матрицы m.
position matrixGetMaxValuePos(matrix m);


//Возвращает матрицу размера nRows на nCols,
//построенную из элементов массива a.
matrix matrixCreateFromArray(const int *a, size_t nRows, size_t nCols);


//возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a.
matrix *matrixCreateArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);













#endif //EDUCATIONPROJECT_MATRIX_H
