// 35. Запись в конец файла используя fputc()

#include <stdio.h>

int main()
{
    FILE * fptr;
    // "a" открыть файл для записи в конец файла,
    // если файла не существует, он будет создан
    fptr = fopen("text.txt", "a");
    // int fputc( int character, FILE * filestream );
    // записывает символ в поток и перемещает позицию
    // индикатора положения
    fputc('7', fptr);  // '7', как символ
    fputc(067, fptr);  // номер ASCII в 8-й системе
    fputc(55, fptr);   // номер ASCII в 10-тичной
    fputc(0x37, fptr); // номер ASCII в 16-ой системе
    fclose(fptr);
    return 0;
}
