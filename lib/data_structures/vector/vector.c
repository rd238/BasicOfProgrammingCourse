#include "vector.h"


/*
Требования к реализации:
– Пользователь должен иметь возможность создавать вектор размера 0.
– Если операционная система не может предоставить нужный объем памяти
под размещение динамического массива, программа должна выводить
сообщение в поток ошибок и заканчиваться с кодом 1:
fprintf(stderr, "bad alloc");
exit(1);
 */
vector vectorCreate(size_t n){
    int *a = malloc(sizeof(int) * n);
    if(a != NULL) {
        return (vector) {a, 0, n};
    }else{
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}


/*
– Если в качестве newCapacity указано значение 0, в data должен быть
записан NULL.
– Если значение newCapacity стало меньше size, тогда значение size
должно равняться newCapacity
 – Если ОС не смогла выделить необходимый фрагмент памяти, вывести
сообщение в поток ошибок и прервать выполнение программы.
 */
void vectorReserve(vector *v, size_t newCapacity){
    if(newCapacity != v->capacity){
        if(newCapacity == 0) {
            v->data = NULL;
        }else {
            int *a = (int*)malloc(sizeof(int) * newCapacity);
            if(a != NULL){
                if(v->size >= newCapacity){
                    for(int i = 0; i < newCapacity; i++)
                        a[i] = v->data[i];
                    free(v->data);
                    v->size = newCapacity;
                    v->capacity = newCapacity;
                    v->data = a;
                }else{
                    for(int i = 0; i < v->size; i++)
                        a[i] = v->data[i];
                    free(v->data);
                    v->capacity = newCapacity;
                    v->data = a;
                }
            }else{
                fprintf(stderr, "bad alloc");
                exit(1);
            }
        }
    }
}


void vectorClear(vector *v){
    v->size = 0;
}


void vectorShrinkToFit(vector *v){
    vectorReserve(v,v->size);
}


void vectorDelete(vector *v){
    free(v->data);
}
