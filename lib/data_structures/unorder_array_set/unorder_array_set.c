#include "unorder_array_set.h"

/*
    int *data; //Элементы множества
    size_t size; //Количество элементов в множестве
    size_t capacity; //Макс. колличество элементов в множестве
 */


unorder_array_set unorderArraySetCreate(size_t capacity){
    return (unorder_array_set){malloc(sizeof(int) * capacity),
                               0, capacity};
}


unorder_array_set unorderArraySetCreateFromArray(int *a, size_t size){
    unorder_array_set set = unorderArraySetCreate(size);
    for(int i = 0; i < size; i++) {
        set.data[i] = a[i];
        set.size++;
    }

    return set;
}


size_t unorderArraySetIn(unorder_array_set set, int value){
    for(int i = 0; i < set.size; i++)
        if(set.data[i] == value)
            return i;
    return -1;
}


bool unorderArraySetIsSubset(unorder_array_set subset, unorder_array_set set){
    for(int i = 0; i < subset.size; i++){
        int k = 0;
        for(int j = 0; j < set.size; j++){
            if(subset.data[i] == set.data[j])
                k = 1;
        }

        if(k == 0)
            return 0;
    }

    return 1;
}


bool unorderArraySetIsEqual(unorder_array_set set1, unorder_array_set set2){
    if(set1.size != set2.size)
        return 0;

    int a[set1.size];
    for(int i = 0; i < set1.size; i++)
        a[i] = set1.data[i];
    int b[set2.size];
    for(int i = 0; i < set2.size; i++)
        b[i] = set2.data[i];

    for(int i = 0; i < set1.size; i++){
        int is_true = 1;
        for(int j = 0; j < set2.size; j++){
            if(a[i] == b[j]) {
                is_true = 0;
                b[j] = -10;
            }
        }

        if(is_true)
            return 0;
    }
    return 1;
}


void unorderArraySetIsAbleAppend(unorder_array_set *set){
    assert(set->size < set->capacity);
}


void unorderArraySetInsert(unorder_array_set *set, int value){
    int is_original = 1;
    for(int i = 0; i < set->size; i++){
        if(set->data[i] == value){
            is_original = 0;
            break;
        }
    }

    unorderArraySetIsAbleAppend(set);
    append(set->data,&set->size, value);
}


void unorderArraySetDeleteElement(unorder_array_set *set, int value){
    deleteByPosUnsaveOrder(set->data, &set->size, value);
}


unorder_array_set unorderArraySetUnion(unorder_array_set set1, unorder_array_set set2){
    unorder_array_set a = unorderArraySetCreate(set1.size + set2.size);
    for(int i = 0; i < set1.size; i++)
        unorderArraySetInsert(&a, set1.data[i]);

    for(int i = 0; i < set2.size; i++) {
        int is_original = 1;
        for (int j = 0; j < set1.size; j++) {
            if (set2.data[i] == set1.data[j]) {
                is_original = 0;
                break;
            }
        }

        if (is_original)
            unorderArraySetInsert(&a, set2.data[i]);
    }

    return a;
}


unorder_array_set unorderArraySetIntersection(unorder_array_set set1, unorder_array_set set2){
    unorder_array_set a = unorderArraySetCreate(set1.size < set2.size ? set2.size : set1.size);
    for(int i = 0; i < set1.size; i++) {
        int is_original = 0;
        for (int j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j]) {
                is_original = 1;
                break;
            }
        }
        if (is_original)
            for(int k = 0; k < a.size; k++){
                if(set1.data[i] == set2.data[k]){
                    is_original = 0;
                    break;
                }
            }

        if (is_original) {
            unorderArraySetInsert(&a, set1.data[i]);
        }
    }

    return a;
}


unorder_array_set unorderArraySetDifference(unorder_array_set set1, unorder_array_set set2){
    unorder_array_set set = unorderArraySetCreate(set1.size);

    for(int i = 0; i < set1.size; i++){
        int is_original = 1;
        for(int j = 0; j < set2.size; j++){
            if(set1.data[i] == set2.data[j]) {
                is_original = 0;
                break;
            }
        }

        if(is_original)
            unorderArraySetInsert(&set, set1.data[i]);
    }

    return set;
}


unorder_array_set unorderArraySetSymmetricDifference(unorder_array_set set1, unorder_array_set set2){
    unorder_array_set a = unorderArraySetDifference(set1, set2);
    unorder_array_set b = unorderArraySetDifference(set2, set1);
    unorder_array_set c = unorderArraySetUnion(a,b);
    unorderArraySetDelete(a);
    unorderArraySetDelete(b);
    return c;
}


unorder_array_set unorderArraySetComplement(unorder_array_set set, unorder_array_set universum_set){
    unorder_array_set return_set = unorderArraySetCreate(set.size + universum_set.size);
    for(int i = 0; i < set.size; i++)
        unorderArraySetInsert(&return_set, set.data[i]);

    for(int i = 0; i < universum_set.size; i++){
        int is_original = 1;
        for(int j = 0; j < set.size; j++){
            if(universum_set.data[i] == set.data[j]){
                is_original = 0;
                break;
            }
        }

        if(is_original)
            unorderArraySetInsert(&return_set, universum_set.data[i]);
    }

    return return_set;
}


void unorderArraySetPrint(unorder_array_set set){
    printf("{");
    for(int i = 0; i < set.size; i++){
        if(i != set.size - 1)
            printf("%d, ", set.data[i]);
        else
            printf("%d", set.data[i]);
    }
    printf("}\n");
}


void unorderArraySetDelete(unorder_array_set set){
    free(set.data);
}

































