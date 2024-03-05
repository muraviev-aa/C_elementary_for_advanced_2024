// 53. Находим текущее значение смещения внутри файла

#include <stdio.h>

int main()
{
    long value = 0;
    FILE * fptr = fopen("start.exe", "rb+");

    value = ftell(fptr); // при открытии файла указатель в 0 позиции
    printf("Value is %ld\n", value);

    fseek(fptr, 0, SEEK_END);
    value = ftell(fptr);
    printf("Value is %ld\n", value);

    fclose(fptr);

    return 0;
}
