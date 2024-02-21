/*
ORDER ARRAY SET TESTS


#include "lib/data_structures/order_array_set/order_array_set.h"


void order_in(){
    int aa[10] = {1,2,3,4};
    order_array_set set1 = orderArraySetCreateFromArray(aa, 4);
    int a = orderArraySetIn(&set1, 4);
    int b = orderArraySetIn(&set1, 5);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("element 4 in set1:%d  element 5 in set1: %d\n\n", a, b);
    orderArraySetDelete(set1);
}

void order_is_equal(){
    int a[4] = {1, 2, 3, 4};
    int b[4] = {1,2,3,4};
    int c[4] = {1, 2, 3, 5};
    order_array_set set1 = orderArraySetCreateFromArray(a, 4);
    order_array_set set2 = orderArraySetCreateFromArray(b, 4);
    order_array_set set3 = orderArraySetCreateFromArray(c, 4);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    printf("set3:");
    orderArraySetPrint(set3);
    int res1 = orderArraySetIsEqual(set1, set2);
    int res2 = orderArraySetIsEqual(set2, set3);
    printf("set1 is equal set2:%d   set2 is equal set3:%d\n\n", res1, res2);
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
    orderArraySetDelete(set3);
}

void order_is_subset(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[4] = {6,7,8,9};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    order_array_set set2 = orderArraySetCreateFromArray(b, 4);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    int res1 = orderArraySetIsSubset(set1, set2);
    int res2 = orderArraySetIsSubset(set2, set2);
    printf("set1 is subset set2:%d set2 is subset set1:%d\n\n", res1, res2);
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
}

void order_insert_delete(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    printf("set1:");
    orderArraySetPrint(set1);
    orderArraySetDeleteElement(&set1, 1);
    orderArraySetDeleteElement(&set1, 10);
    printf("DELETE 1 and 10:");
    orderArraySetPrint(set1);
    orderArraySetInsert(&set1, 1);
    orderArraySetInsert(&set1, 10);
    printf("INSERT 1 and 10");
    orderArraySetPrint(set1);
    printf("\n");
    orderArraySetDelete(set1);
}

void order_union(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[4] = {11,12,13,14};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    order_array_set set2 = orderArraySetCreateFromArray(b, 4);
    order_array_set set3 = orderArraySetUnion(set1, set2);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    printf("UNION set1 and set2:");
    orderArraySetPrint(set3);
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
    orderArraySetDelete(set3);
}

void order_intersection(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[4] = {1,3,5,8};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    order_array_set set2 = orderArraySetCreateFromArray(b, 4);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    order_array_set set3 = orderArraySetIntersection(set1, set2);
    printf("INTERSECTION set1 and set2");
    orderArraySetPrint(set3);
    printf("\n");
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
    orderArraySetDelete(set3);
}

void order_difference(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[4] = {1,3,5,8};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    order_array_set set2 = orderArraySetCreateFromArray(b, 4);
    order_array_set set3 = orderArraySetDifference(set1, set2);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    printf("DIFFERENCE set1 and set2");
    orderArraySetPrint(set3);
    printf("\n");
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
    orderArraySetDelete(set3);
}

void order_symmetric_difference(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {11,2,33,4,55,6,77,8,99,10};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    order_array_set set2 = orderArraySetCreateFromArray(b, 10);
    printf("set1:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    order_array_set set3 = orderArraySetSymmetricDifference(set1, set2);
    printf("SYMMETRIC DIFFERENCE set1 and set2");
    orderArraySetPrint(set3);
    printf("\n");
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
    orderArraySetDelete(set3);
}

void order_complement(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[4] = {1,2,3,4};
    order_array_set set1 = orderArraySetCreateFromArray(a, 10);
    order_array_set set2 = orderArraySetCreateFromArray(b, 4);
    order_array_set set3 = orderArraySetComplement(set2, set1);
    printf("set universum:");
    orderArraySetPrint(set1);
    printf("set2:");
    orderArraySetPrint(set2);
    printf("COMPLEMENT set1 universum set2");
    orderArraySetPrint(set3);
    orderArraySetDelete(set1);
    orderArraySetDelete(set2);
    orderArraySetDelete(set3);
}

void test(){
    order_in();
    order_is_equal();
    order_is_subset();
    order_insert_delete();
    order_union();
    order_intersection();
    order_difference();
    order_symmetric_difference();
    order_complement();
}

*/

/*
    VECTOR STRUCTURE TESTS


#include "lib/data_structures/vector/vector.h"



void test_vectorPushBack_emptyVector(){
    vector a = vectorCreate(0);
    vectorPushBack(&a, 5);
    printf("%d\n %zu %zu\n\n", a.data[0], a.size, a.capacity);
    vectorDelete(&a);
}

void test_vectorPushBack_fullVector(){
    vector a = vectorCreate(5);
    for(int i = 0; i < 5; i++)
        vectorPushBack(&a, i + 1);
    vectorPushBack(&a, 6);
    for(int i = 0; i < a.size; i++)
        printf("%d ", a.data[i]);
    vectorDelete(&a);
}

void test_vectorPopBack_notEmptyVector() {
    vector v = vectorCreate(0);
    vectorPushBack(&v, 10);
    assert(v.size == 1);
    vectorPopBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_vectorAt_notEmptyVector(){
    vector a = vectorCreate(5);
    for(int i = 0; i < 5; i++)
        vectorPushBack(&a, i + 1);
    int *b = vectorAt(&a, 0);
    printf("\n%d\n", *b);
    vectorDelete(&a);
}

void test_vectorAt_requestToLastElement(){
    vector a = vectorCreate(5);
    for(int i = 0; i < 5; i++)
        vectorPushBack(&a, i + 1);
    a.size = 5;
    int *b = vectorAt(&a, 4);
    printf("%d\n", *b);
    vectorDelete(&a);
}

void test_vectorBack_oneElementInVector(){
    vector a = vectorCreate(5);
    for(int i = 0; i < 5; i++)
        vectorPushBack(&a, i + 1);
    int *b = vectorBack(&a);
    printf("%d\n", *b);
    vectorDelete(&a);
}

void test_vectorFront_oneElementInVector(){
    vector a = vectorCreate(5);
    for(int i = 0; i < 5; i++)
        vectorPushBack(&a, i + 1);
    int *b = vectorFront(&a);
    printf("%d\n", *b);
    vectorDelete(&a);
}

void test(){
    test_vectorPushBack_emptyVector();
    test_vectorPushBack_fullVector();
    test_vectorPopBack_notEmptyVector();
    test_vectorAt_notEmptyVector();
    test_vectorAt_requestToLastElement();
    test_vectorBack_oneElementInVector();
    test_vectorFront_oneElementInVector();
}

*/

/*

#include <stdio.h>
#include "lib/data_structures/matrix/matrix.h"

int func(int *a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int main(){
    matrix a = matrixGetMem(2,5);
    matrixInput(&a);
    printf("%d %d\n", getMinValuePos(a).rowIndex, getMinValuePos(a).colIndex);
    matrixOutput(a);
    matrixFreeMem(&a);
}
*/

#include "lib/data_structures/string_/string_.h"

int main(){
    char *a = "123";
    char *b = "1234";
    printf("%d\n", strCmp(a,b));
    for(int i = 0; i < strLen(a); i++)
        printf("%c", a[i]);
}































