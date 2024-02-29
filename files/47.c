// 47. Читаем исполняемый файл нашей программы в текстовом режиме
// argc - кол-во аргументов
// char * argv[] - массив строк с самими аргументами
// argv[0] - полное имя файла программы, включая путь
#include <stdio.h>

int main(int argc, char * argv[])
{
    int ch;
    FILE * fptr;
    fptr = fopen(argv[0], "r");

    while(feof(fptr) == 0)
    {
        ch = fgetc(fptr);
        putc(ch, stdout);
    }

    fclose(fptr);
}
