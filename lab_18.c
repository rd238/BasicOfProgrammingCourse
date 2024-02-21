#include "lib/data_structures/string_/string_.h"



int predicate1(int a){
    return !isspace(a);
}
void zadanie1(){
/*
удалить из строки все пробельные символы.
*/
    char a[] = "Hello world  ";
    char *end = a + strLen(a);
    char *dest = strCopyIf(a, end, a, predicate1);
    *dest = '\0';
    printf("%s\n", a);

}





int main(){
    zadanie1();
}