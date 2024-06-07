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





typedef struct{
    int coefficient;
    int degree;
} polynomial;



void zadanie6(int x){
/*
В бинарном файле структур хранятся многочлены в порядке
убывания степеней. Каждая структура содержит два поля: показатель
степени члена и коэффициент. Члены с нулевыми коэффициентами
не хранятся. Свободный член присутствует обязательно, даже если он
равен нулю. Удалить из файла многочлены, для которых данное x
является корнем.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie6.txt", "rb");
    FILE *filew = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie6_result.txt", "wb");
    while(!feof(file)){
        polynomial poly;
        int sum = 0;
        polynomial a[10];
        int size_a = 0;
        while(fread(&poly, sizeof(poly), 1, file)){
            a[size_a++] = poly;
            int b = poly.degree;
            while(poly.degree--)
                sum += x * x;
            sum *= poly.coefficient;
            if(!b)
                break;
        }
        if(sum == 0){
            for(int i = 0; i < size_a; i++){
                fwrite(&a[i], sizeof(a[i]), 1, filew);
            }
        }
    }
    fclose(file);
    fclose(filew);
}






void zadanie7(){
/*
Дан бинарный файл целых чисел. Нулевых компонент в файле нет.
Число отрицательных компонент равно числу положительных.
Преобразовать файл таким образом, чтобы сначала были
положительные числа, а затем отрицательные. Порядок следования
как положительных, так и отрицательных чисел сохранить.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie7.txt", "rb");
    FILE *filew = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie7_result.txt", "wb");
    int plus[100];
    int size_plus = 0;
    int minus[100];
    int size_minus = 0;
    while(!feof(file)){
        int digit;
        fread(&digit, sizeof(digit), 1, file);
        if(digit >= 0)
            plus[size_plus++] = digit;
        else
            minus[size_minus++] = digit;
    }
    for(int i = 0; i < size_plus; i++)
        fwrite(&plus[i], sizeof(plus[i]), 1, filew);
    for(int i = 0; i < size_minus; i++)
        fwrite(&minus[i], sizeof(minus[i]), 1, filew);
    fclose(file);
    fclose(filew);
}





void zadanie8(){
/*
Дан бинарный файл квадратных матриц порядка n. Преобразовать
его, заменив каждую матрицу, не являющуюся симметричной,
транспонированной.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie8.txt", "rb");
    FILE *filew = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie8_result.txt", "wb");
    int size;
    fread(&size, sizeof(size), 1, file);
    while(!feof(file)) {
        matrix m = matrixGetMem(size, size);
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                fread(&m.values[i][j], sizeof(m.values[i][j]), 1, file);
        if(!matrixIsSymmetric(&m)){
            matrixTransposeSquare(&m);
        }
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                fwrite(&m.values[i][j], sizeof(m.values[i][j]), 1, filew);
        matrixOutput(m);
        matrixFreeMem(&m);
    }
    fclose(file);
    fclose(filew);
}




typedef struct{
    char *name;
    int result;
} sportsmen;


void zadanie9(int n){
/*
В бинарном файле структур хранится информация о спортсменах:
Ф.И.О., наилучший результат. Требуется сформировать команду из n
лучших спортсменов. Преобразовать файл, сохранив в нем
информацию только о членах команды.
*/
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie9.txt", "rb");
    FILE *filew = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie9_result.txt", "wb");
    sportsmen a[20];
    int size_a = 0;
    while(!feof(file)){
        sportsmen b;
        fread(&b, sizeof(b), 1, file);
        a[size_a++] = b;
    }
    for(int i = 0; i < size_a - 1; i++){
        int min = i;
        for(int j = i; j < size_a; j++){
            if(a[i].result < a[j].result)
                min = j;
        }
        if(min != i){
            sportsmen temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    for(int i = 0; i < n; i++){
        fwrite(&a[i], sizeof(a[i]), 1, filew);
        printf("name:%s score:%d\n", a[i].name, a[i].result);
    }
    fclose(file);
    fclose(filew);
}




typedef struct{
    char *name;
    int price_one;
    int price_all;
    int amount;
} stock_product;

typedef struct{
    char *name;
    int amount;
} order_product;

void zadanie10(){
/*
В бинарном файле f структур хранится следующая информация о
товарах, имеющихся на складе: наименование товара, цена единицы
товара, общая стоимость и количество. В бинарном файле структур g
хранится информация о заказах: наименование товара и его
количество. Обновить файл f с учетом отпущенных товаров в
соответствии с заказами из файла g. Если товар отпущен полностью,
запись о нем из файла f удаляется.
*/
    FILE *file_f = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie10f.txt", "rb");
    FILE *file_g = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie10g.txt", "rb");
    FILE *filew = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie10_result.txt", "wb");
    stock_product a[20];
    int size_a = 0;
    order_product b[20];
    int size_b = 0;
    while(!feof(file_f)){
        stock_product product;
        fread(&product, sizeof(product), 1, file_f);
        a[size_a++] = product;
    }
    while(!feof(file_g)){
        order_product product;
        fread(&product, sizeof(product), 1, file_g);
        b[size_b++] = product;
    }
    for(int i = 0; i < size_a; i++){
        for(int j = 0; j < size_b; j++){
            if(a[i].name == b[j].name){
                a[i].amount -= b[j].amount;
            }
        }
        if(a[i].amount > 0)
            fwrite(&a[i], sizeof(a[i]), 1, filew);
    }
    fclose(file_f);
    fclose(file_g);
    fclose(filew);
}



/*
int main(){

    /* Zadanie 6
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie6.txt", "wb");
    for(int i = 0; i < 5; i++){
        for(int j = 3; j >= 0; j--){
            polynomial a = {i + 1, j};
            fwrite(&a, sizeof(a), 1, file);
        }
    }
    fclose(file);
    */

    /* Zadanie 7
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie7.txt", "wb");
    for(int i = 0; i < 100; i++){
        if(i % 2) {
            fwrite(&i, sizeof(i), 1, file);
        }else {
            int j = -i;
            fwrite(&j, sizeof(j), 1, file);
        }
    }
    fclose(file);
    zadanie7();
    file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie7_result.txt", "rb");
    while(!feof(file)){
        int digit;
        fread(&digit, sizeof(digit), 1, file);
        printf("%d ", digit);
    }
    fclose(file);
     */

    /* zadanie 8
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie8.txt", "wb");
    int size = 3;
    fwrite(&size,sizeof(int), 1, file);
    for(int q = 0; q < 10; q++){
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                fwrite(&i,sizeof(int), 1, file);
    }
    fclose(file);
    zadanie8();
    */


    /*
    FILE *file = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie9.txt", "wb");
    for(int i = 0; i < 6; i++){
        sportsmen b = {"noname", i * 5};
        fwrite(&b, sizeof(b), 1, file);
    }
    fclose(file);

    zadanie9(4);



    FILE *file_f = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie10f.txt", "wb");
    FILE *file_g = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie10g.txt", "wb");
    stock_product a1 = {"product1", 100, 5000, 50};
    stock_product a2 = {"product2", 10, 300, 30};
    stock_product a3 = {"product3", 50, 5000, 100};
    stock_product a4 = {"product4", 100, 5000, 50};
    stock_product a5 = {"product5", 23, 2300, 100};
    fwrite(&a1, sizeof(a1), 1, file_f);
    fwrite(&a2, sizeof(a2), 1, file_f);
    fwrite(&a3, sizeof(a3), 1, file_f);
    fwrite(&a4, sizeof(a4), 1, file_f);
    fwrite(&a5, sizeof(a5), 1, file_f);
    order_product b1 = {"product1", 50};
    order_product b2 = {"product3", 90};
    order_product b3 = {"product5", 100};
    fwrite(&b1, sizeof(b1), 1, file_g);
    fwrite(&b2, sizeof(b2), 1, file_g);
    fwrite(&b3, sizeof(b3), 1, file_g);
    fclose(file_f);
    fclose(file_g);

    zadanie10();

    FILE *filew = fopen("D:\\CLion 2023.3.4\\Projects\\text\\zadanie10_result.txt", "rb");
    while(!feof(filew)){
        stock_product a;
        fread(&a, sizeof(a), 1, filew);
        printf("name:%s price:%d amount:%d\n", a.name, a.price_one, a.amount);
    }
    fclose(filew);


}
*/