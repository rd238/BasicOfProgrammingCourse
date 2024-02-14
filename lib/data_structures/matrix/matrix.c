#include "matrix.h"

/*
typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;
 */


matrix matrixGetMem(int nRows, int nCols){
    int **values = (int **) malloc(sizeof(int) * nRows);
    for(int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}


matrix *matrixGetMemArray(int nMatrices, int nRows, int nCols){
    matrix *matrica = (matrix *)malloc(sizeof(matrix) * nMatrices);
    for(int i = 0; i < nMatrices; i++)
        matrica[i] = matrixGetMem(nRows,nCols);
    return matrica;
}


void matrixFreeMem(matrix *m){
    for(int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}


void matrixFreeMemArray(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        matrixFreeMem(&ms[i]);
    free(ms);
}


void matrixInput(matrix *m){
    for(int i = 0; i < m->nRows; i++)
        for(int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}


void matrixInputArray(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        matrixInput(&ms[i]);
}


void matrixOutput(matrix m){
    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}


void matrixOutputArray(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        matrixOutput(ms[i]);
}


void matrixSwapRows(matrix m, int i1, int i2){
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}


void matrixSwapColumns(matrix m, int j1, int j2){
    for(int i = 0; i < m.nCols; i++) {
        int pa = m.values[i][j2];
        m.values[i][j2] = m.values[i][j1];
        m.values[i][j1] = pa;
    }
}




