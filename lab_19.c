#include <stdio.h>
#include <stdlib.h>
#include "lib/data_structures/matrix/matrix.h"


void zadanie1(){
/*
В текстовом файле хранятся целочисленные квадратные матрицы
следующим образом: сначала целое число n – порядок матрицы, а
затем ее элементы по строкам. Преобразовать файл так, чтобы
элементы матрицы хранились по столбцам.
*/
    FILE *file_read = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie1.txt", "r");
    FILE *file_write = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie1_result.txt", "w");
    while(!feof(file_read)){
        int size;
        fscanf(file_read, "%d\n", &size);
        matrix m = matrixGetMem(size, size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                fscanf(file_read, "%d ", &m.values[i][j]);
            }
        }
        matrixTransposeSquare(&m);
        fprintf(file_write, "%d\n", size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(j < size - 1)
                    fprintf(file_write, "%d ", m.values[i][j]);
                else
                    fprintf(file_write, "%d\n", m.values[i][j]);
            }
        }
    }
    fclose(file_read);
    fclose(file_write);

}



int main(){
    zadanie1();
}
