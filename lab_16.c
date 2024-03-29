

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
    matrixInput(&a);
    int sum = 0;
    for (int k = 0; k < a.nRows + a.nCols - 1; k++) {
        int max = a.values[k < a.nRows ? k : a.nRows - 1][k < a.nRows ? 0 : k - a.nRows + 1];
        for (int i = (k < a.nRows ? k : a.nRows - 1),
                j = (k < a.nRows ? 0 : k - a.nRows + 1); i >= 0 && j < a.nCols; i--, j++) {
            if (a.values[i][j] > max) {
                max = a.values[i][j];
            }
        }
        sum += max;
    }
    printf("%d", --sum);

    matrixFreeMem(&a);
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






#include <math.h>
float getDistance(int *a, int n){
    int d = 0;
    for(int i = 0; i < n; i++)
        d += a[i] * a[i];
    return sqrtf(d);
}
void zadanie9(){
/*
Дано n точек в m-мерном пространстве. Упорядочить точки по неубыванию их
расстояний до начала координат.
*/
    matrix a = matrixGetMem(5, 5);
    matrixInput(&a);
    for(int i = 0; i < a.nRows - 1; i++){
        int jj = i;
        float min = getDistance(a.values[i], a.nRows);
        for(int j = i + 1; j < a.nRows; j++){
            float min1 = getDistance(a.values[j], a.nCols);
            if(min1 - 0.01 < min - 0.01)
                jj = j;
        }
        if(jj != i){
            matrixSwapRows(a,i, jj);
        }
    }
    matrixOutput(a);
    matrixFreeMem(&a);
}





void zadanie10(){
/*
Определить количество классов эквивалентных строк данной прямоугольной
матрицы. Строки считать эквивалентными, если равны суммы их элементов.
Указание: задача сводится к тому, чтобы подсчитать количество уникальных
сумм строк матрицы.
*/
    matrix a = matrixGetMem(6, 2);
    matrixInput(&a);
    int equal_class = 0;
    for(int i = 0; i < a.nRows - 1; i++){
        int sum = 0;
        for(int j = 0; j < a.nCols; j++){
            sum += a.values[i][j];
        }
        int sum1 = 0;
        for(int j = i + 1; j < a.nRows; j++){
            for(int k = 0; k < a.nCols; k++){
                sum1 += a.values[j][k];
            }
        }
        if(sum != sum1) {
            i++;
            equal_class++;
        }
    }
    printf("%d", equal_class);
    matrixFreeMem(&a);
}




void zadanie11(){
/*
Дана матрица. Определить k – количество "особых" элементов матрицы, считая
элемент "особым", если он больше суммы остальных элементов своего столбца.
*/
    matrix a = matrixGetMem(3, 4);
    matrixInput(&a);
    int element = 0;
    for(int i = 0; i < a.nCols; i++){
        int aa[a.nRows];
        for(int j = 0; j < a.nRows; j++){
            aa[j] = a.values[j][i];
        }
        int max = aa[0];
        int sum = aa[0];
        for(int j = 1; j < a.nRows; j++){
            if(aa[j] > max)
                max = aa[j];
            sum += aa[j];
        }
        if(sum - max < max)
            element++;
    }

    printf("%d", element);

    matrixFreeMem(&a);
}





void zadanie12(){
/*
Дана квадратная матрица. Заменить предпоследнюю строку матрицы первым
из столбцов, в котором находится минимальный элемент матрицы.
*/
    matrix a = matrixGetMem(3,3);
    matrixInput(&a);
    position ap = matrixGetMinValuePos(a);
    for(int i = a.nRows - 1, j = a.nCols - 1; j >= 0; j--){
        a.values[a.nRows - 2][j] = a.values[j][ap.rowIndex];
    }
    matrixOutput(a);
    matrixFreeMem(&a);
}




void zadanie13(){
/*
Дан массив матриц одного размера. Определить число матриц, строки кото-
рых упорядочены по неубыванию элементов
*/
    matrix *a = matrixGetMemArray(4, 2, 2);
    matrixInputArray(a, 4);
    for(int k = 0; k < 4; k++){
        int is_sorted = 1;
        for(int i = 0; i < a->nRows; i++){
            int br = 0;
            for(int j = 0; j < a->nCols - 1; j++){
                if(a[k].values[i][j] > a[k].values[i][j + 1]){
                    br = 1;
                    is_sorted = 0;
                    break;
                }
            }
            if(br)
                break;
        }
        if(is_sorted)
            matrixOutput(a[k]);
    }
    matrixFreeMemArray(a, 4);
}



void zadanie14(){
/*
Дан массив целочисленных матриц. Вывести матрицы, имеющие наибольшее
число нулевых строк
*/
    matrix *a = matrixGetMemArray(5, 3, 2);
    matrixInputArray(a, 5);
    int aa[5];
    int size = 0;
    for(int k = 0; k < 5; k++){
        int rows = 0;
        for(int i = 0; i < a->nRows; i++){
            int b = 1;
            for(int j = 0; j < a->nCols; j++){
                if(a[k].values[i][j] != 0){
                    b = 0;
                    break;
                }
            }
            if(b)
                rows++;
        }
        if(rows > 1)
            aa[size++] = k;
    }
    for(int i = 0; i < size; i++){
        matrixOutput(a[aa[i]]);
    }
    matrixFreeMemArray(a, 5);
}





void zadanie15(){
/*
Дан массив целочисленных квадратных матриц. Вывести матрицы с наименьшей
нормой. В качестве нормы матрицы взять максимум абсолютных величин ее элементов.
*/
    matrix *a = matrixGetMemArray(4, 3, 3);
    matrixInputArray(a, 4);
    int min_index = 0;
    int min_value = 10000;
    for(int k = 0; k < 4; k++){
        position ap = matrixGetMinValuePos(a[k]);
        if(a[k].values[ap.rowIndex][ap.colIndex] < min_value) {
            min_value = a[k].values[ap.rowIndex][ap.colIndex];
            min_index = k;
        }
    }
    matrixOutput(a[min_index]);
    matrixFreeMemArray(a, 4);
}



void zadanie18(){
/*
*Дана целочисленная квадратная матрица, все элементы которой различны.
Найти скалярное произведение строки, в которой находится наибольший элемент
матрицы, на столбец с наименьшим элементом.
*/
    matrix a = matrixGetMem(3, 3);
    matrixInput(&a);
    position min = matrixGetMinValuePos(a);
    position max = matrixGetMaxValuePos(a);
    int product = 0;
    for(int i = 0; i < a.nRows; i++){
        product += a.values[max.rowIndex][i] * a.values[i][min.colIndex];
    }
    printf("%d", product);
    matrixFreeMem(&a);
}
/*
int main(){
    //zadanie1();
    //zadanie2();
    //zadanie3();
    //zadanie4();
    //zadanie5();
    //printf("%d", zadanie6());
    //zadanie7();
    //zadanie8();
    //zadanie9();
    //zadanie10();
    //zadanie11();
    //zadanie12();
    //zadanie13();
    //zadanie14();
    //zadanie15();
    //zadanie18();
}
*/































