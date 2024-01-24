// 11. Пишем свою функцию на основе malloc() №2

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NUM 20000

void * myMalloc(size_t count)
{
    void * ptr;
    ptr = malloc(count);

    if(ptr == 0)
    {
        puts("Error! NULL pointer!");
        perror("Error");
        // далее можно вставить код, который запишет данные
        // этой ошибки в лог файл, запустит какую-то ф-цию
        exit(1);
    }
    else
        printf("%u byte is alloced!\n", count);
        return ptr;

}

int main()
{
    int * p1;
    p1 = (int*) myMalloc(NUM);

    p1[10] = 5;
    printf("Address is %u, value is %d\n", &p1[10], p1[10]); // нотация массивов
    printf("Address is %u, value is %d\n", p1+10, *(p1+10)); // нотация указателей
    system("pause");
    free(p1);

    return 0;
}
