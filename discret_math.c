#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *array, int n){
    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\b}\n");
}
/*
3. Программно реализовать операции над множествами, используя
следующие способы представления множества в памяти ЭВМ:

а) элементы множества А хранятся в массиве А. Элементы массива А неупорядочены;

б) элементы множества А хранятся в массиве А. Элементы массива А упорядочены по возрастанию;

в) элементы множества А хранятся в массиве А, элементы которого типа boolean.
  Если i принадлежит A, то Аi=true, иначе Ai=false.

4. Написать программы для вычисления значений выражений
(см. “Задания”, п.1 и п.2).
5. Используя программы (см. “Задания”, п.4), вычислить значения
выражений (см. “Задания”, п.1 и п.2).
 */

//Пересечение, Объединение, Разность, Симметрическая разность
// пункт А: неупорядоченное множество.
size_t unorderIntersection(int *a, int *b, int *c, size_t an, size_t bn){
    int size_c = 0;
    for(int i = 0; i < an; i++){
        int is_finded = 0;
        for(int j = 0; j < bn; j++){
            if(a[i] == b[j]) {
                is_finded = 1;
                break;
            }
        }
        for(int k = 0; k < size_c; k++)
            if(a[i] == c[k]) {
                is_finded = 0;
                break;
            }
        if(is_finded)
            c[size_c++] = a[i];
    }

    return size_c;
}



size_t unorderUnion(int *a, int *b, int *c, size_t an, size_t bn){
    int size_c = 0;
    for(int i = 0; i < an; i++, size_c++)
        c[size_c] = a[i];
    for(int i = 0; i < bn; i++) {
        int is_original = 1;
        int ii = 0;
        for (int j = 0; j < size_c; j++)
            if (c[j] == b[i])
                is_original = 0;
        if (is_original)
            c[size_c++] = b[i];

    }

    return size_c;
}



size_t unorderDifference(int *a, int *b, int *c, size_t an, size_t bn){
    int size_c = 0;
    for(int i = 0; i < an; i++){
        int is_original = 1;
        for(int j = 0; j < bn; j++){
            if(a[i] == b[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            c[size_c++] = a[i];
    }

    return size_c;
}



size_t unorderSymmetricDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t first = unorderDifference(a, b, c, an, bn);
    size_t second = unorderDifference(b, a, c + first, an, bn);
    first = first + second;
    return first;
}


int unorderIsEqual(int *a, int *b, size_t an, size_t bn) {
    for (int i = 0; i < bn; i++) {
        int is_true = 0;
        for (int j = 0; j < an; j++) {
            if (b[i] == a[j]) {
                is_true = 1;
                break;
            }
        }
        if (is_true == 0)
            return 0;
    }

    return 1;
}

//Пересечение, Объединение, Разность, Симметрическая разность
// пункт Б: упорядоченное множество.
int orderIntersection(int *a, int *b, int *c, size_t an, size_t bn){
    int ind_a = 0, ind_b = 0, size_c = 0;
    int i = 0;
    int is_original = 1;
    while(ind_a < an && ind_b < bn){
        if(a[ind_a] <= b[ind_b]) {
            if(a[ind_a] == b[i] && is_original) {
                c[size_c++] = a[ind_a++];
                i = 0;
                is_original = 0;
            }else if (i == bn || c[i] == a[ind_a]) {
                ind_a++;
                i = 0;
                is_original = 1;
            }else {
                i++;
            }
        }else {
            if(b[ind_b] == a[i] && is_original) {
                c[size_c++] = b[ind_b++];
                i = 0;
                is_original = 0;
            }else if (i == an || c[i] == b[ind_b]) {
                ind_b++;
                i = 0;
                is_original = 1;
            }else {
                i++;
            }
        }
    }

    return size_c;
}


int orderUnion(int *a, int *b, int *c, size_t an, size_t bn){
    int ind_a = 0, ind_b = 0, size_c = 0;
    while(ind_a < an && ind_b < bn){
        if(a[ind_a] <= b[ind_b])
            c[size_c++] = a[ind_a++];
        else
            c[size_c++] = b[ind_b++];
    }
    while(ind_a < an)
        c[size_c++] = a[ind_a++];
    while(ind_b < bn)
        c[size_c++] = b[ind_b++];

    return size_c;
}


int orderDifference(int *a, int *b, int *c, size_t an, size_t bn){
    int ind_a = 0, size_c = 0;
    int i = 0;
    while(ind_a < an){
        if(b[i] == a[ind_a]) {
            ind_a++;
            i = 0;
        }else if(i == bn - 1){
            c[size_c++] = a[ind_a++];
            i = 0;
        }else{
            i++;
        }
    }

    return size_c;
}



size_t orderSymmetricDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t first = orderDifference(a, b, c, an, bn);
    size_t second = orderDifference(b, a, c + first, an, bn);
    first += second;
    if(first) {
        for (int i = 0; i < first - 1; i++) {
            int min = i;
            for (int j = i + 1; j < first; j++) {
                if (c[min] > c[j])
                    min = j;
            }
            if (min != i) {
                int copy = c[i];
                c[i] = c[min];
                c[min] = copy;
            }
        }
    }

    return first;
}


int orderIsEqual(int *a, int *b, size_t an, size_t bn){
    int sizeb = 0;
    int i = 0;
    while(sizeb != bn){
        if(i == an)
            return 0;
        if(a[i] == b[sizeb]){
            sizeb++;
            i = 0;
            continue;
        }else{
            i++;
        }
    }


    return 1;
}


//Пересечение, Объединение, Разность, Симметрическая разность
// пункт В: битовое множество.
size_t bitIntersection(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    int max_size = an > bn ? an : bn;
    for(int i = 0; i < max_size; i++){
        c[cn++] = a[i] & b[i];
    }

    return cn;
}

size_t bitUnion(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    int max_size = an > bn ? an : bn;
    for(int i = 0; i < max_size; i++){
        c[cn++] = a[i] | b[i];
    }

    return cn;
}


size_t bitDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    int max_size = an > bn ? an : bn;
    for(int i = 0; i < max_size; i++){
        if(a[i] == b[i] && a[i] == 1){
            c[cn++] = 0;
        }else{
            c[cn++] = a[i];
        }
    }

    return cn;
}


size_t bitSymmetricDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    int max_size = an > bn ? an : bn;
    for(int i = 0; i < max_size; i++){
        c[cn++] = a[i] ^ b[i];
    }

    return cn;
}

int orderIntersection1(int *a, int *b, int *c, size_t an, size_t bn){
    int size_c = 0;
    for(int i = 0; i < an; i++){
        for(int j = 0; j < bn; j++){
            if(a[i] == b[j]){
                c[size_c++] = a[i];
                break;
            }
        }
    }

    return size_c;
}







// (A − X) sym B ^ X
void v1(int *A, size_t an, int *B, size_t bn,
        int *X, size_t xn){

    int step1[10];
    int step1n = 0;
    for(int i = 0; i < an; i++){
        int is_original = 1;
        for(int j = 0; j < xn; j++){
            if(A[i] == X[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step1[step1n++] = A[i];
    }

    int step2[10];
    int step2n = 0;
    for(int i = 0; i < bn; i++){
        int is_original = 0;
        for(int j = 0; j < xn; j++){
            if(B[i] == X[j]){
                is_original = 1;
                break;
            }
        }
        if(is_original)
            step2[step2n++] = B[i];
    }

    int step3[10];
    int step3n = 0;
    for(int i = 0; i < step1n; i++){
        int is_original = 1;
        for(int j = 0; j < step2n; j++){
            if(step1[i] == step2[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step3[step3n++] = step1[i];
    }
    for(int i = 0; i < step2n; i++){
        int is_original = 1;
        for(int j = 0; j < step1n; j++){
            if(step2[i] == step1[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step3[step3n++] = step2[i];
    }



    printf("{ ");
    for(int i = 0; i < step3n; i++){
        printf("%d ", step3[i]);
    }
    printf("} ");
}




// ¯(A - ¯X  )  sym (C − X)
void v2(int *A, size_t an, int *C, size_t cn, int *X,
        size_t xn, int *neX, size_t nexn, int *U, size_t un){

    int step1[10];
    int step1n = 0;
    for(int i = 0; i < cn; i++){
        int is_original = 1;
        for(int j = 0; j < xn; j++){
            if(C[i] == X[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step1[step1n++] = C[i];
    }

    int step2[10];
    int step2n = 0;
    for(int i = 0; i < an; i++){
        int is_original = 1;
        for(int j = 0; j < nexn; j++){
            if(A[i] == neX[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step2[step2n++] = A[i];
    }
    int step3[10];
    int step3n = 0;
    for(int i = 0; i < un; i++){
        int is_original = 1;
        for(int j = 0; j < step2n; j++){
            if(U[i] == step2[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step3[step3n++] = U[i];
    }


    int step4[10];
    int step4n = 0;
    for(int i = 0; i < step1n; i++){
        int is_original = 1;
        for(int j = 0; j < step3n; j++){
            if(step1[i] == step3[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step4[step4n++] = step1[i];
    }
    for(int i = 0; i < step3n; i++){
        int is_original = 1;
        for(int j = 0; j < step1n; j++){
            if(step3[i] == step1[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original)
            step4[step4n++] = step3[i];
    }

    printf("{ ");
    for(int i = 0; i < step4n; i++){
        printf("%d ", step4[i]);
    }
    printf("} ");
}









void generationOfSets(int k){
    long long nk = 1 << k;
    for(long long i = 0; i < nk; i++){
        long long m = i;
        printf("{");
        for(long long j = k; j >= 0; j--){
            if(1 & m){
                printf("%lld ", j);
            }
            m >>= 1;
        }
        if(i != 0)
            printf("\b}\n");
        else
            printf("}\n");
    }
}









void generationCombinations_(int *arr, int n, int k, int *visited, int *result, int result_index){
    if(result_index == k){
        int is_sorted = 1;
        for(int i = 0; i < k - 1 && is_sorted; i++)
            if(result[i] >= result[i + 1])
                is_sorted = 0;
        if(is_sorted) {
            for (int i = 0; i < k; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            result[result_index] = arr[i];
            visited[i] = 1;
            generationCombinations_(arr, n, k, visited, result, result_index + 1);
            visited[i] = 0;
        }
    }
}
void generationCombinations(int n, int k) {
    int arr[n];
    int visited[n];
    int result[k];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    generationCombinations_(arr, n, k, visited, result, 0);
}






void generationPermutations_(int n, int *visited, int *result, int result_index){
    if(result_index == n){
        printArray(result, n);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            result[result_index] = i + 1;
            visited[i] = 1;
            generationPermutations_(n, visited, result, result_index + 1);
            visited[i] = 0;
        }
    }
}
void generationPermutations(int n) {
    int visited[n];
    int result[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    generationPermutations_(n, visited, result, 0);
}








void generationPlacements_(int *arr, int n, int k, int *visited, int *result, int result_index){
    if(result_index == k){
        printArray(result, k);
        return;
        }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            result[result_index] = arr[i];
            visited[i] = 1;
            generationPlacements_(arr, n, k, visited, result, result_index + 1);
            visited[i] = 0;
        }
    }
}
void generationPlacements(int n, int k) {
    int arr[n];
    int visited[n];
    int result[k];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    generationPlacements_(arr, n, k, visited, result, 0);
}



void searchAndReturn_(int *M, int *R, int nM, int index){
    for(int i = 0; i < nM; i++){
        R[index] = M[i];
        if(nM == index){
            printArray(R, index);
            break;
        }else {
            searchAndReturn_(M, R, nM, index + 1);
        }
    }
    return;
}

void searchAndReturn(int nM){
    int M[nM];
    int R[nM];
    for(int i = 0; i < nM; i++)
        M[i] = i + 1;
    searchAndReturn_(M, R, nM, 0);
}



void combination_(int *M, int *C, int nM, int k, int i, int b){
    for(;b < nM - k + i + 1; b++){
        C[i] = M[b];
        if(i == k){
            printArray(C, k);
            break;
        }else{
            combination_(M, C, nM, k, i + 1, b + 1);
        }
    }
    return;
}

void combination(int nM, int k){
    int M[nM];
    int C[k];
    for(int i = 0; i < nM; i++)
        M[i] = i + 1;
    combination_(M, C, nM, k, 0, 0);
}


void permutation_(int *M, int *P, int nM, int i){
    if(i == nM){
        printArray(P, nM);
        return;
    }
    for(int j = 0; j < nM; j++){
        P[i] = M[j];
            swap(&M[j], &M[nM - 1]);
            permutation_(M, P, nM , i + 1);
            swap(&M[nM - 1],&M[j]);
    }
}

void permutation(int nM){
    int M[nM];
    int P[nM];
    for(int i = 0; i < nM; i++)
        M[i] = i;
    permutation_(M, P, nM, 0);
}

int razmes(int n, int k){
    int d = n - k;
    int d1 = 1;
    while(d != 0) {
        d1 *= d;
        d -= 1;
    }
    int n1 = 1;
    while(n != 0) {
        n1 *= n;
        n -= 1;
    }
    return n1 / d1;
}


void printSAR(int *D, int n) {
    printf("{ ");
    for(int i = 0; i < n; i++){
        if(D[i])
            printf("%d ", i + 1);
    }
    printf("\b }\n");
}

void sAR_(int *R, int nM, int index) {
    for(int i = 0; i < 2; i++){
        R[index] = i;
        if(nM == index){
            printSAR(R, index);
            return;
        }else{
            sAR_(R, nM, index + 1);
        }
    }
}


void sAR(int nM){
    int M[nM];
    int R[nM];
    for(int i = 0; i < nM; i++)
        M[i] = i + 1;
    sAR_( R, nM, 0);
}







//Структура для сохранения всех перестановок
typedef struct {
    int size;
    int max_size;
    int **arr;
} set2;
//Структура для сохранения множества работ
typedef struct {
    int size;
    int **arr;
} worker;

//Генерирует все возможные перестановки и записывает в структуру M
void gp_(int n, int *visited, int *result, int result_index, set2 *M){
    if(result_index == n){
        for(int i = 0; i < n; i++)
            M->arr[M->size][i] = result[i];
        M->size++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            result[result_index] = i;
            visited[i] = 1;
            gp_(n, visited, result, result_index + 1, M);
            visited[i] = 0;
        }
    }
}
//Генерирует все возможные перестановки и записывает в структуру M
void gP(set2 *M, int n) {
    int visited[n];
    int result[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    gp_(n, visited, result, 0, M);
}

//Функция распознование решения
void test() {
    //Массив всех возможных перестановок 4-х элементного множества
    set2 b = {0,24, malloc(sizeof(int *) * 24)};
    for(int i = 0; i < b.max_size; i++) {
        b.arr[i] = malloc(sizeof(int) * 4);
    }
    //Заполняет варианты работ
    worker work = {4, malloc(sizeof(int *) * 4)};
    for(int i = 0; i < 4; i++) {
        work.arr[i] = malloc(sizeof(int) * 4);
        for(int j = 0; j < 4; j++)
            scanf("%d", &work.arr[i][j]);
    }

    gP(&b,4);

    for(int i = 0; i < b.max_size; i++) {
        int is_find = 1;
        for(int j = 0; j < 4; j++) {
            int is_find1 = 0;
            for(int k = 0; k < work.size; k++) {
                if(work.arr[j][k] == b.arr[i][j])
                    is_find1 = 1;
            }
            if(!is_find1) {
                is_find = 0;
                break;
            }
        }
        if(is_find) {
            printf("solution found\n solution:\n");
            for(int j = 0; j < 4; j++) {
                printf("%d ", b.arr[i][j]);
            }
            printf("\n");
        }
    }

    for(int i = 0; i < 4; i++)
        free(work.arr[i]);
    free(work.arr);

    for(int i = 0; i < b.max_size; i++) {
        free(b.arr[i]);
    }
    free(b.arr);
}


//int main() {
//    //Ввод - (размер массива работ всегда 4)(множество работ(возможно повторение))
  //  test();
//}
