#include "order_array_set.h"



order_array_set orderArraySetCreate(size_t capacity){
    return (order_array_set){malloc(sizeof(int) * capacity), 0, capacity};
}


order_array_set orderArraySetCreateFromArray(const int *a, size_t size){
    order_array_set set = orderArraySetCreate(size);
    for(int i = 0; i < size; i++){
        orderArraySetInsert(&set, a[i]);
    }

    return set;
}


int orderArraySetIn(order_array_set *set, int value){
    return binarySearch(set->data, set->size, value);
}


bool orderArraySetIsEqual(order_array_set set1, order_array_set set2){
    if(set1.size == set2.size){
        for(int i = 0; i < set1.size; i++){
            if(set1.data[i] != set2.data[i])
                return 0;
        }

        return 1;
    }else{
        return 0;
    }
}


bool orderArraySetIsSubset(order_array_set subset, order_array_set set){
    for(int i = 0; i < subset.size; i++){
        if(binarySearch(set.data, set.size, subset.data[i]) == -1)
            return 0;
    }

    return 1;
}


void orderArraySetIsAbleAppend(order_array_set *set){
    assert(set->size < set->capacity);
}


void orderArraySetInsert(order_array_set *set, int value){
    orderArraySetIsAbleAppend(set);
    if(binarySearch(set->data, set->size, value) == -1){
        int index_insert = binarySearchMoreOrEqual(set->data, set->size, value);
        for(int i = set->size; i > index_insert; i--){
            set->data[i] = set->data[i - 1];
        }
        set->size++;
        set->data[index_insert] = value;
    }
}


void orderArraySetDeleteElement(order_array_set *set, int value){
    int index = binarySearch(set->data, set->size, value);
    if(index != -1){
        for(int i = index; i < set->size - 1; i++){
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}


order_array_set orderArraySetUnion(order_array_set set1, order_array_set set2){
    order_array_set set = orderArraySetCreate(set1.size + set2.size);
    for(int i = 0; i < set1.size; i++)
        orderArraySetInsert(&set,set1.data[i]);

    for(int i = 0; i < set2.size; i++)
        orderArraySetInsert(&set, set2.data[i]);

    return set;
}


order_array_set orderArraySetIntersection(order_array_set set1, order_array_set set2){
    order_array_set set = orderArraySetCreateFromArray(set1.data, set1.size);
    for(int i = 0; i < set.size;){
        int index_set2 = binarySearch(set2.data, set2.size, set.data[i]);
        if(index_set2 == -1)
            orderArraySetDeleteElement(&set, set.data[i]);
        else
            i++;
    }

    return set;
}


order_array_set orderArraySetDifference(order_array_set set1, order_array_set set2){
    order_array_set set = orderArraySetCreateFromArray(set1.data, set1.size);
    for(int i = 0; i < set.size; i++){
        int index_set2 = binarySearch(set2.data, set2.size, set.data[i]);
        if(index_set2 != -1)
            orderArraySetDeleteElement(&set, set.data[i--]);

    }

    return set;
}


order_array_set orderArraySetSymmetricDifference(order_array_set set1, order_array_set set2){
    order_array_set set_one = orderArraySetDifference(set1, set2);
    order_array_set set_two = orderArraySetDifference(set2, set1);
    order_array_set set = orderArraySetUnion(set_one, set_two);
    orderArraySetDelete(set_one);
    orderArraySetDelete(set_two);
    return set;
}


order_array_set orderArraySetComplement(order_array_set set, order_array_set universum_set){
    return orderArraySetUnion(set, universum_set);

}


void orderArraySetPrint(order_array_set set){
    printf("{");
    for(int i = 0; i < set.size; i++){
        if(i != set.size - 1)
            printf("%d, ", set.data[i]);
        else
            printf("%d", set.data[i]);
    }
    printf("}\n");
}





void orderArraySetDelete(order_array_set set){
    free(set.data);
}


