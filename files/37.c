// 37. Считывание текстового файла используя fgetc() №2

#include <stdio.h>

int main()
{
    int ch;
    FILE * fptr;
    fptr = fopen("text.txt", "r"); // "r" режим чтения

    while((ch = fgetc(fptr)) != EOF)
        putc(ch, stdout);

    fclose(fptr);
    return 0;
}
