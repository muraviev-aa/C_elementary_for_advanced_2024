//-+// 42. Работа с бинарными данными, используя функцию fwrite() №2

#include <stdio.h>
#define NUM 3

int main()
{
    unsigned short data1[NUM] = {12342, 12343, 12344};
    unsigned short data2[NUM] = {12345, 12345, 12345};

    FILE * fptr;
    fptr = fopen("array.dat", "wb");
    // 1 вариант
    for(unsigned i = 0; i < NUM; i++)
        fwrite(&data1[i], sizeof(data1[i]), 1, fptr);
    fclose(fptr);

    fptr = fopen("array.dat", "ab");
    // 2 вариант
    //fwrite(data2, sizeof(data2[0]), NUM, fptr);

    // 3 вариант
    fwrite(data2, sizeof(data2), 1, fptr);
    fclose(fptr);

    return 0;
}
