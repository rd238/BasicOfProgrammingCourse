#ifndef EDUCATIONPROJECT_STRING__H
#define EDUCATIONPROJECT_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 1000
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20





//Возвращает длинну строки str.
int strLen(char *str);


//Возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end. Если символ не найден, возвращается значение end.
char* strFind(char *begin, char *end, int ch);


//Возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с begin и заканчивая ноль-символом. Если символ не найден,
//возвращается адрес первого ноль-символа.
char* strFindNonSpace(char *begin);


//Возвращает указатель на первый пробельный символ,
//расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.
char* strFindSpace(char *begin);


//Возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (последний символ строки, за которым следует ноль-символ)
//и заканчивая rend (адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char* strFindNonSpaceReverse(char *rbegin, const char *rend);


//Возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
//начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char* strFindSpaceReverse(char *rbegin, const char *rend);


//Функция возвращает отрицательное значение, если lhs располагается до rhs
//в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
//равны, иначе – положительное значение.
int strCmp(const char *lhs, const char *rhs);


//Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination.
//По окончанию работы функции ноль-символ не записывается.
char* strCopy(const char *beginSource, const char *endSource, char *beginDestination);


//Записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f.
//Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
//По окончанию работы функции ноль-символ не записывается.
char* strCopyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));


//Записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f.
//Функция возвращает значение beginDestination по окончанию работы функции.
//По окончанию работы функции ноль-символ не записывается.
char* strCopyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));




typedef struct WordDescriptor {
    char *begin;        // позиция начала слова
    char *end;          // позиция первого символа, после последнего символа слова
} WordDescriptor;


//Записывает слово в word начиная с beginSearch
//Возвращает 1 при успешном считывании
int strGetWord(char *beginSearch, WordDescriptor *word);


//Записывает слово в word с конца строки rbegin и до начала rend
//Возвращает 1 при успешном считывании
bool strGetWordReverse(char *rbegin, char *rend, WordDescriptor *word);


//Преобразует слово word в строку string
void wordDescriptionToString(WordDescriptor word, char *string);


//Сравнивает word1 и word2.
bool wordIsEqual(WordDescriptor word1, WordDescriptor word2);





#endif //EDUCATIONPROJECT_STRING__H
