// 34. Запись в файл используя функцию fprintf()

#include <stdio.h>

int main()
{
    int num = 2;
    char * str = "Hello, ";

    FILE * fptr;
    fptr = fopen("text.txt", "w");

    // int fprintf(FILE *, const char *, ...)
    // выполняет форматированный вывод в поток
    fprintf(fptr, "%s%d", str, num);
    fprintf(stdout, "%s%d", str, num);

    return 0;
}
