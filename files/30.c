// 30. Создание файла. Версия 1

#include <stdio.h>

int main()
{
    // указатель на файл
    FILE * fptr;

    // связали указатель с файлом
    // w - режим записи
    fptr = fopen("text.txt", "w");

    // закрыли файл
    fclose(fptr);

    return 0;
}
