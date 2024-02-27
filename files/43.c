// 43. Чтение бинарных данных с помощью ф-ции fread() №1

#include <stdio.h>

int main()
{
    FILE * fptr;
    const char * filename = "text.dat";
    unsigned short num;

    fptr = fopen(filename, "rb"); // rb - считать бинарное значение

    // fread(void *, size_t, size_t, FILE *);
    // (куда записать/размер 1-го эл-та/ кол-во эл-ов/ откуда взять)
    fread(&num, sizeof(num), 1, fptr);
    fclose(fptr);

    printf("num is %hu", num);

    return 0;
}
