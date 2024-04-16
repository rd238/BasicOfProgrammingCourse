#include "lib/data_structures/string_/string_.h"

char string_buffer[MAX_STRING_SIZE + 1];
int buffer_size = 0;



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





char zadanie4(char *s){
/*
Преобразовать строку, заменяя каждую цифру соответствующим ей числом
пробелов.
*/
    unsigned int size = strLen(s);
    char *i = s;
    while(*i != '\0'){
        if(isdigit(*i)){
            int j = *i - '0';
            while(j--)
                string_buffer[buffer_size++] = ' ';
        }else{
            string_buffer[buffer_size++] = *i;
        }
        i++;
    }
    string_buffer[buffer_size++] = '\0';
}



void zadanie5(char *sourse, char *w1, char *w2){
/*
Заменить все вхождения слова w1 на слово w2.
 */
    size_t w1_len = strLen(w1);
    size_t w2_len = strLen(w2);
    WordDescriptor word_w1 = {w1, w1 + w1_len};
    WordDescriptor word_w2 = {w2, w2 + w2_len};

    char *read_ptr = sourse;
    char *rec_ptr = string_buffer;
    WordDescriptor word_read;

    while(strGetWord(read_ptr, &word_read)){
        size_t is_equal = 1;
        char *j = word_w1.begin;
        for(char *i = word_read.begin; i < word_read.end; i++, j++){
            if(*i != *j || j > word_w1.end) {
                is_equal = 0;
                break;
            }
        }
        if(is_equal){
            for(char *i = word_w2.begin; i <= word_w2.end; i++, rec_ptr++)
                *rec_ptr = *i;
            read_ptr += word_w1.end - word_w1.begin;
        }else{
            for(char *i = word_read.begin; i <= word_read.end; i++, rec_ptr++, read_ptr++)
                *rec_ptr = *i;
        }
    }
    *rec_ptr = '\0';
    printf("%s", string_buffer);
}




bool zadanie6(char *sourse){
    WordDescriptor word1, word2;
    strGetWord(sourse, &word1);
    while(strGetWord(word1.end, &word2)){
        int difference = 0;
        for(char *i = word1.begin; i < word1.end; i++)
            difference += *i;
        for(char *i = word2.begin; i < word2.end; i++)
            difference -= *i;
        if(difference <= 0) {
            word1 = word2;
        }else {
            return 0;
        }
    }
    return 1;
}




void zadanie7(char *sourse){
    WordDescriptor word;
    if(!strGetWord(sourse, &word))
        return;

    zadanie7(word.end);

    for(char *i = word.begin; i < word.end; i++)
        printf("%c", *i);
    printf("\n");
}

int main(){
    //zadanie1();



    //zadanie 2
    //char a[] = "aaadddssswwwrrrrrrr";
    //removeAdjacentEqualLetters(a);
    //printf("%s", a);





    /*  zadanie 3
     * Преобразовать строку таким образом, чтобы цифры каждого слова были
        перенесены в конец слова без изменения порядка следования их в слове, а
        буквы – в начало.
    char a[] = "hello123 123hello 1234hell privet5";
    WordDescriptor word;
    char *aa = a;
    while(strGetWord(aa, &word)){
        aa = word.end;
        char *end = word.end - 1;
        for(char *i = word.begin; i < word.end; i++){
            if(isdigit(*i) && i <= end){
                char copy = *end;
                *end = *i;
                *i = copy;
                end--;
            }
            printf("%c", *i);
        }
        printf("\n");
    }

    printf("%s", a);
    */




    /*Zadanie 4
    char a[] = "abc3sss2s1c";
    zadanie4(a);
    printf("%s", string_buffer);
    */



    /* Zadanie 5
    char a[] = "slovo ne viletit vorobei";
    char b[] = "vorobei";
    char c[] = "vorobeiiiiiiii";
    zadanie5(a, b, c);
    */




    /* Zadanie 6
    char a[] = "bbb aaa ccc ddd eee fff ggg";
    printf("%d", zadanie6(a));
    */


    char a[] = "aaa bbb ccc dedd eee";
    zadanie7(a);


}