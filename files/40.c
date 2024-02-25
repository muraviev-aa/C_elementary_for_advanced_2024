// 40. Считывание текстового файла ф-цией fgets() по абсолютному пути
// с использованием макроса feof()

#include <stdio.h>

int main()
{
    char ch[100];
    FILE * fptr;
    fptr = fopen("E:\\ITMO\\C\\text.txt", "r");

    while(feof(fptr) == 0)
    {
        fgets(ch, 100, fptr);
        fputs(ch, stdout);
    }

    fclose(fptr);

    return 0;
}
