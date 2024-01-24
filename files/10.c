// 10. Пишем свою функцию на основе malloc() №1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NUM 1000000

int * intMalloc(int * ptr, unsigned count)
{
    ptr = (int*) malloc(NUM * sizeof(int));
    if(ptr == 0)
    {
        puts("Error! NULL pointer!");
        perror("Error");
        // далее можно вставить код, который запишет данные
        // этой ошибки в лог файл, запустит какую-то ф-цию
        exit(1);
    }
    else
    {
        printf("%u byte is alloced!\n", NUM * sizeof(int));
        return ptr;
    }
}

int main()
{
    int * p1;
    p1 = intMalloc(p1, NUM);

    p1[10] = 100;
    printf("Address is %u, value is %d\n", &p1[10], p1[10]); // нотация массива
    printf("Address is %u, value is %d\n", p1+10, *(p1+10)); // нотация указателя
    system("pause");
    free(p1);
    return 0;
}

