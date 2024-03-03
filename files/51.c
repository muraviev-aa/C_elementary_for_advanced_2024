// 51. Работаем с функцией fseek()

#include <stdio.h>

// int fseek( FILE * filestream, long int offset, int origin );
// перемещает указатель позиции в потоке
// параметр origin:
// SEEK_SET начало файла
// SEEK_CUR текущее положение файла
// SEEK_END конец файла

int main()
{
    FILE * fptr;
    fptr = fopen("simple.txt", "w+b");

    fseek(fptr, -10, SEEK_CUR); // смещение на -10 не произойдет, т.к. указатель в начале файла
    fprintf(fptr, "%ld", ftell(fptr));

    fseek(fptr, 20, SEEK_CUR);
    fprintf(fptr, "%ld", ftell(fptr));

    fseek(fptr, 0, SEEK_END);
    fputs("END", fptr);

    return 0;
}
