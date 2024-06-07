/*
Дан массив чисел типа int.
Если есть числа a и -a то они взаимо исключаются.
Вывести количество повторений оставшихся чисел в масиве.
Реализовать используя оптимальное представление множеств.
*/

#include "lib/data_structures/unorder_array_set/unorder_array_set.h"
#include "lib/data_structures/order_array_set/order_array_set.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void function(int *array, int size) {
    int n = size;
    for(int i = 0; i < n; i++) {
        int is_find = 0;
        for(int j = 0; j < n; j++) {
            if(-array[i] == array[j]) {
                swap(&array[i], &array[n-1]);
                n--;
                swap(&array[j], &array[n-1]);
                n--;
                is_find = 1;
            }
        }
        if(is_find)
            i--;
    }
    order_array_set set = orderArraySetCreateFromArray(array, n);
    for(int i = 0; i < set.size; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(set.data[i] == array[j])
                count++;
        }
        printf("element %d count %d\n", set.data[i], count);
    }
    orderArraySetDelete(set);
}

int main() {
    int array1[10] = {1,1,1,-1,3,2,-2,3,2,3};
    int array2[10] = {1,1,1,-1,-1,1,1,-1,1,1};
    int array3[10] = {2,2,2,2,1,-2,1,1,1,-1};

    printf("array 1 :\n");
    function(array1, 10);
    printf("array 2 :\n");
    function(array2, 10);
    printf("array 3 :\n");
    function(array3, 10);
}