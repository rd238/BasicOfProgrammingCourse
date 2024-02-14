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
//значения функции criteria применяемой для столбцов
void matrixSelectionSortColsByColCriteria(matrix m, int (*criteria)(int*, int));














#endif //EDUCATIONPROJECT_MATRIX_H
