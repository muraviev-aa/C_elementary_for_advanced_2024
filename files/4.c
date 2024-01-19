// 4. Передача массива в функцию
#include <stdio.h>
// макрос для нахождения кол-ва элементов в массиве
// вместо х будет подставлено имя массива
#define COUNT(x) (sizeof(x)/sizeof(x[0]))

void printArray(int * array, size_t num)
{
    for(unsigned i = 0; i < num; i++)
        //printf("%d ", *(array+i)); // нотация указателей
        printf("%d ", array[i]); // нотация массивов
}

void incArray(int * array, unsigned num)
{
    for(unsigned i = 0; i < num; i++)
        (*(array+i))++; // нотация указателей
        //array[i]++; // нотация массивов
}

int main()
{
    int myArr[] = {10, 20, 30, 40, 50};
    printArray(myArr, COUNT(myArr));
    incArray(myArr, COUNT(myArr));
    putchar('\n');
    printArray(myArr, COUNT(myArr));

    return 0;
}
