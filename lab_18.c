/*
#include "lib/data_structures/string_/string_.h"

char string_buffer[MAX_STRING_SIZE + 1];
int buffer_size = 0;



int predicate1(int a){
    return !isspace(a);
}
void zadanie1(char *a){
/*
удалить из строки все пробельные символы.
*//*
    char *end = a + strLen(a);
    char *dest = strCopyIf(a, end, a, predicate1);
    *dest = '\0';
    printf("%s\n", a);

}


void removeAdjacentEqualLetters(char *s){
/*
Преобразовать строку, оставляя только один символ в каждой
последовательности подряд идущих одинаковых символов
*//*
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




void zadanie3(char *a){
/*
Преобразовать строку таким образом, чтобы цифры каждого слова были
перенесены в конец слова без изменения порядка следования их в слове, а
буквы – в начало.

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

}



char zadanie4(char *s){
/*
Преобразовать строку, заменяя каждую цифру соответствующим ей числом
пробелов.

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
/*
Определить, упорядочены ли лексикографически слова данного предложения.

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
/*
Вывести слова данной строки в обратном порядке по одному в строке экрана.

    WordDescriptor word;
    if(!strGetWord(sourse, &word))
        return;

    zadanie7(word.end);

    for(char *i = word.begin; i < word.end; i++)
        printf("%c", *i);
    printf("\n");
}



int zadanie8(char *sourse){
/*
В данной строке соседние слова разделены запятыми. Определить количество слов-палиндромов.

    char *ptr = sourse;
    size_t amount = 0;
    for(char *i = sourse; *i != '\0' && ptr != NULL; i++){
        if(*i == ',' || *i == '\0'){
            char *ptr_copy = ptr;
            char *i_copy = i;
            size_t is_palindrome = 1;
            while(ptr_copy > i_copy)
                if(*ptr_copy != *i_copy)
                    is_palindrome = 0;
            if(*i == '\0')
                ptr = NULL;
            else
                ptr = i + 1;
            amount += is_palindrome;
        }
    }

    return amount;
}




void zadanie9(char *str1, char *str2){
/*
Даны две строки. Получить строку, в которой чередуются слова первой и второй
строки. Если в одной из строк число слов больше, чем в другой, то оставшиеся
слова этой строки должны быть дописаны в строку-результат. В качестве
разделителя между словами используйте пробел.

    WordDescriptor word1, word2;
    int f_bool, s_bool;
    int switcher = 1;
    char *ptr1 = str1;
    char *ptr2 = str2;
    char *ptr_rec = string_buffer;
    while(f_bool = strGetWord(ptr1, &word1),
            s_bool = strGetWord(ptr2, &word2),
            f_bool || s_bool){
        if(f_bool && s_bool){
            if(switcher){
                for(char *i = word1.begin; i <= word1.end; i++, ptr_rec++)
                    *ptr_rec = *i;
                ptr1 = word1.end;
                switcher = 0;
            }else{
                for(char *i = word2.begin; i <= word2.end; i++, ptr_rec++)
                    *ptr_rec = *i;
                ptr2 = word2.end;
                switcher = 1;
            }
        }else{
            if(f_bool){
                for(char *i = word1.begin; i <= word1.end; i++, ptr_rec++)
                    *ptr_rec = *i;
                ptr1 = word1.end;
            }
            if(s_bool){
                for(char *i = word2.begin; i <= word2.end; i++, ptr_rec++)
                    *ptr_rec = *i;
                ptr2 = word2.end;
            }
        }
    }
    *ptr_rec = '\0';
    printf("%s", string_buffer);
}





void zadanie10(char *sourse){
/*
Преобразовать строку, изменив порядок следования слов в строке на обратный.

    WordDescriptor array[20];
    WordDescriptor word;
    char *ptr = sourse;
    char *ptr_buffer = string_buffer;
    int index = 0;
    while(strGetWord(ptr, &word)) {
        array[index++] = word;
        ptr = word.end;
    }
    while(index > 0){
        for(char *i = array[index].begin; i < array[index].end; i++, ptr_buffer++)
            *ptr_buffer = *i;
        index--;
        *ptr_buffer = ' ';
        ptr_buffer++;
    }
    *ptr_buffer = '\0';
    printf("%s", string_buffer);
}



void zadanie11(char *sourse){
/*
Вывести слово данной строки, предшествующее первому из слов, содержащих
букву "а". Регистр значения не имеет.

    WordDescriptor word1, word2;
    char *prt1 = sourse;
    int a = 1;
    strGetWord(sourse, &word1);
    while(strGetWord(prt1, &word2) && a){
        for(char *i = word2.begin; i < word2.end; i++){
            if(*i == 'a') {
                a = 0;
                break;
            }
        }
        if(!a) {
            break;
        }else{
            prt1 = word2.end;
            word1 = word2;
        }
    }
    for(char *i = word1.begin; i < word1.end; i++)
        printf("%c", *i);
}



void zadanie12(char *str1, char *str2){
/*
Даны две строки. Определить последнее из слов первой строки, которое есть
во второй строке.

    char string[MAX_WORD_SIZE];
    WordDescriptor word1, word2;
    while(strGetWord(str1, &word1) &&
            strGetWord(str2, &word2)){
        int is_equal = 1;
        char *j = word2.begin;
        for(char *i = word1.begin; i < word1.end; i++, j++){
            if(*i != *j){
                is_equal = 0;
                break;
            }
        }
        if(is_equal)
            wordDescriptionToString(word1, string);
        str1 = word1.end;
        str2 = word2.end;
    }
    printf("%s", string);
}





bool zadanie13(char *str){
/*
Определить, есть ли в данной строке одинаковые слова.

    WordDescriptor word1, word2;
    while(strGetWord(str, &word1)){
        char *str_copy = word1.end;
        while(strGetWord(str_copy, &word2)){
            char *j = word2.begin;
            int is_equal = 1;
            for(char *i = word1.begin; i < word1.end && j < word2.end; i++, j++){
                if(*i != *j){
                    is_equal = 0;
                    break;
                }
            }
            if(is_equal)
                return 1;
            str_copy = word2.end;
        }
        str = word1.end;
    }

    return 0;
}




bool zadanie14(char *str){
/*
Определить, есть ли в данной строке пара слов, составленных из одинакового
набора букв.

    char *buffer = string_buffer;
    for(char *i = str; *i != '\0'; i++, buffer++)
        *buffer = *i;
    *buffer = '\0';
    buffer = string_buffer;
    WordDescriptor word;
    while(strGetWord(buffer, &word)) {
        for (char *i = word.begin; i < word.end; i++) {
            char *min = i;
            for (char *j = i + 1; j < word.end; j++) {
                if (*j < *i)
                    min = j;
            }
            if (min != i) {
                char temp = *min;
                *min = *i;
                *i = temp;
            }
        }
        buffer = word.end;
    }
    return zadanie13(string_buffer);

}




void zadanie15(char *str){
/*
Получить строку из слов данной строки, которые отличны от последнего слова.

    WordDescriptor end_word;
    char *str_copy = str;
    strGetWord(str_copy, &end_word);
    while(*end_word.end != '\0'){
        str_copy = end_word.end;
        strGetWord(str_copy, &end_word);
    }
    WordDescriptor word;
    char *buff = string_buffer;
    while(strGetWord(str, &word)){
        int is_word = 1;
        for(char *i = word.begin, *j = end_word.begin; i < word.end; i++, j++){
            if(*i != *j || j > end_word.end){
                is_word = 0;
                break;
            }
        }
        if(!is_word)
            for(char *i = word.begin; i <= word.end; i++, buff++)
                *buff = *i;
        str = word.end;
    }

    printf("%s", string_buffer);
}



void zadanie16(char *str1, char *str2){
/*
Даны две строки s1 и s2. Пусть w – первое из слов строки s1, которое есть и в
строке s2. Найти слово, предшествующее первому вхождению w в s1.

    WordDescriptor w;
    char *str1_copy = str1;
    strGetWord(str1_copy, &w);
    str1_copy = w.end;
    for(WordDescriptor i; strGetWord(str1_copy, &i);){
        char *str22 = str2;
        int is_orig = 0;
        for(WordDescriptor j; strGetWord(str22, &j);){
            if(wordIsEqual(i,j)){
                is_orig = 1;
                break;
            }
            str22 = j.end;
        }
        if(is_orig)
            break;
        str1_copy = i.end;
        w = i;
    }
    *w.end = '\0';
    printf("%s", w.begin);
}




void zadanie17(char *str){
/*
Задача на удаление слов из строки (любую одну на выбор):
 Удалить из данной строки слова-палиндромы.

    WordDescriptor word;
    char *buffer = string_buffer;
    while(strGetWord(str, &word)){
        int is_palindrome = 1;
        for(char *i = word.begin, *j = word.end - 1; i < j; i++, j--){
            if(*i != *j){
                is_palindrome = 0;
                break;
            }
        }
        if(!is_palindrome){
            for(char *i = word.begin; i <= word.end; i++, buffer++){
                *buffer = *i;
            }
        }
        str = word.end;
    }

    printf("%s", string_buffer);
}



void zadanie18(char *str1, int n1, char *str2, int n2){
/*
Даны две строки. Пусть n1 – число слов в первой строке, а n2 – во второй.
Требуется дополнить строку, содержащую меньшее количество слов, последними
словами строки, в которой содержится большее количество слов.

    char *min, *max;
    if(n1 > n2){
        min = str2;
        max = str1;
        n1 = n2;
    }else{
        min = str1;
        max = str2;
    }
    char *buffer = string_buffer;
    for(WordDescriptor i; strGetWord(min, &i);){
        *i.end = ' ';
        for(char *j = i.begin; j <= i.end; j++, buffer++) {
            *buffer = *j;
        }
        min = i.end;
    }

    for(WordDescriptor i; strGetWord(max, &i); n1--){
        if(n1 <= 0){
            for(char *j = i.begin; j <= i.end; j++, buffer++)
                *buffer = *j;
        }
        max = i.end;
    }
    *buffer = '\0';
    printf("%s", string_buffer);
}




bool zadanie19(char *str, char *word){
/*
Определить, входит ли в данную строку каждая буква данного слова.

    for(char *i = str, *j = word; *j != '\0';){
        if(*i == *j){
            j++;
            i = str;
        }else if(*i != *j){
            i++;
        }
        if( *i == '\0')
            return 0;
    }
    return 1;
}






void test1(){
    printf("exercise 1 \n");
    char a[] = "H  e  ll o wo rl d  ";
    zadanie1(a);
    printf("\n");
    char b[] = "o    d    i     n";
    zadanie1(b);
    printf("\n");
    printf("=====================\n");
}
void test2(){
    printf("exercise 2 \n");
    char a[] = "aaadddssswwwrrrrrrr";
    removeAdjacentEqualLetters(a);
    printf("%s", a);
    printf("\n");
    char b[] = "oooooodddddddiiiiiinnnnnn";
    removeAdjacentEqualLetters(b);
    printf("%s", b);
    printf("\n");
    printf("=====================\n");
}
void test3(){
    printf("exercise 3 \n");
    char a[] = "hello123 123hello 1234hell privet5";
    zadanie3(a);
    printf("\n");
    char b[] = "hell111 1444lo 1254ll pri335";
    zadanie3(b);
    printf("\n");
    printf("=====================\n");
}
void test4(){
    printf("exercise 4 \n");
    char a[] = "abc3sss2s1c";
    zadanie4(a);
    printf("%s", string_buffer);
    printf("\n");
    char b[] = "o5d5i5n";
    zadanie4(b);
    printf("%s", string_buffer);
    printf("\n");
    printf("=====================\n");
}
void test5(){
    printf("exercise 5 \n");
    char a[] = "slovo ne viletit vorobei";
    char b[] = "vorobei";
    char c[] = "vorobeiiiiiiii";
    zadanie5(a, b, c);
    printf("\n");
    char q[] = "slovo ne vorobei";
    char w[] = "vorobei";
    char e[] = "vor";
    zadanie5(q, w, e);
    printf("\n");
    printf("=====================\n");
}
void test6(){
    printf("exercise 6 \n");
    char a[] = "bbb aaa ccc ddd eee fff ggg";
    printf("%d", zadanie6(a));
    printf("\n");
    char b[] = "hello world hello!";
    printf("%d", zadanie6(b));
    printf("\n");
    printf("=====================\n");
}
void test7(){
    printf("exercise 7 \n");
    char a[] = "aaa bbb ccc dedd eee";
    zadanie7(a);
    printf("\n");
    char b[] = "Gioanni is name my world hello";
    zadanie7(b);
    printf("\n");
    printf("=====================\n");
}
void test8(){
    printf("exercise 8 \n");
    char a[] = "plalp,plaalp,plall,aaaa,abcba";
    printf("%d", zadanie8(a));
    printf("\n");
    char b[] = "plalp,plaalp,pltttl,aabaa,abcba,heleh";
    printf("%d", zadanie8(b));
    printf("\n");
    printf("=====================\n");
}
void test9(){
    printf("exercise 9 \n");
    char a[] = "hello my is";
    char b[] = "world name Gioanni Petya";
    zadanie9(a,b);
    printf("\n");
    char c[] = "privet poka zdrawstvuite";
    char d[] = "Oleg Denis Petr Petya";
    zadanie9(c,d);
    printf("\n");
    printf("=====================\n");
}
void test10(){
    printf("exercise 10 \n");
    char a[] = "poka goodbue git privet";
    zadanie10(a);
    printf("\n");
    char b[] = "word hello world wolder";
    zadanie10(b);
    printf("\n");
    printf("=====================\n");
}
void test11(){
    printf("exercise 11 \n");
    char a[] = "odin fave tri chetire pat";
    zadanie11(a);
    printf("\n");
    char b[] = "hello word name is";
    zadanie11(b);
    printf("\n");
    printf("=====================\n");
}
void test12(){
    printf("exercise 12 \n");
    char str1[] = "word end start";
    char str2[] = "start end word";
    zadanie12(str1, str2);
    printf("\n");
    char str3[] = "world hello word zadanie exercive";
    char str4[] = "start end word";
    zadanie12(str3, str4);
    printf("\n");
    printf("=====================\n");
}
void test13(){
    printf("exercise 13 \n");
    char str1[] = "word is a capital of great Britain word";
    printf("%d", zadanie13(str1));
    printf("\n");
    char str2[] = "word is a capital of great Britain";
    printf("%d", zadanie13(str2));
    printf("\n");
    printf("=====================\n");
}
void test14(){
    printf("exercise 14 \n");
    char a[] = "word capital rowd";
    printf("%d",zadanie14(a));
    printf("\n");
    char b[] = "hello world oleg word";
    printf("%d",zadanie14(b));
    printf("\n");
    printf("=====================\n");
}
void test15(){
    printf("exercise 15 \n");
    char a[] = "rbegin word rend end word";
    zadanie15(a);
    printf("\n");
    char b[] = "hello world oleg guru hello";
    zadanie15(b);
    printf("\n");
    printf("=====================\n");
}
void test16(){
    printf("exercise 16 \n");
    char a[] = "pyat capital right rbegin pyat";
    char b[] = "odin dva tri chetire right tri";
    zadanie16(a,b);
    printf("\n");
    char c[] = "oleg hello word world britain";
    char d[] = "dirol hell word would";
    zadanie16(c,d);
    printf("\n");
    printf("=====================\n");
}
void test17(){
    printf("exercise 17 \n");
    char a[] = "abccba hello worow world";
    zadanie17(a);
    printf("\n");
    char b[] = "palidrome hello worow woronorow world";
    zadanie17(b);
    printf("\n");
    printf("=====================\n");
}
void test18(){
    printf("exercise 18 \n");
    char a[] = "odin dwa tri chetire pyat shest";
    int n1 = 6;
    char b[] = "open open open open open open open open sem vosem";
    int n2 = 10;
    zadanie18(a, n1, b, n2);
    printf("\n");
    char c[] = "hello world book";
    int c1 = 3;
    char d[] = "odin odin odin odin odin";
    int d2 = 5;
    zadanie18(c, c1, d, d2);
    printf("\n");
    printf("=====================\n");
}
void test19(){
    printf("exercise 19 \n");
    char a[] = "london is a capital of great britain";
    char b[] = "lord";
    printf("%d",zadanie19(a,b));
    printf("\n");
    char c[] = "london is a capital of great britain";
    char d[] = "word";
    printf("%d",zadanie19(c,d));
    printf("\n");
    printf("=====================\n");
}
void test(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
}


//int main(){
//    test();









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




    /* Zadanie 7
    char a[] = "aaa bbb ccc dedd eee";
    zadanie7(a);
    */



    /* Zadanie 8
    char a[] = "plalp,plaalp,plall,aaaa,abcba";
    printf("%d", zadanie8(a));
    */



    /* Zadanie 9
    char a[] = "privet poka zdrawstvuite";
    char b[] = "Oleg Denis Petr Petya";
    zadanie9(a,b);
    */



    /* Zadanie 10
    char a[] = "poka goodbue git privet";
    zadanie10(a);
     */




    /* Zadanie 11
    char a[] = "odin fave tri chetire pat";
    zadanie11(a);
    */



    /* Zadanie 12
    char str1[] = "word end start";
    char str2[] = "start end word";
    zadanie12(str1, str2);
    */



    /* Zadanie 13
    char str1[] = "word is a capital of great Britain word";
    printf("%d", zadanie13(str1));
    */




    /* Zadanie 14
    char a[] = "word capital rowd";
    printf("%d",zadanie14(a));
    */




    /* Zadanie 15
    char a[] = "rbegin word rend end word";
    zadanie15(a);
    */


    /* Zadanie 16
    char a[] = "pyat capital right rbegin pyat";
    char b[] = "odin dva tri chetire right tri";
    zadanie16(a,b);
    */



    /* Zadanie 17
    char a[] = "abccba hello worow world";
    zadanie17(a);
    */



    /* Zadanie 18
    char a[] = "odin dwa tri chetire pyat shest";
    int n1 = 6;
    char b[] = "open open open open open open open open sem vosem";
    int n2 = 10;
    zadanie18(a, n1, b, n2);
    */



    /* Zadanie 19
    char a[] = "london is a capital of great britain";
    char b[] = "lord";
    printf("%d",zadanie19(a,b));
    */

//}
