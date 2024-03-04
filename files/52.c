// 52. Запись бинарных данных из массива в файл
// и чтение этих данных из файла в другой массив

#include <stdio.h>

int main()
{
    unsigned arr1[3] = {1, 2, 3};
    unsigned arr2[3];

    FILE * fptr;
    fptr = fopen("test.dat", "wb+");     // wb+ произвольный доступ
    fwrite(arr1, sizeof(arr1), 1, fptr);

    rewind(fptr); // вернул внутренний указатель в файле в начало

    fread(arr2, sizeof(arr1), 1, fptr);
    for(unsigned i = 0; i < 3; i++)
        printf("%u ", arr2[i]);

    fclose(fptr);
    return 0;
}
