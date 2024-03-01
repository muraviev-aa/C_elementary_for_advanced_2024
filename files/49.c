// 49. Вывод в консоль нескольких файлов

#include <stdio.h>
#include <windows.h>

int main(int argc, char * argv[])
{
    system("chcp>1251"); system("cls");
    FILE * fptr;
    int ch;

    for(unsigned i = 0; i < argc; i++)
    {
        printf("File %s:\n", argv[i]);
        fptr = fopen(argv[i], "rb");
        if(fptr == NULL)
            printf("Can't open file \"%s\"\n", argv[i]);

        while(feof(fptr) == 0)
        {
            fread(&ch, sizeof(char), 1, fptr);
            printf("%c", ch);
        }
        putchar('\n');
        fclose(fptr);
    }

    return 0;
}
