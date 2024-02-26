// 41. Работа с бинарными данными, используя функцию fwrite()

#include <stdio.h>

int main()
{
    unsigned short num = 12345;
    FILE * fptr;
    fptr = fopen("text.dat", "wb");

    // size_t fwrite (const void*, size_t, size_t, FILE*);
    // fwrite(что записать, размер информации, кол-во эл-ов, куда записать)
    fwrite(&num, sizeof(num), 1, fptr);
    /*
    число 12345 --> 00110000 00111001 в двоичной
    в десятичной это:     48       57
    в кодировке ASCII      0        9
    записаны в файл будут в обратном порядке: 90
    */
    fclose(fptr);
    return 0;
}
