// 31. Создание файла. Версия 2

#include <stdio.h>
#include <stdlib.h> // для exit()

int main()
{
    FILE * fptr;

    // связали указатель с созданным файлом
    // режим записи "w"
    fptr = fopen("text.txt", "w");
    // проверили, что указатель создан
    if(fptr == NULL)
    {
        puts("Unable to create a file. Exit...");
        exit(1);
    }
    else
        puts("File is created in \"write\" mode");

    // проверяем, что закрыли файл
    if(fclose(fptr) == 0)
        puts("File is closed. Exit...");
    else
        puts("Unable to close a file");
    return 0;
}
