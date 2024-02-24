// 38. Считывание текстового файла по абсолютному пути

#include <stdio.h>

int main()
{
    int ch;
    FILE * fptr;
    // "r" режим чтения
    fptr = fopen("E:\\ITMO\\C\\text.txt", "r");
    // EOF End Of File
    while((ch = fgetc(fptr)) != EOF)
        putc(ch, stdout);

    fclose(fptr);

    return 0;
}
