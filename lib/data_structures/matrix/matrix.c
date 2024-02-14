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


void matrixSelectionSortRowsByRowCriteria(matrix m, int (*criteria)(int*, int)){
    for(int i = 0; i < m.nRows - 1; i++){
        int jj = i;
        int min = criteria(m.values[i], m.nCols);
        for(int j = i + 1; j < m.nRows; j++){
            int min1 = criteria(m.values[j], m.nCols);
            if(min1 < min)
                jj = j;
        }
        if(jj != i){
            matrixSwapRows(m,i, jj);
        }
    }
}


void matrixSelectionSortColsByColCriteria(matrix m, int (*criteria)(int*, int)){
    for(int i = 0; i < m.nCols - 1; i++){
        int jj = i;

        int a[m.nRows];
        for(int j = 0; j < m.nCols; j++)
            a[j] = m.values[j][i];

        for(int j = i + 1; j < m.nCols; j++){

            int b[m.nRows];
            for(int k = 0; k < m.nCols; k++)
                b[k] = m.values[k][j];

            if(criteria(a, m.nRows) > criteria(b, m.nRows))
                jj = j;
        }
        if(jj != i)
            matrixSwapColumns(m, i, jj);
    }
}


bool matrixIsSquare(matrix *m){
    return m->nRows == m->nCols;
}


bool matrixIsEqual(matrix *m1, matrix *m2){
    if(m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return 0;

    for(int i = 0; i < m1->nRows; i++){
        for(int j = 0; j < m1->nCols; j++){
            if(m1->values[i][j] != m2->values[i][j])
                return 0;
        }
    }

    return 1;
}


bool matrixIsE(matrix *m){
    if(!matrixIsSquare(m))
        return 0;

    for(int i = 0; i < m->nRows; i++){
        for(int j = 0; j < m->nCols; j++){
            if(i != j && m->values[i][j] != 0)
                return 0;
        }
        if(m->values[i][i] != 1)
            return 0;
    }

    return 1;
}


bool matrixIsSymmetric(matrix *m){
    if(!matrixIsSquare(m))
        return 0;

    for(int i = 0; i < m->nCols; i++){
        for(int j = 0; j < m->nRows; j++){
            if(m->values[i][j] != m->values[j][i])
                return 0;
        }
    }

    return 1;
}



