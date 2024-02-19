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


void zadanie5(){
/*
5. Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных,
   то транспонировать матрицу.
*/
    matrix a = matrixGetMem(3, 3);
    matrixInput(&a);
    int e[a.nCols];
    for(int i = 0; i < a.nRows; i++){
        int sum = 0;
        for(int j = 0; j < a.nCols; j++)
            sum += a.values[i][j];
        e[i] = sum;
    }
    int is_original = 1;
    for(int i = 0; i < a.nCols - 1 && is_original; i++){
        for(int j = i + 1; j < a.nCols; j++) {
            if (e[i] == e[j]) {
                is_original = 0;
                break;
            }
        }
    }
    if(is_original)
        matrixTransposeSquare(&a);
    matrixOutput(a);
    matrixFreeMem(&a);
}



bool zadanie6(){
/*
6. Даны две квадратные матрицы A и B. Определить, являются ли они взаимно
   обратными (A = B^(−1)).
*/
    matrix a = matrixGetMem(3, 3);
    matrix b = matrixGetMem(3, 3);
    matrix c = matrixGetMem(3, 3);
    matrixInput(&a);
    matrixInput(&b);
    for(int i = 0; i < a.nCols; i++){
        for(int j = 0; j < a.nRows; j++){
            c.values[i][j] = a.values[i][j] * b.values[j][i];
        }
    }
    int ret = matrixIsE(&c);
    matrixFreeMem(&a);
    matrixFreeMem(&b);
    matrixFreeMem(&c);
    return ret;
}


int zadanie7(){
/*
Дана прямоугольная матрица. Назовем псевдодиагональю множество элементов
этой матрицы, лежащих на прямой, параллельной прямой, содержащей
элементы ai,i. Найти сумму максимальных элементов всех псевдодиагоналей
данной матрицы.
*/
    matrix a = matrixGetMem(3, 4);
    //matrix b = matrixGetMem(a.nRows, a.nCols - 1);
    matrixInput(&a);
    /*for(int i = 0; i < a.nRows; i++){
        int k = 0;
        for(int j = 0; j < a.nCols; j++)
            if(i != j)
                b.values[i][k++] = a.values[i][j];
    }
    */
    int sum = 0;
    for (int k = 0; k < a.nRows + a.nCols - 1; k++) {
        int max = a.values[k < a.nRows ? k : a.nRows - 1][k < a.nRows ? 0 : k - a.nRows + 1];
        for (int i = (k < a.nRows ? k : a.nRows - 1), j = (k < a.nRows ? 0 : k - a.nRows + 1); i >= 0 && j < a.nCols; i--, j++) {
            if (a.values[i][j] > max) {
                max = a.values[i][j];
            }
        }
        sum += max;
    }
    printf("%d", --sum);

    matrixFreeMem(&a);
    //matrixFreeMem(&b);
}



void zadanie8(){
/*
Дана прямоугольная матрица, все элементы которой различны. Найти мини-
мальный элемент матрицы в выделенной области:
*/
    matrix a = matrixGetMem(4, 3);
    matrixInput(&a);
    position ap = matrixGetMaxValuePos(a);
    int min = 1000000;
    int b = 0;
    for(int i = 0, j = 0; i < a.nRows && j >= 0; i++){
        if(b) {
            j--;
        }else {
            j = a.nRows - ap.colIndex - i;
        }
        if(j == a.nRows)
            b = 1;
        for(int k = 0; k < j; k++){
            if(a.values[k][i] < min)
                min = a.values[k][i];
        }
    }

    printf("%d", min);
    matrixFreeMem(&a);
}

int main(){
    //zadanie1();
    //zadanie2();
    //zadanie3();
    //zadanie4();
    //zadanie5();
    //printf("%d", zadanie6());
    //zadanie7();
    zadanie8();

}
































