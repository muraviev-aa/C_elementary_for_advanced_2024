// 33. Создание файла. Версия 4;
// Создал собственную ф-ию myWfopen() для создания пустого файла для записи (режим "w")

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ф-ия создания пустого файла для записи
FILE * myWfopen(const char * name)
{
    FILE * fptr;
    fptr = fopen(name, "w");
    if(fptr == NULL)
    {
        printf("fopen with %s file in \"%w\" mode is BREAK\n", name);
        puts("Press any key to exit...");
        getch(); // считывает символ из входного потока, но не выводит на экран
        exit(1);
    }
    else
        printf("fopen with %s file in \"w\" mode is DONE\n", name);
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
    FILEptr = myWfopen("text.txt");
    myFclose(FILEptr);
    return 0;
}
