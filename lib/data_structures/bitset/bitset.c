#include <stdio.h>
#include "bitset.h"


/*
typedef struct bitset {
    uint32_t value; // множество
    uint32_t maxValue; // Максимальный элемент
} bitset;
 */

bitset bitsetCreate(unsigned max_value){
    return (bitset){0, max_value};
}


bool bitsetIn(bitset set, unsigned int value){
    return set.value & 1 << value;
}


bool bitsetIsEqual(bitset set1, bitset set2){
    return set1.value == set2.value;
}


bool bitsetIsSubset(bitset subset, bitset set){
    return (subset.value & set.value) == subset.value;
}


void bitsetInsert(bitset *set, unsigned int value){
    set->value |= (1 << value);
}


void bitsetDeleteElement(bitset *set, unsigned int value){
    if(set->value & 1 << value)
        set->value ^= 1 << value;
}


bitset bitsetUnion(bitset set1, bitset set2){
    return (bitset){set1.value | set2.value, set1.maxValue};
}


bitset bitsetIntersection(bitset set1, bitset set2){
    return (bitset){set1.value & set2.value, set1.maxValue};
}


bitset bitsetDifference(bitset set1, bitset set2){
    return (bitset){set1.value & ~ set2.value, set1.maxValue};
}


bitset bitsetSymmerticDifference(bitset set1, bitset set2){
    return (bitset){set1.value ^ set2.value, set1.maxValue};
}


bitset bitsetComplement(bitset set){
    unsigned int n = 32 - set.maxValue;
    return (bitset){(~(uint32_t)0 << n) >> n, set.maxValue};
}


void bitsetPrint(bitset set) {
    printf("{");
    for (int i = 0; i < set.maxValue; i++) {
        if (set.value & 1 << i)
            if (!(i == set.maxValue - 1))
                printf("%d, ", i + 1);
            else
                printf("%d", i + 1);
    }
        printf("}\n");
}






















