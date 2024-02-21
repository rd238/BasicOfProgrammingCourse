#include "string_.h"


int strLen(char *str){
    char *copy = str;
    while(*copy != '\0')
        copy++;
    return copy - str;
}


