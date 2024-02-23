// 36. Считывание текстового файла используя fgetc() №1

#include <stdio.h>
#include <conio.h>

int main()
{
    int ch;
    FILE * fptr;
    fptr = fopen("text.txt", "r"); // r - режим чтения

    // int fgetc( FILE * filestream );
    // возвращает символ на который ссылается внутренний индикатор
    // позиции файла указанного потока
    ch = fgetc(fptr);

    // int putc( int character, FILE * filestream );
    // помещает символ в поток и перемещает позицию индикатора текущего положения.
    putc(ch, stdout);
    getch();

    // после первого вызова fgetc() внутренний указатель
    // в файле передвинется на 1 вперед из 0 в 1
    ch = fgetc(fptr);
    putc(ch, stdout);
    fclose(fptr);

    return 0;
}
