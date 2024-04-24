#include <stdio.h>
#include <stdlib.h>
#include "lib/data_structures/matrix/matrix.h"
#include "lib/data_structures/string_/string_.h"


void zadanie1(){
/*
В текстовом файле хранятся целочисленные квадратные матрицы
следующим образом: сначала целое число n – порядок матрицы, а
затем ее элементы по строкам. Преобразовать файл так, чтобы
элементы матрицы хранились по столбцам.
*/
    FILE *file_read = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie1.txt", "r");
    FILE *file_write = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie1_result.txt", "w");
    while(!feof(file_read)){
        int size;
        fscanf(file_read, "%d\n", &size);
        matrix m = matrixGetMem(size, size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                fscanf(file_read, "%d ", &m.values[i][j]);
            }
        }
        matrixTransposeSquare(&m);
        fprintf(file_write, "%d\n", size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(j < size - 1)
                    fprintf(file_write, "%d ", m.values[i][j]);
                else
                    fprintf(file_write, "%d\n", m.values[i][j]);
            }
        }
        matrixFreeMem(&m);
    }
    fclose(file_read);
    fclose(file_write);

}



void zadanie2(){
/*
В текстовом файле записаны вещественные числа в форме с
фиксированной точкой. Преобразовать файл, представив каждое
число в форме с плавающей точкой, сохранив две цифры после точки
в мантиссе.
*/
    FILE *file_read = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie2.txt", "r");
    FILE *file_write = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie2_result.txt",
                             "w");
    while(!feof(file_read)){
        float digit;
        fscanf(file_read, "%f ", &digit);
        fprintf(file_write, "%.2f ", digit);
    }
    fclose(file_read);
    fclose(file_write);
}






int operation(int a, int b, char op){
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else if(op == '*')
        return a * b;
    else if(op == '/')
        return a / b;
}
void zadanie3(){
/*
Дан текстовый файл, представляющий собой запись
арифметического выражения, операндами которого являются
однозначные числа. Число операций в выражении не больше двух.
Вычислить значение этого выражения и дописать его в конец этого
файла.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie3.txt", "r");
    int buf[5];
    int size_buf = 0;
    char buf_[2];
    int size_buf_ = 0;
    int a = 0;
    while(!feof(file)){
        if(a % 2 == 0)
            fscanf(file, "%d ", &buf[size_buf++]);
        else
            fscanf(file, "%c ", &buf_[size_buf_++]);
        a++;
    }
    fclose(file);
    file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie3.txt", "a");
    if(size_buf_ > 1){
        int result = 0;
        if((buf_[1] == '*' || buf_[1] == '/') &&
            buf_[0] != '*' && buf_[0] != '/'){
            result = operation(buf[1], buf[2], buf_[1]);
            result = operation(buf[0], result, buf_[0]);
        }else{
            result += operation(buf[0], buf[1], buf_[0]);
            result = operation(result, buf[2], buf_[1]);
        }
        fprintf(file, " = %d", result);
    }else{
        fprintf(file, " = %d", operation(buf[0], buf[1], buf_[0]));
    }


    fclose(file);
}



void zadanie4(char *sub){
/*
Дан текстовый файл. Сохранить в файле только те слова, которые
содержат данную последовательность символов.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie4.txt", "r");
    char a[100];
    fgets(a, 100, file);
    fclose(file);
    file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie4_result.txt", "w");
    WordDescriptor word;
    char *ptr = a;
    while(strGetWord(ptr, &word)){
        int is_true = 1;
        for(char *i = sub; i < sub + strLen(sub); i++){
            int is_finded = 0;
            for(char *j = word.begin; j < word.end; j++){
                if(*j == *i){
                    is_finded = 1;
                    break;
                }
            }
            if(!is_finded) {
                is_true = 0;
                break;
            }
        }
        if(is_true){
            for(char *i = word.begin; i < word.end; i++)
                fputc(*i, file);
            fputc(' ', file);
        }
        ptr = word.end;
    }
    fclose(file);
}





void zadanie5(){
/*
Дан текстовый файл. Преобразовать его, оставив в каждой строке
только самое длинное слово.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie5.txt", "r");
    FILE *file_res = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie5_result.txt", "w");
    while(!feof(file)){
        char str[100];
        fgets(str, 99, file);
        long long max = 0;
        char max_str[30];
        WordDescriptor word;
        char *ptr = str;
        while(strGetWord(ptr, &word)){
            if(word.end - word.begin > max){
                wordDescriptionToString(word, max_str);
                max = word.end - word.begin;
            }
            ptr = word.end;
        }
        fputs(max_str, file_res);
        fputs("\n", file_res);
    }
    fclose(file);
    fclose(file_res);
}
int main(){
    zadanie5();
}
