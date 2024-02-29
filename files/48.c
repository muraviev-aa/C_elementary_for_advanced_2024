// 48. Читаем исполняемый файл нашей программы в бинарном режиме

#include <stdio.h>

int main(int argc, char ** argv)
{
    int ch;
    FILE * fptr;
    fptr = fopen(argv[0], "rb");

    while(feof(fptr) == 0)
    {
        fread(&ch, sizeof(char), 1, fptr);
        fputc(ch, stdout);
    }

    fclose(fptr);
    return 0;
}
