// 39. Используем макрос feof() для фиксации конца файла

#include <stdio.h>

int main()
{
    int ch;
    FILE * fptr;
    // "r" режим чтения
    fptr = fopen("E:\\ITMO\\C\\text.txt", "r");
    printf("feof(fptr) = %d\n", feof(fptr));

    // feof() != 0 если достигнут конец файла
    // т.е. указатель внутри файла вышел за его пределы
    while(feof(fptr) == 0)
    {
        ch = fgetc(fptr);
        putc(ch, stdout);
    }

    printf("\nfeof(fptr) = %d\n", feof(fptr));

    return 0;
}
