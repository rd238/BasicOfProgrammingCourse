#include <stdio.h>

/*
3.Программно реализовать операции над множествами, используя
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
    size_t cn = 0;
    for(int i = 0; i < an; i++){
        int is_orig = 1;
        for(int j = 0; j < bn; j++) {
            int is_orig = 1;
            if (a[i] == b[j]) {
                int is_orig = 1;
                break;
            }
        }
        if(is_orig)
            c[cn++] = a[i];

        }
    return cn;
}


size_t unorderUnion(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    for(int i = 0; i < an; i++)
        c[cn++] = a[i];
    for(int i = 0; i < bn; i++){
        int is_orig = 1;
        for(int j = 0; j < cn; j++){
            if(b[i] == c[j]){
                is_orig = 0;
                break;
            }
        }
        if(is_orig)
            c[cn++] = b[i];
    }

    return cn;
}


size_t unorderDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    for(int i = 0; i < an; i++)
        c[cn++] = a[i];
    for(int i = 0; i < bn; i++){
        for(int j = 0; j < cn; j++){
            if(b[i] == c[j]){
                c[j] = c[cn-- - 1];
                break;
            }
        }
    }

    return cn;
}


size_t unorderSymmetricDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t first = unorderDifference(a, b, c, an, bn);
    size_t second = unorderDifference(b, a, c + first, an, bn);
    first = first + second;
    return first;
}


//Пересечение, Объединение, Разность, Симметрическая разность
// пункт Б: упорядоченное множество.
size_t orderIntersection(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    for(int i = 0; i < an; i++)
        c[cn++] = a[i];
    for(int i = 0; i < cn; i++){
        int is_original = 0;
        for(int j = 0; j < bn; j++){
            if(b[j] == c[i]){
                is_original = 1;
                break;
            }
        }
        if(!is_original){
            for(int i = 0; i < cn - 1; i++){
                c[i] = c[i + 1];
            }
            cn--;
            i--;
        }
    }
}


size_t orderUnion(int *a, int *b, int *c, size_t an, size_t bn){
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

    for(int i = 0; i < size_c - 1; i++){
        if(c[i] == c[i + 1]){
            for(int j = i + 1; j < size_c; j++)
                c[j] = c[j + 1];
            size_c--;
        }
    }

    return size_c;
}


size_t orderDifference(int *a, int *b, int *c, size_t an, size_t bn){
    size_t cn = 0;
    for(int i = 0; i < an; i++)
        c[cn++] = a[i];
    for(int i = 0; i < bn; i++){
        for(int j = 0; j < cn; j++){
            if(c[j] == b[i]){
                for(int ss = j; ss < cn; ss++){
                    c[ss] = c[ss + 1];
                }
                cn--;
                break;
            }
        }
    }

    return cn;
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


int main() {
    int A[3] = {1,2,8};
    int B[2] = {6,7};
    int C[5] = {2,3,4,5,7};

    int res1[10], res2[10], res3[10], res4[10], res5[10], res6[10];

    int r1n = unorderIntersection(A, C, res1, 3, 5);
    int r2n = orderDifference(C, res1, res2, 5, r1n);
    for(int i = 0; i < r1n; i++){
        printf("%d ",res1[i]);
    }
}