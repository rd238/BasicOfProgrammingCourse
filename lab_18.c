#include "lib/data_structures/string_/string_.h"



int predicate1(int a){
    return !isspace(a);
}
void zadanie1(){
/*
удалить из строки все пробельные символы.
*/
    char a[] = "H  e  ll o wo rl d  ";
    char *end = a + strLen(a);
    char *dest = strCopyIf(a, end, a, predicate1);
    *dest = '\0';
    printf("%s\n", a);

}


void removeAdjacentEqualLetters(char *s){
/*
Преобразовать строку, оставляя только один символ в каждой
последовательности подряд идущих одинаковых символов
*/
    char *snext = s + 1;
    char *sfirst = s;
    char *sfirst2 = s - 1;
    while(*snext != '\0'){
        if(*sfirst2 != *snext){
            *sfirst2 = *snext;
            *sfirst = *snext;
            sfirst++;
        }
        snext++;
    }
    *sfirst = '\0';
}


int main(){
    //zadanie1();


    //char a[] = "aaadddssswwwrrrrrrr";
    //removeAdjacentEqualLetters(a);
    //printf("%s", a);


    char a[] = "hello123 123hello h1e2ll3o privet5";
    WordDescriptor word;
    char *aa = a;
    while(strGetWord(aa, &word)){
        aa = word.end;
        for(char *i = word.begin; i < word.end; i++){
            printf("%c", *i);
        }
        printf("\n");
    }


}