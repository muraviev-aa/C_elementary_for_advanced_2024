// 6. Пример использования быстрой сортировки №1

#include <stdio.h>
#include <stdlib.h>
#define COUNT(x) (sizeof(x) / sizeof(x[0]))

// функция сравнения элементов массива
// если результат вычитания равен 0, то числа равны; < 0, то x1 < x2; > 0, то x1 > x2
/*
// если хотим получить сортировку массива от MIN к MAX
int compare(const void * x1, const void * x2)
{
    return ( *(int*)x1 - *(int*)x2 );
}
*/

// если хотим получить сортировку массива от MAX к MIN
int compare(const void * x1, const void * x2)
{
    return ( -*(int*)x1 + *(int*)x2 );
}


int main()
{
    int arr[] = {-1, 1, 0, 44, 5975, -3375, 4386, 333, 234, 333};

    // указатель - имя массива, кол-во эл-ов, размер одного элемента, ф-ия сравнения двух эл-ов,
    // ф-ия изменяет содержимое массива
    // void qsort(void*, size_t, size_t, int (*)(const void*, const void*));
    qsort(arr, COUNT(arr), sizeof(int), compare);
    for (unsigned i = 0; i < COUNT(arr); i++)
        printf("%d ", arr[i]);

    return 0;
}
