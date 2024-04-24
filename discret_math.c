#include <stdio.h>

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


int main() {
    int U[10] = {1,2,3,4,5,6,7,8,9,10};
    int A[4] = {3, 7, 9, 10};
    int neA[6] = {1,2,4,5,6,8};
    int B[5] = {1, 3, 8, 9, 10};
    int C[5] = {2, 4, 5, 6, 7};
    int X[3] = {1, 7, 8};
    int neX[7] = {2,3,4,5,6,9,10};

    v1(A, 4, B, 5, X, 3);
    printf(" = ");
    v2(A, 4, C, 5, X, 3, neX, 7, U, 10);

}