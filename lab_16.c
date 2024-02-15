#include <stdio.h>
#include "lib/data_structures/matrix/matrix.h"

void zadanie1(){
/*
1. Дана квадратная матрица, все элементы которой различны. Поменять местами
строки, в которых находятся максимальный и минимальный элементы.
*/
    matrix a = matrixGetMem(3, 3);
    matrixInput(&a);
    matrixSwapRows(a, matrixGetMaxValuePos(a).rowIndex, matrixGetMinValuePos(a).rowIndex);
    matrixOutput(a);
    matrixFreeMem(&a);

}




int func(int *a, int n){
    int max =a[0];
    for(int i = 0; i < n; i++)
        if(max < a[i])
            max = a[i];
    return max;
}

void zadanie2(){
/*
2. Упорядочить строки матрицы по неубыванию наибольших элементов строк:
*/
    matrix a = matrixGetMem(3, 3);
    matrixInput(&a);
    matrixSelectionSortRowsByRowCriteria(a, func);
    matrixOutput(a);
    matrixFreeMem(&a);

}



int func1(int *a, int n){
    int max =a[0];
    for(int i = 0; i < n; i++)
        if(max > a[i])
            max = a[i];
    return max;
}

void zadanie3(){
/*
3. Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
минимальных элементов столбцов:
*/
    matrix  a = matrixGetMem(3, 6);
    matrixInput(&a);
    matrixSelectionSortColsByColCriteria(a, func1);
    matrixOutput(a);
    matrixFreeMem(&a);
}


void zadanie4(){
/*
4. Если данная квадратная матрица A симметрична, то заменить A ее квадратом (A2).
*/
    matrix a = matrixGetMem(3, 3);
    matrixInput(&a);
    if(matrixIsSquare(&a) && matrixIsSymmetric(&a)){
        for(int i = 0; i < a.nRows; i++)
            for(int j = 0; j < a.nCols; j++)
                a.values[i][j] *= a.values[i][j];
    }
    matrixOutput(a);
    matrixFreeMem(&a);
}
int main(){
    //zadanie1();
    //zadanie2();
    //zadanie3();
    zadanie4();


}
































