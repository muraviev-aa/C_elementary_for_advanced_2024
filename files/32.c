// 32. Создание файла. Версия 3

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE * myFopen(const char * name, const char * mode)
{
    FILE * fptr;
    fptr = fopen(name, mode);
    if(fptr == NULL)
    {
        printf("fopen with %s file in \"%s\" mode is BREAK\n", name, mode);
        puts("Press any key to exit...");
        getch(); // считывает символ их входного потока, но не выводит на экран
        exit(1);
    }
    else
        printf("fopen with %s file in \"%s\" mode is DONE\n", name, mode);
    return fptr;
}

void myFclose(FILE * fptr)
{
    if(fclose(fptr)== 0)
        puts("File is closed. Exit...");
    else
    {
        puts("Unable to close a file. Press any key to exit...");
        getch();
        exit(1);
    }
}

int main()
{
    FILE * FILEptr;
    FILEptr = myFopen("text.txt", "w");
    myFclose(FILEptr);
    return 0;
}
