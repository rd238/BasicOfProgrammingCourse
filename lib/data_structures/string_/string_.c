#include "string_.h"


int strLen(char *str){
    char *copy = str;
    while(*copy != '\0')
        copy++;
    return copy - str;
}


char* strFind(char *begin, char *end, int ch){
    while(begin != end && *begin != ch)
        begin++;
    return begin;
}


char* strFindNonSpace(char *begin){
    while(*begin != '\0' && isspace(*begin))
        begin++;
    return begin;
}


char* strFindSpace(char *begin){
    while(*begin != '\0' && !isspace(*begin))
        begin++;
    return begin;
}


char* strFindNonSpaceReverse(char *rbegin, const char *rend){
    while(rbegin != rend && isspace(*rbegin))
        rbegin--;
    return rbegin;
}


char* strFindSpaceReverse(char *rbegin, const char *rend){
    while(rbegin != rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}


int strCmp(const char *lhs, const char *rhs){
    while(*lhs && *rhs && *lhs == *rhs)
        lhs++, rhs++;
    return *lhs - *rhs;
}


char* strCopy(const char *beginSource, const char *endSource, char *beginDestination){
    while(beginSource != endSource) {
        *beginDestination = *beginSource;
        beginDestination++;
        beginSource++;
    }
    return beginDestination;
}


char* strCopyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)){
    while(beginSource != endSource) {
        if(f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}


char* strCopyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){
    while(rbeginSource != rendSource) {
        if(f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}