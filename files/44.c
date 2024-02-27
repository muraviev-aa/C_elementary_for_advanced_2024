// 44. Чтение бинарных данных с помощью ф-ции fread() №2

#include <stdio.h>
#define NUM 6

int main()
{
    unsigned short data1[NUM] = {0};
    unsigned short data2[NUM] = {0};
    FILE * fptr;
    const char * filename = "array.dat";
    fptr = fopen(filename, "rb");
    size_t result = 0;

    // работаем поэлементно
    for(unsigned i = 0; i < NUM; i++)
    {
        result = fread(&data1[i], sizeof(data1[i]), 1, fptr);
        printf("%hu result is %zu\n", data1[i], result);
    }
    putchar('\n');

    // работаем с целым массивом
    // void rewind ( FILE * filestream );
    // устанавливает внутренний указатель положения файла
    // в начальное положение (начало файла)
    rewind(fptr);
    result = fread(data2, sizeof(data2[0]), NUM, fptr);
    for(unsigned i = 0; i < NUM; i++)
        printf("%hu\n", data2[i]);
    printf("%zu elements were read\n", result);
    fclose(fptr);

    return 0;
}
